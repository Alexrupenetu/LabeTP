#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdarg.h>

float * vector_raport(int n,...)
{
	va_list args;
	va_start(args, n);
	
	float *v = NULL; int val;
	
	if(( v = malloc(sizeof(float)*n))==NULL)
	{
		printf("uh oh");
		exit(-1);
	}
	
	for(int i=0; i<n; i++)
	{
		val = va_arg(args, int);
		v[i] = (float)val/n;
	}
	
	va_end(args);
	return v;
}

int *vector_patrat(int n,...)
{
	va_list args;
	va_start(args, n);
	
	int *v = NULL;
	
	if((v = malloc(sizeof(int)*n))==NULL)
	{
		printf("caca");
		exit(-1);
	}
	
	for(int i=0; i<n; i++)
	{
		v[i] = va_arg(args, int);
		v[i]=v[i]*v[i];
	}
	va_end(args);
	return v;
}

int prim(int n)
{
	if(n==0 || n==1)
		return 0;
		
	int d;
	for(d=2; d*d<n; d++)
		if(n%d==0)
			return 0;
	if(d*d==n)
		return 0;
	return 1;
}

int *vector_primi(int n,...)
{
	va_list args;
	va_start(args, n);
	
	int *v = NULL;
	
	if((v = malloc(sizeof(int)*n))==NULL)
	{
		printf("caca");
		exit(-1);
	}
	int val, k=0;
	for(int i=0; i<n; i++)
	{
		val = va_arg(args, int);
		if(prim(val)==1)
			v[k++]=val;
	}
	va_end(args);
	return v;
}

//nr n + n caractere => sir doar cu vocalele
char *concatenare_vocale(int n,...)
{
	va_list args;
	va_start(args, n);
	
	char *string = NULL;
	
	if((string = malloc(sizeof(char)*(n+1)))==NULL)
	{
		printf("uh oh");
		exit(-1);
	}
	
	char c, litera[2];
	for(int i=0; i<n; i++)
	{
		c = va_arg(args, int);
		if(strchr("aeiou", c)!=0)
		{
		litera[0]=c;
		litera[1]='\0';
		strcat(string, litera);
		}		
	}
	
	return string;
}

int main()
{
	float *v=NULL; int*v1=NULL;
	v = vector_raport(4, 44, 10, 12, 10);
	for(int i=0; i<4; i++)
		printf("%.2f ", v[i]);
	printf("\n");
	
	v1 = vector_patrat(4, 2, 6, 7, 5);
	for(int i=0; i<4; i++)
		printf("%d ", v1[i]);
	printf("\n");
	
	v1 = vector_primi(5, 2, 3, 5, 6, 7);
	for(int i=0; i < sizeof(v1)/sizeof(v1[0])+2; i++)
		printf("%d ", v1[i]);
	printf("\n");
	
	printf("%s\n", concatenare_vocale(6, 'a', 'n', 'a', 'b', 'c', 'e'));
}
