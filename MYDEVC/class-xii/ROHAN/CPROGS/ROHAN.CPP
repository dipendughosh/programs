# include<conio.h>
# include<process.h>
# include<iostream.h>
# include<math.h>
int number(int num,int base)
{
	int s=0,h,i=0;
	while(num!=0)
	{
		h=num%10;
		num=num/10;
		s+=(h*(pow(base,i++)));
	}
	return s;
}
void main()
{
	clrscr();
	int x,y,count=0;
	cout<<"\n Enter the two number's  ...";
	cout<<"\n Enter X -->  ";cin>>x;
	cout<<"\n Enter Y -->  ";cin>>y;
	for(int i=1;i<=20;i++)
	{
		for(int j=1;j<=20;j++)
		if(number(x,i)==number(y,j))
		{
			cout<<x<<"(base"<<i<<")  = "<<y<<"(base"<<j<<")";
			cout<<endl;
			count=1;
			getch();
		}
	}
	if(count==0)
	cout<<"\n Sorry the numbers are not equall in the given base range.\n";
	getch();
}



