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
	/*printf("\n");
	for(i=0;i<n;i++)
		printf("%d\t",a[i]);*/

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
	for(i=0;i<n;i++)
		printf("%d\t",a[i]);
	printf("\n");
}

void hp_dsply(int a[],int n)
{  int p,t,m,i;
	m=n;n--;
	while(n>=0)
	{  t=a[0];
		a[0]=a[n-1];
		a[n-1]=t;
		n--;
		p=0;
		while((a[(2*p)+1]>=a[p] || a[(2*p)+2]>=a[p]) && n>(2*p))
		{  t=a[p];
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
	for(i=0;i<m;i++)
		printf("%d\t",a[i]);
	getch();
	/*int k,temp,i,j,key;
	//Heap Sort logic
	for(k=n-1;k>=1;--k)
	{	temp=a[0];
		a[0]=a[k];
		a[k]=temp;
		i=0;
		key=a[0];
		j=1;
		if((j+1)<k)
			if(a[j+1]>a[j])
				j=j+1;
		while((j<=(k-1)) && (a[j]>key))
		{	a[i]=a[j];
			i=j;
			j=2*i;
			if((j+1)<k)
			{	if(a[j+1]>a[j])
					j=j+1;
				else if(j>n)
					j=n;
			}
			a[i]=key;
		}
	 }*/
}


