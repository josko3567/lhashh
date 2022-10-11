/*
 * lhashhout() function.
 * get values from a lhashhtable type.
 * Values are returned to va_list arguemnts
 * that are pointers to variable that will
 * hold the values.
 *
 * Return values:
 *  0 - Success.
 *  1 - Error, call errno for further description.
 *
 * Can set errno to these values for reasons...
 *  EINVAL - Invalid argument.
 *  ENOMEM - Exhausted all memory spaces.
 *  EILSEQ - Called when table entry has a illegal
 *           value set for their .type value.
 *  ENOENT - If the there is no chunk with the given
 *           key we return ENOENT to signify that
 *           the entry doesn't exist.
 *  EEXIST - If key already exists, we cannot place 
 */

#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <errno.h>
#include "./../lhashh.h"

void lhashhout_vawrite_char(
	void *ptr,
	const char *value,
	int i )
{
	
	if( ptr == NULL
	||  value == NULL ) {
		
		return;
		
	}
	
	*((char*)ptr) = *(char*)&value[i];
	
	return;
	
	
}

void lhashhout_vawrite_uchar(
	void *ptr,
	const char *value,
	int i )
{
	
	if( ptr == NULL
	||  value == NULL ) {
		
		return;
		
	}
	
	*((unsigned char*)ptr) = *(unsigned char*)&value[i];
	
	return;
	
	
}

void lhashhout_vawrite_short(
	void *ptr,
	const char *value,
	int i )
{
	
	if( ptr == NULL
	||  value == NULL ) {
		
		return;
		
	}
	
	*((short*)ptr) = *(short*)&value[i];
	
	return;
	
	
}

void lhashhout_vawrite_ushort(
	void *ptr,
	const char *value,
	int i )
{
	
	if( ptr == NULL
	||  value == NULL ) {
		
		return;
		
	}
	
	*((unsigned short*)ptr) = *(unsigned short*)&value[i];
	
	return;
	
	
}

void lhashhout_vawrite_int(
	void *ptr,
	const char *value,
	int i )
{
	
	if( ptr == NULL
	||  value == NULL ) {
		
		return;
		
	}
	/*
	 * We get the adress of char * value at "i",
	 * cast it to a int * and read from the
	 * int *.
	 */
	*((int*)ptr) = *(int*)&value[i];
	
	return;
	
	
}

void lhashhout_vawrite_uint(
	void *ptr,
	const char *value,
	int i )
{
	
	if( ptr == NULL
	||  value == NULL ) {
		
		return;
		
	}
	
	*((unsigned int*)ptr) = *(unsigned int*)&value[i];
	
	return;
	
	
}

void lhashhout_vawrite_long(
	void *ptr,
	const char *value,
	int i )
{
	
	if( ptr == NULL
	||  value == NULL ) {
		
		return;
		
	}
	
	*((long*)ptr) = *(long*)&value[i];
	
	return;
	
	
}

void lhashhout_vawrite_ulong(
	void *ptr,
	const char *value,
	int i )
{
	
	if( ptr == NULL
	||  value == NULL ) {
		
		return;
		
	}
	
	*((unsigned long*)ptr) = *(unsigned long*)&value[i];
	
	return;
	
	
}

void lhashhout_vawrite_longlong(
	void *ptr,
	const char *value,
	int i )
{
	
	if( ptr == NULL
	||  value == NULL ) {
		
		return;
		
	}
	
	*((long long*)ptr) = *(long long*)&value[i];
	
	return;
	
	
}

void lhashhout_vawrite_ulonglong(
	void *ptr,
	const char *value,
	int i )
{
	
	if( ptr == NULL
	||  value == NULL ) {
		
		return;
		
	}
	
	*((unsigned long long*)ptr) = *(unsigned long long*)&value[i];
	
	return;
	
}

void lhashhout_vawrite_float(
	void *ptr,
	const char *value,
	int i )
{
	
	if( ptr == NULL
	||  value == NULL ) {
		
		return;
		
	}
	
	*((float*)ptr) = *(float*)&value[i];
	
	return;
	
}

