# include <stdio.h>
# include <conio.h>
void main()
{
int n=0,i,j;
float s=0.0,x=0.0,f;
printf("enter limit");
scanf("%d",&n);
for(i=1;i<=n;i++)
{
  f=1.0;
 for(j=1;j<=i;j++)
 {
 f=f*j;
 }
 x=(i/f);
s=s+x;
}
printf("the sum is %f",s);
getch();
}
