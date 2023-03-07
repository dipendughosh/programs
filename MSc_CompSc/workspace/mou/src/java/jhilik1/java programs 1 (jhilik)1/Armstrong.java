import java.util.Scanner;
public class Armstrong
{
	public static void main(String args[])
	{
		Scanner input = new Scanner(System.in);
		int number,k,d,s=0;
		System.out.println("Enter the number");
		number=input.nextInt();
		k=number;
		while(number>0)
		{
		d=number%10;
		s=s+(d*d*d);
		number=number/10;
		}
		if(k==s) 
		System.out.println("The number is an Armstrong number");
		else
		System.out.println("The number is not an Armstrong number");

	} 
}