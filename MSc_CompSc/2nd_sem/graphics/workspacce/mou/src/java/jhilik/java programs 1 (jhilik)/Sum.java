import java.util.Scanner;
public class Sum
{
	public static void main(String args[])
	{
	Scanner input = new Scanner(System.in);	
	int range,number,sum=0,i;
	System.out.println("Enter the range");
	range=input.nextInt();
	for(i=1;i<=range;i++)
	{
		System.out.println("Enter the number");	
		number=input.nextInt();
		sum=sum+number;
	}
	System.out.println("The sum is:"+sum);
	}
}