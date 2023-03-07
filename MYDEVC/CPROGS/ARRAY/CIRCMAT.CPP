//FILLING 2D ARRAY IN CIRCULAR MOTION

#include <iostream.h>
#include <stdlib.h>
#include <conio.h>

int main()
{   int cirmat[5][5];
	int move = 5, row = 0, col = 0;
	int dir, i, j, num = 1;
	clrscr();
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
	cirmat[--row][--col] = num;
	cout<<"\t\tThe Array filled thus ...\n\n";
	for(i = 0; i < 5; i++)
	{   for(j = 0; j < 5; j++)
			cout<<cirmat[i][j]<<"\t";
		cout<<"\n\n";
	}
	cout<<endl;
	getche();
	return 0;
}
