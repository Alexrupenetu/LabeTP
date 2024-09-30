#include<stdio.h>
#include<string.h>

void afisare_numar(int n)
{
	if(n<0 || n>=1000)
	{
		printf("Eroare: n apartine [0, 999]");
		return;
	}
	
	char *unitati[] = {"zero", "unu", "doi", "trei", "patru", "cinci", "sase", "sapte", "opt", "noua"};
	char *zeci[] = {"", "zece", "douazeci", "treizeci", "patruzeci", "cincizeci", "saizeci", "saptezeci", "optzeci", "nouazeci"};
    	char *sute[] = {"", "o suta", "doua sute", "trei sute", "patru sute", "cinci sute", "sase sute", "sapte sute", "opt sute", "noua sute"};
    	
    	int u = n%10;
    	int z = n/10%10;
    	int s = n/100;
    	
    		
    	printf("%s", sute[s]);
    	
    	if(n == 0)
    		printf("zero");
    	else if(n>=10 && n<=19)
    	{
    	switch(n)
    	{
    		case 10:
    			printf("zece");
    		case 11: 
    			printf("unsprezece");
    		case 12:
    			printf("doisprezece");
    		case 13:
			printf("treisprezece");
		case 14: 
			printf("patrusprezece");
		case 15:
			printf("cincisprezece");
		case 16:
			printf("saisprezece");
		case 17:
			printf("saptesprezece");
		case 18:
			printf("optsprezece");
		case 19:
			printf("nouasprezece");
    	}
    	}
    	else
    	{
    		printf(" %s", zeci[z]);
    		if(u!=0)
    			printf(" si %s", unitati[u]);
    	}
    	
    	printf("\n");

}

int main()
{
	afisare_numar(999);
}
