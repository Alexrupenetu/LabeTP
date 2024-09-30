#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>
#include<string.h>
int n, s, k, v[100], bani[100], a, b;
int coef[100];

void afisare1(int coef[], int k)
{
	for(int i=0; i<=k; i++)
		if(coef[i]!=0)
		printf("%d*%d ", coef[i] , bani[i]);
	printf("\n");
}

int valid1(int k)
{
	int suma = 0;
	
	for(int i=0; i<=k; i++)
		suma += coef[i] * bani[i];
	
	if(suma<=s)
		return 1;
	else
		return 0;
}

int solutie1(int k)
{
	int suma = 0;
	
	for(int i=0; i<=k; i++)
		suma += coef[i] * bani[i];
	
	if(suma==s)
		return 1;
	else
		return 0;
}


void back1(int k)
{
	for(int i=0; i<=s/bani[k]; i++)
	{
		coef[k] = i;
		
		if(valid1(k))
		{
			if(solutie1(k))
				afisare1(coef, k);
			else if(k+1<n)
				back1(k+1);
		}
	}
}


void pb1() 
{
    printf("Introduceti numarul de valori ale bancnotelor: ");
    scanf("%d", &n);

    printf("Introduceti valorile bancnotelor ordonate strict crescator: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &bani[i]);
    }

    printf("Introduceti suma de platit: ");
    scanf("%d", &s);

    printf("Moduri de a plati suma %d:\n", s);
    back1(0);
}

int credite[100];

void afisare2(int v[], int k)
{
	for(int i=0; i<=k; i++)
		printf("%d ", credite[v[i]]);
	printf("\n");
}

int valid2(int k)
{
	for(int i=0; i<k; i++)
		if(v[i] == v[k] || v[k]>v[i])
			return 0;
	int suma=0;
	for(int i=0; i<=k; i++)
		suma+=credite[v[i]];
		
	if(suma-credite[v[k]]>suma)
		return 0;
	else
		return 1;
}

int solutie2(int k)
{
	int suma=0;
	for(int i=0; i<=k; i++)
		suma+=credite[v[i]];
		
	if(suma>=s )
		return 1;
	else
		return 0;
}

void back2(int k)
{
	for(int i=0; i<n; i++)
	{
		v[k] = credite[i];
		
		if(valid2(k))
		{
			if(solutie2(k))
				afisare2(v, k);
			else
				back2(k+1);
		}
	}
}

void pb2()
{
	/*
	printf("n= ");scanf("%d", &n);
	printf("Elementele vectorului ");
	for(int i=0; i<n; i++)
		scanf("%d", &credite[i]);
	printf("s= ");scanf("%d", &s);*/
	n=7;
	credite[0] = 10; credite[1]=10; credite[2]=10; credite[3]=8; credite[4]=7;
	credite[5]=6; credite[6]=2;
	s=30;
	back2(0);
}

void afisare5(int v[], int k)
{
	for(int i=0; i<=k; i++)	
		if(v[i]==0)
			printf("(");
		else
			printf(")");
}


int valid5(int k)
{
	int pi=0, pd=0;
	for(int i=0; i<=k; i++)
		if(v[i]==0)
			pd++;
		else
			pi++;
			
	if(pi<=pd && pd<=n/2)
		return 1;
	else
		return 0;
}

int solutie5(int k)
{
	if(k+1==n)
		return 1;
	else
		return 0;
}

void back5(int k)
{
	for(int i=0; i<=1; i++)
	{
		v[k] = i;
		
		if(valid5(k))
		{
			if(solutie5(k))
				afisare5(v, k);
			else
				back5(k+1);
		}
	}
}

void afisare6(int v[], int k)
{
	for(int i=0; i<=k; i++)
		printf("%d ", v[i]);
	printf("\n");
}

int suma_cif(int n)
{
	int s=0;
	
	while(n)
	{
		s+=n%10;
		n=n/10;
	}
	return s;
}

int valid6(int k)
{
	if(k==0)
		return 1;
	else
	{
		if(suma_cif(v[k]) + suma_cif(v[k-1])!=10)
				return 0;
		return 1;
	}
}

int solutie6(int k)
{
	if(k+1==n)
		return 1;
	else
		return 0;
}

void back6(int k)
{
{
	for(int i=a; i<=b; i++)
	{
		v[k] = i;
		
		if(valid6(k))
		{
			if(solutie6(k))
				afisare6(v, k);
			else
				back6(k+1);
		}
	}
}
}

int valid7(int k)
{
	if(k==9)
		{
			if(v[8] + v[7] != v[0]+v[1])
				return 0;
			else
				return 1;
		}
	if(k>3 && k%2==0)
		if(v[k-2]+v[k-1]+v[k]!=v[0]+v[1])
			return 0;
	return 1;
}

void back7(int k)
{
	for(int i=1; i<=9; i++)
	{
		v[k]=i;
		
		if(valid7(k))
			{
				if(k+1==9)
					afisare6(v, 8);
				else
					back7(k+1);
			}
	}
}

void tiparire(const char*inputFile, const char*outputFile, int NumArgs, ...)
{
	FILE *fin = fopen(inputFile, "");
}

int main()
{
	n=3; a=4, b=20;
	back7(0);	
}
