
package javaapplication3;

import java.awt.List;
import java.util.ArrayList;


class Dossier implements Element {
ArrayList<Element> listeElts = new ArrayList<Element>();


public Dossier(long l) {
	
	super();
}

public String getNom() {

return "Dossier";

}

public void addFile(Element file) {

listeElts.add(file);

}

public Long getTaille() {

Long size = 0L;

for (Element file : listeElts) {

size = size + file.getTaille();

}

return size;

}


}
