#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

FILE *f = NULL;

typedef union {
    char isbn[14];
    uint16_t an_aparitie;
} uniune;

typedef struct {
    char titlu[20];
    char autor[20];
    uint32_t nr_exemplare:7;
    uint32_t pret:9;
    uint32_t pagini:10;
    uint32_t tip:1; // 0-carte 1-revista
    float greutate;
    uniune detaliu;
} carte;

carte *v = NULL;
int n;

void creare_fisier() {
    if ((f = fopen("data.bin", "wb")) == NULL) {
        printf("Eroare la deschiderea fișierului pentru scriere.");
        exit(EXIT_FAILURE);
    }
    int n = 2;
    fwrite(&n, sizeof(int), 1, f);

    uint32_t aux;
    char aux_s[20];
    uint16_t aux2;
    float aux3;

    // Carte 1
    strcpy(aux_s, "Tangled");
    fwrite(aux_s, sizeof(char), 20, f);
    strcpy(aux_s, "Ana Pop");
    fwrite(aux_s, sizeof(char), 20, f);
    aux = 100;
    fwrite(&aux, sizeof(int), 1, f);
    aux = 50;
    fwrite(&aux, sizeof(int), 1, f);
    aux = 678;
    fwrite(&aux, sizeof(int), 1, f);
    aux = 0;
    fwrite(&aux, sizeof(int), 1, f);
    strcpy(aux_s, "9783161484100");
    fwrite(aux_s, sizeof(char), 14, f);
    aux3 = 127.89;
    fwrite(&aux3, sizeof(float), 1, f);

    // Carte 2
    strcpy(aux_s, "Matca Lit");
    fwrite(aux_s, sizeof(char), 20, f);
    strcpy(aux_s, "Henry Bob");
    fwrite(aux_s, sizeof(char), 20, f);
    aux = 567;
    fwrite(&aux, sizeof(int), 1, f);
    aux = 78;
    fwrite(&aux, sizeof(int), 1, f);
    aux = 123;
    fwrite(&aux, sizeof(int), 1, f);
    aux = 1;
    fwrite(&aux, sizeof(int), 1, f);
    aux2 = 2004;
    fwrite(&aux2, sizeof(uint16_t), 1, f);
    aux3 = 67.43;
    fwrite(&aux3, sizeof(float), 1, f);

    if (fclose(f) != 0) {
        printf("Eroare la închiderea fișierului.");
    }
}

void citire_fisier() {
    if ((f = fopen("data.bin", "rb")) == NULL) {
        printf("Eroare la deschiderea fișierului pentru citire.");
        exit(EXIT_FAILURE);
    }

    fread(&n, sizeof(int), 1, f);

    v = malloc(n * sizeof(carte));
    if (v == NULL) {
        printf("Eroare la alocarea memoriei.");
        exit(EXIT_FAILURE);
    }

    uint32_t aux;
    char aux_s[20];
    uint16_t aux2;
    float aux3;

    for (int i = 0; i < n; i++) {
        fread(aux_s, sizeof(char), 20, f);
        strcpy(v[i].titlu, aux_s);
        fread(aux_s, sizeof(char), 20, f);
        strcpy(v[i].autor, aux_s);
        fread(&aux, sizeof(int), 1, f);
        v[i].nr_exemplare = aux;
        fread(&aux, sizeof(int), 1, f);
        v[i].pret = aux;
        fread(&aux, sizeof(int), 1, f);
        v[i].pagini = aux;
        fread(&aux, sizeof(int), 1, f);
        v[i].tip = aux;

        if (v[i].tip == 0) {
            fread(aux_s, sizeof(char), 14, f);
            strcpy(v[i].detaliu.isbn, aux_s);
        } else {
            fread(&aux2, sizeof(uint16_t), 1, f);
            v[i].detaliu.an_aparitie = aux2;
        }
        fread(&aux3, sizeof(float), 1, f);
        v[i].greutate = aux3;
    }

    if (fclose(f) != 0) {
        printf("Eroare la închiderea fișierului.");
    }
}

void afisare(carte v[], int n) {
    for (int i = 0; i < n; i++) {
        printf("---------------\n Carte %d: \n", i + 1);
        printf("Titlu: %s\n", v[i].titlu);
        printf("Autor: %s\n", v[i].autor);
        printf("Exemplare: %d\n", v[i].nr_exemplare);
        printf("Pret: %d\n", v[i].pret);
        printf("Pagini: %d\n", v[i].pagini);
        if (v[i].tip == 0) {
            printf("ISBN: %s\n", v[i].detaliu.isbn);
        } else {
            printf("An aparitie: %d\n", v[i].detaliu.an_aparitie);
        }
        printf("Greutate: %.2f\n", v[i].greutate);
    }
}

int main() {
    creare_fisier();
    citire_fisier();
    afisare(v, n);
    free(v); // Eliberăm memoria alocată
    return 0;
}

