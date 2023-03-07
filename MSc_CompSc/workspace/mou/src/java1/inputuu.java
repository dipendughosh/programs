package java1;
import java.util.Scanner;

class inputuu
{
	public static void main(String argv[])
    {
		Scanner in = new Scanner(System.in);
		int intNumber=0;
		float floatNumber=0.0f;
		System.out.print("Enter Integer Value: ");
		intNumber=in.nextInt();
		System.out.print("Enter Float Value: ");
		floatNumber=in.nextFloat();
		System.out.println("intNumber = "+intNumber);
		System.out.println("floatNumber = "+floatNumber);	
	}
}