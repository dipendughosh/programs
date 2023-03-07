import java.util.Scanner;

public class LucasSeq
{
	public static void main(String args[])
	{
		Scanner input = new Scanner(System.in);
		int range,a=2,b=1,c=0;
		System.out.println("Enter the range");
		range= input.nextInt();
		System.out.println("The sequence is as follows : ");
		System.out.println(a);
		System.out.println(b);
		for(int i=3;i<=range;i++)
		{
			c=a+b;
			System.out.println(c);
			a=b;
			b=c;
		}
	}
}			
			
		
		
		
		