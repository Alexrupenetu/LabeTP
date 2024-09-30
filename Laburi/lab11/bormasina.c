#include<stdio.h>
#include<math.h>

#define MAX_SIZE 100

typedef struct 
{
	float x, y; 	
	int vizitat;
}punct;

punct p[MAX_SIZE];

void citire_puncte(punct p[MAX_SIZE], int *n)
{
	scanf("%d", n);
	
	for(int i=0; i<*n; i++)
		scanf("%g,%g", &p[i].x, &p[i].y);
	
	printf("Punctele citite sunt: \n");
	for(int i=0; i<*n; i++)
		printf("%g %g \n", p[i].x, p[i].y);
}

void init(punct p[MAX_SIZE], int n)
{
	for(int i=0; i<n; i++)
		p[i].vizitat = 0;
}

float distanta(punct a, punct b)
{
	float d;
	d = sqrt((a.x-b.x) * (a.x - b.x) + (a.y - b.y)*(a.y - b.y));
	return d;
}

int cel_mai_ap(punct p[MAX_SIZE], int n, punct pct_curr)
{
	int indice; float dist_min = 10, d;
	
	for(int i=1; i<n; i++)
		if(p[i].vizitat==0)
			{
				d = distanta(pct_curr, p[i]);
				
				if(d<dist_min)
				{
					dist_min = d;
					indice = i;
				}
				printf("%d: d = %g min = %g indice=%d\n", i, d, dist_min, indice);
			}
	return indice;
}

void afiseaza_ordine(punct p[MAX_SIZE], int n)
{
	punct poz_curr = p[0];
	p[0].vizitat = 1;
	
	for(int i=1; i<n; i++)
		{
			int indice = cel_mai_ap(p, n, poz_curr);
			printf("Gaura %d: (%g, %g)\n", i+1, p[indice].x, p[indice].y);
			poz_curr = p[indice];
			p[indice].vizitat = 1;
		}
}

int main()
{
	//am facut citirea prin redirectare si am presupus ca punctul de pornire e mereu primul punct citit 
	int n;
	citire_puncte(p, &n);
	init(p, n);
	afiseaza_ordine(p, n);
	
}
