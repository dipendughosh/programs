//Searching an element from a given set of data
#include<stdio.h>
#include<conio.h>

void main()
{       //Declaring Variables and Functions
	int a[100],n,trgt,i,c,loc;
	int linear(int [],int,int);
	int binary(int [],int,int);
	clrscr();
	//Entering the data
	printf("Enter size of array - ");
	scanf("%d",&n);
	printf("Enter elements of array-\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	//The element to be searched
	printf("Enter target - ");
	scanf("%d",&trgt);
	//Choseing the type of search
	printf("\tMENU\n");
	printf("\t1.Linear Search\n");
	printf("\t2.Binary Search\n");
	printf("\t3.Exit\n");
	printf("Enter choice - ");
	scanf("%d",&c);
	switch(c)
	{	case 1:
			loc=linear(a,n,trgt);
			break;
		case 2:
			loc=binary(a,n,trgt);
			break;
		case 3:
			exit(0);
		default:
			printf("\nWrong Input");
			break;
	}
	if(loc==-1)
		printf("\n%d not found",trgt);
	else
		printf("\n%d found at %d position",trgt,loc);
	getch();
}












//Linear search method function
int linear(int b[],int m,int t)
{	int i,loc=-1;
	//Linear search logic
	for(i=0;i<m;i++)
	{	if(b[i]==t)
		{	loc=i+1;
			return(loc);
		}
	}
	return(loc);
}

//Binary search function
int binary(int b[],int m,int t)
{	int low=0,high=m-1,mid,loc=-1;
	//Binary search logic
	while(low!=high)
	{	mid=(low+high)/2;
		if(b[mid]==t)
		{	loc=mid+1;
			return(loc);
		}
		else if(b[mid]>t)
			high=mid;
		else if(b[mid]<t)
			low=mid;
	}
	return(loc);
}



























Searching programs

Output:-

Set 1:-

Enter size of array - 10                                      
Enter elements of array-                                    
87                                                                       
45                                                                       
24                                                                       
14                                                                       
87                                                                       
35                                                                       
20                                                                       
5                                                                         
8                                                                         
48                                                                       
Enter target - 5                                                   
        MENU                                                        
        1.Linear Search                                           
        2.Binary Search                                           
        3.ExitEnter choice - 1                                  
5 found at 8                                                          

Set 2:-

Enter size of array - 10                                        
Enter elements of array-                                      
29                                                                         
45                                                                         
64                                                                         
69                                                                         
74                                                                         
83                                                                         
89                                                                         
94                                                                         
99                                                                         
104                                                                       
Enter target - 89                                                   
        MENU                                                          
        1.Linear Search                                             
        2.Binary Search                                             
        3.Exit                                                             
Enter choice - 2                                                     
89 found at 7 position                                                        

