/*
 * lhashhin() function.
 * Inputs a value inside the hash table,
 * Where it is placed is controlled by 
 * the key and hash function pointer given
 * to the function.
 *
 * Return values:
 *  0 - Success.
 *  1 - Error, call errno for further description.
 *
 * Can set errno to these values for reasons...
 *  EINVAL - Invalid argument.
 *  ENOMEM - Exhausted all memory spaces.
 *  EILSEQ - Called when searching for free space
 *           while collision was detected. Occurs 
 *           when the chunk we check for free space 
 *           has value allocated but key points to 
 *           NULL or vise versa.
 *  ENOSPC - No free chunk was found in hash table
 *           when using collision handling of type
 *           LHASHH_TCH_PROBE_LIN or 
 *           LHASHH_TCH_PROBE_QUAD.
 *  EEXIST - If encountered a table entry with the
 *           same keyvalue as the one that we are
 *           trying to put into the table.
 *           The error can only be set if the value
 *           of table->flag.multi == 0 otherwise it
 *           ignores the extra check.
 */
 
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include "./../lhashh.h"

void lhashhin_varead_char(
	void    *mem,
	int    wsize,
	int        i,
	va_list *list )
{
	
	if( mem == NULL ) {
		
		return;
		
	}
	
	char read = (char)va_arg( *list, int );
	
	memcpy( ((char*)mem)+i, &read, wsize );
	
	return;
	
}

void lhashhin_varead_uchar(
	void    *mem,
	int    wsize,
	int        i,
	va_list *list )
{
	
	if( mem == NULL ) {
		
		return;
		
	}
	
	unsigned char read = (unsigned char)va_arg( 
		*list, 
		int 
	);
	
	memcpy( ((char*)mem)+i, &read, wsize );
	
	return;
	
}

void lhashhin_varead_short(
	void    *mem,
	int    wsize,
	int       i,
	va_list *list )
{
	
	if( mem == NULL ) {
		
		return;
		
	}
	
	short read = (short)va_arg( 
		*list, 
		int 
	);
	
	memcpy( ((char*)mem)+i, &read, wsize );
	
	return;
	
}

void lhashhin_varead_ushort(
	void    *mem,
	int    wsize,
	int       i,
	va_list *list )
{
	
	if( mem == NULL ) {
		
		return;
		
	}
	
	unsigned short read = (unsigned short)va_arg( 
		*list, 
		int 
	);
	
	memcpy( ((char*)mem)+i, &read, wsize );
	
	return;
	
}



void lhashhin_varead_int(
	void    *mem,
	int    wsize,
	int       i,
	va_list *list )
{

	if( mem == NULL ) {
		
		return;
		
	}

	int read = va_arg( 
		*list, 
		int 
	);
	
	memcpy( ((char*)mem)+i, &read, wsize );
	
	return;
	
}

void lhashhin_varead_uint(
	void    *mem,
	int    wsize,
	int       i,
	va_list *list )
{
	
	if( mem == NULL ) {
		
		return;
		
	}
	
	unsigned int read = (unsigned int)va_arg( 
		*list, 
		int 
	);
	
	memcpy( ((char*)mem)+i, &read, wsize );
	
	return;
	
}

void lhashhin_varead_long(
	void    *mem,
	int    wsize,
	int       i,
	va_list *list )
{
	
	if( mem == NULL ) {
		
		return;
		
	}
	
	long read = va_arg( 
		*list, 
		long 
	);
	
	memcpy( ((char*)mem)+i, &read, wsize );
	
	return;
	
}

void lhashhin_varead_ulong(
	void    *mem,
	int    wsize,
	int       i,
	va_list *list )
{
	
	if( mem == NULL ) {
		
		return;
		
	}
	
	unsigned long read = (unsigned long)va_arg( 
		*list, 
		long 
	);
	
	memcpy( ((char*)mem)+i, &read, wsize );
	
	return;
	
}

void lhashhin_varead_longlong(
	void    *mem,
	int    wsize,
	int       i,
	va_list *list )
{
	
	if( mem == NULL ) {
		
		return;
		
	}
	
	long long read = va_arg( 
		*list, 
		long long 
	);
	
	memcpy( ((char*)mem)+i, &read, wsize );
	
	return;
	
}

void lhashhin_varead_ulonglong(
	void    *mem,
	int    wsize,
	int       i,
	va_list *list )
{
	
	if( mem == NULL ) {
		
		return;
		
	}
	
	unsigned long long read = (unsigned long long)va_arg( 
		*list, 
		long long 
	);
	
	memcpy( ((char*)mem)+i, &read, wsize );
	
	return;
	
}

void lhashhin_varead_float(
	void    *mem,
	int    wsize,
	int       i,
	va_list *list )
{
	
	if( mem == NULL ) {
		
		return;
		
	}
	
	float read = (float)va_arg( 
		*list, 
		double 
	);
	
	memcpy( ((char*)mem)+i, &read, wsize );
	
	return;
	
}

