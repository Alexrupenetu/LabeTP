#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 1000

int permutari[MAX_SIZE];
int n=3;
int k2=2;

void afisare(int v[MAX_SIZE], int size)
{
	for(int i=0; i<size; i++)
		printf("%d ", v[i]);
	printf("\n");
}

int valid1(int k)
{
	if(permutari[k] >= 0 && permutari[k]<=9)
		return 1;
	else
		return 0;
}

int solutie1(int k)
{
	int contor = 0;
	
	if(permutari[0] == 0)
		return 0;
	
	for(int i=0; i<=k; i++)
		if(permutari[i]==1)
			contor++;
		
	if(k == n-1 && contor == k2)
		return 1;
	else
		return 0;
}

void afisare2(int v[MAX_SIZE], int size)
{
	for(int i=1; i<=size; i++)
		printf("%d ", v[i]);
	printf("\n");
}

void back1(int k)
{
	if(k==n) {
	return;
	}
	for(int i=0; i<=9; i++)
	{
		permutari[k] = i;
		
		if(valid1(k))
			{
			if(solutie1(k))
				afisare(permutari, n);
			else
				back1(k+1);
			}
	}
}

int valid2(int k)
{
	//verificam sa nu avem duplicate
	for(int i=1; i<k; i++)
		if(permutari[i]==permutari[k])
			return 0;
	return 1;
}

int solutie2(int k)
{	
	
	if(k==n)
	{
	int mijloc = n/2 + n%2;
	
	//descrescator
		for(int i=1; i<mijloc; i++)
			for(int j=i+1; j<=mijloc; j++)
				if(permutari[i]<permutari[j])
					return 0;
	//crescator
		for(int i=mijloc; i<=k; i++)
			for(int j=i+1; j<=k; j++)
				if(permutari[i]>permutari[j])
					return 0;
		return 1;
	}
	else
		return 0;
}


void back2(int k)
{
	for(int i=1; i<=n; i++)
	{
		permutari[k] = i;
		
		if(valid2(k))
		{
			if(solutie2(k))
				afisare2(permutari, n);
			else
				back2(k+1);
		}
	}
}

void pb2()
{
	n = 5;
	back2(1);
}


//PROBLEMA 3 
/*
int cifre[MAX_SIZE], len = 0, v[MAX_SIZE], max;

void descompunere(int n)
{
	int aux, len=0, contor=0;
	aux = n;
	
	while(aux)
	{
		contor++;
		aux = aux/10;
	}
	
	while(n)
	{
		cifre[contor-len] = n%10;
		len++;
		n = n/10;
	}
}

int valid3(int k)
{
	//verificam sa fie indicii in ordine crescatoare
	for(int i=1; i<k; i++)
		if(v[i]>=v[k])
			return 0;
	return 1;
}

int solutie3(int k)
{
	//am ajuns la dimensiunea dorita am eliminat k cifre
	if(k == (len-k2))
		return 1;
	else
		return 0;
}

int numar(void)
{
	int nr = 0;
	for(int i=1; i<=(len-k2); i++)
		nr = nr*10 + cifre[v[i]];
	return nr;
}

void back3(int k)
{
	int aux;
	for(int i=1; i<=len; i++)
	{
		v[k] = i;
		if(valid3(k))
		{
			if(solutie3(k))
				{
					aux = numar();
					if(aux>max)
						max = aux;
				}
			else
				back3(k+1);
		}
	}
}

void pb3()
{
	n = 3452234;
	k2=4;
	descompunere(n);
	back3(1);
	printf("%d\n", max);
}
*/
int numV[MAX_SIZE], len, max, p, ans[MAX_SIZE], k;

void descompunere(int nr)
{
    int aux = nr, count = 0;
    len = 0;
    while (aux)
    {
        count++;
        aux = aux / 10;
    }
    while (nr)
    {
        numV[count - len] = nr % 10;
        len++;
        nr = nr / 10;
    }
}

int verificare3(int p)
{
    int i;
    for (i = 1; i < p; i++)
    {
        if (ans[i] >= ans[p])
        {
            return 0;
        }
    }
    return 1;
}

