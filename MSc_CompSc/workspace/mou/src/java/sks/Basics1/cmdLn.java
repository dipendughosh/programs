package java.sks.Basics1;
//Write a program to demonstrate comand line arguments
class cmdLn
{
    public static void main(String argv[])
    {
		int n=0;
		if(argv.length == 0)
			System.out.println("No arguments passed");
		for(int i=0;i<argv.length;i++)
		{
            n=Integer.parseInt(argv[i]);
            System.out.println("argv["+i+"]="+n);
        }
	}
}
