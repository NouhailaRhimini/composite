//Algorithme de Diffie Hellman (méthode de cryptographie(chiffrement-déchiffrement) qui se base sur l'exponentiation modulaire
//éxpliquée avec des exemples
#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#include <time.h>  //on appel cette bibliothèque car on doit utiliser rand();

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
//Fonction qui permet la génération de g (groupe cyclique)
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
    //imaginons que Alice et Bob voulaient communiquer de facon sécurisé un msg secret(chiffré)
  int main(){
 unsigned long long int n,g, x, a, y, b, ka, kb;  //definition des variables

  //les deux utilisateurs doivent choisir les meme n et g (public)
  printf("Entrer les valeurs choisis de n et de g :");
  fflush(stdout);
  scanf("%llu",&n);
     //n doit etre un grand nbre premier
   while((premier(n))==0){
  printf("le nombre n doit etre un nombre premier , RESAISIR: \n");
  scanf("%llu",&n);  fflush(stdout);

  }
   //Génération du nombe génerateur g :
	    g=PrimitiveRoot(n);
  

  //les valeurs que vous avez choisi
    printf("The value of n : %llu\n", n);
    printf("The value of g : %llu\n", g);
    fflush(stdout);
    srand(time(NULL));
    // Alice choisi sa clé privé a(Il ne doit pas la communiquer à travers le reseau public alors Bob ne la connait pas
    a = rand(); // génere un nbre aleatoire
    printf("La cle privee de Alice:%llu\n", a);
    fflush(stdout);

    x = EXP_RAPIDE(g, a, n); // la clé générée

    // Bob choisi de la meme manière sa clé privé b
    b = rand();
    printf("La cle privee de Bob: %llu\n\n", b);
    fflush(stdout);

    y = EXP_RAPIDE(g, b, n); // la clé génerée

    // Géneration de la clé secrete après l'échange des clés générées
    ka =EXP_RAPIDE(y, a, n); // clé secrete de Alice
    kb = EXP_RAPIDE(x, b, n); // clé secrete de Bob

    printf("Secret key for the Alice is : %llu\n", ka);
    printf("Secret Key for the Bob is : %llu\n", kb);
    //c'est le nbre que Alice et bob doivent utiliser pour chiffrer et déchiffrer leurs messages sans avoir l'obligation
    //de le partager sur le reseau public (qui peut etre un canal non securisé)ce qui élimine les possibilités de décrypter leurs msgs par qqn malveillant

  }
