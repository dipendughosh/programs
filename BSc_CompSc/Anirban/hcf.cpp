# include <stdio.h>
# include <conio.h>
void main()
{
int num(int,int),m=0,n=0,hcf;
printf("enter the two numbers");
scanf("%d%d",&m,&n);
hcf=num(m,n);
printf("the hcf is %d",hcf);
getch();
}
num(int x,int y)
{
int a=0,b=0;
a=(x/y);
b=x-(a*y);
if(b==0)
return(y);
else
{
x=y;
y=b;
}
return(num(x,y));
}