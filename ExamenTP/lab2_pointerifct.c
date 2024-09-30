#include<stdio.h>
#include<stdlib.h>

typedef struct
{
	char nume[20];
	float nota;	
}Student;
Student v[100];


int compar(const void *elem1, const void *elem2)
{
	Student *e1 = (Student*)elem1;
	Student *e2 = (Student*)elem2;
	
	return (e1->nota - e2->nota);
}


void aplicatia_21()
{
	int n=3;
	for(int i=0; i<n; i++)
		{
			printf("Nume = "); scanf("%s", v[i].nume);
			printf("Nota = "); scanf("%f", &v[i].nota);
		}
	
	qsort(v, 3, sizeof(Student), compar);
	
	for(int i=0; i<n; i++)
		printf("%.2f ", v[i].nota);
	printf("\n");
}

double functie(double a)
{
	return a+2.5;
}

void aplicatia_24()
{
	double(*ptr_fct)(double);
	ptr_fct = functie;
	for(int i=-10; i<=10; i++)
	{
		printf("f(%d)=%.2f\n", i, ptr_fct(i));
	}
}

int main()
{
	aplicatia_24();	
}
