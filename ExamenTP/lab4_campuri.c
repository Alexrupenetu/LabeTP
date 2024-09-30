#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<string.h>

#define SIZE 100

typedef struct
{
	uint32_t cod:14;
	uint32_t locuri:3; //offset 1 
	uint32_t putere: 9;
	uint8_t an_fabricatie; //offset 1800
	char nume[10];
	char culoare[10];
	
}Masina;

Masina *v=NULL;
int len = 0;

void introducere_automobil()
{
	uint32_t aux;
	char aux_string[10];
	
	Masina elem;
	
	//printf("Cod = "); 
	scanf("%d", &aux); elem.cod = aux;
	//printf("Locuri = "); 
	scanf("%d", &aux); elem.locuri = aux-1;
	//printf("Putere = "); 
	scanf("%d", &aux); elem.putere = aux;
	//printf("An fabricatie = "); 
	scanf("%d", &aux); elem.an_fabricatie = aux-1800; 
	//printf("Nume = "); 
	scanf("%s", aux_string); strcpy(elem.nume, aux_string);
	//printf("Culoare = "); 
	scanf("%s", aux_string); strcpy(elem.culoare, aux_string);
	
	
	v = realloc(v, (len+1) * sizeof(Masina));
	if(v==NULL)
	{
		printf("caca");
		exit(EXIT_FAILURE);
	}
	v[len++] = elem;

}

void initializare()
{
	v = (Masina*)malloc(sizeof(Masina));
	if(v==NULL)
	{
		printf("caca");
		exit(EXIT_FAILURE);
	}
}

void afisare(Masina v[SIZE], int len)
{
	for(int i=0; i<len; i++)
	{
		printf("--------------\n");
		printf("Masina %d\n", i+1);
		printf("Cod = %d\n", v[i].cod);
		printf("Locuri = %d\n", v[i].locuri+1);
		printf("Putere = %d\n", v[i].putere);
		printf("An fabricatie = %d\n", v[i].an_fabricatie+1800);
		printf("Nume = %s\n", v[i].nume); 
		printf("Culoare = %s\n", v[i].culoare); 
	}
}

int compar(const void *e1, const void *e2)
{
	Masina * elem1 = (Masina*)e1;
	Masina * elem2 = (Masina*)e2;
	
	return(elem1->an_fabricatie - elem2->an_fabricatie);
}

void ordonare()
{
	qsort(v, len, sizeof(Masina), compar);
}

void stergere_automobil(uint32_t code, Masina v[SIZE], int *len)
{
	for(int i=0; i<*len; i++)
		if(v[i].cod == code)
		{
			for(int k=i; k<*len-1; k++)
			{
				v[k] = v[k+1];
			}
			*len= *len-1;
		}
}

int main()
{
	int n;
	initializare();
	 scanf("%d", &n);
	for(int i=0; i<n; i++)
		introducere_automobil();
	afisare(v, len);
	stergere_automobil(24, v, &len);
	printf("VECTOR CU STERGERE:\n");
	afisare(v, len);
	free(v);
}
