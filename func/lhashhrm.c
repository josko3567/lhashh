/*
 * lhashhrm() function.
 * Removes entry chunk inside of
 * located at the given hash value.
 *
 * Return values:
 *  0 - Success.
 *  1 - Error, call errno for further description.
 *
 * Can set errno to these values for reasons...
 *  EINVAL - Invalid argument.
 *  EILSEQ - Called when table entry has a illegal
 *           value set for their .type value or
 *           if the keyent for a chunk is equal
 *           to NULL.
 *  ENOENT - If the there is no chunk with the given
 *           key we return ENOENT to signify that
 *           the entry doesn't exist.
 */

#include <errno.h>
#include <malloc.h>
#include <string.h>
#include "./../lhashh.h"

int lhashhrm(
	lhashhtable    *table,
	const char       *key,
	unsigned short keysize, /* Amount of memory
	object that is pointed to takes up, */
	unsigned long (*hashfunc)(	
		const char *, 
		unsigned short 
                ) 
        )
{

        /*
	 * Check arguments for
	 * validity and check space 
	 * left inside of table.
	 */
	if( table    == NULL 
	||  key      == NULL 
	||  hashfunc == NULL
	||  keysize  == 0 ) {
		
		errno = EINVAL;
		return 1;
		
	}

        /*
         * Check if there are any table
         * chunks that are populated.
         */
        if( table->key.amount < 1 ) {

                errno = ENOENT;
                return 1;

        }

        register unsigned long hash = (*hashfunc)( key, keysize )%table->size;
        struct lhashhtable_chunk *chunk     = &table->chunk[hash];
        struct lhashhtable_chunk *chunkprev = NULL;
        struct lhashhtable_chunk *chunkbuff = NULL;

        /*
	 * Search table for hash with same
	 * hash value and key value.
	 */
	chunk = &table->chunk[hash];
	do {
		
                
		if( chunk->value == NULL
		||  chunk->key   == NULL ) {
			
			errno = ENOENT;
			return 1;
			
		} 
		
		if( keysize == chunk->key->keysize ) {
			
                        if( chunk->key->key == NULL ) {

                                errno = EILSEQ;
                                return 1;

                        }

			if( !memcmp( 
				chunk->key->key,
				key,
				(size_t)keysize ) 
			&& hash == chunk->key->hash ) {
				
				break;  
				
			}
			
		}
		
		if( chunk->next == NULL ) {
			
			errno = ENOENT;
			return 1;
			
		}

		chunkprev = chunk;
		chunk = chunk->next;
		
	} while( 1 );


        /*
         * Check if there was a chunk found
         * otherwise we throw ENOENT
         */
        if( chunk == NULL ) {

                errno = ENOENT;
                return 1;

        }
        
        /*
         * Delete keyent node, first check
         * if the key exist.
         */
        if( chunk->key == NULL ) {

                errno = EILSEQ;
                return 1;

        } 

        /*
         * Swap next and prev node pointers around to
         * remove the chunk's key node from the list.
         */
        if( chunk->key->prev != NULL ) 
                (chunk->key->prev)->next = chunk->key->next;

        if( chunk->key->next != NULL )
                (chunk->key->next)->prev = chunk->key->prev;

        /*
         * If we removed the head node we must replace it with
         * the current next node, which could also be a NULL ptr.
         */
        if( table->key.head == chunk->key )
                table->key.head = table->key.head->next;

        table->key.amount--;

        if( chunk->key->key != NULL )
                free( chunk->key->key );

        free( chunk->key );


        /*
         * Delete chunks depending on the collision handling
         * type...
         */
        switch( table->colhndl ) {

                case LHASHH_TCH_CHAIN:
                /*
                 * If chunkprev != NULL and our collision
                 * handling type is of LHASHH_TCH_CHAIN, 
                 * this indicates that the chunk was
                 * allocated and must be freed to avoid 
                 * leaks.
                 */
                if( chunkprev != NULL ) {

                        chunkprev->next = chunk->next;

                        if( chunk->value != NULL )
                                free( chunk->value );

                        free( chunk );

                        return 0;


                /*
                 * If chunkprev == NULL and our collison handling type
                 * is of LHASHH_TCH_CHAIN we must, if it exists, move the
                 * chunk next in the chain to the spot of the current
                 * chunk.
                 */
                } else {

                        if( chunk->value != NULL )
                                free( chunk->value );

                        if( chunk->next != NULL ) {

                                /* Copy over values to destination. */
                                chunk->value      = chunk->next->value;
                                chunk->key        = chunk->next->key;

                                if( chunk->key == NULL ){

                                        errno = EILSEQ;
                                        return 1;

                                } 
                                chunk->next->key->chunk = chunk;

                                /* Store source chunk in temp buffer. */
                                chunkbuff = chunk->next;

                                /* Swap linked list pointer to point to the
                                chunk after the source chunk. */
                                chunk->next = chunk->next->next;
                                free( chunkbuff );

                        } else {

                                /* 
                                 * If both prev and next chunk are NULL
                                 * then we have nothing to move into the
                                 * currently freed chunk therefore we
                                 * have to memset its values to 0 to
                                 * indicate that it is free.
                                 */
                                memset( 
                                        chunk, 
                                        0, 
                                        sizeof(struct lhashhtable_chunk)
                                );

                        }

                }
                break;


                case LHASHH_TCH_PROBE_LIN:
                case LHASHH_TCH_PROBE_QUAD:

                break;
                

                default:
                if( chunk->value != NULL )
                        free(chunk->value);
                errno = EILSEQ;
                return 1;
                break;


        }

        return 0;
        

}