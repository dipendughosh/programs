package java.sks.ControlFlowStatements1;
//Write a program to demonstrate the Enhanced For Loop in JAVA
class enForLoop
{
	public static void main(String argv[])
    {
		
		int x=0;
		int arr[]={49,93,85,73,82,8,27};
		System.out.println("Displaying Array elements using Enhanced For Loop:--------");
		for(int i:arr)
		{	
			++x;
			System.out.println("array["+x+"] = "+i);
		}
	}
}
