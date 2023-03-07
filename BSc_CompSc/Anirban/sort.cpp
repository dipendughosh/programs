# include <stdio.h>
# include <conio.h>
void main()
{
int m[10];
int i,j,c;
for(i=0;i<=9;i++)
{
printf("\n marks");
scanf("%d",&m[i]);
}
for(i=0;i<=9;i++)
{
for(j=i+1;j<=9;j++)
{
if(m[i]>m[j])
{
c=m[i];
m[i]=m[j];
m[j]=c;
}
}
}
for(i=0;i<=9;i++)
{
printf("%d ",m[i]);
}
getch();
/*bubble sort in ascending order*/
}
