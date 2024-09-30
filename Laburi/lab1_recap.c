#include<stdio.h>
#include<stdlib.h>
#include<string.h>


//Se citesc m (linii) si n(coloane) ale unei matrici alocate dinamic. Sa se afiseze maximul de pe  fiecare coloana. 
void pb1()
{
	int m, n;
	int **a;
	
	printf("m = "); scanf("%d", &m);
	printf("n = "); scanf("%d", &n);
	
	//alocare vector de pointeri la linii 
	
	if((a = (int **)malloc(sizeof(int*)*m))==NULL)
	{
		printf("Memorie insuficienta");
		exit(EXIT_FAILURE);
	}
	
	//alocare linii
	for(int i=0; i<m; i++)
		if((a[i] = (int *)malloc(sizeof(int) * n))==NULL)
		{
			for(i--; i>=0; i--) free(a[i]);
			free(a);
			printf("Memorie insuficienta");
			exit(EXIT_FAILURE);
		}
		
	for(int i=0; i<m; i++)
		for(int j=0; j<n; j++)
			{
				printf("a[%d][%d] = ", i, j);
				scanf("%d", &a[i][j]);
			}
	for(int j=0; j<n; j++)
	{	int max =0;
		for(int i=0; i<m; i++)
			if(a[i][j]>max)
				max = a[i][j];
		printf("%d ", max);
	}	
	
	//eliberare matrice
	for(int i=0; i<m; i++)
		free(a[i]);
	free(a);
	
}

//Inmultire matrici
void inmultire()
{
	int m, n, p;
	int a[11][11], b[11][11], c[11][11];
	printf("m = "); scanf("%d", &m);
	printf("n = "); scanf("%d", &n);
	printf("p = "); scanf("%d", &p);
	
	
	for(int i=0; i<m; i++)
		for(int j=0; j<n; j++)
			{
				printf("a[%d][%d] = ", i, j);
				scanf("%d", &a[i][j]);
			}
	for(int i=0; i<n; i++)
		for(int j=0; j<p; j++)
			{
				printf("b[%d][%d] = ", i, j);
				scanf("%d", &b[i][j]);
			}
			
	for(int i=0; i<n; i++)
		for(int j=0; j<p; j++)
			{
				for(int k=0; k<n; k++)
					c[i][j] += a[i][k] * b[k][j];
			}
			
	for(int i=0; i<n; i++)
		{
		for(int j=0; j<p; j++)
			printf("%d ", c[i][j]);
			
		printf("\n");
			
		}
	
	
}








int main()
{
	pb1();	
}


