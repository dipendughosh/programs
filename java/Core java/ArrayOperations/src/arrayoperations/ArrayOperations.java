/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package arrayoperations;

/**
 *
 * @author DiGhosh
 */
public class ArrayOperations {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        String[] names = new String[3];
        names[0] = "Blues Shirt";
        names[1] = "Red Shirt";
        names[2] = "Black Shirt";
        int[] numbers = {100,200,300};
	
        for (String name:names) {
            System.out.println("Name :" + name);
        }
        for (int number :numbers) {
            System.out.println("Number :" + number);
        }
        
        char[] charname1 = {'T','e','s','t','S','t','r','i','n','g'};
        int len = charname1.length;
        char[] charname2 = new char[len];

        
        for (int i = 0, j = (len-1); i < len; i++, j--) {
            charname2[j] = charname1[i];
        }
        //for 
        System.out.print("Original : ");
        System.out.print(charname1);
        System.out.print(" Reversed : ");
        System.out.println(charname2);
    }
    
}
