//insert and delete integer in dynamic array

#include<stdio.h>
#include<conio.h>

void main()
{
	char *a,*b,*c,*p;
	char ch,m;
	int x,n,i,flag=0,count;
	clrscr();
	printf("\nEnter no. of charcter you want to enter: ");
	scanf("%d", &n);
	a=(char*)malloc(sizeof(char)*(n+1));
	b=a;
	c=a;
	printf("\nEnter the charcters: ");
	for(i=0;i<n;i++)
	{
		//printf("\na[%d]= ",i);
		//scanf("%s",a);
		ch=getchar();
		*a=ch;
		a++;
	}
	a--;

	printf("\nYou have entered--\n");
	while(*b!='\n')
	{
		printf("\n%c",*b);
		b++;
	}

	printf("\ntest");
	printf("\nEnter the letter you want to delete: ");
//	m=getchar();
	scanf("%c",&m);
	printf("\nm=%c",m);
	/*for(i=0;i<n;i++)
	{
		//printf("\n*b at %dth position is:%d ", i,*b);
		if(*b==m)
		{
		     flag=1;
		     while(b!=a)
		     {
			*b=*(b+1);
			b++;
		     }
		}
		else
			b++;
	}
	if(flag==0)
		printf("\nLetter not found!");

	b=c;
	if(flag==1)
	{
		printf("\nThe letters are: ");
		for(i=0;i<n-1;i++)
		{
			printf("\n%s",*b);
			b++;
		}
		a=b;
	}*/
	/*b=c;

	printf("\n\nEnter the number you want to insert: ");
	scanf("%d",&m);
	printf("\nEnter in which position you want to enter: ");
	scanf("%d", &x);
	count=0;
	while(count!=x-1)
	{
		count++;
		b++;
	}
	p=b;
       //	printf("\n p=%d b=%d\n",p,b)   ;
	b=a-1;
	//printf("\n*b=%d",*b);
	while(b!=p)
	{
		*(b+1)=*b;
		 b--;
	}
	*(b+1)=*b;
	*b=m;
	if(flag==1)
	{
		printf("\nAfter insertion the numbers are:");
		for(i=0;i<n;i++)
		{
			printf("\n%d", *c);
			c++;
		}
	}
	if(flag==0)
	{
		printf("\After insertion the numbers are:");
		for(i=0;i<n+1;i++)
		{
			printf("\n%d", *c);
			c++;
		}
	} */
	getch();
}