package java.bala.Basics1;
//Write a program that will declare an integer type of array and display its values initialized at compiled time individually 
class runTimeArrIn
{
	public static void main(String argv[])
    {
		int []a = {3,1,4,1,5,9};
		int b[] = {78,98,63,25,54,49};
		System.out.println("\nUsing enhanced for loop feature");
		for(int i:a)
			System.out.print(i+"\t");
		System.out.println("\nUsing .length feature");
		for(int i=0;i<b.length;i++)
			System.out.println("b["+i+"] = "+b[i]);
	}
}
