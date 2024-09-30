//TEMA LAB 2 ALEX TUNEA 3.2.D
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#define SIZE_MAX 100

typedef struct
{
	char nume[20];
	float nota;
}data;

int comp1(const void *e1, const void *e2)
{
	data *elem1 = (data*)e1;
	data *elem2 = (data*)e2;
	
	if(elem1->nota < elem2->nota)
		return 1;
	if(elem1->nota == elem2->nota)
		if(strcmp(elem1->nume, elem2->nume)>0)
			return 1;
	return 0; //ordinea e corecta
}

int comp2(const void *e1, const void *e2)
{
	float *elem1 = (float*)e1;
	float *elem2 = (float*)e2;
	
	if(*elem1>*elem2) //dereferentiem fiindca lucram cu POINTERI !!!
		return 1;
	else 
		return 0;
}

int comp3(const void *e1, const void *e2)
{
	float *elem1 = (float*)e1;
	float *elem2 = (float*)e2;
	
	if(*elem1 < *elem2) return -1;
	if(*elem1 > *elem2) return 1;
	return 0;
}

void aplicatia21()
{
	int n;
	data v[SIZE_MAX];
	
	printf("n=");scanf("%d", &n);
	
	//citire vector
	for(int i=0; i<n; i++)
		{
			printf("Nume = ");
			scanf("%s", v[i].nume);
			printf("Nota =");
			scanf("%f", &v[i].nota);
		}
		
	qsort(v, n, sizeof(data), comp1);
	
	//afisare vector
	for(int i=0; i<n; i++)
		printf("%s - %.2f\n", v[i].nume, v[i].nota);
}

int negativ(int x)
{
	if(x<0)
		return 1;
	else
		return 0;
}



void functie(int *v, int *dim, int (*cond)(int))
{
	for(int i=0; i<*dim; i++)
		if(cond(v[i]))
		{
			for(int k=i; k<*dim-1; k++)
				v[k] = v[k+1];
			*dim = *dim - 1;
		}
}

void aplicatia22()
{
	
	int v[5]={1, -3, 4, -7, 9}, n=5;
	int (*p)(int);
	p = negativ;
	functie(v, &n, p);
	
	for(int i=0; i<n; i++)
		printf("%d ", v[i]);
	printf("\n");
	
}

void tabelare(double a, double b , int n, double(*fct)(double))
{
	double pas = (b-a)/n;
	
	for(double i=a; i<=b; i=i+pas)
	{
		printf("f(%.2lg) = %.2lg", i, fct(i));
		printf("\n");
	}
}

void aplicatia23()
{
	//citire vector
	int n;
	float key;
	printf("n=");scanf("%d", &n);
	printf("key=");scanf("%f", &key);
	
	float v[10];
	
	for(int i=0; i<n; i++)
	{
		printf("v[%d]=", i); scanf("%f", &v[i]);
	}
	
	qsort(v, n, sizeof(float), comp2);
	
	float *item;
	
	if((item = bsearch(&key, v, n, sizeof(float), comp3)) != NULL)
		printf("Exista elementul %.2f", key);
	else
		printf("Nu exista");
	
}
	
void aplicatia24()
{
	double a, b;
	int n;
	printf("a="); scanf("%lg", &a);
	printf("b="); scanf("%lg", &b);
	printf("n="); scanf("%d", &n);
	tabelare(a, b, n, cos);
	printf("\n");
	tabelare(a, b, n, sqrt);
	printf("\n");
	tabelare(a, b, n, fabs);
	printf("\n");
}

int f1(int x)
{
	return x*x*x + 4;
}

int f2(int x)
{
	return x*x+5;
}

int f3(int x)
{
	return x+10;
}

int f4(int x)
{
	return 2*x*x-1;
}

void subiectul21()
{
	int (*v[4])(int) = {f1, f2, f3, f4}, a, b, p;
	printf("a="); scanf("%d", &a);
	printf("b="); scanf("%d", &b);
	printf("p="); scanf("%d", &p);
	printf("%-10s%-10s%-10s%-10s%-10s\n", "x", "f1(x)", "f2(x)", "f3(x)", "f4(x)");
	
	for(int i=a; i<=b; i=i+p)
		printf("%-10d%-10d%-10d%-10d%-10d\n", i, v[0](i), v[1](i), v[2](i), v[3](i));
	
}

int f_a(char *string)
{
	return strlen(string);
}

int f_b(char *string)
{
	int contor=0;
	for(int i=0; i<strlen(string); i++)
		if(strchr("aeiou", string[i]))
			contor++;
	return contor;
			
}

int f_c(char *string)
{
	int contor=0;
	
	for(int i=0; i<strlen(string); i++)
		if(isupper(string[i]))
			contor++;
	return contor;
}

int f_d(char *string)
{
	return (int)(string[0]-string[strlen(string)-1]);
}

void subiectul22()
{
	char string[255];
	int (*v[4])(char *)={f_a, f_b, f_c, f_d};
	
	fgets(string, 255, stdin);
	string[strlen(string)-1]=0;
	char *p=NULL;
	p = strtok(string, " ");
	
	FILE *out = NULL;
	
	if((out = fopen("cuvinte.txt", "w"))==NULL)
	{
		printf("Memorie insuficienta");
		exit(-1);
	}
	
	while(p!=NULL)
	{
		printf("%s - ", p);
		fprintf(out, "%s - ", p);
		for(int i=0; i<4; i++)
			{
			printf(" %d ", v[i](p));
			fprintf(out," %d ", v[i](p));
			}
		printf("\n");
		fprintf(out, "\n");
		p=strtok(NULL, " ");
			
	}
	
	fclose(out);
}



int main(void)
{
	//aplicatia21();
	//aplicatia22();
	//aplicatia23();
	//aplicatia24();
	//subiectul21();
	subiectul22();
}
