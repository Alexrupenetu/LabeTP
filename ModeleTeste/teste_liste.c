#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct list_t{

	int info;
	struct list_t* next;
	
}list_t;

list_t *creare_nod(int info, list_t *nod)
{
	list_t *p = (list_t*)malloc(sizeof(list_t));
	
	if(p==NULL)
	{
		printf("uh oh");
		exit(-1);
	}
	
	p->info = info;
	p->next = nod;
	
	return p;
}

list_t *adaugare_sfarsit(list_t *lista, int info)
{
	if(lista == NULL)
		return creare_nod(info, NULL);
	
	list_t *aux = lista;
	while(aux->next!=NULL)
		aux=aux->next;
	aux->next = creare_nod(info, NULL);
	return lista;
}

void afisare_lista(list_t *lista)
{
	list_t *aux = lista;
	
	while(aux)
	{
		printf("%d ", aux->info);
		aux = aux->next;
	}
}

list_t *adaugare_dupa(list_t *head)
{
	list_t *aux = head;
	
	while(aux)
	{
		if(aux->info<0)
			{
				list_t *elem = creare_nod(aux->info*(-1), aux->next);
				aux->next = elem;
				aux = aux->next;
			}
		aux=aux->next;
	}
	return head;
}

int main(void)
{
	list_t *lista = NULL;
	lista = adaugare_sfarsit(lista, 10);
	lista = adaugare_sfarsit(lista, -11);
	lista = adaugare_sfarsit(lista, 5);
	lista = adaugare_sfarsit(lista, 9);
	lista = adaugare_sfarsit(lista, -6);
	lista = adaugare_sfarsit(lista, 17);
	
	lista = adaugare_dupa(lista);

	afisare_lista(lista);
}
