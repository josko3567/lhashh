/*
 * lhashhdy() function.
 * Destroy memory allocated for lhashhtable object.
 *
 * No return
 *
 * Does not set errors.
 *
 */

#include <stdlib.h>
#include <malloc.h>
#include "./../lhashh.h"


#define LHASHH_LHASHHDY_PRINT 0

void lhashhdy( 
	lhashhtable * table ) 
{
	
	if( table == NULL ) {
		
		return;
		
	}
	
	struct lhashhtable_keyent *keyent;
	struct lhashhtable_keyent *keydel;
	struct lhashhtable_chunk  *chunk;
	struct lhashhtable_chunk  *chunkdel;
	
	int hash;
	
	int keyfree = 0;
	int chunkfree = 0;
	
	keyent = table->key.head;
	
	/*
	 * Delete operation takes O(n) time.
	 */
	while( keyent != NULL ) {
		
		keydel = keyent;
		keyent = keyent->next;
		free( keydel->key );
		
		hash = keydel->realhash;
		
		chunk = &table->chunk[hash];
		if( chunk->value == NULL ) {
			keyfree++;
			free( keydel );
			continue;
			
		}
		free( chunk->value );
		chunk->value = NULL;
		chunkfree++;
		chunk = chunk->next;
		if( table->colhndl == LHASHH_TCH_CHAIN ) {
			
			while( chunk != NULL ) {
				
				chunkdel = chunk;
				chunk = chunk->next;
				free( chunkdel->value );
				free( chunkdel );
				chunkfree++;
				
			}
			
		}
		
		keyfree++;
		free( keydel );
		
	}
	
	free( table->chunk );
	free( table->entry.list );
	free( table );
#if LHASHH_LHASHHDY_PRINT == 1
	printf("\nCall to lhashhdy():\n");
	printf("\tChunks freed = %d\n\tKeys   freed = %d\n", chunkfree, keyfree );
#endif
	return;
	
	
	
}