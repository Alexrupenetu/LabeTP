#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int v[100], numv[100], len, max=-1, n, k;

void descompunere(int n)
{
	int contor = 0, aux = n; 
	len = 0;
	
	while(aux)
	{
		contor++;
		aux = aux/10;
	}
	
	while(n)
	{
		numv[contor-len] = n%10;
		len++;
		n=n/10;
	}
}

int numar()
{
	int nr = 0;
	
	for(int i=1; i<=(len-k); i++)
		nr = nr*10 + numv[v[i]];
		
	return nr;
}

int valid(int p)
{
	for(int i=1; i<p; i++)
		if(v[i]>=v[p])
			return 0;
	return 1;
}

int solutie(int p)
{
	if(p==(len-k))
		return 1;
	else
		return 0;
}

void back(int p)
{
	for(int i=1; i<=len; i++)
	{
		v[p] = i;
		
		if(valid(p))
		{
			if(solutie(p))
			{
				int aux = numar();
				if(aux>max)
					max = aux;
			}
			else
				back(p+1);
		}
	
	}
	
	
}

//Se citeste un numar natural n. Sa se afiseze toate modurile in care poate fi descompus ca suma de numere naturale impare distincte.

void afisare(int v[], int k)
{
	for(int i=1; i<=k; i++)
		printf("%d ", v[i]);
	printf("\n");
}

int valid2(int k)
{
	for(int i=1; i<k; i++)
		if(v[i]==v[k])
			return 0;
	if(v[k]%2==0)
		return 0;
	return 1;
}

int solutie2(int k)
{
	int s = 0;
	for(int i=1; i<=k; i++)
		s+=v[i];
		
	if(s==n)
		return 1;
	
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
						afisare(v, k);
					else
						back2(k+1);
				}
				
		}
}

void pb2()
{
	n=12;
	back2(1);
}

void sum_max(int v[100], int size)
{
	int st, dr, max=-1, st_max, dr_max;
	
	for(int i=0; i<size-1; i++)
		for(int j=i+1; j<size; j++)
			{
				int suma=0;
				for(int k=i; k<=j; k++)
				{
					suma+=v[k];
					if(suma>max)
						{
						max = suma;
						st_max = i;
						dr_max = j;
						}
				}
			}
	printf("max = %d", max);
}

void minmax(int v[], int st, int dr, int *min, int *max)
{
	if(st==dr) *min = *max = v[st];
	else
	{
	int a, b, x, y;
	minmax(v, st, (st+dr)/2, &a, &x);
	minmax(v, (st+dr)/2+1,  dr, &b, &y);
	if(a<b) *min = a;
	else	*min = b;
	
	if(x>y) *max = x;
	else 	*max = y;
	}
}

int minim_prim(int v[], int st, int dr)
{
	if(st == dr)
		return v[st]%2!=0;
	
	int mij = (st+dr)/2;
	
	int rez_st = minim_prim(v, st, mij);
	int rez_dr = minim_prim(v, mij+1, dr);
	
	return rez_st || rez_dr;
	
}

int suma_div(int v[], int st, int dr)
{
	if(st==dr)
		return v[st];
	
	int mij = (st+dr)/2;
	
	int left_sum = suma_div(v, st, mij);
	int right_sum = suma_div(v, mij+1, dr);
	
	return left_sum + right_sum;
}

int nr_el_impare(int v[], int st, int dr)
{
	if(st == dr)
		return v[st]%2;
		
	int mij = (st+dr)/2;
	
	int rez_st = nr_el_impare(v, st, mij);
	int rez_dr = nr_el_impare(v, mij+1, dr);
	
	return rez_st + rez_dr;
}


int nr_vocale(char s[], int st, int dr)
{
	if(st == dr)
		if(strchr("aeiou", s[st]))
			return 1;
		else
			return 0;
			
	int mij = (st+dr)/2;
	
	int left_rez = nr_vocale(s, st, mij);
	int right_rez = nr_vocale(s, mij+1, dr);
	
	return left_rez + right_rez;
}

int t[]={10, 7, 5, 18, 12, 20, 15};

int valid_subseturi(int k)
{
	int s = 0;	
	
	for(int i=0; i<k; i++)
		if(v[i] == v[k])
			return 0;
	
	for(int i=0; i<k; i++)
		s+=t[v[i]];
		
	if(s<35)
		return 1;
	else
		return 0;
}

int solutie_subseturi(int k)
{
	int s = 0;
	
	for(int i=0; i<=k; i++)
		s+=t[v[i]];
	if(s == 35)
		return 1;
	else
		return 0;
}

void afisare_subseturi(int v[], int k)
{
	for(int i=0; i<=k; i++)
		printf("%d ", t[v[i]]);
	printf("\n");
}

void back_subseturi(int k)
{
	for(int i=0; i<n; i++)
		{
			v[k] = i;
			
			if(valid_subseturi(k))
			{
				if(solutie_subseturi(k))
					afisare_subseturi(v, k);
				else
					back_subseturi(k+1);
			}
		}
}

int D[100], len;

void creare_vector(int n)
{
	len = 0;
	for(int d=2; d*d<=n; d++)
		if(n%d == 0)
			{
			D[len++] = d;
			if(d*d!=n)
				D[len++] = n/d;
			}
			
}

int compare(const void *elem1, const void *elem2)
{
	int a = *(int*)elem1;
	int b = *(int*)elem2;
	
	return a-b;
}

int valid5(int k)
{
	for(int i=0; i<k; i++)
		if(v[i]==v[k])
			return 0;
		
	return 1;
}

int solutie5(int k)
{
	int prod = 1;
	
	for(int i=0; i<k; i++)
		prod*=D[v[i]];
		
	if(prod==n)
		return 1;
	else
		return 0;
}

void afisare5(int v[], int k)
{
	for(int i=0; i<k; i++)
		printf("%d ", D[v[i]]);
	printf("\n");
}

void back5(int k)
{
	for(int i=0; i<len; i++)
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

int main(void)
{
	char s[]={'A', 'n', 'a', 'm', 'a', 'r', 'i', 'a', '\0'};
	//printf("%d\n", nr_vocale(s, 0, 7));
	n = 30;
	creare_vector(n);
	qsort(D, len, sizeof(int), compare);
	back5(0);
	//back_subseturi(0);
}










