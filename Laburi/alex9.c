#include<stdio.h>
#include<stdlib.h>

typedef struct list_t 
{
	int n;
	struct list_t *next;
}list_t;



list_t * make_new(int elem, list_t *urm)
{
	list_t *aux = (list_t*)malloc(sizeof(list_t));
	
	if(aux == NULL)
		{
			printf("nashpa");
			exit(EXIT_FAILURE);
		}
		
	aux->n = elem;
	aux->next = urm;
	return aux;
}

list_t *insert_front(int elem, list_t * lista)
{
	return make_new(elem, lista);
}

list_t *insert_end(int elem, list_t *lista)
{
	list_t*aux = lista;
	
	if(aux == NULL)
		return make_new(elem, NULL);
	else
	{
		while(aux->next!=NULL)
			aux = aux->next;
			
		aux->next = make_new(elem, NULL);
		return lista;
	}
}

list_t *sterge_primul(list_t *head)
{
	list_t *aux = head;
	head = head->next;
	free(aux);
	return head;
}

void display(list_t *lista)
{
	list_t *aux = lista;
	
	while(aux!=NULL)
	{
		printf("%d ", aux->n);
		aux = aux->next;
	}
	printf("\n");
}

list_t *uneste_liste(list_t *lista1, list_t *lista2)
{
	list_t *aux1 = lista1, *aux2 = lista2;
	
	while(aux1->next!=NULL)
		aux1 = aux1->next;
		
	while(aux2!=NULL)
	{
		aux1->next = aux2;
		aux2 = aux2->next; 
		aux1 = aux1->next;
	}	
	
	return lista1;
}

list_t * permutare_k(list_t *lista, int k)
{
		while(k)
		{
			int val = lista->n;
			lista = sterge_primul(lista);
			lista = insert_end(val, lista);
			k--;
		}
		return lista;
}

list_t * insert_after(int elem, list_t *list, int x)
{
	list_t *aux = list;
	
	while(aux!=NULL && aux->n!=x)
		aux= aux->next;
	
	if(aux == NULL) 	return list;
	aux->next = insert_front(elem, aux->next);
	return list;
}


list_t *inserare(list_t *head)
{
	list_t *aux = head;
	int val;
	
	while(aux!=NULL)
	{
		val = aux->n;
		if(val%2==0)
			head = insert_after(val/2, head, val);
		aux = aux->next;
		aux=aux->next;
	}
	return head;
}


void pb9_1()
{
	list_t *lista=NULL;
	
	FILE *f = NULL;
	
	if((f = fopen("numere.txt", "r"))==NULL)
	{
		printf("uh oh");ee
		exit(EXIT_FAILURE);
	}
	
	int k, val;
	
	fscanf(f, "%d", &k);
	
	while(fscanf(f,"%d", &val)!=EOF)
		{
			lista = insert_end(val,lista);
		}
	fclose(f);
	display(lista);
	lista = permutare_k(lista, k);
	display(lista);
}


void pb9_2()
{
	list_t *lista1=NULL;
	list_t *lista2=NULL;
	list_t *lista = NULL;
	
	FILE *f = NULL;
	
	if((f = fopen("numere.txt", "r"))==NULL)
	{
		printf("uh oh");
		exit(EXIT_FAILURE);
	}
	
	int val;
	
	while(fscanf(f,"%d", &val)!=EOF)
	{
		if(val%2==0)
			lista1 = insert_front(val, lista1);
		else 
			lista2 = insert_front(val, lista2);
	}
	fclose(f);
	printf("Lista nr pare: ");
	display(lista1);
	printf("LIsta nr impare: ");
	display(lista2);
	
	lista = uneste_liste(lista1, lista2);
	display(lista);
}


void pb9_3()
{
	list_t *lista = NULL;
	
	lista = insert_end(1, lista);
	lista = insert_end(2, lista);
	lista = insert_end(2, lista);
	lista = insert_end(4, lista);
	lista = insert_end(5, lista);
	lista = insert_end(6, lista);
	display(lista);
	lista=inserare(lista);
	display(lista);
}

void pb9_4()
{
	
}

int main(void)
{
	//pb9_1();
	//pb9_2();
	pb9_3();
	
}
