/*
 * Dynamic hash table in C.
 * Creator: josko3567
 * TODO: Cleanup after errors in lhashhmk() ::DONE
 *
 */

#ifndef LHASHH_HEADER_INCLUDED
#define LHASHH_HEADER_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Entry type key values.
 */
enum lhashh_kv_entry_type {
	
	LHASHH_ENTRY_IS_FIRSTVALUE = 0,
	
	LHASHH_ENTRY_IS_CHAR,
	LHASHH_ENTRY_IS_UCHAR,
	
	LHASHH_ENTRY_IS_SHORT,
	LHASHH_ENTRY_IS_USHORT,
	
	LHASHH_ENTRY_IS_INT,
	LHASHH_ENTRY_IS_UINT,
	
	LHASHH_ENTRY_IS_LONG,
	LHASHH_ENTRY_IS_ULONG,
	
	LHASHH_ENTRY_IS_LONGLONG,
	LHASHH_ENTRY_IS_ULONGLONG,
	
	LHASHH_ENTRY_IS_FLOAT,
	LHASHH_ENTRY_IS_DOUBLE,
	LHASHH_ENTRY_IS_LONGDOUBLE,
	
	LHASHH_ENTRY_IS_STRING,
	LHASHH_ENTRY_IS_POINTER,
	
	LHASHH_ENTRY_IS_LASTVALUE
	
}; 

struct lhashhtable_entry {
	
	unsigned int type;
	unsigned int size;
	
}
#ifndef LHASHH_RM_DEF_FOR_OBJ_COMP

  LHASHH_ENTRY_TYPE_FIRSTVALUE = { LHASHH_ENTRY_IS_FIRSTVALUE, 0},

  LHASHH_ENTRY_TYPE_CHAR       = { LHASHH_ENTRY_IS_CHAR,       sizeof( char ) },
  LHASHH_ENTRY_TYPE_UCHAR      = { LHASHH_ENTRY_IS_UCHAR,      sizeof( unsigned char ) },
  
  LHASHH_ENTRY_TYPE_SHORT      = { LHASHH_ENTRY_IS_SHORT,      sizeof( short ) },
  LHASHH_ENTRY_TYPE_USHORT     = { LHASHH_ENTRY_IS_USHORT,     sizeof( unsigned short ) },
  
  LHASHH_ENTRY_TYPE_INT        = { LHASHH_ENTRY_IS_INT,        sizeof( int ) },
  LHASHH_ENTRY_TYPE_UINT       = { LHASHH_ENTRY_IS_UINT,       sizeof( unsigned int ) },
  
  LHASHH_ENTRY_TYPE_LONG       = { LHASHH_ENTRY_IS_LONG,       sizeof( long ) },
  LHASHH_ENTRY_TYPE_ULONG      = { LHASHH_ENTRY_IS_ULONG,      sizeof( unsigned long ) },
  
  LHASHH_ENTRY_TYPE_LONGLONG   = { LHASHH_ENTRY_IS_LONGLONG,   sizeof( long long ) },
  LHASHH_ENTRY_TYPE_ULONGLONG  = { LHASHH_ENTRY_IS_ULONGLONG,  sizeof( unsigned long long ) },
  
  LHASHH_ENTRY_TYPE_FLOAT      = { LHASHH_ENTRY_IS_FLOAT,      sizeof( float ) },
  LHASHH_ENTRY_TYPE_DOUBLE     = { LHASHH_ENTRY_IS_DOUBLE,     sizeof( double ) },
  LHASHH_ENTRY_TYPE_LONGDOUBLE = { LHASHH_ENTRY_IS_LONGDOUBLE, sizeof( long double ) },
  
  LHASHH_ENTRY_TYPE_STRING     = { LHASHH_ENTRY_IS_STRING,     sizeof( char * ) },
  LHASHH_ENTRY_TYPE_POINTER    = { LHASHH_ENTRY_IS_POINTER,    sizeof( void * ) },
  
  LHASHH_ENTRY_TYPE_LASTVALUE  = { LHASHH_ENTRY_IS_LASTVALUE,  0 }

