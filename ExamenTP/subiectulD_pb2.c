#include<stdio.h>
#include<stdlib.h>

int oglindit(int a, int ogl)
{
	if(a>0)
	{
		int cifra = a % 10;
		ogl = ogl*10 + cifra;
		a = a / 10;
		return oglindit(a, ogl);
	}
	else
		return ogl;
}

int descomp(int n, int a)
{
	int b = oglindit(a, 0);
	if(a + b == n && a%10 != 0)
		printf("%d + %d \n", a, b);
	if(a<n)
		return descomp(n, a+1);
	else
		return 0;
}

int main()
{
	printf("%d\n",  oglindit(123, 0));
	descomp(787, 1);
}