int solutie3(int p)
{
    if (p == (len - k))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int numar(void)
{
    int i, numar = 0;
    for (i = 1; i <= (len - k); i++)
    {
        numar = numar * 10 + numV[ans[i]];
    }
    return numar;
}

void back3(int p)
{
    int i, aux;
    for (i = 1; i <= len; i++)
    {
        ans[p] = i;
        if (verificare3(p))
        {
            if (solutie3(p))
            {
                aux = numar();
                if (aux > max)
                {
                    max = aux;
                }
            }
            else
            {
                back3(p + 1);
            }
        }
    }
}

void p3(void)
{
    n = 3452234;
    k = 4;
    descompunere(n);
    back3(1);
    printf("%d\n", max);
}

//PROBLEMA 4

int v[MAX_SIZE];
char culori[7][20] = {" ", "alb", "galben", "rosu", "verde", "albastru", "negru"};

int valid4(int p)
{
	//verificare elemente distincte
	for(int i=1; i<p; i++)
		if(v[i] == v[p])
			return 0;
	return 1;	
}

int solutie4(int p)
{
	if(p==3 && (v[2] == 2 || v[2] == 4))
		return 1;
	 
	return 0;
}

void afisare4()
{
	for(int i=1; i<=3; i++)
		printf("%s ", culori[v[i]]);
	printf("\n");
}

void back4(int p)
{
	for(int i=1; i<=6; i++)
	{
		v[p] = i;
		
		if(valid4(p))
		{
			if(solutie4(p))
				afisare4();
			else
				back4(p+1);
		}
	}
}


void pb4()
{
	back4(1);
}

//PROBLEMA 5
float volume[MAX_SIZE] = {0.0, 1.23, 3.47, 0.89, 4.12, 2.36, 4.78, 1.56, 3.09, 0.45, 2.78, 4.33, 1.98, 3.67, 0.11, 2.45, 3.79, 4.56, 0.67, 2.88, 3.21}, volum;


int valid5(int p)
{
	//verificare elemente distincte
	for(int i=1; i<p; i++)
		if(v[i] == v[p])
			return 0;
	return 1;
}

int solutie5(int p)
{
	float s = 0.0;
	
	for(int i=1; i<=p; i++)
		s+=volume[v[i]];
		
	return s<=volum;
}

void afisare5(int p)
{
	for(int i=1; i<=p; i++)
		printf("%.2f ", volume[v[i]]);
	printf("\n");
}

void back5(int p)
{
	for(int i=1; i<=n; i++)
	{
		v[p] = i;
		
		if(valid5(p))
			{
				if(solutie5(p))
				{
					afisare5(p);
				}
				
				back5(p+1);
			}	
	}
}


void pb5()
{
	n = 5;
	volum = 6.6;
	back5(1);
}

//PROBLEMA 6
int c, b, g, a;
char chestii[5][100] = {"", "casa", "bloc", "gradina", "atelier"};

int valid6(int p)
{
	//verificam daca sunt vecinatatile ca lumea 
	//verificam doar vecinul din spate fiindca asa se populeaza vectorul de permutari
	if(p!=1)
	{
		switch(v[p])
		{
			case 1:
			{
				if(v[p-1] == 1 || v[p-1] == 2 || v[p-1] ==3 )
					return 1;
				break;
			}
			case 2:
			{
				if(v[p-1] == 1 || v[p-1] == 2)
					return 1;
				break;
			}
			case 3:
			{
				if(v[p-1] == 1 || v[p-1] == 3 || v[p-1] == 4 )
					return 1;
				break;
			}
			case 4:
			{
				if (v[p - 1] == 3 || v[p - 1] == 4)
				    {
					return 1;
				    }
				    break;
			}
		}
	}
	else
	{
		return 1;
	}
	return 0;
}

int solutie6(int p)
{
	int contorC=0, contorB=0, contorG=0, contorA=0;
	
	for(int i=1; i<=p; i++)
	{
		switch(v[i])
		{
		case 1:
		{
			contorC++;
			break;
		}
		case 2:
		{
			contorB++;
			break;
		}
		case 3:
		{
			contorG++;
			break;
		}
		case 4:
		{
			contorA++;
			break;
		}
		}
	}
	return (c==contorC && b==contorB && g==contorG && a==contorA);
}


int D[100];

void creare_vector()
{

}

void afisare6(void)
{
	for(int i=1; i<=c+g+b+a; i++)
		printf("%s ", chestii[v[i]]);
		
	printf("\n");
}

void back6(int p)
{
	if(p > c + b + g + a)
		{
			return;
		}
	for(int i=1; i<=4; i++)
	{
		v[p] = i;
		
		if(valid6(p))
			{
				if(solutie6(p))
					afisare6();
				else
					back6(p+1);
			}
			
	}
}

void pb6(void)
{
    c = 2;
    b = 1;
    g = 1;
    a = 1;
    back6(1);
}

//PROBLEMA 7
int laturi[100] = {0, 1, 2, 2, 1}, latura, ok;

int valid7(int p)
{
	for(int i=1; i<p; i++)
		if(v[i] == v[p])
			return 0;
	return 1;
}

int solutie7(int p)
{
	int ArieTotala=0, ArieSol = 0;
	ArieTotala = latura * latura;
	
	for(int i=1; i<=p; i++)
	{
		ArieSol += laturi[v[i]] * laturi[v[i]];
	}
	
	return (ArieSol <= ArieTotala) && (p==n);
}

void back7(int p)
{
	for(int i=1; i<=n; i++)
	{
		v[p] = i;
		
		if(valid7(p))
		{
			if(solutie7(p))
				ok=1;
			else
				back7(p+1);
		}
	}
}

void pb7(void)
{
    n = 4;
    k = 0;
    latura = 4;
    back7(1);
    if(k == 1)
    {
        printf("Exista configuratie\n");
    }
    else
    {
        printf("Nu exista configuratie\n");
    }
}


//PROBLEMA 8

int lungime;

int valid8(int p)
{
	//verificam sa nu fie elemente in ordine descrescatoare
	for(int i=0; i<p; i++)
		if(v[i]>=v[p])
			return 0;
	return 1;
}


int solutie8(int p)
{
	int suma = 0;
	
	for(int i=1; i<=p; i++)
		suma += v[i];
	
	return (suma == lungime) && (p==n);
}

void afisare8(void)
{
    int i;
    for(i = 1; i <= n; i++)
    {
        printf("%d ", v[i]);
    }
    printf("\n");
}


void back8(int p)
{
	for(int i=1; i<=lungime; i++)
	{
		v[p] = i;
		
		if(valid8(p))
		{
			if(solutie8(p))
			{
				afisare8();
			}
			else
				back8(p+1);
		}
	}
}

void pb8(void)
{
    lungime = 20;
    n = 3;
    back8(1);
}

int main(void)
{
	pb8();
}

