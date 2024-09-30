#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct list{
	char text[1001];
	int contor;
	struct list *prev;
	struct list *next;
}list_d;

list_d *creare_nod(const char *text)
{
	list_d *p = (list_d*)malloc(sizeof(list_d));
	
	if(p==NULL)
	{
		printf("caca");
		exit(EXIT_FAILURE);
	}
	strcpy(p->text, text);
	p->next = NULL; p->prev = NULL;
	p->contor = 1;
	return p;
}

list_d *adaugare_inceput(list_d *lista, const char *text)
{
	list_d *p = creare_nod(text);
	if(lista == NULL)
		return p;
	else
	{
		p->next = lista;
		lista->prev = p;
		p->prev = NULL;
		return p;
	}	
}

list_d *adaugare_final(list_d *lista, list_d *nod)
{
	if(lista == NULL)
		{
			return nod;
			
		}
	else
	{
		list_d *aux = lista;
		while(aux->next!=NULL)
		{
			aux = aux->next;
		}
		
		aux->next = nod;
		nod->prev = aux;
		return lista;
	}
}

void display(list_d *lista, int optiune)
{
	list_d *aux=lista;
	
	while(aux)
	{
		if(optiune == 0)
		printf("%s\n", aux->text);
		else
		{
		printf("%s : %d\n", aux->text, aux->contor);
		}
		aux = aux->next;
	}
	printf("\n");
}


int in_prop(list_d *lista, const char *text)
{
	list_d *aux = lista;
	
	while(aux)
	{
		if(strcmp(aux->text, text)==0)
			return 1;
		aux = aux->next;
	}
	return 0;
}

list_d *modif_contor(list_d *lista, const char *text)
{
	list_d *aux = lista;
	
	if(strcmp(aux->text, text)==0)
		aux->contor = aux->contor+1;
	else
	{
	while(strcmp(aux->text, text)!=0)
		aux = aux->next;
	
	aux->contor = aux->contor+1;
	}
	return lista;	
}

list_d *adaugare_cuvant(list_d *lista, const char *text)
{
	list_d *new = creare_nod(text);
	if(in_prop(lista, text)==1)
	{
		lista = modif_contor(lista, text);
	}
	else
	{
		lista = adaugare_final(lista, new);
	}
	return lista;
}

list_d *inserare_cuvant(list_d *lista, const char *text, const char *succesor)
{
	list_d *new = creare_nod(text);
	if(in_prop(lista, succesor)==1)
	{
	if(strcmp(lista->text, succesor)==0)
	{
		lista = adaugare_inceput(lista, text);
	}
	else
	{
	list_d *aux = lista;
	while(strcmp(aux->next->text, succesor)!=0)
		aux = aux->next;
		
	new->next = aux->next;
	aux->next->prev = new;
	new->prev = aux;
	aux->next = new;
	}
	}
	else
	{
		lista = adaugare_final(lista, new);
	}
	return lista;
}

void pb1_2()
{
	list_d *lista=NULL; char text[10];
	lista = adaugare_final(lista, creare_nod("caca"));
	lista = adaugare_final(lista, creare_nod("maca"));
	printf("cuvant = "); scanf("%s", text);
	lista=adaugare_cuvant(lista, text);
	display(lista, 0);
	display(lista, 1);
	lista = inserare_cuvant(lista, "alex", "caca");
	display(lista, 0);
}

list_d *insert_sorted(list_d *lista, const char *text)
{
	list_d *new = creare_nod(text);
	
	if(lista == NULL || strcmp(lista->text, text)>0)
	{
		lista = adaugare_inceput(lista, text);
		
	}
	else
	{
		list_d *aux = lista;
		while(aux->next!=NULL && strcmp(aux->next->text, text)<=0)
			aux = aux->next;
		
		new->next = aux->next;
		new->prev = aux;
		if(aux->next!=NULL)
		aux->next->prev = new;
		aux->next = new;
	}
	return lista;
}

list_d *sorted(list_d *lista)
{
	list_d *aux = lista;
	list_d *sort = NULL;
	
	while(aux)
	{
		sort = insert_sorted(sort, aux->text);
		aux = aux->next;
	}
	return sort;
}

/**/

int main(int argc, char **argv)
{
	FILE *f = NULL;
	
	if((f = fopen(argv[1], "rb"))==NULL)
	{
		printf("eroare");
		exit(EXIT_FAILURE);
	}
	char linie[1000];
	
	/*strcpy(linie, "ana are mere");
	fwrite(linie, sizeof(char), 1000, f);
	strcpy(linie, "calin e urat");
	fwrite(linie, sizeof(char), 1000, f);
	strcpy(linie, "bunica cumpara pere");
	fwrite(linie, sizeof(char), 1000, f);
	strcpy(linie, "doresc un cadou");
	fwrite(linie, sizeof(char), 1000, f);*/
	
	
	list_d *lista = NULL; 
	while(fread(linie, sizeof(char), 1000, f))
	{
		linie[strlen(linie)] = '\0';
		printf("%s\n", linie);
		lista = insert_sorted(lista, linie);
	}	

	printf("Lista sortata este:\n");
	display(lista, 0); 
	
	if(fclose(f)!=0)
		{
			printf("error");
			exit(-1);
		}

}




