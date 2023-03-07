#include<conio.h>
#include<iostream.h>
int fact(int);
void main()
{   clrscr();
	int perm(int,int);
	for(int i=0;i<6;i++)
	{	for(int j=0;j<=i+1;j++)
			cout<<"  "<<perm(i,j);
		cout<<endl;
	}
	getch();
}


int perm(int n,int r)
{	if(n<0 || r<0 || r>n)
	return 0;
	return (fact(n)/fact(r));
}

int fact(int p)
{   int fact=1;
	while(p)
	  fact*=p--;
	return fact;
}


