#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void alocare()
{
	int m, n;
	int **a=NULL;
	
	
	printf("m = "); scanf("%d", &m);
	printf("n = "); scanf("%d", &n);
	
	//ALocare vector de pointeri la linii
	
	if((a = (int**)malloc(m*sizeof(int*)))==NULL)
	{
		printf("caca");
		exit(EXIT_FAILURE);
	}
	
	//Alocare coloane la fiecare linie
	for(int i=0; i<m; i++)
	if((a[i] = (int*)malloc(n*sizeof(int)))==NULL)
	{
		while(i>=0)
		{
			free(a[i]);
			i--;
		}
		free(a);
		printf("caca");
		exit(EXIT_FAILURE);
	}

	for(int i=0; i<m; i++)
		for(int j=0; j<n; j++)
			{
			printf("a[%d][%d] = ", i, j);
			scanf("%d", &a[i][j]);
			}
		
	for(int i=0; i<m; i++)
		{
		for(int j=0; j<n; j++)
			printf("%d ", a[i][j]);
		printf("\n");
		}	
}



void sub_82()
{
	char a[5][5]={{'e', 'r', 'e', 'm', 'a'}, {'h', 'e', 'r', 'e', 'b'}, {'b', 'm', 'e', 'r', 'e'}, {'b', 'a', 'm', 'e', 'r'}, {'a', 'e', 'm', 'r', 'e'}};
	
	for(int i=0; i<5; i++)
		{
			for(int j=0; j<5; j++)
				printf("%c ", a[i][j]);
			printf("\n");
		}
		
		
	char cuv[]="mere";
	
	//DREAPTA
	for(int i=0; i<5; i++)
		for(int j=0; j<=5-strlen(cuv); j++)
	{
			int ok=1;
			
			for(int l=0; l<strlen(cuv); l++)
				if(a[i][j+l]!=cuv[l])
					ok=0;
			if(ok == 1)
				printf("De la linia %d coloana %d spre DREAPTA\n", i, j);
	}
	
	//STANGA
	for(int i=0; i<5; i++)
		for(int j=strlen(cuv)-1; j<5; j++)
	{
			int ok=1;
			
			for(int l=0; l<strlen(cuv); l++)
				if(a[i][j-l]!=cuv[l])
					ok=0;
			if(ok == 1)
				printf("De la linia %d coloana %d spre STANGA\n", i, j);
	}
	
	//JOS
	for(int j=0; j<5; j++)
		for(int i=0; i<=5-strlen(cuv); i++)
		{
			int ok=1;
			
				for(int l=0; l<strlen(cuv); l++)
					if(a[i+l][j]!=cuv[l])
						ok=0;
			if(ok==1)
				printf("De la linia %d coloana %d in JOS\n", i, j);
		}
		
	//SUS
	for(int j=0; j<5; j++)
		for(int i=strlen(cuv)-1; i<5; i++)
		{
			int ok=1;
			
				for(int l=0; l<strlen(cuv); l++)
					if(a[i-l][j]!=cuv[l])
						ok=0;
			if(ok==1)
				printf("De la linia %d coloana %d in SUS\n", i, j);
		}
}

int main()
{
	
	sub_82();
}
