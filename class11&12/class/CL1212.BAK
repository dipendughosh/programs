#include<iostream.h>
#include<process.h>
#include<string.h>
#include<conio.h>
#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<iomanip.h>

class calander
{	int startday,numday,cal[6][7];
	public:
	calander(int x,int y)
	{       int i,j;
		startday=x;
		numday=y;y=0;
		for(i=0;i<6;i++)
		{	for(j=x;j<7;j++)
			{	if(y==numday)
				{	cal[i][j]=y;
					break;
				}
				else
				{	cal[i][j]=y;
					y++;
				}
			}
			x=0;
		}
		prn();
	}
	void prn()
	{       int i,j;
		for(i=0;i<6;i++)
		{	for(j=0;j<7;j++)
			{	if(cal[i][j]>=1 || cal[i][j]<=31)
				{	cout<<cal[i][j]<<"  ";
				}
			}
			cout<<"\n";
		}
	}
};
void main()
{	clrscr();
	calander obj1(3,30);
	//cout<<"\n\aP\aR\aE\aS\aS\a \aA\aN\aY\a \aK\aE\aY\a \aT\aO\a \aC\aO\aN\aT\aI\aN\aU\aE\a \a.\a.\a.\a.\a.\a.\a.\a.\a.\a.\a.\a.\a";
	getche();
}

