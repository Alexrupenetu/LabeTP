#include <stdio.h>

#define MAX 100

int bani[MAX], credite[7]={7, 8, 10, 10, 10, 2, 6};
int sol[MAX];
int n, m, s;

void afisare1(int sol[], int bani[], int k)
{
	for( int i=0; i<=k; i++)
		if(sol[i]>0)
			printf("%d * %d ", sol[i], bani[i]);
	printf("\n");
}


int valid1(int k)
{
	int suma=0;
	
	for(int i=0; i<=k; i++)
		suma+=sol[i]*bani[i];
	
	if(suma<=s)
		return 1;
	else
		return 0;
}

int solutie1(int k)
{
	int suma=0;
	
	for(int i=0; i<=k; i++)
		suma+=sol[i]*bani[i];
	
	if(suma==s)
		return 1;
	else
		return 0;
}

void back1(int k)
{
	for(int i=0; i<=s/bani[k]; i++)
	{
		sol[k] = i;
		
		if(valid1(k))
		{
			if(solutie1(k))
				afisare1(sol, bani, k);
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

void afisare2(int sol[], int k)
{
	int contor=0;
	for(int i=0; i<=k; i++)
		if(sol[i]==1)
			contor++;
	printf("%d: ", contor);
	for(int i=0; i<=k; i++)
		if(sol[i]==1)
		printf("%d ", credite[i]);
	printf("\n");
}

int valid2(int k)
{
	int suma=0;
	for(int i=0; i<=k; i++)
		if(sol[i]==1)
		suma+=credite[i];
		
	if(suma<=s)
		return 1;
	else
		return 0;
}

int solutie2(int k)
{
	int suma=0;
	for(int i=0; i<=k; i++)
		if(sol[i]==1)
		suma+=credite[i];
		
	if(suma==s)
		return 1;
	else
		return 0;
}

void back2(int k)
{
	for(int i=0; i<=1; i++)
	{
		sol[k] = i;
		
		if(valid2(k))
		{
			if(solutie2(k))
				afisare2(sol, k);
			else if(k+1<n)
				back2(k+1);
		}
	}
}


int sol[MAX];
int n, m;

void afisare(int sol[], int m) {
    for (int i = 0; i < m; i++) {
        printf("%02d", sol[i]); // afișăm cu 2 cifre pentru lizibilitate
    }
    printf("\n");
}

int valid(int k) {
    // Verifică dacă două examene nu sunt în zile consecutive
    if (k > 0 && sol[k] != 0 && sol[k - 1] != 0) {
        return 0;
    }
    return 1;
}

int solutie(int k) {
    // Verifică dacă soluția este completă (toate examenele 1...n sunt prezente)
    int count[MAX] = {0};
    for (int i = 0; i <= k; i++) {
        if (sol[i] != 0) {
            count[sol[i]]++;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (count[i] == 0) {
            return 0;
        }
    }
    return 1;
}

void backtracking(int k) {
    for (int i = 0; i <= n; i++) { // 0 pentru zi liberă, 1-n pentru examene
        sol[k] = i;
        if (valid(k)) {
            if (solutie(k) && k + 1 == m) {
                afisare(sol, m);
            } else if (k + 1 < m) {
                backtracking(k + 1);
            }
        }
    }
}

int main(void) {
pb1();
}



