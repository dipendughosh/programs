#include <iostream.h>
#include <stdlib.h>
#include <conio.h>
int main()
{
    //clrscr();
	int row, col, i, j, flag = 1;
    char arrout[15][15];
	char character ='A';
	cout << " Enter Rows for array "; cin >> row;
    cout << " Enter cols for array "; cin >> col;
	for(i = 0; i < col; i++)
	{
		if(flag == 1)
			for(j = 0; j < row; j++)
				arrout[j][i] = character++;
  		else
  			for(j = row-1; j >= 0; j--)
				arrout[j][i] = character++;
 		flag *= -1;
	}
	cout << endl;
	for(i = 0; i < row; i++)
	{
		for(j = 0; j < col; j++)
 			cout << arrout[i][j]<<" ";
 		cout << endl;
	}
    cout << endl;
    system("PAUSE");
    return 0;
}
