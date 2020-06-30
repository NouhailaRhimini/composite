/*
 ============================================================================
 Name        : AlgGamal.cuthor      
 Version     :IKBANE Imane
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
unsigned long long int Secondaire(unsigned long long int t,unsigned long long int k,unsigned long long  int* q,unsigned long long int* p)//on utilise long long car les nbres peuvent etre très grands
{//on utilise des pointeurs pour pour agir sur la valeur de la variable on mémoire
	if (t == 1)
		*q = (*q * (*p)) % k;

	*p = (*p) * (*p) % k; 
}

unsigned long long int EXP_RAPIDE(unsigned long long int x,unsigned long long int y, unsigned long long int mod)
{
    unsigned long long int var,resultat = 1;//la variable resultat ou on stocke le calcul
    

	while (y > 0)//tant que l'expossant est strictement possitif on refait le calcul
	{
		var = y % 2;  //var est une variable locale temporaire
		Secondaire(var, mod, &resultat, &x);//Appel de la fct précedamant définie
		y = y / 2;
	}

	return resultat;
}
//fonction qui detecte si un nbre est premier ou pas
long long int premier (long long int n){
	int count=1,i;
	for(i=2;i<n;i++) {
      if(n%i==0)
      {
       count = 0;
       break;
       }}
       return count;
}

  long long int gcd(long long int a, long long int b){
    if(b == 0)
        return a;
    return gcd(b,a%b);

}
long long int PrimitiveRoot(long long int p)
{
	int flag;
	for (long long int a = 2; a < p; a++)
	{
		flag = 1;
		for (int i = 1; i < p; i++) {
			if (EXP_RAPIDE(a, i, p) == 1 && i < p - 1) {
				flag = 0;
			}
			else if (flag && EXP_RAPIDE(a, i, p) == 1 && i == p - 1) {
				return a;
			}
		}
	}
}

long long int rand_interval(long long int max)
{
  int r;
  const  long int range = 1 + max -2;
  const  long int buckets = RAND_MAX / range;
  const  long int limit = buckets * range;

  do
  {
      r = rand();
  } while (r >= limit);

  return 2 + (r / buckets);
}


//Génération des clés

//le message est le nombre à chiffrer avec la clé publique et la clé privée

int main(){
	 long long int p,g,kp,kb,i,ke,x,kma,kmb,y;

	  printf("Entrer une valeur d'un nombre entier p : ");
	  fflush(stdout);
	  scanf("%lld",&p);

	  //p et q doivent etre des nombres premiers
	  while(premier(p)==0){
	  printf("le nombre p doit etre un nombre premier , RESAISIR: \n");
	  fflush(stdout);
	  scanf("%lld",&p);
	  }

	    printf("The value of p : %lld\n", p);
	    fflush(stdout);
	    g=PrimitiveRoot(p);
	    kp=rand_interval(p-2);
	    // clé privée de Bob
	    kb=EXP_RAPIDE(g, kp, p); // clé publique de Bob
	    i=rand_interval(p-2);

	    ke=EXP_RAPIDE(g, i, p);// clé temporaire d'Allice
	    kma=EXP_RAPIDE(kb, i, p);// clé de masque d'Allice
	    printf("La clé kma est: %lld\n",kma);
	    // chiffrement de message
	    long long int msg;
	    do{printf("Entrer votre message(le message ne doit pas dépasser la valeur 1698888999999:");
	    scanf("%llu",&msg);
	    }
	    while(msg>=1698888999999);
	    y=msg*EXP_RAPIDE(kb, i, p);
	    printf("Le message crypté est: %lld\n",y );
	    // dechifrement
	    kmb=EXP_RAPIDE(ke, kp, p);
	    printf("La clé kmb est: %lld\n",kmb );
	    x=y/EXP_RAPIDE(ke, kp, p);
	    printf("Le message decrypté est: %lld\n",x );
	    return 0;
}
