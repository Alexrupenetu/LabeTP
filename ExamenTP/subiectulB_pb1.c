#include<stdio.h>
#include<stdlib.h>

typedef struct lista{
	int info;
	struct lista* next;
	struct lista* prev;
}list_d;

list_d *make_new(int info)
{
	list_d *p = (list_d*)malloc(sizeof(list_d));
	
	if(p==NULL)
		{
			printf("error");
			exit(-1);
		}
	p->info = info;
	p->next = NULL; p->prev = NULL;
	return p;
}

list_d *adaugare_final(list_d *lista, int info)
{
	list_d *p = make_new(info);
	
	if(lista == NULL)
		return p;
	else
	{
		list_d *aux = lista;
		while(aux->next!=NULL)
			aux = aux->next;
			
		p->prev = aux;
		aux->next = p;
		return lista;
	}
}

int counter(list_d *lista1)
{
	list_d *lista = lista1;
	int count = 0;
	while(lista!=NULL)
	{
		count++;
		lista = lista->next;
	}
	return count;
}



list_d *inserare_mijloc(list_d *lista1, list_d* lista2)
{
	
	list_d *mijloc=lista1; list_d *dupa_mijloc = NULL;
	list_d *prim = lista2; list_d *ultim= lista2;
	
	
	int mij = counter(lista1)/2, k=0;
	//Aflam mijlocul de la prima lista;
	while(k!=mij)
	{
		mijloc = mijloc->next;
		k++;
	}
	mijloc = mijloc->prev;
	printf("Mijloc: %d\n", mijloc->info);
	dupa_mijloc=mijloc->next;
	
	while(ultim->next!=NULL)
		ultim = ultim->next;
		
	mijloc->next = prim;
	prim->prev = mijloc;
	ultim->next = dupa_mijloc;
	dupa_mijloc->prev = ultim;
	
	return lista1;
}


void display(list_d *lista)
{
	list_d *aux = lista;
	
	while(aux)
	{
		printf("%d ", aux->info);
		aux = aux->next;
	}
	printf("\n");
}

int main()
{
	list_d *lista = NULL, *lista2=NULL, *new = NULL;
	lista = adaugare_final(lista, 1);
	lista = adaugare_final(lista, 3);
	lista = adaugare_final(lista, 6);
	lista = adaugare_final(lista, 7);
	
	lista2 = adaugare_final(lista2, 4);
	lista2 = adaugare_final(lista2, 5);
	
	display(lista);
	display(lista2);
	new = inserare_mijloc(lista, lista2);
	
	display(new);
}




