#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<string.h>
#include<stdbool.h>

#define CHUNK 20

//Rand 1 
/*
 filme: 
 nume: 35 caractere => 36 bytes (1 byte pt \0)
 an aparitie: max 2023 => 11 biti
 premii: da/nu => 1 bit 
*/

typedef struct
{
	char nume[36];
	uint16_t an_ap: 11;
	uint16_t premii: 1;
}filme;

int comp(const void *e1, const void *e2)
{
	filme *elem1 = (filme*)e1;
	filme *elem2 = (filme*)e2;
	
	if(elem1->premii == 0 && elem2->premii ==1)
	 return 0;
	else
         return 1;
}

void pb1()
{

	filme *v;
	char string[36];
	uint16_t aux;
	
	if((v = malloc(CHUNK*sizeof(filme)))==NULL)
	{
		printf("Memorie insuficienta");
		exit(-1);
	}
	
	int len=0, current_size=CHUNK;
	
	while(scanf("%s", string)!=EOF)
	{
		
		strcpy(v[len].nume, string);
		scanf("%hd", &aux);
		v[len].an_ap = aux;
		scanf("%hd", &aux);
		v[len].premii = aux;
		
		len++;
		
		if(len == current_size)
		{
			current_size = current_size + CHUNK;
			if((v = realloc(v, current_size * sizeof(filme)))==NULL)
			{
				printf("Memorie insuficienta");
				exit(-1);
			}
		}
	}
	
	int (*p) (const void*, const void*);
	p = &comp;
	qsort(v, len, sizeof(filme), p);
	
	for(int i=0; i<len; i++)
		printf("%s - %d - %d\n", v[i].nume, v[i].an_ap, v[i].premii);
	free(v);
	
}


void pb2()
{
	int n, m, p, v[10], contor=0;
	int a[2][5]={{1, 2, 3, 5, 6}, {4, 5, 6, 7, 8}};
	
	printf("n = "); scanf("%d", &n);
	printf("m = "); scanf("%d", &m);
	printf("p = "); scanf("%d", &p);
	
	/*if((a = (int **)malloc(m * sizeof(int*)))==NULL)
	{
		printf("Memorie insuficienta");
		exit(EXIT_FAILURE);
	}
	
	for(int i=0; i<m; i++)
		if((a[i] = (int *)malloc(n*sizeof(int)))==NULL)
		{
			for(i--; i>=0; i--) free(a[i]);
			free(a);
			printf("Memorie insuficienta");
			exit(EXIT_FAILURE);
		} */
		
	
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
			printf("%d ", a[i][j]);
		printf("\n");
	}
		
	for(int i=0; i<p; i++)
		scanf("%d", &v[i]);
		
	for(int k=0; k<n; k++)
		for(int i=0; i<=m-p; i++)
			{	
				int poz = i;
				bool gasit = true;
				for(int j=0; j<p; j++)
					{
						if(v[j]!=a[k][poz])
							gasit = false;
						poz++;
					}
				if(gasit == true)
					contor++;
			}
			
			
	for(int k=0; k<n; k++)
		for(int i=m-1; i>=0; i--)
		{
			int poz = i;
			printf("poz =%d\n", poz);
			bool gasit = true;
				for(int j=0; j<p; j++)
					{
						printf("a[%d][%d] = %d\n", k, poz, a[k][poz]);
						if(v[j]!=a[k][poz] && poz>=0)
							{
							
							gasit = false;
							}
						poz--;
					}
			if(gasit == true)
				contor++;
		}
	if(contor)
		printf("S a gasit");
	else
		printf("NU");
	

}



int main(void)
{
	pb2();
}
