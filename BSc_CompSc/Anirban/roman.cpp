# include <stdio.h>
# include <conio.h>
void main()
{
int a[10];
int x=0,n=0,i,y;
printf("enter the item");/*this program is on binary search*/
scanf("%d",&x);
printf("enter the number of elements to be entered");
scanf("%d",&n);
if((n%2)==0)
y=n/2;
else
y=(n+1)/2;
printf("enter the elements");
for(i=0;i<=n-1;i++)
{
scanf("%d",&a[i]);
}
if(x==a[y])
printf("the item is in position %d",(y+1));
else
{
if(x<a[y])
{
for(i=0;i<=y-1;i++)
{
if(x==a[i])
printf("the item is in position %d",i+1);
}
}
else
{
for(i=y;i<=n;i++)
{
if(x==a[i])
printf("the item is in position %d",i+1);
}
}
}
}

