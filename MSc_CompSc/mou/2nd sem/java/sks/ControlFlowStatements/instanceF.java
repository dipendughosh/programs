//Write a program that will demonstrate instanceOf operator in JAVA
class x
{
	x()
	{
	}
}
class y
{
	y()
	{
	}
}
class instanceF
{
	public static void main(String argv[])
    {
		x ob1 = new x();
		y ob2 = new y();
		if( ob1 instanceof x)
			System.out.println("ob1 is instance of x ");
		if( ob2 instanceof y)
			System.out.println("ob2 is instance of y ");
	}
}
