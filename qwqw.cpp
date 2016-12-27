#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


unsigned sdvigright(unsigned a, int n, int L)
{

	unsigned maska = 0;
	for (int i = 0; i<L; i++)
	{
		maska <<= 1;
		maska += 1;
	}
	unsigned b = a & maska;
	b <<= (n - L);
	a >>= L;
	return a | b;
}

unsigned sdvigleft(unsigned a, int n, int L)
{

	unsigned maska = 0;
	for (int i = 0; i<L; i++)
	{
		maska <<= 1;
		maska += 1;
	}
	maska <<= (n - L);

	unsigned b = a & maska;
	b >>= (n - L);
	a <<= L;
	return a | b;
}


void shifrDeshifr(char *in, char *out, int n, int key, int reg)
{
	srand(key);
	unsigned char a, b, gamma;
	for (int i = 0; i < n; i ++)
	{
		memcpy(&a, in + i, 1);
		if (reg == 2)
			a = sdvigright(a, 8, 3);
		gamma = rand();
		b = gamma ^ a;
		if (reg == 1) b = sdvigleft(b, 8, 3);
		memcpy(out+i, &b, 1);
	}
}


int main()
{
	char StrIn[64];
	char StrShifr[64];
	char StrOut[64];
	printf("Str = "); fflush(stdin);
	gets(StrIn);
	int len = strlen(StrIn);
	int key1, key2;
	printf("key1 = "); scanf("%d", &key1);
	shifrDeshifr(StrIn, StrShifr, len, key1, 1);
	printf("Posle shifr: ");
	for (int i = 0; i < len; i++)
		printf("\nChar=%c Code=%d", StrShifr[i], StrShifr[i]);
	printf("\nkey2 = "); scanf("%d", &key2);
	shifrDeshifr(StrShifr, StrOut, len, key2, 2);
	StrOut[len] = 0;
	printf("\nPosle deshfr:\n%s\n", StrOut);
    return 0;
}

