public class EnhancedForDemo
{
	public static void main(String args[])
	{
		int sum=0;
		int[] numbers={1,2,3,4,5};
		for(int i : numbers)
		{
			sum=sum+i;
		}
	System.out.println("The sum is:"+sum);
	}
}	