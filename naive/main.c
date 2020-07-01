#include <stdio.h>
#include <stdlib.h>

// fonction qui commence par 1 multiplié par x puis , elle prend le résultat modulo mod, ensuite elle répète cette dernière opération y fois
unsigned long long int ExpNaiv(unsigned long long int x,unsigned long long int y,unsigned long long int mod){
    unsigned long long int r=1,c=1;
    while (c<y+1)
    {    r=((r%mod)*(x%mod))%mod;
         c= c+1;
    }
    return r;}
int main() {
    unsigned long long int x,y,mod;
    printf("Entrer les valeurs choisis de x et y et mod  : "); 
    scanf("%llu,%llu,%llu",&x,&y,&mod);
    printf("%llu",ExpNaiv(x,y,mod));

}

