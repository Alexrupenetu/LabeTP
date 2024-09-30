#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//liste simplu inlantuite
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

void pare_impare(list_t *lista)
{   
	list_t *aux = lista;
	list_t *lp=NULL; list_t *li=NULL;
	
	while(aux)
	{
		if(aux->n%2==0)
			lp = insert_end(aux->n, lp);
		else
			li = insert_end(aux->n, li);
		aux = aux->next;
	}
	display(li);
	display(lp);
}

list_t * stergere_inceput(list_t *head)
{
	
		list_t *aux = head;
		head = head->next;
		free(aux);
		return head;

}


list_t *stergere_nod(list_t *head, int value)
{
	list_t *aux = head;
	
	if(head->n == value)
	{
		return stergere_inceput(head);
	}
	
	else
	{
	
	while(aux->next->n!=value && aux!=NULL)
		aux = aux->next;
		
	list_t *p = aux->next;
	aux->next = aux->next->next;
	free(p);
	return head;

	}
} 

list_t *stergere_pare(list_t *lista)
{
	list_t* aux = lista;
	
	if(aux->n%2==0)
		aux = stergere_inceput(aux);
		
	while(aux->next!=NULL)
	{
		if(aux->next->n % 2 == 0)
		{
			list_t *p = aux->next;
			aux->next = aux->next->next;
			free(p);
		}
		else
		aux = aux->next;
	}
	return lista;
}

void pb9_1()
{
	list_t *lista=NULL;
	
	FILE *f = NULL;
	
	if((f = fopen("numere.txt", "r"))==NULL)
	{
		printf("uh oh");
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

void pb9_9()
{
	list_t *lista = NULL;
	
	lista = insert_end(1, lista);
	lista = insert_end(2, lista);
	lista = insert_end(2, lista);
	lista = insert_end(4, lista);
	lista = insert_end(5, lista);
	lista = insert_end(6, lista);
	display(lista);
	lista=stergere_pare(lista);
	display(lista);
}

void pb9_10()
{
	list_t *lista = NULL;
	
	lista = insert_end(1, lista);
	lista = insert_end(2, lista);
	lista = insert_end(2, lista);
	lista = insert_end(4, lista);
	lista = insert_end(5, lista);
	lista = insert_end(7, lista);
	
	display(lista);
	pare_impare(lista);
}

//liste dublu inlantuite
typedef struct list{
	int info;
	struct list *prev;
	struct list *next;
}list_d;

list_d *make_new2(int info)
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

list_d *stergere_prim_ultim(list_d *lista)
{
	list_d *aux = lista;
	if(aux->prev == NULL)
		{
			list_d *p = aux;
			aux->next->prev = NULL;
			aux = aux->next;
			free(p);
			lista = aux;
		}
	while(aux->next->next!=NULL)
		aux = aux->next;
	
	list_d *p = aux->next;
	free(p);
	aux->next = NULL;
		
	return lista;
}

list_d *ultim_infata_prim(list_d* head)
{
	list_d* aux = head;
	
	while(aux->next->next!=NULL)
		aux = aux->next;
	
	int valoare = aux->next->info;
	list_d *p = aux->next;
	free(p);
	aux->next = NULL;
	
	list_d *aux2 = head;
	
	list_d* elem = make_new2(valoare);
	head = adauga_inceput(head, elem);
	
	return head;
}

int palindrom(list_d *lista)
{
	list_d *aux = lista;
	int nr=0, ogl=0, p=1;
	while(aux)
	{
		int cif = aux->info;
		nr = nr*10+cif;
		ogl = cif*p + ogl;
		p=p*10;
		aux = aux->next;
	}
	
	if(ogl == nr)
		return 1;
	else
		return 0;
}

list_d *primul_dupa_ultimul(list_d* lista)
{
	list_d *aux = lista; int val;
	if(aux->prev == NULL)
		{
			val = aux->info;
			list_d *p = aux;
			aux->next->prev = NULL;
			aux = aux->next;
			free(p);
			lista = aux;
		}
	list_d *aux2 = lista;
	
	while(aux2->next!=NULL)
		aux2=aux2->next;
	
	list_d *elem = make_new2(val);
	aux2->next = elem;
	elem->prev = aux2;
	elem->next = NULL;
	return lista;
}


void pb9_5()
{
	list_d *lista = NULL;
	list_d *elem;
	
	elem = make_new2(8);
	lista = adauga_sfarsit(lista, elem);
	elem = make_new2(11);
	lista = adauga_sfarsit(lista, elem);
	elem = make_new2(6);
	lista = adauga_sfarsit(lista, elem);
	elem = make_new2(14);
	lista = adauga_sfarsit(lista, elem);
	
	lista = stergere_prim_ultim(lista);
	afisare_lista(lista);
}

void pb9_6()
{
	list_d *lista = NULL;
	list_d *elem;
	
	elem = make_new2(8);
	lista = adauga_sfarsit(lista, elem);
	elem = make_new2(11);
	lista = adauga_sfarsit(lista, elem);
	elem = make_new2(6);
	lista = adauga_sfarsit(lista, elem);
	elem = make_new2(14);
	lista = adauga_sfarsit(lista, elem);
	
	afisare_lista(lista);
	lista = ultim_infata_prim(lista);
	afisare_lista(lista);
}

void pb9_7()
{
	list_d *lista = NULL;
	list_d *elem;
	
	elem = make_new2(8);
	lista = adauga_sfarsit(lista, elem);
	elem = make_new2(9);
	lista = adauga_sfarsit(lista, elem);
	elem = make_new2(6);
	lista = adauga_sfarsit(lista, elem);
	elem = make_new2(1);
	lista = adauga_sfarsit(lista, elem);
	
	afisare_lista(lista);
	int rez = palindrom(lista);
	printf("%d\n", rez);
}

void pb9_8()
{
	list_d *lista = NULL;
	list_d *elem;
	
	elem = make_new2(8);
	lista = adauga_sfarsit(lista, elem);
	elem = make_new2(11);
	lista = adauga_sfarsit(lista, elem);
	elem = make_new2(6);
	lista = adauga_sfarsit(lista, elem);
	elem = make_new2(14);
	lista = adauga_sfarsit(lista, elem);
	
	afisare_lista(lista);
	lista = primul_dupa_ultimul(lista);
	afisare_lista(lista);
}

int main(void)
{
	//pb9_1();
	//pb9_2();
	//pb9_3();
	//pb9_5();
	//pb9_6();
	//pb9_7();
	//pb9_8();
	pb9_9(); //-> aici da seg fault :( si nuj de ce :((
	//pb9_10();
}
















