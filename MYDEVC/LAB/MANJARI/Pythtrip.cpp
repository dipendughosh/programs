// Finding Pythagorean Triplets //

#include <iostream.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
int main()
{
	//clrscr();
	int i, j, k, first, last;
    double isqr, jsqr, ksqr;
    cout << "Input First number : "; cin >> first;
    cout << "Input Last number  : "; cin >> last;
	cout <<"\nAll PYTHAGOREAN TRIPLETS from "<< first <<" to " << last;
    cout << endl;
	for(i = first; i <= last; i++)
	{
		isqr = pow(i,2);
		for(j = i+1; j <= last; j++)
		{
			jsqr = pow(j,2);
			for(k = j+1; k <= last; k++)
			{
				ksqr = pow(k,2);
				if(isqr + jsqr == ksqr)
				{
					cout<<"\n "<< i <<" "<< j <<" "<< k
                        <<"\tbecause "<< i << "^2 + "
                        << j <<"^2 = "<< k << "^2";
				}
			}
		}
	}
    cout<<endl;
    system("PAUSE");
    return 0;
}
