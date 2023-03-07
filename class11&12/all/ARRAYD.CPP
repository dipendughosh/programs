#include<iostream.h>
#include<conio.h>
#include<math.h>
void main()
{		clrscr();
		int a[20],i,sum=0,dev=0,max=0,min=0;
		float ave=0,sd=0;
		for( i=0;i<20;i++)
				cin>>a[i];
		max=a[0];
		min=a[0];
		for( i=1;i<20;i++)
		{		sum=sum+a[i];
				if(max<=a[i])
						max=a[i];
				if(min>=a[i])
						min=a[i];
		}
			ave=sum/20;
		for( i=0;i<20;i++)
				dev=pow((a[i]-ave),2);
		sd=sqrt(dev/20);
		cout<<"SUM OF ARRAY :"<<sum<<"\n";
		cout<<"MAXUIMUM NUMBER :"<<max<<"\n";
		cout<<"MINIMUM NUMBER :"<<min<<"\n";
		cout<<"STANDARD DEVIATION :"<<sd<<"\n";
		cout<<"AVERAGE NUMBER :"<<sd<<"\n";
		getche();
}