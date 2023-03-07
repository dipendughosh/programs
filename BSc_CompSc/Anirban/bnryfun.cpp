# include <stdio.h>
# include <conio.h>
void main()
{
int binary(int),n=0,b;
printf("enter number");
scanf("%d",&n);
b=binary(n);
printf("the binary number is %d",b);
getch();
}
binary(int x)
{
int r,i=1,s=0;
while(x>0)
{
r=x%2;
s=s+(r*i);
x=x/2;
i=i*10;
}
return(s);
} 