void lhashhout_vawrite_double(
	void *ptr,
	const char *value,
	int i )
{
	
	if( ptr == NULL
	||  value == NULL ) {
		
		return;
		
	}
	
	*((double*)ptr) = *(double*)&value[i];
	
	return;
	
	
}

void lhashhout_vawrite_longdouble(
	void *ptr,
	const char *value,
	int i )
{
	
	if( ptr == NULL
	||  value == NULL ) {
		
		return;
		
	}
	
	*((long double*)ptr) = *(long double*)&value[i];
	
	return;
	
	
}

void lhashhout_vawrite_string(
	void *ptr,
	const char *value,
	int i )
{
	
	if( ptr == NULL
	||  value == NULL ) {
		
		return;
		
	}
	
	*((char**)ptr) = *(char**)&value[i];
	
	return;
	
	
}

void lhashhout_vawrite_pointer(
	void *ptr,
	const char *value,
	int i )
{
	
	if( ptr == NULL
	||  value == NULL ) {
		
		return;
		
	}
	
	*((void**)ptr) = *(void**)&value[i];
	
	return;
	
	
}


void (*lhashhout_vawrite_list[])(
	void*,
	const char*,
	int) =
{
	
	NULL, /* firstval */
	
	lhashhout_vawrite_char,
	lhashhout_vawrite_uchar,
	
	lhashhout_vawrite_short,
	lhashhout_vawrite_ushort,
	
	lhashhout_vawrite_int,
	lhashhout_vawrite_uint,
	
	lhashhout_vawrite_long,
	lhashhout_vawrite_ulong,
	
	lhashhout_vawrite_longlong,
	lhashhout_vawrite_ulonglong,
	
	lhashhout_vawrite_float,
	lhashhout_vawrite_double,
	lhashhout_vawrite_longdouble,
	
	lhashhout_vawrite_string,
	lhashhout_vawrite_pointer,
	
	NULL /* lastval */
	
};

int lhashhout(
	lhashhtable    *table,
	const char       *key,
	unsigned short keysize,
	unsigned long (*hashfunc)(
		const char *, 
		unsigned short ),
	... )
{
	
	/*
	 * Check arguments for
	 * validity.
	 */
	if( table    == NULL 
	||  key      == NULL 
	||  hashfunc == NULL
	||  keysize  == 0 ) {
		
		errno = EINVAL;
		return 1;
		
	}
	
	va_list arglist;
	
	register int           i, j;
	register int           args = table->entry.amount;
	register unsigned long hash = (*hashfunc)( key, keysize );
	struct lhashhtable_chunk *chunk = NULL;
	
	/*
	 * Limit hash with table size.
	 */
	hash %= table->size;
	
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
			
			if( !memcmp( 
				chunk->key->key,
				key,
				keysize ) 
			&& hash == chunk->key->hash ) {
				
				break;  
				
			}
			
		}
		
		if( chunk->next == NULL ) {
			
			errno = ENOENT;
			return 1;
			
		}
		
		chunk = chunk->next;
		
		
	} while( 1 );
	
	/*
	 * If entry found, assume all varadict arguments are
	 * pointers. Call to a function from the function list
	 * lhashhout_vawrite_list indexed by 
	 * table->entry.list[?].type will write to said pointer.
	 */
	va_start( arglist, hashfunc );

	for( i = 0, j = 0; i < args; i++ ) {
		
		if( table->entry.list[i].type <= LHASHH_ENTRY_IS_FIRSTVALUE
		||  table->entry.list[i].type >= LHASHH_ENTRY_IS_LASTVALUE ) {
			
			errno = EILSEQ;
			return 1;
			
		}
		
		(*lhashhout_vawrite_list[table->entry.list[i].type])(
			va_arg( arglist, void* ),
			chunk->value,
			j
		);
		j+=table->entry.list[i].size;
		
	}
	
	va_end( arglist );
	
	return 0;
	
}
	