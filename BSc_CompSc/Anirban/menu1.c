# include <stdio.h>
# include <conio.h>
void main()
{
int n=0,h=0,i,j,k;
printf("1.first numeric pattern");
printf("\n 2.second numeric pattern");
printf("\n 3.alphabetical ppattern");
printf("\n enter your choice");
scanf("%d",&n);
switch(n)
{
case 1:
printf("enter height");
scanf("%d",&h);
for(i=1;i<=h;i++)
{
for(j=1;j<=(2*i)-1;j++)
{
printf("%d ",j);
}
printf("\n");
}
break;
case 2:
printf("enter height");
scanf("%d",&h);
k=1;
for(i=1;i<=h;i++)
{
for(j=1;j<=i;j++)
{
printf("%d ",k);
k++;
}
printf("\n");
}
break;
case 3:
printf("enter height");
scanf("%d",&h);
char ch ='a';
for(i=1;i<=h;i++)
{
for(j=1;j<=i;j++)
{
printf("%c ",ch);
}
ch=ch+1;
printf("\n");
}
break;
}
getch();
}