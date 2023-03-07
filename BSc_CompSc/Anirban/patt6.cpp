# include <stdio.h>
# include <conio.h>
int main()
{
int h=0,i,j,k,c;
printf("enter the number of rows");
scanf("%d",&h);
if((h%2)==0)
printf("enter an odd number else proper alignment will not take place\n");
if (h>9)
printf("two digit numbers will distort the diamond\n");
for(i=1;i<=h;i++)
{
if(i<=h/2)
{
c=i;
	for(j=1;j<=(h/2-i)+1;j++)
		{
			printf(" ");
		}
			for(k=1;k<=(2*i)-1;k++)
				{
				 if(k<=((2*i)-1)/2)
				  {
				  printf("%d",c);
				  c=c+1;
				  }
				  else
				  {
				  printf("%d",c);
				  c=c-1;
				  }
				}
}
else
{
c=(h-i)+1;
for(j=1;j<=(i-h/2)-1;j++)
{
printf(" ");
}
for(k=1;k<=(2*(h-i))+1;k++)
{
if(k<=(2*(h-i)+1)/2)
{
printf("%d",c);
c=c+1;
}
else
{
printf("%d",c);
c=c-1;
}
}
}
printf("\n");
}
getch();
return(0);
}
