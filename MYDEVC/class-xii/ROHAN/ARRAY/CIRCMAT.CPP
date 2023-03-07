//FILLING 2D ARRAY IN CIRCULAR MOTION

#include <iostream.h>
#include <stdlib.h>
#include <conio.h>

int main()
{   int cirmat[150][150];
	int move , row = 0, col = 0;
	int dir, i, j, num = 1,x;
	char ch;
	//clrscr();
    do
    {
	row=0,col=0,num=1;
	cout<<"\nEnter size........";cin>>x;
	//clrscr();
	move=x;
	do
	{   for(dir = 1; dir < 5; dir++)            // For direction
		{   for(int i = 0; i < move-1; i++)     // Filling array
			{   cirmat[row][col] = num++;
				switch (dir)
				{   case 1: ++col; break;       // Increment/Decrement
					case 2: ++row; break;       // of row and col
					case 3: --col; break;       // according to
					case 4: --row; break;       // direction
				}
			}
		}
		++row;                                 // After one rotation
		++col;
		move -= 2;
	}
	while( move > 0);
	if(x%2==1)
	{	cirmat[--row][--col] = (x*x);	}
	cout<<"\t\tThe Array filled thus ...\n\n";
	for(i = 0; i < x; i++)
	{   for(j = 0; j < x; j++)
			cout<<cirmat[i][j]<<"\t";
		cout<<"\n\n";
	}
	cout<<endl;
	getche();
	cout<<"\nWant to continue";cin>>ch;
    }
    while(ch==(char)(48));
    return 0;
}
