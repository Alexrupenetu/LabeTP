#include<stdio.h>
#include<stdlib.h>
#include "recap_liste_simple.c"

//ex 1
int verif_liste_identice(list_t *lista1, list_t *lista2)
{
	list_t *aux1 = lista1;
	list_t *aux2 = lista2;
	
	
	while(aux1!=NULL && aux2!=NULL)
	{
		if(aux1->info != aux2->info)
			return 0;
		aux1 = aux1->next;
		aux2 = aux2->next;
	}
	
	
	return (aux1 == NULL && aux2 == NULL);
}


//ex2
list_t *reverse(list_t *lista)
{
	list_t *prev = NULL; 
	list_t *current = lista;
	list_t * next = NULL;
	
	while(current!=NULL)
	{
		next = current->next; 
		current->next = prev;
		prev = current;
		current = next;
	}
	return prev;
}

list_t *reverse2(list_t *lista)
{
	list_t *rev = NULL;
	list_t *current;
	
	while(lista)
	{
		current = lista;
		lista = lista->next;
		current->next = rev;
		rev = current;
	}
	return rev;
}

//ex 3 : Reuniunea a 2 liste 

int verif_exista(list_t *lista, int val)
{
	list_t *aux = lista;
	
	int ok=0;
	
	while(aux)
	{
		if(aux->info == val)
			ok=1;
		aux = aux->next;
	}
	
	return ok;
}

list_t *reuniune(list_t *lista1, list_t *lista2)
{
	list_t *list = lista1;
	list_t *aux = lista2;
	
	while(aux)
	{
		if(verif_exista(lista1, aux->info)!=1)
			list = adaugare_final(list, aux->info);
		aux = aux->next;
	}
	return list;
}

//ex 5: o functie care primeste 2 liste si returneaza 1 daca sunt egale indiferent de ordinea si nr elementelor
// de ex 1 3 5 3 si 1 3 5 sunt egale 
int egale(list_t *lista1, list_t *lista2)
{
	list_t *aux1 = lista1;
	
	while(aux1!=NULL && verif_exista(lista2, aux1->info)==1)
		aux1=aux1->next;
	//daca dupa ce se termina while-ul aux1 ajunge la NULL inseamna ca toate elementele din lista1 se regasesc in lista2
	
	return (aux1==NULL);
}

//ex 6: functie care insereaza un nod intr o lista sortata + functie care sorteaza o lista

list_t *insert_in_sorted_list(int value, list_t *lista)
{
	if(lista == NULL)
	{
		return creare_nod(value, NULL);
	}
	if(lista->info >= value)
	{
		lista = adaugare_inceput(lista, value);
		return lista;
	}
	list_t *aux = lista;
	while(aux->next!=NULL && aux->next->info<value)
		aux = aux->next;
	list_t *new = creare_nod(value, aux->next);
	aux->next = new;
	return lista;
}

list_t *sort_list(list_t *list)
{
	list_t *nxt = NULL;
	list_t *sorted = NULL;
	
	while(list)
	{
		nxt = list->next;
		sorted = insert_in_sorted_list(list->info, sorted);
		list=nxt;
	}
	return sorted;
}

//ex 7



int main(void)
{
	list_t *lista1=NULL; list_t *lista2 = NULL; list_t *lista3=NULL;
	
	lista1 = creare_nod(10, creare_nod(11, creare_nod(13, creare_nod(14, NULL))));
	lista2 = creare_nod(4, creare_nod(2, creare_nod(7, creare_nod(13, creare_nod(11, NULL)))));
	afisare_lista(lista1);
	afisare_lista(lista2);
	
	/*printf("Listele sunt identice(0/1): %d\n", verif_liste_identice(lista1, lista2));
	afisare_lista(lista1);
	lista1 = reverse2(lista1);
	afisare_lista(lista1);	
	printf("%d\n", verif_exista(lista1, 20));
	list_t *r=NULL;
	r = reuniune(lista1, lista2);
	afisare_lista(r); 
	printf("%d\n", egale(lista1, lista2)); */
	
	lista3 = insert_in_sorted_list(9, lista1);
	afisare_lista(lista3);
	
	lista3 = sort_list(lista2);
	afisare_lista(lista3);
}





