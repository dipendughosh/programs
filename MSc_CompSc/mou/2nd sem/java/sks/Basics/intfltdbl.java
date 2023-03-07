//Write a program that will take int,float and double values given by user and display them
import java.util.Scanner;
class intfltdbl
{
	public static void main(String argv[])
    {
		Scanner in = new Scanner(System.in);
		int intNumber=0;
		float floatNumber=0.0f;
		double doubleNumber=0.0;
		System.out.print("Enter Integer Value: ");
		intNumber=in.nextInt();
		System.out.print("Enter Float Value: ");
		floatNumber=in.nextFloat();
		System.out.print("Enter Double Value: ");
		doubleNumber=in.nextDouble();			
        System.out.println("intNumber = "+intNumber);
		System.out.println("floatNumber = "+floatNumber);	
		System.out.println("doubleNumber = "+doubleNumber);	
	}
}