//
# include <iostream.h>
# include <conio.h>

void main()
{	clrscr();
	long int a,d=0,t=1,x,mn=0,p;
   long	float n=0.,c=0;
	cout<<"ENTER A NUMBER :"; cin>>n;
	mn=n;
	c=n-mn;
   while(mn!=0)
	{	a=mn%2;
		d=d+(a*t) ;
		t=t*10;
		mn= mn/2;
	}   cout<<d<<".";
	for(int r=1;r<=5;r++)
	{  //x=c*2;
		c=c*2;//
		//cout<<x;
		if(c>=1)
			{cout<<1;c=c-1; }

		else
			cout<<0;
	 //  g=g+(f*u);
	   //u=u/10 ;
	 }
   //	cout<<x;
	getch();
   }




