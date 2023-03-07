class IntegerDemo
{
	public static void main(String args[])
	{
		int y1,y2;
		long x1,x2;
		short m1,m2;
		byte n1,n2;
		x1=-9223372036854775808L;
		x2=9223372036854775807L;
		System.out.println("\n There are four variations of Integers :");
		System.out.println(" 1. long\n 2. int\n 3. short\n 4.byte");
		System.out.println("long ranges from "+x1+ "to " +x2);
		y1=-2147483648;
		y2=2147483647;
		System.out.println("int ranges from"+y1 + "to" +y2);
		m1=-32768;
		m2=32767;
		System.out.println("short ranges from" + m1 + "to" + m2);
		n1=-128;
		n2=127;
		System.out.println("byte ranges from" +n1+ " to " +n2);
	}
}