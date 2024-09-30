#include<stdio.h>
#include<stdarg.h>
#include<stdlib.h>
#include<string.h>

float *allocVec(int n, ...)
{
	va_list va;
	va_start(va, n);
	
	float *vector = NULL;
	
	if((vector = (float*)malloc(n*sizeof(float)))==NULL)
	{
		printf("eroare");
		va_end(va);
	}
	
	for(int i=0; i<n; i++)
	{
		vector[i] = va_arg(va, double);
	}
	va_end(va);
	return vector;
}

void absN(int n, ...)
{
	va_list va;
	va_start(va, n);
	float *ptr;
	
	for(int i=0; i<n; i++)
	{
		ptr = va_arg(va, float*);
		*ptr = (-1)* (*ptr); 
	}
	va_end(va);
}

int crescator(int n,  char tip, ...)
{
	va_list va;
	va_start(va, tip);
	
	switch(tip)
	{
		case 'd':
		{
			int *v=NULL;
			if((v=(int*)malloc(n*sizeof(int)))==NULL)
			{
				printf("err");
				va_end(va);
			}
			for(int i=0; i<n; i++)
				v[i] = va_arg(va, int);
				
			for(int i=0; i<n; i++)
				for(int j=i+1; j<n; j++)
					if(v[i]>v[j])
						return 0;
			return 1;
		}
		case 'f':
		{
			float *v=NULL;
			if((v=(float*)malloc(n*sizeof(float)))==NULL)
			{
				printf("err");
				va_end(va);
			}
			for(int i=0; i<n; i++)
				v[i] = va_arg(va, double);
				
			for(int i=0; i<n; i++)
				for(int j=i+1; j<n; j++)
					if(v[i]>v[j])
						return 0;
			return 1;
		}
	}
}

void input(const char *fmt, ...)
{
	int *ptr1;
	float *ptr2;
	char *ptr3;
	
	va_list va;
	va_start(va, fmt);
	
	for(int i=1; i<strlen(fmt); i++)
	{
		if(fmt[i-1] == '%')
		{
			switch(fmt[i])
			{
				case 'd':
				{
					ptr1 = va_arg(va, int*);
					scanf("%d", ptr1);
					break;
				}
				case 'f':
				{
					ptr2 = va_arg(va, float*);
					scanf("%f", ptr2);
					break;
				}
				case 'c':
				{
					ptr3 = va_arg(va, char*);
					scanf("%c", ptr3);
					break;
				}
				
			}
		}
	}
	va_end(va);
}

void pb5()
{
	int n; char ch;
	input("n=%dch=%c", &n, &ch);
	printf("%d %c\n", n, ch);
}

char *concat(int n, ...)
{
	va_list va;
	va_start(va, n);
	
	char *string;
	char *new_string;
	
	string = va_arg(va, char*);
	new_string = (char*)malloc((strlen(string)+1)*sizeof(char));
	strcpy(new_string, string);
	strcat(new_string, " ");
	
	for(int i=1; i<n; i++)
	{
		string = va_arg(va, char*);
		new_string = realloc(new_string, (strlen(string)+1)*sizeof(char));
		strcat(new_string, string);
		strcat(new_string, " ");
	}
	va_end(va);
	return new_string;
}

void pb6()
{
	char *str = concat(3, "Ana", "are", "mere");
	printf("%s\n", str);
}

int comune(int nVec, ...)

int main()
{
	pb6();	
}
