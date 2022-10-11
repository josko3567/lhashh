#include <limits.h>

unsigned long
lhashhfnv(
	const char *key,
	unsigned short keysize )
{
	
	unsigned long long hash = 0xCBF29CE484222325;
	int c;
	
	long i;
	i = 0;
	
	while ((c = *key++) && (i < keysize)){
		
		hash *= 0x100000001B3; 
		hash ^= c;
		
	}

	return (unsigned long)(hash%UINT_MAX);
	
}