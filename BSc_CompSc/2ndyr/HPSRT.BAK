//heap sort
#include<stdio.h>
#include<conio.h>


void main()
{	int a[20],n,i;
	void hp_crt(int [],int);
	void hp_dsply(int [],int);
	clrscr();
	printf("Enter number of elements:-");
	scanf("%d",&n);
	hp_crt(a,n);
	hp_dsply(a,n);
	printf("\n");
	for(i=0;i<n;i++)
		printf("%d\t",a[i]);

	getch();
}

void hp_crt(int a[],int n)
{       int i,k,p,q,x=0,r,f,j;
	printf("Enter 1st element:-\n");
	scanf("%d",&a[0]);
	for(i=1;i<n;i++)
	{       f=0;   x++;
		scanf("%d",&a[i]);
		q=a[i];
		r=i;
		while(r>0)
		{	if(x%2==0)
				p=(r-1)/2;
			else
				p=(r-2)/2;
			if(q<=a[p])
			{	f=1;
				break;
			}
			a[r]=a[p];
			r=p;
		}
		if(f==0)
			a[r]=q;
	}
}

void hp_dsply(int a[],int n)
{       int p,t;
	while(n>=0)
	{	printf("%d\t",a[0]);
		a[0]=a[n-1];
		n--;
		p=0;
		while(a[(2*p)+1]>=a[p] || a[(2*p)+2]>=a[p] && n>(2*p))
		{       t=a[p];
			if(a[(2*p)+1]>=a[(2*p)+2])
			{	a[p]=a[(2*p)+1];
				p=(2*p)+1;
				a[p]=t;
			}
			else if(a[(2*p)+1]<=a[(2*p)+2])
			{	a[p]=a[(2*p)+2];
				p=(2*p)+2;
				a[p]=t;
			}
		}
	}
}






