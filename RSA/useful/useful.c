#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "../linkedList/linkedList.h"

int mdcEuclides(long long int n, long long int m)
{
	if(n%m == 0)
		return m;
	return mdcEuclides(m, n%m);
}

int isPrime(long long int number, long long int div)
{
	if(div >= sqrt(number)+1)
		return 1;
	else if(number%div == 0)
		return 0;
	return isPrime(number, div+1);
}

node* mdcAux(node *list, long long int n, long long int m, int* size)
{
	if(n%m == 0)
		return list;
	if(n >= m) list = addNode(n/m, list);
	*size += 1;
	return mdcAux(list, m, n%m, size);
}