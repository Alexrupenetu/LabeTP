#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int v[100], ap[100], n;
char s[10], sol[10];

/*Se citesc un cuv�nt s (cu cel mult 10 caractere litere mici distincte). Sa se genereze si sa se afiseze toate anagramele cuv�ntului s �n care consoanele sunt puncte fixe.
Exemplu: s=�alinus�, => alinus, alunis, ilanus, ilunas, ulanis, ulinas. 

void afisare(int v[], char s[], int n)
{
	for(int i=0; i<n; i++)
		printf("%c", s[v[i]]);
	printf("\n ");
}

int valid(int k)
{
	if(k<=n)
		return 1;
	else
		return 0;	
}

int solutie(int k)
{
	if(k==n)
	{
	int ok = 1;
	for(int i=0; i<k+1; i++)
		if(strchr("aeiou", s[v[i]])!=NULL || v[i]==i)
			continue;
		else
			return 0;
			
	return 1;
	}
	
	return 0;		
}

void back(int k)
{
	for(int i=0; i<n; i++)
		{
		if(ap[i] == 0)
		{
			ap[i] = 1; 
			v[k] = i;
			if(solutie(k+1))
					afisare(v, s, k+1);
			else
					back(k+1);
			ap[i] = 0;
		}
		}
}

int main() 
{
	printf("cuvant: ");scanf("%s", s);
	n = strlen(s);
	back(0);
	
}



//Folosind metoda backtracking sa se descompuna in toate modurile un numar natural n ca suma de numere prime distincte ordonate crescator.  nr cu nr prime distincte

void afisare(int v[], int n)
{
	for(int i=1; i<=n; i++)
		printf("%d ", v[i]);
	printf("\n");
}

int prim(int n)
    {int i;
     if(n==0 || n==1) return 0;
	else if(n==2 || n==3) return 1;
	  else if(n%2==0) return 0;
	    for(i=3;i*i<=n;i+=2)
	      if(n%i==0) return 0;
     return 1;

   }
int valid(int k)
{
	for(int i=1; i<k; i++)
		if(v[i]==v[k])
			return 0;  //verif distincte
	
	if(prim(v[k])==0)
		return 0;
	return 1;
		
}

int solutie(int k)
{
	

	for(int i=1; i<k; i++)
		for(int j=i+1; j<=k; j++)
			if(v[i]>v[j])
				return 0;
	int suma = 0;
	
	for(int i=1; i<=k; i++)
		suma+=v[i];
		
	if(suma == n)
		return 1;
	return 0;
}

void back(int k)
{
	for(int i=0; i<=n; i++)
	{
		v[k] = i;
		
		if(valid(k))
			{
				if(solutie(k))
					afisare(v, k);
				else
					back(k+1);
			}
	}
}

int main()
{
	n=12;
	back(1);
}
*/









int main()
{

}








