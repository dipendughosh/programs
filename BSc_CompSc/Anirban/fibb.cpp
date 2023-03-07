# include <stdio.h>
# include <conio.h>
void main()
{
int n=0,f1=0,f2=1,f3;
printf("enter limit");
scanf("%d",&n);
printf("%d%d",f1,f2);
while(n>2)
{
f3=f1+f2;
printf("%d ",f3);
f1=f2;
f2=f3;
n=n-1;
}
getch();
}
