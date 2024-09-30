#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 20

int n, k, sol[MAX], p;
char alf[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
const char *string = NULL;

void afisare()
{
	for(int i=0; i<p; i++)
		printf("%c", alf[sol[i]]);
	printf("\n");
}

int valid(int k)
{
	//verificam sa nu fie 2 litere cons egale sau vocale 
	if(k>=1)
	{
		if(alf[sol[k-1]]==alf[sol[k]] ||(strchr("aeiou", alf[sol[k-1]])!=NULL && strchr("aeiou", alf[sol[k]])!=NULL))
			return 0;
		if(abs(alf[sol[k-1]] - alf[sol[k]])==1)
			return 0;
		return 1;
	}
	else
		return 1;
}

int solutie(int k)
{
	return k+1 == p;
}


void back(int k)
{
	for(int i=0; i<n; i++)
	{
		sol[k] = i;
		
		if(valid(k))
		{
			if(solutie(k))
			{
				afisare();
			}
			else
			back(k+1);

		}
	}
}

/*
int main(int argc, char*argv[])
{
	n = atoi(argv[1]);
	p = atoi(argv[2]);
	
	for(int i=0; i<n; i++)
		{
			string = argv[i+3];
			alf[i] = string[0];
		}
		
	for(int i=0; i<n; i++)
		printf("%c ", alf[i]);
	printf("\n");
	
	back(0);
}
*/

int main()
{
 n=8; p=3; 
 back(0);
}
	
