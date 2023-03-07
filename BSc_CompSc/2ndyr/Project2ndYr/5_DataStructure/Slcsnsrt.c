//Selection sort
#include<stdio.h>
#include<conio.h>


void main()
{       //Declaring Variables and Functions
	int i,a[20],n;
	void sel_srt(int [],int);
	clrscr();
	printf("Enter number of elements:-");
	scanf("%d",&n);
	printf("Enter elements:-\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	//Calling the Selection sort function
	sel_srt(a,n);
	//Displaying the sorted array
	printf("\nArray after sorting:-\n");
	for(i=0;i<n;i++)
		printf("%d\t",a[i]);
	getch();
}

//Selection sort function is defined
void sel_srt(int a[],int n)
{       //Declaring Variables
	int i,j,pos,min;
	//Selection sort logic
	for(i=0;i<n;i++)
	{	min=a[i];
		pos=i;
		for(j=i+1;j<n;j++)
		{	if(min>a[j])
			{	min=a[j];
				pos=j;
			}
		}
		a[pos]=a[i];
		a[i]=min;
	}
}
 














Selection Sort

Output:-

Enter number of elements:-10                               
Enter elements:-                                                     
89                                                                           
57                                                                           
68                                                                           
94                                                                           
4                                                                             
32                                                                            
15                                                                            
105                                                                          
78                                                                            
34                                                                           

Array after sorting:- 
4       15      32      34      57      68      78      89      94      105
                                                                              
