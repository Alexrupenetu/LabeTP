#include<stdio.h>
#include<stdlib.h>

typedef struct lista{

	int info;
	struct lista* next;
}list_t2;


typedef struct lista2{
	list_t2 *first;
	list_t2 *last;
}lnr_list; //last node reference list 

list_t2 *make_new(int value, list_t2 *nod)
{
	list_t2 *p = (list_t2*)malloc(sizeof(list_t2));
	if(p == NULL)
		{
			printf("Memorie insuficienta");
			exit(-1);
		}
	p->info = value;
	p->next = nod;
	return p;
}

void init(lnr_list *list)
{
	list->first = list->last = NULL;
}

void adaugare_final2(int value, lnr_list *lista)
{
	
}
