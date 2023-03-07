//Write a program to demonstrate Boolean variable in JAVA and also show that they are compatible with relational operators
class boolen
{
	public static void main(String argv[])
    {
		boolean state;
		state=false;
		System.out.println("The state now is "+state);
		state=true;
		System.out.println("The state now is "+state);
		System.out.println("A boolean variable can contain the branching statement");
		if(state)
			System.out.println("TRUE");
		System.out.println("Outcome of Relational Operator is boolean");
		System.out.println("12>9\t"+(12>9));
		System.out.println("12<9\t"+(12<9));
	}
}