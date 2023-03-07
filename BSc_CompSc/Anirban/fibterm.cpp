# include <stdio.h>
# include <conio.h>
void main()
{
int f1=0,f2=1,f3,n=0;
printf("enter term");
scanf("%d",&n);
while(n>2)
{
f3=f1+f2;
f1=f2;
f2=f3;
n=n-1;
}
printf("%d",f3);
getch();
}
