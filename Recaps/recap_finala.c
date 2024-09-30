#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>


//liste dublu inlantuite
typedef struct list{

	int info;
	struct list* next;
	struct list* prev;
}list_d;

list_d *creare_nod(int info)
{
	list_d *elem = (list_d*)malloc(sizeof(list_d));
	
	if(elem==NULL)
		{
			printf("caca");
			exit(-1);
		}
		
	elem->info=info;
	elem->prev = elem->next = NULL;
	return elem;
}

list_d *adaugare_inceput(list_d *lista, list_d *elem)
{
	if(lista == NULL)
		return elem;

	list_d* aux = lista;
	lista->prev = elem;
	elem->next = lista;
	elem->prev = NULL;
	return elem;
}

list_d *adaugare_sfarsit(list_d *lista, list_d *elem)
{
	if(lista == NULL)
		return elem;
	list_d *aux = lista;
	
	while(aux->next!=NULL)
		aux = aux->next;
		
	aux->next = elem;
	elem->prev = aux;
	elem->next = NULL;
	return lista;
}

list_d *stergere_ultim(list_d *lista)
{
	list_d *aux = lista;
	while(aux->next->next!=NULL)
		aux = aux->next;
	
	if(aux->next->info%2==0)
	{
	list_d *p = aux->next;
	free(p);
	aux->next = NULL;
	}
	return lista;
}

list_d *stergere_pare(list_d *lista)
{		
	list_d *aux = lista;
	while(aux->next!=NULL)
	{
		if(aux->next->info%2==0)
		{
			list_d *p = aux->next;
			aux->next = aux->next->next;
			aux->next->prev = aux;
			free(p);
		}
		else
		aux = aux->next;
	}
	
	lista = stergere_ultim(lista);
	
	return lista;
}

list_d *adaugare_inainte_dupa(list_d *lista)
{
	list_d *aux = lista;
	if(aux->prev==NULL && aux->info%2==0)
	{
		list_d *elem1 = creare_nod(aux->info/2);
		list_d *elem2 = creare_nod(aux->info*2);
		
		elem1->prev = NULL;
		elem1->next = aux;
		
		elem2->prev = aux;
		elem2->next = aux->next;
		
		aux->next->prev = elem2;
		aux->prev = elem1;
		aux->next = elem2;
		
		lista = elem1;
		aux = aux->next->next;
	}
	
	while(aux->next!=NULL)
	{
		if(aux->info%2 == 0)
		{
		
			list_d *elem1 = creare_nod(aux->info/2);
		        list_d *elem2 = creare_nod(aux->info*2);
		        
		        elem1->prev = aux->prev;
		        elem1->next = aux;
		        
		        elem2->next = aux->next;
		        elem2->prev = aux;
		        
		        aux->prev->next = elem1;
		        aux->next->prev = elem2;
		        
		        aux->prev = elem1;
		        aux->next = elem2;
		        
		        aux = aux->next->next;
		}
		else
		aux = aux->next;
	}
	
	if(aux->next == NULL && aux->info%2==0)
	{
		list_d *elem1 = creare_nod(aux->info/2);
		list_d *elem2 = creare_nod(aux->info*2);
		
		
		elem1->prev = aux->prev;
		elem1->next = aux;
		
		elem2->prev = aux;
		elem2->next = NULL;
		
		aux->prev->next = elem1;
		aux->next = elem2;
		
	}
	
	return lista;
}

void afisare(list_d* lista)
{
	list_d* aux = lista;
	
	while(aux)
	{
		printf("%d ", aux->info);
		aux = aux->next;
	}
	printf("\n");
}

void free_lista(list_d *lista)
{
	list_d *aux;
	
	while(lista)
	{
		aux = lista->next;
		free(lista);
		lista = aux;
	}
}

//liste simplu inlantuite

typedef struct 

int main()
{
	list_d *lista = NULL, *elem = NULL;
	
	elem = creare_nod(10);
	lista = adaugare_sfarsit(lista, elem);
	elem = creare_nod(13);
	lista = adaugare_sfarsit(lista, elem);
	elem = creare_nod(8);
	lista = adaugare_sfarsit(lista, elem);
	elem = creare_nod(6);
	lista = adaugare_sfarsit(lista, elem);
	elem = creare_nod(4);
	lista = adaugare_sfarsit(lista, elem);
	
	afisare(lista);
	lista = adaugare_inainte_dupa(lista);
	afisare(lista);
	free_lista(lista);
		
}



