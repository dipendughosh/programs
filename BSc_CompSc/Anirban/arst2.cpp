# include <stdio.h>
# include <conio.h>
void main()
{
int i,n=0,x=0,s=0;
printf("enter number");
scanf("%d",&n);
i=n;
while(i>0)
{
x=i%10;
s=s+(x*x*x);
i=i/10;
}
if(s==n)
printf("%d is armstrong",s);
else
printf("%d is not armstrong",n);
getch();
}
