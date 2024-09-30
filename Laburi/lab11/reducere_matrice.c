#include<stdio.h>
#define MAX_SIZE 100
 
int reducere(int a[][MAX_SIZE], int m, int n)
{
	if(m==0 || n==0) //matricea nu are niciun element
		return 0;
	else if(m==1 && n==1)
		return a[0][0];
		
	else
	{
		int mijR = m/2; //mijlocul randului
		int mijC = n/2; //mijlocul coloanei
		
		//construim cele 4 submatrici 
		int stangaSUS[m][n], dreaptaSUS[m][n], stangaJOS[m][n], dreaptaJOS[m][n];
		
		for(int i=0; i<mijR; i++)
			for(int j=0; j<mijC; j++)
				stangaSUS[i][j] = a[i][j];
			
		for(int i=0; i<mijR; i++)
			for(int j=mijC; j<n; j++)
				dreaptaSUS[i][j-mijC] = a[i][j];
				
		for(int i=mijR; i<m; i++)
			for(int j=0; j<mijC; j++)
				stangaJOS[i-mijR][j] = a[i][j];
				
		for(int i=mijR; i<m; i++)
			for(int j=mijC; j<n; j++)
				stangaJOS[i-mijR][j-mijC] = a[i][j];
				
				
		int reducereStangaSUS = reducere(stangaSUS, mijR, mijC);
        	int reducereDreaptaSUS = reducere(dreaptaSUS, mijR, n - mijC);
        	int reducereStangaJOS = reducere(stangaJOS, m - mijR, mijC);
        	int reducereDreaptaJOS = reducere(dreaptaJOS, m - mijR, n - mijC);
        	
        	int maximSUS, minimJOS;
        	if(reducereStangaSUS > reducereDreaptaSUS)
        		maximSUS = reducereStangaSUS;
        	else
        		maximSUS = reducereDreaptaSUS;
        		
        	if(reducereStangaJOS < reducereDreaptaJOS)
        		minimJOS = reducereStangaJOS;
        	else
        		minimJOS = reducereDreaptaJOS;
        		
        	return maximSUS - minimJOS;
        		
	}
}


int main()
{
		int m, n, a[MAX_SIZE][MAX_SIZE];
		
		printf("m= "); scanf("%d", &m);
		printf("n= "); scanf("%d", &n);
		
		for(int i=0; i<m; i++)
			for(int j=0; j<n; j++)
				{
					printf("a[%d][%d]=", i, j);
					scanf("%d", &a[i][j]);
				}
		for(int i=0; i<m; i++)
			{
				for(int j=0; j<n; j++)
					printf("%d ", a[i][j]);
				printf("\n");
			}
			
		printf("%d\n", reducere(a, m, n));
}







