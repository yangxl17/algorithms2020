#include "HashTable.h"
const unsigned int A = 2654435769;
unsigned int MultFunction(unsigned int k, unsigned int p)
{
	return (k*A)>>(32-p);
}

