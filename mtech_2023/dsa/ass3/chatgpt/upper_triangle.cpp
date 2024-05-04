#include <iostream>

using namespace std;

void printUpperTriangle(int mat[][3], int n)
{
    cout << "Upper Triangle Elements: " << endl;
    for (int i = 0; i < n; ++i)
    {
        for (int j = i; j < n; ++j)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    const int N = 3;
    int mat[N][N] = {{1, 2, 3},
                     {4, 5, 6},
                     {7, 8, 9}};

    printUpperTriangle(mat, N);

    return 0;
}
