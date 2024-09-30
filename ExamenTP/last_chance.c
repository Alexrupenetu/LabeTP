#include<stdio.h>
#include<stdlib.h>


int n, k, s, credite[7], v[10], m;

void afisare(int v[], int k)
{
	printf("%d: ", k+1);
	for(int i=0; i<=k; i++)
		printf("%d " ,credite[v[i]]);
	printf("\n");
}

int valid(int k)
{
	//verificare distincte
	for(int i=0; i<k; i++)
		if(v[i]==v[k] || v[i]>v[k])
			return 0;
	return 1;
}

int solutie(int k)
{
	int suma=0;
	for(int i=0; i<=k; i++)
		suma+=credite[v[i]];
		
	return suma>=s;	
}

void back(int k)
{
	for(int i=0; i<n; i++)
	{
		v[k] = i;
		
		if(valid(k))
		{
			if(solutie(k))
				afisare(v, k);
			else if(k+1<n)
				back(k+1);
		}
	}
}



void pb2()
{
	n=7; s=30;
	credite[0]=10; credite[1]=10; credite[2]=10; credite[3]=8; credite[4]=7; credite[5]=6; credite[6]=2;
	
	back(0);
}

void afisare3(int v[], int k)
{
	for(int i=0; i<=k; i++)
		printf("%d ", v[i]);
	printf("\n");
}

int valid3(int k)
{
	if(k==0)
		return 1;
	else
	{
		//verificam sa fie in ordine
		for(int i=0; i<k; i++)
			if(v[i]!=0 && v[k]!=0 && v[i]>=v[k])
				return 0;
	}
	return ((v[k-1]==0 || v[k]==0) && k+1<=m);
}

int solutie3(int k)
{
	int sum=0, target = (n*(n+1))/2;
	for(int i=0; i<=k; i++)
		sum+=v[i];
	return (sum == target && k+1==m);
}

void back3(int k)
{
	for(int i=0; i<=n; i++)
	{
		v[k] = i;
		
		if(valid3(k))
		{
			if(solutie3(k))
				afisare3(v, k);
			else 
				back3(k+1);
		}
	}
}



int main()
{
	n=3; m=6;
	back3(0);	
}