void lhashhin_varead_double(
	void    *mem,
	int    wsize,
	int       i,
	va_list *list )
{
	
	if( mem == NULL ) {
		
		return;
		
	}
	
	double read = va_arg( 
		*list, 
		double 
	);
	
	memcpy( ((char*)mem)+i, &read, wsize );
	
	return;
	
}

void lhashhin_varead_longdouble(
	void    *mem,
	int    wsize,
	int       i,
	va_list *list )
{
	
	if( mem == NULL ) {
		
		return;
		
	}
	
	long double read = va_arg( 
		*list, 
		long double 
	);
	
	memcpy( ((char*)mem)+i, &read, wsize );
	
	return;
	
}

void lhashhin_varead_pointer(
	void    *mem,
	int    wsize,
	int       i,
	va_list *list )
{
	
	if( mem == NULL ) {
		
		return;
		
	}
	
	void* read = va_arg( 
		*list, 
		void* 
	);
	
	memcpy( ((char*)mem)+i, &read, wsize );
	
	return;
	
}

void lhashhin_varead_string(
	void    *mem,
	int    wsize,
	int       i,
	va_list *list )
{
	
	if( mem == NULL ) {
		
		return;
		
	}
	
	char* read = va_arg( 
		*list, 
		char* 
	);
	
	memcpy( ((char*)mem)+i, &read, wsize );
	
	return;
	
}

/*
 * List follows the same arrangment as lhashh_kv_entry_type
 * enum list inside of lhashh.h, so if u update that list you
 * also must update this list to.
 */
void (*lhashhin_varead_list[])(
	void*,
	int,
	int,
	va_list*) = 
{
	
	NULL,
	
	lhashhin_varead_char,
	lhashhin_varead_uchar,
	
	lhashhin_varead_short,
	lhashhin_varead_ushort,
	
	lhashhin_varead_int,
	lhashhin_varead_uint,
	
	lhashhin_varead_long,
	lhashhin_varead_ulong,
	
	lhashhin_varead_longlong,
	lhashhin_varead_ulonglong,
	
	lhashhin_varead_float,
	lhashhin_varead_double,
	lhashhin_varead_longdouble,
	
	lhashhin_varead_string,
	lhashhin_varead_pointer,
	
	NULL
	
};

