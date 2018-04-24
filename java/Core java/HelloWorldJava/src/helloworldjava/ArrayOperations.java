package helloworldjava;

import java.io.*;
import java.lang.*;

public class ArrayOperations {
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
        
        try {
            int arr[] = {5,0,1,2};
            try{
                int x = arr[3] / arr[1];
            }
            catch(ArithmeticException ae) {
                System.out.println("Divide by 0");
            }
            int y = arr[4];
        }
        catch(ArrayIndexOutOfBoundsException aiob) {
            System.out.println("Array Index Out of Bounds");
        }
    }
}