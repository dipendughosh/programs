# include <stdio.h>
# include <conio.h>
void main()
{
int n=0,i,j,k;
printf("enter limit");
scanf("%d",&n);
k=1;
for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
{
printf("%d ",k);
k=k+1;
}
printf("\n");
}
getch();
}