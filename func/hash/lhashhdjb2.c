unsigned long
lhashhdjb2(
	const char *key,
	unsigned short keysize )
{
	
	unsigned long hash = 5381;
	int c;
	
	long i;
	i = 0;
	
	while ((c = *key++ )&& (i < keysize)){
		
		/* hash * 33 + c */
		hash = ((hash << 5) + hash) + c; 
		i++;
	}

	return hash;
	
}