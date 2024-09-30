/*#include<stdio.h>

int n, k, v[100];

void afisare(int v[], int k)
{
	for(int i=0; i<=k; i++)
		printf("%d ", v[i]);
	printf("\n");
}

int valid(int k)
{
	if(k+1<n)
		return 1;
	else
		return 0;
}

int solutie(int k)
{
	return (k+1==n);
}

void back(int k)
{
	for(int i=1; i<=n; i++)
	{
		v[k] = i;
		
			if(solutie(k))
				afisare(v, k);
			else
				back(k+1);
		
	}
}
int main()
{
	n=4;
	back(0);
}*/
#include <stdio.h>

int credite[100];
int v[100];
int n, s;

void afisare2(int v[], int k)
{
    int contor = 0;
    for (int i = 0; i <= k; i++)
        if (v[i] == 1)
            contor++;
    printf("%d: ", contor);
    
    for (int i = 0; i <= k; i++)
        if (v[i] == 1)
            printf("%d ", credite[i]);
    printf("\n");
}

int valid2(int k)
{
    int suma = 0;
    for (int i = 0; i <= k; i++)
        if (v[i] == 1)
            suma += credite[i];
    return suma <= s;
}

int solutie2(int k)
{
    int suma = 0;
    for (int i = 0; i <= k; i++)
        if (v[i] == 1)
            suma += credite[i];
    return suma >= s;
}

void back2(int k)
{
    if (k == n)
    {
        if (solutie2(k - 1))
            afisare2(v, k - 1);
        return;
    }

    for (int i = 0; i <= 1; i++)
    {
        v[k] = i;
        if (valid2(k))
        {
            back2(k + 1);
        }
    }
}

void pb2()
{
    n = 7;
    credite[0] = 7;
    credite[1] = 8;
    credite[2] = 10;
    credite[3] = 10;
    credite[4] = 10;
    credite[5] = 2;
    credite[6] = 6;
    s = 30;
    back2(0);
}

int main()
{
    pb2();
    return 0;
}

