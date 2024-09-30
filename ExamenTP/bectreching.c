#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int v[100], n, k, p;

void afisare1(int v[100], int k)
{
	for(int i=0; i<n; i++)
		printf("%d", v[i]);
	printf("\n");
}

int valid1(int k)
{
	if(k<n)
		return 1;
	else
		return 0;
} 

int solutie1(int k)
{
	
		int contor = 0;
		
		for(int i=0; i<=k; i++)
			if(v[i]==1)
				contor++;
				
		if(contor == p && k==n-1 && v[0]!=0)
			return 1;
		else
			return  0;
	
}

void back1(int k)
{
	for(int i=0; i<=9; i++)
	{
		v[k] = i;
		if(valid1(k))
			{
				if(solutie1(k))
					afisare1(v, k);
				else 
					back1(k+1);
			}
	}
}

void pb1()
{
	n=5; p=3;
	back1(0);
}


int valid2(int k)
{
	//verificam sa fie distincte
	for(int i=0; i<k; i++)
		if(v[i]==v[k])
			return 0;
	return 1;
}

int solutie2(int k)
{
	if(k==n-1)
	{
	int mij = n/2 + n%2;
	int ok=1;
	for(int i=0; i<mij; i++)
		for(int j=i+1; j<mij; j++)
			if(v[i]<v[j])
				ok=0;
	
	for(int i=mij; i<n; i++)
		for(int j=i+1; j<n; j++)
			if(v[i]>v[j])
				ok=0;
		
	if(ok==1)
		return 1;
	else
		return 0;
	}
	else
		return 0;
				
		
}


void back2(int k)
{
	for(int i=1; i<=n; i++)
	{
		v[k] = i;
		
		if(valid2(k))
		{
			if(solutie2(k))
				afisare1(v, k);
			else
				back2(k+1);
		}
	}
}

void pb2()
{
	n=5;
	back2(0);
}


void afisare4(int v[])
{
	for(int i=0; i<3; i++)
		printf("%d ", v[i]);
	printf("\n");
	
}

int valid4(int k)
{
	for(int i=0; i<k; i++)
		if(v[i]==v[k])
			return 0;
	return 1;
}

int solutie4(int k)
{
	if(k==3)
	{
		if(v[1]==2 || v[1]==4)
			return 1;
		else
			return 0;
	}
	else
		return 0;
}

void back4(int k)
{
	for(int i=1; i<6; i++)
	{
		v[k]=i;
		if(valid4(k))
		{
			if(solutie4(k))
				afisare4(v);
			else
				back4(k+1);
		}
	}
}

int main(void)
{
	back4(0);
}
