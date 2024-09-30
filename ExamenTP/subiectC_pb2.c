#include <stdio.h>
#include <stdlib.h>

int v[100], n, k, impare[100], pare[100], perm[100];
int cnt_imp, cnt_pare;

void afisare()
{
	int index_imp = 0;
	for(int i=-n; i<=n; i++)
		if(i%2==0)
			printf("%d ", i);
		else
			printf("%d ", v[perm[index_imp++]]);
	printf("\n");
}

int valid(int k)
{
	//verificam sa fie distincte
	for(int i=0; i<k; i++)
		if(perm[i] == perm[k])
			return 0;
	return 1;
}

int solutie(int k)
{
	return k+1 == cnt_imp;
}

void back(int k)
{
	for(int i=0; i<cnt_imp; i++)
	{
		perm[k] = impare[i];
		
		if(valid(k))
		{
			if(solutie(k))
				afisare();
			else
				back(k+1);
		}
	}
}


int main(int argc, char **argv)
{
	n = atoi(argv[1]);
	
	int val = (-1) * n;
	for(int i=0; i<2*n+1; i++, val++)
			v[i] = val;
			
			
	for(int i=0; i<2*n+1; i++)
		if(v[i]%2==1 || v[i]%2 == -1)
			{
				impare[cnt_imp] = i;
				cnt_imp++;
			}
	back(0);
	
}
