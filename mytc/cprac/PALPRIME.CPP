#include<iostream.h>
#include<conio.h>
void main()
{
	clrscr();
	int digit = 1,j,check,tot,temp,i;
	while(digit<=19999)
	{   check=0;
		for(j=2;j<=digit/2;j++)
		{
			if(digit%j ==0)
			{
				check = 1;
				break;
			}
		}
		if(check == 0)
		{
			//cout<<digit;
			//getche();
			i = digit ;
			tot = i%10;
			i/=10;
			while(i>0)
			{
				tot*=10;
				temp = i%10;
				tot+=temp;
				i/=10;
			}
			//cout<<"\n===========> tot  " <<tot;
			//getche();
			if(tot == digit)
			{
				cout<<"\n\tpalin "<<digit;
				getche();
			}
		}
		digit++;
	}
}
