
package javaapplication3;

import java.awt.List;
import java.util.ArrayList;


class Dossier implements Element {
ArrayList<Element> files = new ArrayList<Element>();


public Dossier(long l) {
	
	super();
}

public String getType() {

return "Fichier";

}

public void addFile(Element file) {

files.add(file);

}

public Long getTaille() {

Long size = 0L;

for (Element file : files) {

size = size + file.getTaille();

}

return size;

}


}
