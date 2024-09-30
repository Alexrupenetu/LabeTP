#include<stdio.h>
#define MAX_SIZE 100
int n, m, p, v[MAX_SIZE][MAX_SIZE], a[MAX_SIZE][MAX_SIZE], b[MAX_SIZE][MAX_SIZE];

void citire_matrice_p(int *n, int a[][MAX_SIZE])
{
	printf("dim=");
	scanf("%d", n);
	for(int i=0; i<*n; i++)
		{
			for(int j=0; j<*n; j++)
				{
					printf("a[%d][%d]=", i, j);
					scanf("%d", &a[i][j]);
				}
		}
}

void afisare_matrice_p(int n, int a[MAX_SIZE][MAX_SIZE])
{
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
			printf("%d ", a[i][j]);
		printf("\n");
	}
}

void aplicatia_83()
{
	printf("Introduceti dimensiunile ");
	scanf("%d %d", &m, &n);
	
	int k=0;

	for(int i=0; i<m; i++)
		for(int j=0; j<n; j++)
			{
			*(&v[0][0] + i*n + j) = k;
			 k++;
			}
			

	for(int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++)
			printf("%d ", *(&v[0][0]+i*n + j));
		printf("\n");
	}
}

void aplicatia84()
{
	citire_matrice_p(&n,a);
	afisare_matrice_p(n,a);

	for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				if(i<j)
				{
				int aux;
				aux = a[i][j];
				a[i][j] = a[j][i];
				a[j][i] = aux;
				}	
	afisare_matrice_p(n,a);
}

void aplicatia85()
{
	citire_matrice_p(&n, a);
	afisare_matrice_p(n, a);
	
	int suma_linie[21]={0}, suma_col[21]={0};
	
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
				{
					suma_linie[i] += a[i][j];
					suma_col[j] += a[i][j];
				}
			
	}
	
	printf("Sume linii: ");
	for(int i=0; i<n; i++)
		printf("%d ", suma_linie[i]);
	printf("\n");
	printf("Sume coloane: ");
	for(int i=0; i<n; i++)
		printf("%d ", suma_col[i]);
	printf("\n");
	
}

void aplicatia86()
{
	citire_matrice_p(&n, a);
	//o sa presupun ca problema asta de fapt imi cere sa zic pt fiecare nod dintr un graf cu cate noduri este adiacent :)
	//marcam adiacenta cu 1    de ex: nodul 1 adiacent cu nodul 2 => a[1][2] = [2][1] = 1
	
	for(int i=0; i<n; i++)
		{
			int prieteni = 0;
			for(int j=0; j<n; j++)
				if(i!=j && a[i][j]!=0)
					prieteni++;
			printf("%d - %d\n", i, prieteni);
		}
		
}

void aplicatia87()
{
		//citim distantele dintre fiecare 2 orase cu precizarea ca v[i][i] va fi mereu zero deoarece dist dintre un oras si el insusi e nula mereu
		
		citire_matrice_p(&n,v);
		
		int DistMin = 100000, oras1=-1, oras2;
		
		//parcurgem vectorul si vedem care e distanta minima, respectiv orasele situate la distanta aceea 
		
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				if(v[i][j]!=0 && v[i][j]<DistMin)
				{
					DistMin = v[i][j];
					oras1 = i;
					oras2 = j;
				}
		if(oras1 == -1)
			printf("Nu exista drumuri directe intre orase");
		else
			printf("Orasele cele mai apropiate sunt %d si %d ", oras1, oras2);
		
		
}

void aplicatia88()
{
	printf("m="); scanf("%d", &m);
	printf("n="); scanf("%d", &n);
	printf("p="); scanf("%d", &p);
	
	for(int i=0; i<m; i++)
		for(int j=0; j<n; j++)
		{
			printf("a[%d][%d]=", i, j);
			scanf("%d", &a[i][j]);
		}
		
	for(int i=0; i<n; i++)
		for(int j=0; j<p; j++)
		{
			printf("b[%d][%d]=", i, j);
			scanf("%d", &b[i][j]);
		}
		
	for(int i=0; i<m; i++)
		for(int j=0; j<p; j++)
			{
				for(int k=0; k<n; k++)
					v[i][j] += a[i][k] * b[k][j];
			}
		
	//v e declarat global deci e automat initializat cu 0 peste tot, altfel trebuia s o facem inainte de for 
	
	for(int i=0; i<m; i++)
		{
			for(int j=0; j<p; j++)
				printf("%d ", v[i][j]);
			printf("\n");
		}

			
}

void subiect81()
{
	citire_matrice_p(&n, a);
	citire_matrice_p(&m, b);
	
	for(int i=0; i<=n-m; i++)
		for(int j=0; j<=n-m; j++)
			{
				int ok=1;
					for(int k=0; k<m; k++)
						for(int l=0; l<m; l++)
							if(a[i+k][j+l]!=b[k][l])
								ok=0;
				if(ok == 1)
					printf("(%d, %d) ", i, j);
			}
	
}

int main()
{
	/*aplicatia83();
	aplicatia84();
	aplicatia85();
	aplicatia86();
	aplicatia87();
	aplicatia88();*/
	subiect81();
	
	
	
}
