#include<stdio.h>
#include<conio.h>

void main()
{       int a=0,i,j,n,x,z,b=0;
	clrscr();
	printf("Enter n ");
	scanf("%d",&n);
	z=n;
	for(i=0;i<z;i++)
	{       j=65;
		b++;
		while(j<n+65)
		{	printf("%c",j);
			j++;
		}
		for(x=0;x<a;x++)
			printf(" ");
		if(j==z+65)
			j--;
		while(j>65)
		{       j--;
			printf("%c",j);
		}
		n--;
		if(b==1)
			a++;
		else
			a+=2;
		printf("\n");
	}
	getch();
}

