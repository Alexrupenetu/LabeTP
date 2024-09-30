#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct lista{
	char info;
	struct lista *next;
}list_t;

list_t *make_new(char info, list_t *nod)
{
	list_t *p = (list_t *)malloc(sizeof(list_t));
	
	if(p==NULL)
		{
			printf("error");
			exit(-1);
		}
	p->info = info;
	p->next = nod;
	return p;
}

list_t *adaugare_final(list_t *lista, char info)
{	
	list_t *p = make_new(info, NULL);
	
	if(lista == NULL)
		return p;
	else
	{
		list_t *aux = lista;
		
		while(aux->next!=NULL)
		{
			aux = aux->next;
		}
		aux->next = p;
		return lista;
	}
}

list_t *adaugare_inceput(list_t *lista, char info)
{
	list_t *p = make_new(info, NULL);
	
	if(lista == NULL)
		return p;
	else
	{
		p->next = lista;
		return p;
	}
}

list_t *insert_sorted(list_t *lista, char info)
{
	 if (lista == NULL || info < lista->info)
        return adaugare_inceput(lista, info);
    else {
        list_t *aux = lista;
        while(aux->next!=NULL && aux->next->info<info)
        	aux = aux->next;
        
        list_t *new = make_new(info, aux->next);
	aux->next = new;
	
        return lista;
    }
}

void display(list_t *lista)
{
	list_t *aux = lista;
	while(aux)
	{
		printf("%c ", aux->info);
		aux = aux->next;
	}
	printf("\n");
}

list_t *inversare(list_t *lista)
{
	list_t *prev = lista;
	list_t *aux = prev->next;
	
	while(aux!=NULL)
	{	
		if(strchr("aeiou", prev->info)!=NULL && strchr("aeiou", aux->info)==NULL)
			{
				char caca = prev->info;
				prev->info = aux->info;
				aux->info = caca;
			}
		prev = aux; 
		aux = aux->next;
	}
	return lista;
}

int main(void)
{
	FILE *f = NULL;
	list_t *lista = NULL;
	
	if((f = fopen("caca.in", "r"))==NULL)
	{
		printf("eroare fisier");
		exit(-1);
	}
	
	
	int n;
	char ch;
	
	fscanf(f, "%d", &n);
	
	for(int i=0; i<n; i++)
		{
			fscanf(f, " %c", &ch);

			lista = insert_sorted(lista, ch);
		}
	
	
	display(lista);
	lista = inversare(lista);
	display(lista);
	
	
}







