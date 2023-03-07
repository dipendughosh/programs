       /* KRISHNAMURTY NUMBER BETWEEN TWOGIVEN RANGE */

#include<stdio.h>
#include<conio.h>
void main()
{
int n1,n2,r,f,a,t,i,s;
clrscr();
	printf("enter the two numbers n1,n2:   ");
	scanf("%d%d",&n1,&n2);
	for(i=n1;i<=n2;i++)
		{
		t=i;
		s=0;
		while (t>0)
			{
			r=t%10;
			t=t/10;
			for(f=1,a=r;a>0;a--)
			    f=f*a;
			s=s+f;
			}
		if(i==s)
			printf("\n %d is a krishnamurti no.\n",i);
		} /* end of for loop */
	getch();
    }
