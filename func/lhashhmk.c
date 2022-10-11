/*
 * lhashhmk() function:
 * Setup lhashhtable and return it's pointer.
 *
 * Return values:
 *  Address of a lhashhtable structure upon success.
 *  NULL pointer if failure. Call errno for further
 *  description.
 *
 * Can set errno to these values for reasons...
 *  EINVAL - Invalid arguments.
 *  ENOMEM - Exhausted all memory spaces.
 * 
 */

#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <errno.h>
#include "./../lhashh.h"

lhashhtable *lhashhmk(
	unsigned long size,
	unsigned short colhndl, 
	long entamt,
	... )
{
	
	register long i;
	register long entsize = 0;
	struct lhashhtable_entry *ent;
	va_list entlist;
	
	if( colhndl <= LHASHH_TCH_FIRSTVALUE 
	||  colhndl >= LHASHH_TCH_LASTVALUE 
	||  size    == 0 ) {
		
		errno = EINVAL;
		return NULL;
		
	}

	/*
	* C90 and prior versions allow 31 arguments to a function
	* C99 allows 127 arguments.
	*/
#if __STDC_VERSION__ >= 199000L
	if( entamt == 0 || entamt > 31 - 3 ) {
		
		errno = EINVAL;
		return NULL;
		
	}
#else
	if( entamt <= 0 || entamt > 127 - 3 ) {
		
		errno = EINVAL;
		return NULL;
		
	}
#endif
	
	/*
	 * Alloc memory for table structure...
	 */
	lhashhtable *table = (lhashhtable*)malloc( sizeof(lhashhtable) );
	if( table == NULL ) {
		
		errno = ENOMEM;
		return NULL;
		
	}
	
	table->size       = size;
	table->colhndl    = colhndl;
	table->flag.multi = 0;

	/*
	 * Create memory for entry list....
	 */
	table->entry.list = (struct lhashhtable_entry*)malloc( 
		sizeof( struct lhashhtable_entry ) * (entamt) 
	);
	if(  table->entry.list == NULL ) {
		
		errno = ENOMEM;
		free( table );
		return NULL;
		
	}
	
	/*
	 * Copy entry types passed through stdarg into entry list...
	 */	
	va_start( entlist, entamt );
	for( i = 0; i < entamt; i++ ) {
		
		ent = (struct lhashhtable_entry*) va_arg( 
			entlist, 
			struct lhashhtable_entry* 
		);
		
		if( ent->type <= LHASHH_ENTRY_IS_FIRSTVALUE
		 || ent->type >= LHASHH_ENTRY_IS_LASTVALUE ) {
			
			va_end( entlist );
			errno = EINVAL;
			return NULL;			
			
		}
		
		memcpy( 
			&(table->entry.list[i]), 
			ent, 
			sizeof( struct lhashhtable_entry )
		);
		
		entsize += ent->size;
		
		
	}
	va_end( entlist ); 
	
	table->entry.amount = entamt;
	table->entry.size   = entsize;
	
	/*
	 * Create the table part of "hash table"...
	 */
	table->chunk = (struct lhashhtable_chunk*)malloc( sizeof(struct lhashhtable_chunk) * size );
	if( table->chunk == NULL ) {
		
		errno = ENOMEM;
		free( table->entry.list );
		free( table );
		return NULL;
		
	} 
	memset( 
		table->chunk, 
		0, 
		sizeof(struct lhashhtable_chunk) * size 
	);
	
	/*
	 * Head node of key list starts as NULL...
	 */
	table->key.head = NULL;
	table->key.amount =  0;
	
	return table;
	
}