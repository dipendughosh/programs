# include <stdio.h>
# include <conio.h>
void main()
{
/*a menu driven program*/
int choice=0,h=0,i,j,k;
printf("\n 1.right angle triangle");
printf("\n 2.inverted triangle");
printf("\n 3.pyramid");
printf("\n enter your choice");
scanf("%d",&choice);
switch(choice)
{
case 1:
/*right angle triangle*/
printf("\n enter height");
scanf("%d",&h);
for(i=1;i<=h;i++)
{
for(j=1;j<=i;j++)
{
printf("*");
}
printf("\n");
}
break;
case 2:
/*inverted right angle*/
printf("\n enter height");
scanf("%d",&h);
for(i=1;i<=h;i++)
{
for(j=1;j<=(h-i+1);j++)
{
printf("*");
}
printf("\n");
}
break;
case 3:
/*pyramid*/
printf("\n enter height");
scanf("%d",&h);
for(i=1;i<=h;i++)
{
for(j=1;j<=(h-i);j++)
{
printf(" ");
}
for(k=1;k<=(2*i)-1;k++)
{
printf("*");
}
printf("\n");
}
break;
}
getch();
}
