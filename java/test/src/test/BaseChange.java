package test;

import java.util.Scanner;

public class BaseChange {

	int deci;
	int bin;

	public BaseChange(int d, int b) {
		deci=d;
		bin=b;
	}

	public static void main(String[] args) {
		int decimal;
		int bin;
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter decimal integer: ");
		decimal = sc.nextInt();
		System.out.print("Enter binary number : ");
		bin= sc.nextInt();
		BaseChange ob=new BaseChange(decimal,bin);
		ob.convertD2B(decimal);
		int size=0;

		int n=ob.convertB2D(bin,size);
		System.out.println("The decimal equivalent is: "+n);

	}
	public static void convertD2B(int num) {
		if (num > 0) {
			convertD2B(num / 2);
			System.out.print(num % 2 + " ");
		}
	}

	public static int convertB2D(int bin,int size) {
		if (bin == 0) {
			return 0;
		}
		else {
			//int s=0
			return bin % 10* (int) Math.pow(2, size) + convertB2D((int) bin / 10,size+1);
		}
	}

}
