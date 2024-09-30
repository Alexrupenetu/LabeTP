#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct lista
{
	int info;
	struct lista *prev, *next;
}list_t;


list_t *creare_nod(int info, list_t *nod)
{
	list_t *p = (list_t*)malloc(sizeof(list_t));
	
	if(p==NULL)
	{
		printf("error");
		exit(-1);
	}
	
	p->info = info;
	p->next = nod;
	
	return p;
}

list_t *stergere_inceput(list_t *lista)
{
	list_t *aux = lista;
	lista = lista->next;
	free(aux);
	return lista;
}

list_t *stergere_sfarsit(list_t *lista)
{
	list_t *aux = lista;
	while(aux->next->next!=NULL)
		aux = aux->next;
	
	list_t *p = aux->next;
	aux->next = NULL;
	free(p);
	return lista;
}

list_t *adaugare_sfarsit(list_t *lista, int value)
{
	list_t *aux = lista;
	
	while(aux->next!=NULL)
		aux = aux->next;
		
	list_t *new = creare_nod(value, NULL);
	aux->next = new;
	return lista;
}

void display(list_t *lista)
{
	list_t *aux = lista;
	while(aux)
	{
		printf("%d ", aux->info);
		aux = aux->next;
	}
	printf("\n");
}

void free_lista(list_t *lista)
{
	list_t *aux = lista;
	list_t *prev = lista;
	
	while(aux)
	{
		prev = aux;
		aux = aux->next;
		free(prev);
	}
}

void permutare_k(list_t *lista, int k)
{
	while(k)
	{
		int value = lista->info;
		lista = stergere_inceput(lista);
		lista = adaugare_sfarsit(lista, value);
		k--;	
	}
	display(lista);
}

list_t *insert_after(list_t *lista, int elem, int value)
{
	list_t *new = creare_nod(value, NULL);
	list_t *aux = lista;
	
	while(aux!=NULL && aux->info!=elem)
		aux = aux->next;
	
	if(aux==NULL) return lista;
	
	new->next = aux->next;
	aux->next = new;
	return lista;
}

list_t *inserare(list_t *head)
{
	list_t *aux = head;
	int val;
	
	while(aux!=NULL)
	{
		val = aux->info;
		if(val%2==0)
		{	
			head = insert_after(head, val, val/2);
			aux = aux->next;
		}
		
		if(aux!=NULL)
		aux = aux->next;
	}
	return head;
}

list_t *stergere_elem

int main(void)
{
	list_t *lista1=NULL;
	lista1 = creare_nod(1, creare_nod(2, creare_nod(3, creare_nod(4, NULL))));
	//permutare_k(lista, 3);
	list_t *lista2 = creare_nod(2, creare_nod(3, NULL));
	lista1 = inserare(lista1);
	display(lista1);
}
