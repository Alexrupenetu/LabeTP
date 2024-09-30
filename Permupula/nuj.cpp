#include <fstream>
#include<iostream>
#include <cstring>
using namespace std;
ofstream fout("p2.out");

int P[11],X[11],n;
char s[12];

void afis()
{
    for(int i=1;i<=n;i++)
        fout<<s[X[i]-1];
    fout<<endl;
}

void back(int k)
{
    for(int i=1;i<=n;i++)
        if(!P[i])
        {
            P[i]=1;
            X[k]=i;
            if(strchr("aeiou",s[i-1])!=0 || X[k]==k) //vocala sau punct fix
                if(k==n) afis();
                else back(k+1);
            P[i]=0;
        }
}

int main()
{
    cin>>s;
    n=strlen(s);
    back(1);
    return 0;
}


