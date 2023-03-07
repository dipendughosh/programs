package java.sks.Basics1;
//Write a program to to demonstrate character variables in JAVA also show that in ceratin situations they behave like integers
class chrctr
{
	public static void main(String argv[])
    {
		char a1='a',a2=65;
		System.out.println("The value of a1 is = "+a1);
		System.out.println("The value of a2 is = "+a2);
		System.out.println("Character variables sometimes behaves like Integers = ");
		a1++;
		a2++;
		System.out.println("The value of a1++ is = "+a1);
		System.out.println("The value of a2++ is = "+a2);
	}
}