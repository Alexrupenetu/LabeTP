#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

void pb2(int argc, char **argv)
{

	FILE *src, *dest;
	
	if((src = fopen(argv[1], "rb"))==NULL)
	{
		printf("eraore");
		exit(EXIT_FAILURE);
	}
	
	if((dest = fopen(argv[2], "wb"))==NULL)
	{
		printf("eraore");
		exit(EXIT_FAILURE);
	}
	
	uint64_t buffer[512];
	uint64_t r;
	
	while((r = fread(buffer, sizeof(uint64_t), 512, src))>0)
	{
		fwrite(buffer, sizeof(uint64_t), r, dest);
	}
	
	if(fclose(src)!=0)
	{
		printf("eraore");
		exit(EXIT_FAILURE);
	}
	
	if(fclose(dest)!=0)
	{
		printf("eraore");
		exit(EXIT_FAILURE);
	}

}

void pb3(int argc, char **argv)
{
int m, n;
	int **a= NULL;
	
	FILE *f=NULL;
	
	printf("m="); scanf("%d", &m);
	printf("n="); scanf("%d", &n);
	
	//Alocam nr de linii
	if((a = (int**)malloc(m*sizeof(int*)))==NULL)
	{
		printf("eroare");
		exit(EXIT_FAILURE);
	}
	
	for(int i=0; i<m; i++)
		if((a[i] = (int*)malloc(n*sizeof(int)))==NULL)
		{
			printf("eroare");
			exit(EXIT_FAILURE);
		}
	
	for(int i=0; i<m; i++)
		for(int j=0; j<n; j++)
			{
				printf("a[%d][%d]=", i, j);
				scanf("%d", &a[i][j]);
			}
			
	if((f = fopen("src.bin", "wb"))==NULL)
	{
		printf("eroare");
		exit(EXIT_FAILURE);
	}
	
	fwrite(&m, sizeof(int), 1, f);
	fwrite(&n, sizeof(int), 1, f);

	for(int i=0; i<m; i++)
		for(int j=0; j<n; j++)
			fprintf(f, "%d", a[i][j]);
			
	for(int i=0; i<m; i++)
		free(a[i]);
		
	if(fclose(f)!=0)
	{
		printf("caca");
		exit(EXIT_FAILURE);
	}	
	
}

int main(int argc, char **argv)
{
	
}









