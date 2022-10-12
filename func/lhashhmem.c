

#include "./../lhashh.h"
#include "string.h"

int
lhashh_freekeyent(
        lhashhtable_keyent * keyent )

int
lhashh_freechunk(
        lhashhtable table,
        lhashhtable_chunk __restrict *chunk,
        lhashhtable_chunk __restrict *prev  )
{

        if( chunk->value != NULL )
                free( chunk->value )
        if()
}


/*
 * lhashh_copychunk() function.
 * Copy the contents of one hash table chunk to
 * another chunk.
 *
 * Return values:
 *  0 - Success.
 *  1 - Error, call errno for further description.
 *
 * Can set errno to these values for reasons...
 *  EINVAL - Invalid argument.
 */
int
lhashh_copychunk(
        lhashhtable_chunk __restrict *to,
        const lhashhtable_chunk __restrict *from )
{

        if( to )



}