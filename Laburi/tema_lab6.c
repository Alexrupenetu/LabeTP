#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>
#include<math.h>
#include<string.h>

//aplicatia 6.1
void err(int prop, const char *fmt,...)
{
	va_list va;
	va_start(va, fmt);
	
	if(prop == 1)
	{
		fprintf(stderr, "eroare: ");
		vfprintf(stderr, fmt, va);
		va_end(va);
		fputc('\n', stderr);
		exit(EXIT_FAILURE);
	}
}

void aplicatia61()
{
	int n;
	printf("n=");scanf("%d",&n);
	err(n<=0||n>100, "n invalid: %d\n",n);
}

//aplicatia 6.3
void absN(int n,...)
{
	va_list va;
	va_start(va, n);
	
	for(int i=0; i<n; i++)
		{
			float *x = va_arg(va, float*);
			*x = fabs(*x);
		}
	va_end(va);
}

void aplicatia63()
{
	float x = -18, y = 9;
	absN(2, &x, &y);
	printf("%.2f %.2f\n", x, y);
}

//aplicatia 6.4
int crescator(int n, char tip, ...)
{
	va_list va;
	va_start(va, tip);
	switch(tip)
	{
		case 'd': {
			int elem1 = va_arg(va, int);
			for(int i=2; i<=n; i++)
				{
					int elem2 = va_arg(va, int);
					if(elem1 > elem2)
						{
							return 0;
							break;
						}
					elem1 = elem2;
				}
			return 1;
		}
		case 'f': {
			double ele1 = va_arg(va, double);
			for(int i=2; i<=n; i++)
				{
					double ele2 = va_arg(va, double);
					if(ele1 > ele2)
						{
							return 0;
							break;
						}
					ele1 = ele2;
				}
			return 1;
		}
	}
	va_end(va);
	return 1;
}

//aplicatia 65
void input(const char *fmt, ...)
{
	va_list va;
	va_start(va, fmt);
	
	while(*fmt){
		if(*fmt=='%')
		{
			fmt++;
			switch(*fmt)
			{
				case 'd': {
					int *num = va_arg(va, int*);
					scanf("%d", num);
					fgetc(stdin);
					break;
				}
				case 'c': {
					char *car = va_arg(va, char*);
					scanf("%c", car);
					fgetc(stdin);
					break;
				}
				case 'f': {
					double *fnum = va_arg(va, double*);
					scanf("%f", fnum);
					fgetc(stdin);
					break;
				}
			}		
		}
		fmt++;
	}
	va_end(va);
}

void aplicatia65()
{
	int n; char ch; float f;
	input("n=%d ch=%c f=%f", &n, &ch, &f);
	printf("n=%d, ch=%c, f=%f\n", n, ch, f);
}

//aplicatia 66

char *concat(int n,...)
{
	va_list args;
	va_start(args, n);
	
	char *sir = va_arg(args, char*);
	
	char *s = NULL, *p=NULL;
	if((p = malloc((strlen(sir)+2)*sizeof(char)))==NULL)
	{
		printf("Memorie insuf");
		exit(-1);
	}
	
	strcat(p, sir);
	strcat(p, " ");
	s=p;
	
	for(int i=2; i<=n; i++)
	{
		char *sir = va_arg(args, char*);
		if((p = realloc(p, (strlen(s)+strlen(sir)+4)*sizeof(char)))==NULL)
		{
			printf("uh oh");
			exit(-1);
		}
		strcat(p, sir);
		strcat(p, " ");
		s=p;
	}
	
	return s;
}

void aplicatia66()
{
	char *s;
	s = concat(3, "Ana", "are", "mere");
	printf("%s\n", s);
}

//aplicatia 67
int comune(int nVec, ...)
{
	va_list args;
	va_start(args, nVec);
	
	int *v1 = va_arg(args, int*);
	int dim1 = va_arg(args, int);
	int contor = 0, *ok=NULL;
	
	if((ok = malloc(sizeof(int)*(dim1+1)))==NULL)
		{
			printf("Memorie insuf");
			exit(-1);
		}
	
	for(int i=0; i<dim1; i++)
		ok[i]=0;
	
	for(int i=2; i<=nVec; i++)
	{
		int *v = va_arg(args, int*);
		int dim = va_arg(args, int);
			
		for(int k=0; k<dim1; k++)
		{ 
		int elem = v1[k];
		for(int j=0; j<dim; j++)
			if(v[j]==elem)
				{
				   ok[k]++;
				   break;//sa nu numere de 2 ori aceeasi valoare in caz ca se repeta
				 }
		}
		
	
	}
	for(int i=0; i<dim1; i++)
		if(ok[i]==nVec-1)
			contor++;
	va_end(args);
	return contor;
}

void aplicatia67()
{
	int v1[]={5, 8};
	int v2[]={8, 3, 5};
	int v3[]={5, 0, 8};
	printf("%d\n", comune(3, v1, 2, v2, 3, v3, 3));	
}

//aplicatia 68
void sortare(int n, ...)
{
	va_list args;
	va_start(args, n);
	
	int *v[n];
	
	for(int i=0; i<n; i++)
		v[i] = va_arg(args, int*);
		
	for(int i=0; i<n; i++)
		for(int j = i+1; j<n; j++)
			if(*v[i]>*v[j])
			{
				int aux = *v[i];
				*v[i] = *v[j];
				*v[j] = aux;
			}
			
	va_end(args);
}


//Stergere duplicate vector

void stergere_duplicate(int n, ...)
{
	va_list args;
	va_start(args, n);
	
	int *v=NULL;
	
	if((v = malloc(sizeof(int)*n))==NULL)
	{
		printf("Memorie insuficienta");
		exit(-1);
	}
	
	for(int i=0; i<n ; i++)
		v[i] = va_arg(args, int);
		
	for(int i=0; i<n; i++)
		for(int j=i+1; j<n; j++)
			if(v[i]==v[j])
			{
				for(int k=j; k<n; k++)
					v[k]=v[k+1];
				i--;
				n--;
			}
	for(int i=0; i<n; i++)
		printf("%d ", v[i]);
	printf("\n");
}


int main(void)
{
	stergere_duplicate(8, 1, 1, 3, 4, 3, 5, 6, 5);
}