int lhashhin(
	lhashhtable    *table,
	const char       *key,
	unsigned short keysize, /* Amount of memory
	object that is pointed to takes up, */
	unsigned long (*hashfunc)(	
		const char *, 
		unsigned short ),
	... )
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
	
	if( 
	( 
            table->colhndl == LHASHH_TCH_PROBE_LIN 
	||  table->colhndl == LHASHH_TCH_PROBE_QUAD 
	) 
	&& table->size    <= table->key.amount ) {
		
		errno = ENOSPC;
		return 1;
		
	}
	
	va_list arglist;
	
	register int           i, j;
	register int           args = table->entry.amount;
         /* Limit hash with table size. */
	register unsigned long hash = (*hashfunc)( key, keysize )%table->size;
	register unsigned long hashcpy = hash;
	struct lhashhtable_chunk *chunk = NULL;
	struct lhashhtable_chunk *chunkeq = NULL;
	
	/*
	 * Memory for key entry and value and copy
	 * key to node.
	 */ 
	struct lhashhtable_keyent *keyent = (struct lhashhtable_keyent*)malloc( 
		sizeof(struct lhashhtable_keyent)
	);
	if( keyent == NULL ) {
		
		errno = ENOMEM;
		return 1;
		
	}

	keyent->key = (char*)malloc( keysize );
	if( keyent->key == NULL ) {
		
		errno = ENOMEM;
		free( keyent );
		return 1;
		
	}
	memcpy( 
		keyent->key, 
		key, 
		keysize 
	);
	
	/*
	 * Copy hash to key.
	 */
	keyent->hash = hash;
	
	/*
	 * Collision detect, and based on 
	 * table->colhndl we handle it.
	 */
	chunk = &table->chunk[hash];
	
	if( chunk->value != NULL
	&&  chunk->key   != NULL ) {
		
		if( table->colhndl == LHASHH_TCH_CHAIN ) {
			
			/*
			 * Go through linked list,
			 * find last node and create new
			 * one, memset to 0 and set it as chunk.
			 */
                        do {
                                
                                /* Check for flag.multi, more in lhashh.h */
                                if( table->flag.multi == 0 
                                &&  keysize == chunk->key->keysize ) {

                                        if( memcmp( 
                                                key, 
                                                chunk->key->key, 
                                                (size_t)keysize 
                                            )  == 0 ) {

                                                errno = EEXIST;
                                                free( keyent->key );
			        	        free( keyent );
                                                return 1;

                                        }

                                }

                                if( chunk->next != NULL )
                                        chunk = chunk->next;
                                else
                                        break;

                        } while( 1 );
			
			chunk->next = (struct lhashhtable_chunk*)malloc( 
				sizeof(struct lhashhtable_chunk )
			);
			if( chunk->next == NULL ) {
				
				errno = ENOMEM;
				free( keyent->key );
				free( keyent );
				return 1;
				
			} 
			
			chunk = chunk->next;
			
			memset( 
				chunk,
				0,
				sizeof( struct lhashhtable_chunk )
			);
			
		} else if( table->colhndl == LHASHH_TCH_PROBE_LIN ) {
			
			/*
			 * Search the table linearly for
			 * free chunk and set it as chunk.
			 * chunkeq is the last chunk that has
			 * the same hash value. We set it's
			 * chunk->next to point to chunk.
			 */
			chunkeq = &table->chunk[hash];
			
			while( chunk->value != NULL ) {
				
				if( chunk->key == NULL ) {
					
					errno = EILSEQ;
					free( keyent->key );
					free( keyent );
					return 1;
					
				}
				
                                /* Check for flag.multi, more in lhashh.h */
                                if( table->flag.multi == 0 
                                &&  keysize == chunk->key->keysize ) {

                                        if( memcmp( 
                                                key, 
                                                chunk->key->key, 
                                                (size_t)keysize 
                                            ) == 0 ) {

                                                errno = EEXIST;
                                                free( keyent->key );
					        free( keyent );
                                                return 1;

                                        }
        
                                }

				if( chunk->key->hash == hashcpy ) {
				
					chunkeq = &table->chunk[hash];
					
				} 
				
				/* Increment */
				hash  = (hash+1)%table->size;
				
				if( hash == hashcpy ) {
					
					/* If function did
					one whole loop and found
					no free chunks, exit
					with errno = ENOSPC */
					errno = ENOSPC;
					free( keyent->key );
					free( keyent );
					return 1;
					
				}
				
				chunk = &table->chunk[hash];
				
			}
			
			chunkeq->next = chunk;
			
		} else if( table->colhndl == LHASHH_TCH_PROBE_QUAD ) {
			
			/*
			 * Same as linear but we don't have
			 * extra check for no space and the
			 * hash formula is different.
			 */
			chunkeq = &table->chunk[hash];
			
			while( chunk->value != NULL ) {
				
				if( chunk->key == NULL ) {
					
					errno = EILSEQ;
					free( keyent->key );
					free( keyent );
					return 1;
					
				}

                                if( table->flag.multi == 0 
                                &&  keysize == chunk->key->keysize ) {

                                        if( memcmp( 
                                                key, 
                                                chunk->key->key, 
                                                (size_t)keysize 
                                            ) == 0 ) {
                                                
                                                errno = EEXIST;
                                                free( keyent->key );
					        free( keyent );
                                                return 1;

                                        }
        
                                }
				
				if( chunk->key->hash == hashcpy ) {
				
					chunkeq = &table->chunk[hash];
					
				} 
				
				/* Quad formula */
				hash  = ((hash*hash)+1)%table->size;
				
				chunk = &table->chunk[hash];
				
			}
			
			chunkeq->next = chunk;
			
			
		} else {
			
			errno = EILSEQ;
			free( keyent->key );
			free( keyent );
			return 1;
			
		}
		
	}
	/*
	 * Allocate memory for chunk value.
	 */
	chunk->value = (char*)malloc( table->entry.size );
	if( chunk->value == NULL ) {
		
		errno = ENOMEM;
		if( table->colhndl == LHASHH_TCH_CHAIN )
			free( chunk );
		free( keyent->key );
		free( keyent );
		return 1;
		
	}
	
	/*
	 * Read from entry list the expected type of value that
	 * is given in va_list. Check if the value is valid.
	 * Call function from array of functions by the
	 * entry type value and increment j by its size.
	 * Branchless edition.
	 */
	va_start( arglist, hashfunc );
	
	for( i = j = 0; i < args; i++ ) { 
	
		if( table->entry.list[i].type <= LHASHH_ENTRY_IS_FIRSTVALUE
		||  table->entry.list[i].type >= LHASHH_ENTRY_IS_LASTVALUE ) {
			
			errno = EILSEQ;
			free( chunk->value );
			if( table->colhndl == LHASHH_TCH_CHAIN )
				free( chunk );
			free( keyent->key );
			free( keyent );
			return 1;
			
		}
		
		(*lhashhin_varead_list[table->entry.list[i].type])(
			chunk->value,
			table->entry.list[i].size,
			j,
			&arglist
		);
		
		j+= table->entry.list[i].size;
		
	}
	
	va_end( arglist );
	
	/*
	 * Edit pointers to next and previous
	 * nodes for current key node and
	 * head node.
	 */
	keyent->next = table->key.head;
	keyent->prev = NULL;
	if( table->key.head != NULL ) {
		
		table->key.head->prev = keyent;
		
	}
	/*
	 * Write the realhash, ie.
	 * hash value + collision movement value
	 * , chunk pointer and keysize to key
	 * entry.
	 */
	keyent->realhash = hash;
	keyent->chunk = chunk;
	keyent->keysize = keysize;
	
	/*
	 * Place key node as head node.
	 * and set key pointer inside
	 * chunk to new head node.
	 */
	table->key.head = keyent;
	table->key.amount++;
	chunk->key = keyent;

	return 0;
	
}