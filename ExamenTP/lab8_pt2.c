#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct produs {
    char nume[20];
    int pret;
    struct produs *prev, *next;
} Produs;

typedef struct categorie {
    char nume[20];
    Produs *lista_prod;
    struct categorie *prev, *next;
} Categorie;

Categorie *newCategorie(const char *nume) {
    Categorie *new = malloc(sizeof(Categorie));
    if (new == NULL) {
        printf("error");
        exit(-1);
    }
    strcpy(new->nume, nume);
    new->prev = NULL;
    new->next = NULL;
    new->lista_prod = NULL;
    return new;
}

Categorie *AdaugaCategorie(Categorie *lista_categorii, const char *nume) {
    Categorie *new = newCategorie(nume);

    if (lista_categorii == NULL) {
        lista_categorii = new;
    } else {
        Categorie *aux = lista_categorii;
        while (aux->next != NULL) {
            aux = aux->next;
        }
        aux->next = new;
        new->prev = aux;
    }
    return lista_categorii;
}

Categorie *cauta_categorie(Categorie *lista_categorii, const char *nume) {
    Categorie *aux = lista_categorii;

    while (aux) {
        if (strcmp(aux->nume, nume) == 0)
            return aux;
        aux = aux->next;
    }
    return NULL;
}

void AfisareCategorii(Categorie *lista_categorii) {
    Categorie *aux = lista_categorii;

    while (aux) {
        printf("%s ", aux->nume);
        aux = aux->next;
    }
    printf("\n");
}

Produs *newProdus(const char *nume, int pret) {
    Produs *p = malloc(sizeof(Produs));
    if (p == NULL) {
        printf("error");
        exit(-1);
    }

    strcpy(p->nume, nume);
    p->pret = pret;
    p->prev = NULL;
    p->next = NULL;
    return p;
}

Categorie *AdaugaProdus(const char *nume, int pret, const char *NumeCategorie, Categorie *listaCategorii) {
    Produs *p = newProdus(nume, pret);
    Categorie *categorie = cauta_categorie(listaCategorii, NumeCategorie);
    
    if (categorie == NULL) {
        printf("Categoria %s nu a fost găsită.\n", NumeCategorie);
        free(p);
        return listaCategorii;
    }

    if (categorie->lista_prod == NULL) {
        categorie->lista_prod = p;
    } else {
        Produs *aux = categorie->lista_prod;
        while (aux->next != NULL) {
            aux = aux->next;
        }
        aux->next = p;
        p->prev = aux;
    }
    return listaCategorii;
}

void afisareProduse(const char *nume_categorie, Categorie *listaCategorii) {
    Produs *p = NULL;
    Categorie *auxC = cauta_categorie(listaCategorii, nume_categorie);
    
    if (auxC == NULL) {
        printf("Categoria %s nu a fost găsită.\n", nume_categorie);
        return;
    }

    p = auxC->lista_prod;

    while (p) {
        printf("%s - %d \n", p->nume, p->pret);
        p = p->next;
    }
}

int main(void) {
    int op;
    char NumeCat[20];
    Categorie *ListaCategorii = NULL;
    
    while(1)
    {
    printf("optiune = ");
    scanf("%d", &op);
    switch (op) {
        case 1:  // adauga categorie
        {
            printf("Nume categorie noua = ");
            scanf("%19s", NumeCat);
            ListaCategorii = AdaugaCategorie(ListaCategorii, NumeCat);
            AfisareCategorii(ListaCategorii);
            break;
        }
        case 2:  // adauga produs
        {
            char NumeProd[20];
            int pret;
            printf("Nume produs = ");
            scanf("%19s", NumeProd);
            printf("Pret produs = ");
            scanf("%d", &pret);
            printf("Nume categorie = ");
            scanf("%19s", NumeCat);
            ListaCategorii = AdaugaProdus(NumeProd, pret, NumeCat, ListaCategorii);
            afisareProduse(NumeCat, ListaCategorii);
            break;
        }
    }
    if(op == 3) //gata circu 
    	break;
    }
    return 0;
}

