package java.sks.Basics1;
//Write a program to demonstrate pre-increment and post-increment operation with an integer.Also perform decrement operation in the same way
class postpreInDe
{
	public static void main(String argv[])
    {
		int intNumber;
		intNumber=198236;
		System.out.println("Before Post-Increment --- "+intNumber+"\nAfter Post-Increment --- "+(intNumber++));
		System.out.println("Before Pre-Increment --- "+intNumber+"\nAfter Pre-Increment --- "+(++intNumber));
		intNumber=937464;
		System.out.println("Before Post-Decrement --- "+intNumber+"\nAfter Post_Decrement ---"+(intNumber--));
		System.out.println("Before Pre-Decrement --- "+intNumber+"\nAfter Pre_Decrement ---"+(--intNumber));
	}
}
