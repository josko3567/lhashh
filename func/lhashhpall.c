#include <stdio.h>
#include "./../lhashh.h"

void lhashhpall( 
	lhashhtable * table )
{
	
	unsigned int i, j;
	struct lhashhtable_keyent * keyent = table->key.head;
	
	while( keyent != NULL ) {
		
		printf("chunk[%lu]:\n", keyent->realhash );
		
		for( i = j = 0; i < table->entry.amount; i++ ) {
			
			// printf("%d|%d\n", i, j );
			
			printf("\t[%3d]: ", j);
			switch( table->entry.list[i].type ) {
				
				case LHASHH_ENTRY_IS_CHAR:
				printf("%c", *(char*)&keyent->chunk->value[j] );
				j+=sizeof(char);
				break;
				
				
				case LHASHH_ENTRY_IS_UCHAR:
				printf("%c", *(unsigned char*)&keyent->chunk->value[j] );
				j+=sizeof(unsigned char);
				break;
				
				
				case LHASHH_ENTRY_IS_SHORT:
				printf("%d", *(short*)&keyent->chunk->value[j] );
				j+=sizeof(short);
				break;
				
				case LHASHH_ENTRY_IS_USHORT:
				printf("%d", *(unsigned short*)&keyent->chunk->value[j] );
				j+=sizeof(unsigned short);
				break;
				
				case LHASHH_ENTRY_IS_INT:
				// printf("called\n");
				printf("%d", *(int*)&keyent->chunk->value[j] );
				j+=sizeof(int);
				break;
				
				case LHASHH_ENTRY_IS_UINT:
				printf("%d", *(unsigned int*)&keyent->chunk->value[j] );
				j+=sizeof(unsigned int);
				break;
				
				case LHASHH_ENTRY_IS_LONG:
				printf("%ld", *(long*)&keyent->chunk->value[j] );
				j+=sizeof(long);
				break;
				
				case LHASHH_ENTRY_IS_ULONG:
				printf("%ld", *(unsigned long*)&keyent->chunk->value[j] );
				j+=sizeof(unsigned long);
				break;
				
				case LHASHH_ENTRY_IS_LONGLONG:
				printf("%lld", *(long long*)&keyent->chunk->value[j] );
				j+=sizeof(long long);
				break;
				
				case LHASHH_ENTRY_IS_ULONGLONG:
				printf("%lld", *(unsigned long long*)&keyent->chunk->value[j] );
				j+=sizeof(unsigned long long);
				break;
				
				case LHASHH_ENTRY_IS_FLOAT:
				printf("%f", *(float*)&keyent->chunk->value[j] );
				j+=sizeof(float);
				break;
				
				case LHASHH_ENTRY_IS_DOUBLE:
				printf("%lf", *(double*)&keyent->chunk->value[j] );
				j+=sizeof(double);
				break;
				
				case LHASHH_ENTRY_IS_LONGDOUBLE:
				printf("%lf", *(double*)&keyent->chunk->value[j] );
				j+=sizeof(long double);
				break;
				
				case LHASHH_ENTRY_IS_STRING:
				printf("%s", *(char**)&keyent->chunk->value[j] );
				j+=sizeof(char*);
				break;
				
				case LHASHH_ENTRY_IS_POINTER:
				printf("%p", *(void**)&keyent->chunk->value[j] );
				j+=sizeof(void*);
				break;
				
			}
			putchar('\n');
			
		}
		keyent = keyent->next;
		
	}
	
}