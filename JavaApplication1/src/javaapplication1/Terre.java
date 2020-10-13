/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package javaapplication1;

import java.util.Scanner;

public final class Terre { // La classe est finale, car un singleton n'est pas censé avoir d'héritier.

	int age;
	int population;

	private Terre() {
            new Scanner(System.in);
            Scanner scan = new Scanner(System.in);
            s = scan.nextLine(); 
            scan.close();
	}
	    private static Terre instance = null;
            public String s; 
	    // Méthode statique qui sert de pseudo-constructeur (utilisation du mot clef "synchronized" pour le multithread).

	   public static synchronized Terre getInstance() {
	 
	     if(instance == null) {
	      instance = new Terre();  
	     }

	     return instance;	
}
}