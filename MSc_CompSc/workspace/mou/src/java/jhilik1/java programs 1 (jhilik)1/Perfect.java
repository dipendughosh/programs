import java.util.Scanner;
public class Perfect
{
	public static void main(String args[])
	{
		Scanner input = new Scanner(System.in);
		int number,i,sum=0;
		System.out.println("Enter the number");
		number=input.nextInt();
		for(i=1;i<number;i++)
		{
			if(number%i==0)
			sum=sum+i;
		}
		if(sum==number)
		System.out.println("The number is a perfect number");
		else
		System.out.println("The number is not a perfect number");
	}
}
