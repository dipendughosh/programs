#include <iostream.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
    int n, num = 1, k = 1;
    cout << "Enter an odd number ( 3 to 15 )";
    cin >> n;
    n--;
    int arr[7][7];
    int i = 0, j = n/2;
    while(num <= (n*n))
    {
        arr[i][j] = num++;
        if( k < n )
        {   k++; i--; j++;
            if(i < 0)
                if(j <= n)
                    continue;
        }
        else
        {   k = 1; i++;
            continue;
        }
        i = num;
        continue;
        j = 0;
    }

    for(i = 0; i < n; i++)
    {   for(j = 0; j < n; j++)
            cout << arr[i][j] << "\t";
        cout << endl;
    }
    cout<<endl;
    system("PAUSE");
    return 0;
}
