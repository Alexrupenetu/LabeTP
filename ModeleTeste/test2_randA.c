#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdarg.h>

typedef struct list_t
{
	int info;
	struct list_t *next;
}list_t;

list_t *creare_nod(int info, list_t *nod)
{
	list_t *p = (list_t*)malloc(sizeof(list_t));
	
	if(p==NULL)
		{
			printf("Memorie insuficienta");
			exit(-1);
		}
		
	p->info = info;
	p->next = nod;
	
	return p;
}

list_t *adaugare_inceput(list_t *lista, int info)
{
	return creare_nod(info, lista);	
}

list_t *adaugare_final(list_t *lista, int info)
{
	list_t *aux = lista;
	
	if(lista == NULL)
		return creare_nod(info, NULL);
	
	while(aux->next!=NULL)
		aux = aux->next;
		
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

list_t * adaugare_inainte_dupa(list_t *lista, int v, int x)
{
	list_t *aux = lista;
	int ok = 0;
	
	if(aux->info == v && ok!=1)
	{
		ok = 1;
		list_t *elem1 = creare_nod(x, aux);
		list_t *elem2 = creare_nod(x, aux->next);
		aux->next = elem2;
		return elem1;
	}
	else
	{
	while(aux->next->info!=v)
		aux = aux->next;
	
	if(ok!=1)
	{
	list_t *elem1 = creare_nod(x, aux->next);
	list_t *elem2 = creare_nod(x, aux->next->next);
	aux->next->next = elem2;
	aux->next = elem1;
	ok=1;
	}
	
	return lista;
	}
}

void pb2()
{
	list_t *lista = NULL;
	
	FILE *f = NULL;
	
	if((f=fopen("numere.in", "r"))==NULL)
	{
		printf("uh oh");
		exit(-1);
	}
	
	int val;
	while(fscanf(f, "%d", &val) != EOF)
		lista = adaugare_final(lista, val);
		
	int v, x;
	printf("v = "); scanf("%d", &v);
	printf("x = "); scanf("%d", &x);
	
	lista = adaugare_inainte_dupa(lista, v, x);
	
	afisare_lista(lista);
}

char *concatenare(char n, ...)
{
	va_list args;
	va_start(args, n);
	
	char *string = ""; 
	char c, chr[2];
	
	if((string = malloc(sizeof(char) * 10))==NULL)
	{
		printf("caca");
		exit(-1);
	}
	
	
	if(n!='.')
		{
			chr[0]=n;
			chr[1]='\0';
			strcat(string,chr);
		}
	
	c = va_arg(args, int);
	
	while(c!='.')
		{
			chr[0]=c;
			chr[1]='\0';
			strcat(string,chr);
			c = va_arg(args, int);
		} 
	return string;
}

int main(void)
{
	//pb2();
	char *string = NULL;
	string = concatenare('a', 'n', 'a', ' ', 'a', 'r', 'e', '.');
	printf("%s\n", string);
}

