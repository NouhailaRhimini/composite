
package javaapplication3;

class Fichier implements Element {
private Long taille;


public Fichier(Long taille) {
this.taille = taille;

}


public String getNom() {
return "Fichier";
}

public Long getTaille() {
return this.taille;
}


}

