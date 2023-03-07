# include <stdio.h>
# include <conio.h>
int a[20];
void main()
{
void sort(int[],int);
void search(int[],int,int);
int x=0,n=0,i;
printf("enter the number to be searched");
scanf("%d",&x);
printf("enter the number elements to be entered");
scanf("%d",&n);
printf("enter the elements");
for(i=0;i<=n-1;i++)
{
scanf("%d",&a[i]);
}
sort(a,n);
search(a,n,x);
}
void sort(int a[20],int n)
{
int t,min,i,j;
for(i=0;i<=n-1;i++)
{
min=i;
for(j=i+1;j<=n;j++)
{
if(a[i]>a[j])
min=j;
}
t=a[i];
a[i]=a[min];
a[min]=t;
}
}
void search(int a[20],int n,int x)
{
int y,i;
if((n%2)==0)
y=n/2;
else
y=(n+1)/2;
if(x==a[y])
printf("the item is in position %d",y);
else
{
if(x<a[y])
{
for(i=0;i<=y-1;i++)
{
if(x==a[i])
printf("the item is in position %d",i);
}
}
else
{
for(i=y;i<=n;i++)
{
if(x==a[i])
printf("the item is in position %d",i);
}
}
}
}

