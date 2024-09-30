#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>

typedef struct lista
{
	int info;
	struct lista *next;
}list_t;

list_t *creare_nod(int n, list_t *nod)
{
	list_t *p = (list_t *)malloc(sizeof(list_t));
	
	p->info = n;
	p->next = nod;
	
	return p;
}

void display(list_t *head)
{
	if(head == NULL)
		printf("Empty list\n");
	list_t *aux = head;
	
	while(aux!=NULL)
	{
		printf("%d ", aux->info);
		aux = aux->next;
	}
	printf("\n");
}

list_t *adaugare_inceput(list_t *head, int info)
{
	list_t *new = creare_nod(info, head);
	return new;
}

list_t *adaugare_final(list_t *head, int info)
{

	if(head == NULL)
		head = creare_nod(info, head);

	else
	{
	list_t *aux = head;
	
	while(aux->next!=NULL)
		aux = aux->next;
	
	aux->next = creare_nod(info, NULL);
	}
	return head;
}


list_t *stergere_inceput(list_t *head)
{
	list_t *aux = head;
	head = head->next;
	free(aux);
	return head;
}

list_t *stergere_final(list_t *head)
{
	list_t *aux1 = head;
	list_t *aux2 = head;
	
	while(aux1->next!=NULL)
		aux1=aux1->next;
		
	while(aux2->next->next!=NULL)
		aux2=aux2->next;
		
	aux2->next = NULL;
	free(aux1);
	return head;
}

list_t *stergere_nod(list_t *head, int value)
{
	list_t *aux = head;
	
	//Mai intai verificam daca nu e la inceput
	if(head->info == value)
		return stergere_inceput(head);
	else
	{
		while(aux->next->info!=value && aux!=NULL)
			aux = aux->next;
		
		list_t *p = aux->next;
		aux->next = aux->next->next;
		free(p);
	}
}

void free_lista(list_t *list)
{
	list_t *aux = list;
	list_t *prev = list;
	
	while(aux)
	{
		aux = aux->next;
		free(prev);
		prev = aux;
	}
}


int identice(list_t *lista1, list_t *lista2)
{
	list_t *aux1 = lista1; list_t *aux2 = lista2;
	
	while(aux1!=NULL && aux2!=NULL)
	{
		if(aux1->info != aux2->info)
			return 0;
		aux1=aux1->next;
		aux2=aux2->next;
	}
	return (aux1==NULL && aux2==NULL);
}

list_t *inversare(list_t *lista)
{
	list_t *current = lista;
	list_t *rev = NULL;
	
	while(lista)
	{
		current = lista;
		lista = lista->next;
		current->next = rev;
		rev = current;
	}
	
	return rev;
}

int inlist(list_t *lista, int value)
{
	list_t *aux = lista;
	while(aux)
	{
		if(aux->info == value)
			return 1;
		aux = aux->next;
	}
	return 0;
}

void reuniune(list_t *lista1, list_t *lista2)
{
	list_t *reuniune=NULL;
	int value = lista1->info;
	reuniune = adaugare_final(reuniune, value);
	list_t *aux1=lista1->next; list_t *aux2=lista2;
	
	while(aux1)
	{
		value = aux1->info;
		if(inlist(reuniune, value)==0)
			reuniune = adaugare_final(reuniune, value);
		aux1= aux1->next; 
	}
	
	while(aux2)
	{
		value = aux2->info;
		if(inlist(reuniune, value)==0)
			reuniune = adaugare_final(reuniune, value);
		aux2=aux2->next;
	}
	display(reuniune);	
}

int egale(list_t *lista1, list_t *lista2)
{
	list_t *aux1 = lista1; int value;
	
	while(aux1!=NULL)
	{
		value = aux1->info;
		if(inlist(lista2, value)==0)
			return 0;
		aux1= aux1->next;
	}
	return 1;
}

list_t *insert_sorted(list_t *lista, int value)
{
	if(lista == NULL)
		{
			lista = creare_nod(value, NULL);
		}
	else
		if(value<lista->info)
			{
				lista = adaugare_inceput(lista, value);
			}
	else
	{
		list_t *aux = lista;
		
		while(aux->next!=NULL && value > aux->next->info)
			aux = aux->next;
			
		list_t *new = creare_nod(value, aux->next);
		aux->next = new;
		
	}
	
	return lista;
}

list_t *sortare(list-t *lista)
{
	list_t *aux = lista;
	list_t *sorted = NULL;
	while(aux)
	{
		sorted = insert_sorted(sorted, aux->info);
		aux = aux->next;
	}
	return sorted;
}

int main(void)
{
	list_t *lista1, *lista2;
	lista1 = creare_nod(1, creare_nod(7, creare_nod(3, creare_nod(1,creare_nod(3,NULL)))));
	lista2 = creare_nod(3, creare_nod(7, creare_nod(8, creare_nod(10, NULL))));

	lista1 = insert_sorted(lista2, 11);
	display(lista1);
}
