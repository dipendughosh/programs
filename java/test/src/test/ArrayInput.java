package test;

import java.util.Scanner;

public class ArrayInput {

	public ArrayInput() {
		// TODO Auto-generated constructor stub
	}

	public static void main(String[] args) {

	    /*Scanner s=new Scanner(System.in);
	    System.out.println("enter number of elements");
	    int n=s.nextInt();
	    int arr[]=new int[n];
	    System.out.println("enter elements");
	    for(int i=0;i<n;i++){//for reading array
	        arr[i]=s.nextInt();
	    }
	    for(int i: arr){ //for printing array
	        System.out.println(i);
	    }*/
		System.out.println("Enter the size of elements: ");
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
		int a[]=new int[n];
	    System.out.println(n);
        
        System.out.println("Enter the Elements: ");
        for(int i=0;i<n;i++)
        {
            System.out.println("a["+i+"]=");
            a[i]=sc.nextInt();
         }
	}
}
