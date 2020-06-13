/*
 ============================================================================
 Name        : AlgGamal.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

//Fonction simple qui calcule a^b % mod  ( on va voir ce calcul avec d'autres méthodes prochainement qui impliqueet la prgram dynamique )
long long int EXP_NAIVE(long long int a,long long int b,long long int mod) //on utilise long long car les nbres peuvent etre très grands
  {
  long long int t;
  if(b==1)
  return a;
  if(b%2==0)       // si l'exposant est paire
  {

  t=EXP_NAIVE(a,b/2,mod);   // appel récurssif de la fonction qu'on va étudier sa compléxité plus tard
  return ((t*t)%mod);
  }

  else          //si l'exposant est impaire on prend un exemple :

  {
  t=EXP_NAIVE(a,b-1,mod);
  return (((a%mod)*t)%mod );
  }

  /*   Exemple Clarifiant :
   5^3 % 2 = ( 5%2 * 5^2%2 ) % 2 = ( 1 * ((5^1%2 * 5^1%2))%2 ) % 2 = ( 1 * (1 * 1)% 2 ) % 2 = (1 *1)% 2 = 1
  */
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
			if (EXP_NAIVE(a, i, p) == 1 && i < p - 1) {
				flag = 0;
			}
			else if (flag && EXP_NAIVE(a, i, p) == 1 && i == p - 1) {
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

  /* Create equal size buckets all in a row, then fire randomly towards
   * the buckets until you land in one of them. All buckets are equally
   * likely. If you land off the end of the line of buckets, try again. */
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
	    kb=EXP_NAIVE(g, kp, p); // clé publique de Bob
	    i=rand_interval(p-2);

	    ke=EXP_NAIVE(g, i, p);// clé temporaire d'Allice
	    kma=EXP_NAIVE(kb, i, p);// clé de masque d'Allice
	    printf("Le message kma est: %lld\n",kma);
	    // chiffrement de message
	    y=1698888999999*EXP_NAIVE(kb, i, p);
	    printf("Le message crypté est: %lld\n",y );
	    // dechifrement
	    kmb=EXP_NAIVE(ke, kp, p);
	    printf("Le message kmb est: %lld\n",kmb );
	    x=y/EXP_NAIVE(ke, kp, p);
	    printf("Le message decrypté est: %lld\n",x );
    	long long int a,b,mod,t;
	    printf("saisir a,b,mod:");
	    fflush(stdout);
	    scanf("%lld %lld %lld",&a,&b,&mod);
	    t=EXP_NAIVE(a,b,mod);
	    fflush(stdout);
	    printf("le résultat est:%lld",t);
	    fflush(stdout);
	    return 0;
}
