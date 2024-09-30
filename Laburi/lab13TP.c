#include<stdio.h>
#include "biblio.h"
#include<time.h>
#include<stdlib.h>
int main()
{
	int v[10000];
	srand(time(0));
	for(int i=0; i<9999; i++)
		v[i] = rand();
	v[200] = 22;
	clock_t start1 = clock();
	printf("%d\n", FindElementLin(v, 10000, 22));
	clock_t end1 = clock();
	double sec1 = ((double)end1 - start1)/CLOCKS_PER_SEC;
	printf("Timp executie 1: %f\n", sec1);
	clock_t start2 = clock();
	printf("%d\n", FindElementBin(v, 10000, 22));
	clock_t end2 = clock();
	double sec2 = ((double)end2 - start2)/CLOCKS_PER_SEC;
	printf("Timp executie 1: %f\n", sec2);
}
