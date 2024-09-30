#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>

typedef struct list{
	int info;
	struct list *prev;
	struct list *next;
}list_d;

list_d *make_new(const int info)
{
	list_d *p = (list_d *)malloc(sizeof(list_d));
	if(p==NULL)
	{
		printf("uh oh");
		exit(EXIT_FAILURE);
	}
	p->info = info;
	return p;
}

list_d * adauga_inceput(list_d *lista, list_d *new)
{
	if(lista == NULL)
	{
		new->prev = new->next = NULL;
	}
	else
	{
		lista->prev = new;
		new->next = lista;
		new->prev = NULL;
	}
	return new;
}

list_d *adauga_sfarsit(list_d *lista, list_d *new)
{
	if(lista == NULL)
	{
		new->prev = new->next = NULL;
		lista = new;
	}
	else
	{
		list_d *aux = lista;
		while(aux->next != NULL)
			aux = aux->next;
		aux->next = new;
		new->prev = aux;
		new->next = NULL;
	}
	return lista;
}

void afisare_lista(list_d *lista)
{
	list_d *aux = lista;
	
	while(aux)
	{
		printf("%d ", aux->info);
		aux = aux->next;
	}
	printf("\n");
}

list_d* inserare_inainte(list_d *lista)
{
	list_d *aux = lista;
	if(aux->prev == NULL)
	{
		list_d *elem1 = make_new(aux->info/2);
		elem1->next = aux;
		aux->prev = elem1;
		elem1->prev = NULL;	
		lista = elem1;
	}
	while(aux)
	{
		if(aux->info % 2 == 0)
			{
				list_d* elem1 = make_new(aux->info/2);
				
				if(aux->prev!=NULL)
				{
				elem1->next = aux;
				elem1->prev = aux->prev;
				aux->prev->next = elem1;
				aux->prev = elem1;
				}
			}
		aux = aux->next;
	}
	return lista;
	
} 

list_d * inserare_dupa(list_d *lista)
{
	list_d *aux = lista;
	
	
	if(aux->next == NULL)
	{
		list_d *elem = make_new(aux->info*2);
		elem->prev = aux;
		elem->next = NULL;
		aux->next = elem;
	}
	while(aux)
	{
		if(aux->info % 2 == 0 && aux->next!=NULL)
		{
			list_d * elem = make_new(aux->info*2);
			
			elem->next = aux->next;
			elem->prev = aux;
			aux->next->prev = elem;
			aux->next = elem;
			
			aux = aux->next;
		}
		aux = aux->next;
	}
	return lista;
}

list_d *inserare_ambele(list_d *lista)
{
	list_d *aux = lista;
	
	if(aux->prev == NULL && aux->info%2==0)
	{
		list_d *elem1 = make_new(aux->info/2);
		list_d *elem2 = make_new(aux->info*2);
		
		elem1->next = aux;
		elem1->prev = NULL;
		
		elem2->prev = aux;
		elem2->next = aux->next;
		aux->next->prev = elem2;
		
		aux->next = elem2;
		aux->prev = elem1;
			
		lista = elem1;
		aux = aux->next->next;
	}
	
	
	while(aux->next!= NULL)
	{
		if(aux->info%2==0)
			{
				list_d *elem1 = make_new(aux->info/2);
				list_d *elem2 = make_new(aux->info*2);
				
				elem1->next = aux;
				elem1->prev = aux->prev;
				aux->prev->next = elem1;
				
				elem2->next = aux->next;
				elem2->prev = aux;
				aux->next->prev = elem2;
				
				aux->next = elem2;
				aux->prev = elem1;
				
				aux = aux->next;
			}
		aux = aux->next;
	}
	
	if(aux->next == NULL && aux->info%2 == 0)
	{
		list_d *elem1 = make_new(aux->info/2);
		list_d *elem2 = make_new(aux->info*2);
		
		elem1->prev = aux->prev;
		elem1->next = aux;
		
		elem2->prev = aux;
		elem2->next = NULL;
		
		aux->prev->next = elem1;
		aux->prev = elem1;
		aux->next = elem2;
	}
	
	return lista;
}


void pb2()
{
	list_d *lista = NULL;
	list_d *elem;
	
	elem = make_new(8);
	lista = adauga_sfarsit(lista, elem);
	elem = make_new(11);
	lista = adauga_sfarsit(lista, elem);
	elem = make_new(6);
	lista = adauga_sfarsit(lista, elem);
	elem = make_new(14);
	lista = adauga_sfarsit(lista, elem);
	
	afisare_lista(lista);
	lista = inserare_ambele(lista);
	afisare_lista(lista);
}

void functie(int n,...)
{
	va_list args;
	va_start(args, n);
	
	float *v = NULL;
	int val;
	
	if((v = (float*)malloc(sizeof(float)*(n+1)))==NULL)
	{
		printf("uh oh");
		exit(EXIT_FAILURE);
	}
	
	for(int i=0; i<n; i++)
	{
		val = va_arg(args, int);
		v[i]=(float)val/n;
	}
	
	for(int i=0; i<4; i++)
		printf("%.2f ", v[i]);
	printf("\n");
	
	va_end(args);
}

int main(void)
{
	//pb2();
	functie(4, 44, 10, 25, 40);
	
}

