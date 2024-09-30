#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<string.h>


typedef struct
{
uint16_t an_nastere:11;
uint16_t bonus: 1; 
char nume[46];
}angajat;

angajat *v=NULL;

int comp(const void *e1, const void *e2)
{
	angajat *elem1 = (angajat*)e1;
	angajat *elem2 = (angajat*)e2;
	
	if(strcmp(elem1->nume, elem2->nume)<=0)
		return 0;
	else
		return 1;
}


void pb1()
{
	int n, aux;
	char  string[46];
	int (*p)(const void*, const void*);
	p = &comp;
	printf("n = ");scanf("%d", &n);
	
	if((v = (angajat*)malloc(sizeof(angajat)*n))==NULL)
	{
		printf("Memorie insuficienta");
		exit(EXIT_FAILURE);
	}
	
	for(int i=0; i<n; i++)
		{
			printf("Nume : "); getchar();fgets(string, 46, stdin);
			strcpy(v[i].nume, string);
			printf("An nastere: "); scanf("%d", &aux);
			v[i].an_nastere = aux;
			printf("Bonus: "); scanf("%d", &aux);
			v[i].bonus = aux;
		}
		
	qsort(v, n, sizeof(angajat), p);
		
	for(int i=0; i<n; i++)
	{
		printf("Nume : %s", v[i].nume);
		printf("An nastere: %d \n", v[i].an_nastere);
		printf("Bonus: %d\n", v[i].bonus);
		printf("-------------\n");
	}
}

int main()
{
	pb1();
}
