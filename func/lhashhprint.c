#include <stdio.h>
#include "./../lhashh.h"

const char * lhashhprint_gettype( 
	unsigned int type )
{
	switch( type ) {
		
		case LHASHH_ENTRY_IS_STRING:
		return "char*";
		break;
		
		case LHASHH_ENTRY_IS_POINTER:
		return "void*";
		break;
		
		case LHASHH_ENTRY_IS_CHAR:
		return "char";
		break;
		
		case LHASHH_ENTRY_IS_UCHAR:
		return "unsigned char";
		break;
		
		case LHASHH_ENTRY_IS_SHORT:
		return "short";
		break;
		
		case LHASHH_ENTRY_IS_USHORT:
		return "unsigned short";
		break;
		
		case LHASHH_ENTRY_IS_INT:
		return "int";
		break;
		
		case LHASHH_ENTRY_IS_UINT:
		return "unsigned int";
		break;
		
		case LHASHH_ENTRY_IS_LONG:
		return "long";
		break;
		
		case LHASHH_ENTRY_IS_ULONG:
		return "unsigned long";
		break;
		
		case LHASHH_ENTRY_IS_LONGLONG:
		return "long long";
		break;
		
		case LHASHH_ENTRY_IS_ULONGLONG:
		return "unsigned long long";
		break;
		
		case LHASHH_ENTRY_IS_FLOAT:
		return "float";
		break;
		
		case LHASHH_ENTRY_IS_DOUBLE:
		return "double";
		break;
		
		case LHASHH_ENTRY_IS_LONGDOUBLE:
		return "long double";
		break;
		
		default:
		return "unknown";
		break; 	
		
	}
	
	return NULL;
}


void lhashhprint( 
	lhashhtable *table )
{
	
	printf("lhashhtable contents:\n");
	
	if( table == NULL ) {
		
		printf("%c%c%c%c%c%c%c%c%c",
			192,196,196,196,196,196,196,196,196);
		printf(" Error!: No table!");
		return;
		
	}
	printf("%c%c%c%c%c%c%c%c%c",
		195,196,196,196,196,196,196,196,196);
	printf(" table->size = %lu %s\n", 
		table->size,
		table->size==1?
		"chunk":"chunks"
	);
	if( table->colhndl == LHASHH_TCH_CHAIN ) {
		
		printf("%c%c%c%c%c%c%c%c%c",
			195,196,196,196,196,196,196,196,196);
		printf(" table->colhndl = LHASHH_TCH_CHAIN\n");
		
	} else if( table->colhndl == LHASHH_TCH_PROBE_LIN ) {
		
		printf("%c%c%c%c%c%c%c%c%c",
			195,196,196,196,196,196,196,196,196);
		printf(" table->colhndl = LHASHH_TCH_PROBE_LIN\n");
		
	} else if( table->colhndl == LHASHH_TCH_PROBE_QUAD ) {
		
		printf("%c%c%c%c%c%c%c%c%c",
			195,196,196,196,196,196,196,196,196);
		printf(" table->colhndl = LHASHH_TCH_PROBE_QUAD\n");
		
	} else {
		
		printf("%c%c%c%c%c%c%c%c%c",
			195,196,196,196,196,196,196,196,196);
		printf(" table->colhndl = UNKNOWN / %d", table->colhndl ); 
		
	}
	
	printf("%c%c%c%c%c%c%c%c%c",
		195,196,196,196,196,196,196,196,196);
	printf(" table->entry.amount = %d\n", table->entry.amount );
	printf("%c%c%c%c%c%c%c%c%c",
		195,196,196,196,196,196,196,196,196);
	printf(" table->entry.size = %d %s\n",
		table->entry.size,
		table->entry.size==1?
		"byte":"bytes"
	);
	if( table->entry.list == NULL ) {
		
		printf("%c%c%c%c%c%c%c%c%c",
			195,196,196,196,196,196,196,196,196);
		printf(" table->entry.list: \n");
		printf("%c\t  %c%c%c%c%c",
			179, 192,196,196,196,196);
		printf(" NULL\n");
		
		
	} else {
		
		printf("%c%c%c%c%c%c%c%c%c",
			195,196,196,196,196,196,196,196,196);
		printf(" table->entry.list: \n");
		printf("%c\t  %c%c%c%c%c",
			179, 195,196,196,196,196);
			
		printf(" &%p\n", table->entry.list );
		
		for( int i = 0; 
			i < (int)table->entry.amount 
			&&  table->entry.list[i].type != LHASHH_ENTRY_IS_FIRSTVALUE;
		i++ ) {
			if( i + 1 == (int)table->entry.amount ) {
				
				printf("%c\t  %c%c%c%c%c",
					179, 192,196,196,196,196);
				printf(" list[%d]:\n", i );
				printf("%c\t        %c",
					179,195);
				printf(" .type = %s\n", 
					lhashhprint_gettype(
						table->entry.list[i].type 
					)
				);
				printf("%c\t        %c",
					179,192);
				printf(" .size = %d %s\n", 
					table->entry.list[i].size,
					table->entry.list[i].size==1?
					"byte":"bytes"
				);
				
			} else {
				
				printf("%c\t  %c%c%c%c%c",
					179, 195,196,196,196,196);
				printf(" list[%d]:\n", i );
				printf("%c\t  %c     %c",
					179, 179,195);
				printf(" .type = %s\n", 
					lhashhprint_gettype(
						table->entry.list[i].type 
					)
				);
				printf("%c\t  %c     %c",
					179, 179,192);
				printf(" .size = %d %s\n", 
					table->entry.list[i].size,
					table->entry.list[i].size==1?
					"byte":"bytes"
				);
				
			}
			
			
		}
		
	}
	
	printf("%c%c%c%c%c%c%c%c%c",
		195,196,196,196,196,196,196,196,196);
	printf(" table->key.amount = %lu\n", table->key.amount );
	if( table->key.head != NULL ) {
		
		printf("%c%c%c%c%c%c%c%c%c",
			195,196,196,196,196,196,196,196,196);
                printf(" table->key.head = &%p\n", 
				table->key.head );
		
	} else {
		
		printf("%c%c%c%c%c%c%c%c%c",
			195,196,196,196,196,196,196,196,196);	
		printf(" table->key.head = NULL\n" );
		
	}
	
	if( table->chunk != NULL ) {
		
		printf("%c%c%c%c%c%c%c%c%c",
			192,196,196,196,196,196,196,196,196);
		printf(" table->chunk = &%p\n", 
				table->chunk );
		
	} else {
		
		printf("%c%c%c%c%c%c%c%c%c",
			192,196,196,196,196,196,196,196,196);	
		printf(" table->chunk = NULL\n" );
		
	}
	
	
	return;
	
	
}