#endif
;

enum lhashh_kv_table_collison_handle_type {
	
	LHASHH_TCH_FIRSTVALUE = 0,
	
	LHASHH_TCH_CHAIN,
	LHASHH_TCH_PROBE_LIN,
	LHASHH_TCH_PROBE_QUAD,
	/* Cannot double hash since we don't
	control the hashing algorithm*/
	
	LHASHH_TCH_LASTVALUE
	
};

struct lhashhtable_keyent {
	
	char *key;
	unsigned short keysize;
	unsigned long hash;
	unsigned long realhash;
	struct lhashhtable_chunk *chunk;
	struct lhashhtable_keyent *next;
	struct lhashhtable_keyent *prev;
	
};

/*
 * Hash table entry.
 */
struct lhashhtable_chunk {
	
	char *value;
	struct lhashhtable_keyent *key;
	struct lhashhtable_chunk *next; 
	/* for linear probing collison handling */
	
};

typedef struct {
	
	unsigned long size; /* sizeof table->chunk */
	unsigned short colhndl; /* collision handling type */
	
	struct {
		unsigned int amount; /* amount of entries per chunk */
		unsigned int size; /* amount of memory all entries occupy */
		struct lhashhtable_entry *list; /* entry list with type and size */
	} entry;
	
	struct {
		unsigned long amount; /* amount of keys stored inside of key list */
		struct lhashhtable_keyent *head; /* key linked list head node 
		... updated every time a new key is added */
		struct lhashhtable_keyent *node; /* Free use node for lhashhfor( ... ) */
		struct lhashhtable_keyent *nodenext; /* Free use node for lhashhfor( ... ) */
	} key;

        struct {

                int multi; /* If set to 0 this flag will check upon collision in lhashhin()
                if the entry that it collided with is the same one as we are trying to put
                into the table. If such is true then we set a EEXIST flag on errno and return 
                1. Otherwise if set to 1 we ignore the check and simply place the entry in the
                next avaliable spot. */

        } flag;
	
	struct lhashhtable_chunk *chunk; /* hash table */
	
} lhashhtable;

/* Functions */

extern
lhashhtable *lhashhmk(
	unsigned long size,
	unsigned short colhndl, 
	long entamt,
	... 
);

extern
void lhashhdy( 
	lhashhtable * table 
); 

extern
int lhashhin(
	lhashhtable    *table,
	const char       *key,
	unsigned short keysize, /* Amount of memory
	object that is pointed to takes up, */
	unsigned long (*hashfunc)(	
		const char *, 
		unsigned short ),
	... 
);

extern
int lhashhout(
	lhashhtable    *table,
	const char       *key,
	unsigned short keysize,
	unsigned long (*hashfunc)(
		const char *, 
		unsigned short ),
	... 
);

extern
int lhashhrm(
	lhashhtable    *table,
	const char       *key,
	unsigned short keysize, /* Amount of memory
	object that is pointed to takes up, */
	unsigned long (*hashfunc)(	
		const char *, 
		unsigned short 
                ) 
 );

#ifdef LHASHH_DEBUG_MODE
#include "func/lhashhprint.c" */
#include "func/lhashhpall.c" */
#endif

extern
void lhashhprint( 
	lhashhtable *table 
);

extern
void lhashhpall( 
	lhashhtable * table 
);

extern
unsigned long lhashhdjb2(
	const char *key,
	unsigned short keysize 
);

extern
unsigned long lhashhfnv(
	const char *key,
	unsigned short keysize 
);

extern
unsigned long lhashhoaat(
	const char *key,
	unsigned short keysize 
);

#define lhashh_for_each_keyent( keyent, table ) \
	\
	table->key.node = table->key.head != NULL ? table->key.head->next : NULL;  \
	\
	for( struct lhashhtable_keyent *keyent = table->key.head; \
		keyent != NULL; \
	keyent = table->key.node, \
	table->key.node = table->key.node ? table->key.node->next : NULL )

#ifdef __cplusplus
}
#endif

#endif 