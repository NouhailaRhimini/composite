
package javaapplication3;

class Fichier implements Element {
private Long size;


public Fichier(Long size) {
this.size = size;

}


public String getNom() {
return "Fichier";
}

public Long getTaille() {
return this.size;
}


}

