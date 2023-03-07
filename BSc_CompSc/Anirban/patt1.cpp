# include <stdio.h>
# include <conio.h>
void main()
{
int h=0,i,j,k;
printf("enter height");
scanf("%d",&h);
for(i=1;i<=h;i++)
{
if(i<=(h/2))
{
for(j=1;j<=(h/2-i)+1;j++)
{
printf(" ");
}
for(k=1;k<=(2*i)-1;k++)
{
printf("*");
}
}
else
{
for(j=1;j<=(i-h/2)-1;j++)
{
printf(" ");
}
for(k=1;k<=2*(h-i)+1;k++)
{
printf("*");
}
}
printf("\n");
}
getch();
}