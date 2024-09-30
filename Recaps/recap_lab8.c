#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct cuv{
	char text[16];
	struct cuv* prev;
	struct cuv* next;
}Cuvant;

Cuvant* make_new(const char *text)
{
	Cuvant *c = (Cuvant*)malloc(sizeof(Cuvant));
	if(c==NULL)
	{
		printf("uh oh");
		exit(EXIT_FAILURE);
	}
	
	strcpy(c->text, text);
	return c;
}


Cuvant* adauga_inceput(Cuvant *prop, Cuvant *cuv)
{
	if(prop == NULL) 
	{
		cuv->prev = cuv->next = NULL;
	}
	else
	{
		prop->prev = cuv;
		cuv->next = prop;
		cuv->prev = NULL;
	}
	return cuv;
}

Cuvant* adauga_sfarsit(Cuvant *prop, Cuvant *cuv)
{
	if(prop == NULL)
	{
		cuv->prev = cuv->next = NULL;
		return cuv;
	}
	else
	{
		Cuvant* aux = prop;
		while(aux->next!=NULL)
			aux = aux->next;
		aux->next = cuv;
		cuv->prev = aux;
		cuv->next = NULL;
	}
	return prop;
}

Cuvant* stergere_cuvant(Cuvant* prop, const char* text)
{
	
}

void afisare_prop(Cuvant* prop)
{
	Cuvant* aux = prop;
	
	while(aux)
	{
		printf("%s ", aux->text);
		aux = aux->next;
	}
	printf("\n");
}

int main(void)
{
	Cuvant *prop=NULL;
	Cuvant *cuv;
	
	cuv = make_new("Ana");
	prop = adauga_sfarsit(prop, cuv);
	cuv = make_new("are");
	prop = adauga_sfarsit(prop, cuv);
	cuv = make_new("mere");
	prop = adauga_sfarsit(prop, cuv);
	cuv = make_new("faine");
	prop = adauga_sfarsit(prop, cuv);
	afisare_prop(prop);
	
}
