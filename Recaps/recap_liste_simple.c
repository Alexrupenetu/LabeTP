#include<stdio.h>
#include<stdlib.h>

typedef struct lista{

	int info;
	struct lista* next;
}list_t;

list_t *creare_nod(int n, list_t* nod)
{
	list_t *p = (list_t *)malloc(sizeof(list_t));
	
	p->info = n;
	p->next = nod;
	
	return p;
}

list_t *adaugare_inceput(list_t *head, int info)
{
	list_t *p = creare_nod(info, head);
	return p;
}

list_t *adaugare_final(list_t *head, int info)
{
	if(head == NULL)
		head = creare_nod(info, head);
		
	else
	{
		list_t *aux = head;
		while(aux->next)
			aux = aux->next;
		aux->next = creare_nod(info, NULL);
	}
	return head;
}

list_t * stergere_inceput(list_t *head)
{
	
		list_t *aux = head;
		head = head->next;
		free(aux);
		return head;

}

list_t *stergere_sfarsit(list_t *head)
{
	list_t *aux1 = head;
	list_t *aux2 = head;
	while(aux1->next!=NULL)
		aux1 = aux1->next;
	while(aux2->next->next!=NULL)
		aux2 = aux2->next;
	aux2->next = NULL;
	free(aux1);
	return head;
	
}

list_t *stergere_nod(list_t *head, int value)
{
	list_t *aux = head;
	
	if(head->info == value)
	{
		return stergere_inceput(head);
	}
	
	else
	
	{
	
	while(aux->next->info!=value && aux!=NULL)
		aux = aux->next;
		
	list_t *p = aux->next;
	aux->next = aux->next->next;
	free(p);
	return head;

	}
}

void free_lista(list_t *head)
{
	list_t *aux = head;
	list_t *prev = head;
	
	while(aux)
	{
		aux = aux->next;
		free(prev);
		prev = aux;
	}
}

void afisare_lista(list_t *head)
{
	list_t *aux = head;
	printf("Elementele listei sunt: ");
	while(aux)
	{
		printf("%d ", aux->info);
		aux = aux->next;
	}
	printf("\n");
}

/*int main(void)
{
	list_t *lista1 = NULL;
	lista1 = creare_nod(11, creare_nod(12, creare_nod(13, creare_nod(14, NULL))));
	lista1 = adaugare_final(lista1, 9);
	afisare_lista(lista1);
	lista1 = stergere_nod(lista1, 12);
	afisare_lista(lista1);
	free_lista(lista1);
}
*/










