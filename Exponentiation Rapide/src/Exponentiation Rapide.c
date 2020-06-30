/*
 ============================================================================
 Name        : Exponentiation.c
 Author      : YousraMzouz
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
//fct qui permet de décomposer x en diviseur premier
unsigned long long int* diviseurpremier(unsigned long long int N){
	unsigned long long Diviseur[100],x=sqrt((unsigned long long int)N); unsigned long long int i=2,z=0;
	while(N>1){while(N%i == 0){  Diviseur[z]=i;	N=N/i;	z++;	}
		i++;	}

	//Affichage des diviseur de la base X
	printf("Les diviseurs de la base sont :");
	for(i=0;i<z;i++)
	{
	  printf("%llu\n",Diviseur[i]);
      fflush(stdout); }

	Diviseur[z]=0;//la derniere case on met 0

	return Diviseur;//la fct return l'addresse de la premiere valeur dans le tableau
	}
//la fct qui permet de faire le calcul (on n'a pas encore finaliser son code)
void calcul1(unsigned long long int V[],unsigned long long int T,unsigned long long int mod,int j){
	int i;	unsigned long long int p=1;	unsigned long long int cal[100];
	cal[j]=1;
		 		for(i=0;i<sizeof(V);i++)
		 		{
		 		p=pow(V[i],T);
		 		p=(p % mod);
		 		cal[j]=(p*cal[j]);
	}
			 	cal[j]=cal[j]%mod;
	printf("%lld",cal[j]);
	  fflush(stdout);

	}
int main(){
	 unsigned long long int x=3,y=94,mod=17;int n=0,count=0,j=0,i;	unsigned long long int* Bin;
 // printf("saisir x,y,mod tel que : x^y[mod]\n"); //scanf("%d",&y);
  //comment decomposer l'exposant en somme de puissance de deux :
  	Bin=(unsigned long long int*)malloc((n+1)*sizeof(unsigned long long int));//tableau dynamique
  	do{ Bin= (unsigned long long int*)realloc(Bin,(n+1)*sizeof(unsigned long long int));//Réallouer une case pour stocker la nouvelle valeur(0 ou 1)
	  Bin[n]=y%2;n++;y=y/2;
	  }while(y!=0);unsigned long long int T[n] ;
    for(i=0;i<n;i++){   if(Bin[i]==1){T[j]=pow(2,count);  j++;}count++; }
 //affichage de l'expossant Y sous forme de somme de puissance de 2
 printf("L'exposant en puissance de 2 est :\n");
  for(i=0;i<j;i++){
  printf("%llu\n",T[i]);
  fflush(stdout); }
//fin de décomposition

                            	printf("\n");  fflush(stdout);

//ici on essaye de décomposer x pour qu'il soit plus petit dans les calculs puisque la langage C ne supporte pas les nbres > à la taille de unsigned long long int
//On travaille sur ce programme il n'est pas 100% correcte
	unsigned long long int *tab,S[100];
	tab=diviseurpremier(x);//on a besoin de ce pointeur pour parcourir le tableau Diviseur de la fct calcul1
	 i=0;
    int w=0;//taille du tableau S
	while(*(tab+i) != 0) {
	S[w]=*(tab+i);//on stocke chaque valeur dans une nouvelle case du tableau S
	w++;
    i++;
	  }
	printf("\n");  fflush(stdout);
  	for(j=0;j<w;j++)
    calcul1(S,T[j],mod,j );



}
