package java.bala.Basics1;
//Write a program to demonstrate comand line arguments
class cmdLn
{
    public static void main(String argv[])
    {
		int n=0;
		for(int i=0;i<argv.length;i++)
		{
            n=Integer.parseInt(argv[i]);
            System.out.println("argv["+i+"]="+n);
        }
	}
}
