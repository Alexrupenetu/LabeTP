#include<stdio.h>
#include<stdlib.h>

typedef struct lista{
	int info;
	struct lista *next;
}lista_t;

lista_t *lista = NULL, *new = NULL;

lista_t *make_new(int info, lista_t *nod)
{
	lista_t *p = (lista_t *)malloc(sizeof(lista_t));
	
	p->info = info;
	p->next = nod;
	
	return p;
}

lista_t *adauga_final(lista_t *head, int info)
{
	lista_t *aux = head;
	lista_t *p = make_new(info, NULL);
	
	if(aux==NULL)
	{
		return p;
	}
	else
	{
		while(aux->next!=NULL)
			aux = aux->next;
		
		aux->next = p;
		return head;
	}
}

void display(lista_t *lista)
{
	while(lista)
	{
		printf("%d ", lista->info);
		lista = lista->next;
	}
	printf("\n");
}

lista_t *sum_elem_cons(lista_t *lista)
{
	if(lista->next==NULL)
		{
			lista_t *p=make_new(lista->info, NULL);
			return p;
		}
	lista_t *prev = lista;
	lista_t *new = NULL;
	lista_t *aux = lista->next;
	
	while(aux)
	{
		int suma = prev->info + aux->info;
		new = adauga_final(new, suma);
		prev = aux;
		aux = aux->next;
	}
	return new;
}

int contor(lista_t *lista)
{
	int k = 0;
	if(lista == NULL)
		return 0;
	else
	{
		while(lista!=NULL)
		{
			k++;
			lista = lista->next;
		}
	}
	return k;
}

void apelare_multipla()
{
	while(contor(new)>1)
	{
		new = sum_elem_cons(new);
		display(new);
	}
}

int main(int argc, char **argv)
{
	FILE *f = NULL;
	
	if((f = fopen(argv[1], "r"))==NULL)
	{
		printf("eroare");
		exit(-1);
	}
	
	int n, val;
	fscanf(f, "%d", &n);
	
	for(int i=1; i<=n; i++)
	{
		fscanf(f, "%d", &val);
		lista = adauga_final(lista, val);
	}
	
	display(lista);
	new = lista;
	apelare_multipla();
	
}
