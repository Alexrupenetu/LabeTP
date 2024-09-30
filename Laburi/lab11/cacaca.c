/*#include <stdio.h>
#include <stdlib.h>

void tiparire(int sol[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", sol[i]);
    printf("\n");
}

int valid(int pas, int sol[]) {
    for(int i =0; i<pas; i++){
        if(sol[i] == sol[pas]){
            return 0;
        }
    }
    return 1;
}

int solutie(int v[], int pas, int n) {
    if (pas == n - 1)
   {
   int mij = (n+1)/2;
   
   for(int i=1; i<mij && i<n; i++)
   	if(v[i-1] < v[i])
   		return 0;
   		
   int j;
   if(n%2==0)
   	j = mij+1;
   else
   	j = mij;
   	
   while(j<n)
   	{
   		if(v[j-1]>v[j])
   			return 0;
   	}
    return 1;
    }
    return 0;
}

void back(int pas, int sol[], int n) {
    for (int i = 1; i <= n; i++) {
        sol[pas] = i;
        if (valid(pas+1, sol)){
            if (solutie(sol, pas, n))
                tiparire(sol, n);
            else
                back(pas + 1, sol, n);    
        }
    }
}

int main() {
    int sol[100];
    int n = 5;
    back(0, sol, n);
}
*/

#include<stdio.h>
#include<stdlib.h>

void afisare(int v[100],int n)
{
  for(int i=0;i<n;i++)
      printf("%d ",v[i]);
  printf("\n");
}

int valid(int v[100],int size,int n)
{
 //Verificam sa nu avem elemente duplicat
  for(int i=0; i<size; i++)
    for(int j=i+1; j<size; j++)
      if(v[i]==v[j])
	return 0;
	
  int mij=(n+1)/2;
  
  
  for(int i=1; i<mij && i<size; i++)
    if(v[i-1]<v[i])
      return 0;
      
  int j=0;
  
  if(n%2==0)
      j=mij+1;
  else
      j=mij;
      
  while(j<size)
  {
    if(v[j-1]>v[j])
      return 0;
    j++;
  }
  return 1;
}

int solutie(int k,int n)
{
  if(k==n-1)
    return 1;
  return 0;
}
void back(int k,int n,int v[100])
{
  for(int i=1;i<=n;i++)
    {
      v[k]=i;
      if(valid(v,k+1,n))
	{
	  if(solutie(k,n))
	    afisare(v,n);
	  else
	    back(k+1,n,v);
	}
    }
}
int main()
{
  int v[100];
  back(0,5,v);
  return 0;
}

