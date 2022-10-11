unsigned long
lhashhoaat(
	const char *key,
	unsigned short keysize )
{
	
	unsigned long hash = 0;
	
	long i;
	i = 0;
	
	while (i < keysize){
		
		hash += key[i++];
		hash += hash << 10;
		hash ^= hash >> 6;
		
	}
	
	hash += hash << 3;
	hash ^= hash >> 11;
	hash += hash << 15;

	return hash;
	
}