/*
 ============================================================================
 Name        : Diffie Hellman.c
 Author      : YousraMzouz
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */


//Algorithme de Diffie Hellman (méthode de cryptographie(chiffrement-déchiffrement) qui se base sur l'exponentiation modulaire
//éxpliquée avec des exemples
#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#include <time.h>  //on appel cette bibliothèque car on doit utiliser rand();

//Fonction simple qui calcule a^b % mod  ( on va voir ce calcul avec d'autres méthodes prochainement qui impliqueet la prgram dynamique )
unsigned long long int EXP_NAIVE(unsigned long long int a,unsigned long long int b,unsigned long long int mod) //on utilise long long car les nbres peuvent etre très grands
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
  int premier (unsigned long int n){
  	int count=1,i;
  	if(n==1)count=0;
  	for(i=2;i<n;i++) {
        if(n%i==0)
        {
         count = 0;
         break;
         }}
         return count;
  }
    //imaginons que Alice et Bob voulaient communiquer de facon sécurisé un msg secret(chiffré)
  int main(){
 unsigned long long int n,g, x, a, y, b, ka, kb;  //definition des variables

  //les deux utilisateurs doivent choisir les meme n et g (public)
  printf("Entrer les valeurs choisis de n et de g :");
  fflush(stdout);
  scanf("%llu%llu",&n,&g);
  //n doit etre un grand nbre premier
  while((premier(n))==0){
  printf("le nombre n doit etre un nombre premier , RESAISIR: \n");
  fflush(stdout);
  scanf("%llu",&n);
  }

  //les valeurs que vous avez choisi
    printf("The value of n : %llu\n", n);
    printf("The value of g : %llu\n", g);
    fflush(stdout);

    // Alice choisi sa clé privé a(Il ne doit pas la communiquer à travers le reseau public alors Bob ne la connait pas
    a = rand(); // génere un nbre aleatoire
    printf("La cle privee de Alice:%llu\n", a);
    fflush(stdout);

    x = EXP_NAIVE(g, a, n); // la clé générée

    // Bob choisi de la meme manière sa clé privé b
    b = rand();
    printf("La cle privee de Bob: %llu\n\n", b);
    fflush(stdout);

    y = EXP_NAIVE(g, b, n); // la clé génerée

    // Géneration de la clé secrete après l'échange des clés générées
    ka = EXP_NAIVE(y, a, n); // clé secrete de Alice
    kb = EXP_NAIVE(x, b, n); // clé secrete de Bob

    printf("Secret key for the Alice is : %llu\n", ka);
    printf("Secret Key for the Bob is : %llu\n", kb);
    //c'est le nbre que Alice et bob doivent utiliser pour chiffrer et déchiffrer leurs messages sans avoir l'obligation
    //de le partager sur le reseau public (qui peut etre un canal non securisé)ce qui élimine les possibilités de décrypter leurs msgs par qqn malveillant

  }
