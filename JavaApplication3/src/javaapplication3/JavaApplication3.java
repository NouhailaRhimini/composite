package javaapplication3;
public class JavaApplication3 { 

                public static void main(String[] args) {
		Fichier child1 = new Fichier(100L);
		Fichier child2 = new Fichier(200L);

		Dossier root= new Dossier(100L);
		root.addFile(child1);
		root.addFile(child2);

		System.out.println(child1.getTaille());      // output : 100
		System.out.println(root.getTaille());    // output : 300
	}   
    }

