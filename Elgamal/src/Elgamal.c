/*
 ============================================================================
 Name        : Elgamal.c
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

int main(){
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


