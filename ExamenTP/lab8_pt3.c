#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<string.h>

typedef struct lista
{
	unsigned int cod:14;
	unsigned int locuri: 4;
	unsigned int putere: 9;
	char marca[40];
	char culoare[40];
	unsigned int AnFabricatie: 11;
	struct lista *prev, *next;
}Automobil;

Automobil *Adaugare(Automobil *lista, unsigned int codM, unsigned int locuri, unsigned int putere, const char *marca, const char *culoare, unsigned int AnFab)
{
	Automobil *new = malloc(sizeof(Automobil));
	if(new == NULL)
	{
		printf("Errror");
		exit(-1);
	}
	strcpy(new->marca, marca);
	strcpy(new->culoare, culoare);
	new->cod = codM;
	new->locuri = locuri;
	new->putere = putere;
	new->AnFabricatie = AnFab;
	new->prev = NULL; new->next = NULL;
	
	if(lista == NULL)
	{
		lista = new;
		return lista;
	}
	else
	{
		new->next = lista;
		lista->prev = new;
		new->prev = NULL;
		return new;
	}
	
}

void AfisareAutomobile(Automobil *lista) {
    Automobil *aux = lista;
    int contor = 1;
    while (aux) {
        printf("Masina %d\n", contor);
        printf("Cod = %d\n", aux->cod);
        printf("Locuri = %d\n", aux->locuri);
        printf("Putere = %d\n", aux->putere);
        printf("Marca = %s\n", aux->marca);
        printf("Culoare = %s\n", aux->culoare);
        printf("An Fabricatie = %d\n", aux->AnFabricatie);
        printf("\n");
        aux = aux->next;
        contor++;
    }
}

Automobil *Stergere_Automobil(Automobil *lista, unsigned int cod) {
    if (lista == NULL) {
        return NULL; // Lista este goală
    }

    Automobil *aux = lista;

    // Dacă nodul de șters este primul din listă
    if (lista->cod == cod) {
        Automobil *p = lista;
        lista = lista->next;
        if (lista != NULL) {
            lista->prev = NULL;
        }
        free(p);
        return lista;
    }

    // Căutare nodul cu codul specificat
    while (aux->next != NULL && aux->next->cod != cod) {
        aux = aux->next;
    }

    // Dacă nodul nu a fost găsit
    if (aux->next == NULL) {
        printf("Automobil cu codul %d nu a fost găsit.\n", cod);
        return lista;
    }

    // Nodul a fost găsit și este intern
    Automobil *p = aux->next;
    aux->next = p->next;
    if (p->next != NULL) {
        p->next->prev = aux;
    }
    free(p);

    return lista;
}


Automobil *stergere(Automobil *lista, unsigned int cod)
{
	if(lista == NULL)
		printf("Lista e goala");
	
	Automobil *aux = lista;
	
	if(aux->cod == cod)
		{
			lista = lista->next;
			if(lista!=NULL)
				lista->prev = NULL;
			return lista;
		}
	
	while(aux->next!=NULL && aux->next->cod!=cod)
		aux = aux->next;
		
	
	if(aux->next == NULL)
	{
		printf("Automobilul nu a fost gasit");
		exit(-1);
	}
	
	Automobil *p = aux->next;
	aux->next = aux->next->next;
	if(aux->next!=NULL)
		aux->next->prev = aux;
	free(p);
	return lista;	
}


int main(void) {
    Automobil *lista = NULL;
    lista = Adaugare(lista, 2345, 5, 150, "Toyota", "Rosu", 2021);
    lista = Adaugare(lista, 7890, 4, 200, "BMW", "Albastru", 2020);
    lista = Adaugare(lista, 4321, 2, 300, "Ferrari", "Galben", 2019);
    lista = Adaugare(lista, 4720, 2, 300, "Ferrari", "Galben", 2019);
    
    AfisareAutomobile(lista);

    lista = stergere(lista, 2345);
    AfisareAutomobile(lista);
    return 0;
}
