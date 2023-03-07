import java.util.Scanner;

public class CheckAmicable
{
	public static void main(String args[])
	{
		Scanner input = new Scanner(System.in);
		int number1,number2,sum1=0,sum2=0,i,j;
		System.out.println("Enter the two numbers");
 		number1=input.nextInt();
		number2=input.nextInt();
		for(i=1;i<=number1/2;i++)
		{
			if(number1%i==0)
			sum1=sum1+i;
		}
		for(j=1;j<=number2/2;j++)
		{
			if(number2%j==0)
			sum2=sum2+j;
		}
		if(sum1==number2&&sum2==number1)		
		System.out.println("The two numbers are Amicable");
		else
		System.out.println("The two numbers are not Amicable");
	}
}