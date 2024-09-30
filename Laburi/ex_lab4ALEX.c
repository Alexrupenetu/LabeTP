#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<string.h>
#include<math.h>

/*

picioare : 0-> 1000 => 10 biti 
greutate: nr real <= 1000 => 10 biti
periculos: da/nu adica 1/0 => 1 bit 
varsta: 0 -> 2000 => 11 biti
TOTAL 32 BITI => uint32_t  -  4 bytes 
abreviere => 9 biti (1 bit pt \0)
*/

typedef struct{
	uint32_t picioare: 10;
	uint32_t greutate: 10;
	uint32_t pericol: 1;
	uint32_t varsta: 11;
	char abreviere[9];
}ferma;

typedef struct{
	uint8_t grad_pericol:2;
	uint8_t reteta: 1;
	uint8_t varsta: 5;
}doctorie;

typedef struct{
	uint16_t um: 3;
	uint16_t multi: 4;
	uint16_t val: 9;

}masuratoare;

/*
pico : pow(10, -12)
nano: pow(10, -9)
mili: pow(10, -3)
centi: pow(10, -2)
deci: pow(10, -1)
deca: pow(10, 1)
hecto: pow(10, 2)
kilo: pow(10, 3)
mega: pow(10, 6)
giga: pow(10, 9)
*/

void aplicatia_4_4()
{
	//Afisare dimensiune
	printf("%ld\n", sizeof(ferma));
	
	//Citire date 
	ferma animal;
	
	uint32_t aux; char string[10];
	printf("Numar picioare:"); scanf("%d", &aux);
	animal.picioare = aux;
	printf("Greutate: "); scanf("%d", &aux);
	animal.greutate = aux;
	printf("Pericol:"); scanf("%d", &aux);
	animal.pericol = aux;
	printf("Varsta maxima:"); scanf("%d", &aux);
	animal.varsta = aux;
	printf("Abreviere: "); scanf("%s", string);
	strcpy(animal.abreviere, string);
	
	//Afisare
	printf("\n Date citite\n");
	printf("Numar picioare: %d\n", animal.picioare);
	printf("Greutate: %d\n", animal.greutate);
	printf("Pericol: %d\n", animal.pericol);
	printf("Varsta maxima: %d\n", animal.varsta);
	printf("Abreviere: %s\n", animal.abreviere);
	
}

void aplicatia_4_5()
{
	
	doctorie medicament;
	
	//Afisare dimensiune 
	printf("%ld\n", sizeof(doctorie));
	
	//Citire Date 
	uint8_t aux;
	printf("Grad de periculozitate: "); scanf("%hhd", &aux);
	medicament.grad_pericol = aux;
	printf("Reteta: "); scanf("%hhd", &aux);
	medicament.reteta = aux;
	printf("Varsta:  "); scanf("%hhd", &aux);
	medicament.varsta = aux;
	
	//Afisare date 
	printf("\n Date citite\n");
	printf("Grad de periculozitate: %hhd\n", medicament.grad_pericol);
	printf("Reteta: %hhd\n", medicament.reteta);
	printf("Varsta: %hhd\n", medicament.varsta);

}

void aplicatia_4_6()
{
	printf("%ld\n", sizeof(masuratoare));
	//efectiv nu pricep cerinta ☹
}

int main(void)
{
	unsigned int  aux1, aux2;
	aplicatia_4_6();
	printf("Valoare: "); scanf("%d", aux1);
	printf("Unitate de masura: "); scanf("%d", aux2);
	
	usigned int maxim = pow(2,9) - 1;
	
}

