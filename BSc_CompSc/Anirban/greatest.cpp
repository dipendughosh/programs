# include <stdio.h>
# include <conio.h>
void main()
{
	int r=0,s=0,a=0,max=0,min=0;
	printf("enter the three ages");
	scanf("%d%d%d",&r,&s,&a);
		if(r>s)
			{
				if(r>a)
				{
					max=r;
				}
				else
				{
					max=a;
					min=s;
				}
			}
		else
			{
				if (s>a)
					{
						max=s;
					 }
				else
				  {
					 max=a;
					 min=r;
				  }
			}
	 printf("greatest is %d the smallest is %d",max,min);
	 getch();
}