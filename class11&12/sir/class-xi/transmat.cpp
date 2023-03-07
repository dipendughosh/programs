#include <iostream.h>
#include <conio.h>

void main()
{   int mat[3][3],i,j,temp;
    cout<<"\nInput the values :\n";
    for(i=0; i<3; i++)
        for(j=0; j<3; j++) cin>>mat[i][j];
    cout<<"\nThe matrix is :\n";
    for(i=0; i<3; i++)
    {   for(j=0; j<3; j++) cout<<mat[i][j]<<"\t";
        cout<<endl;
    }
    for(i=0; i<3; i++)
    {   for(j=i+1; j<3; j++)
        {   temp = mat[j][i];
            mat[j][i] = mat[i][j];
            mat[i][j] = temp;
        }
    }
    cout<<"\nThe Transposed Matrix is :\n";
    for(i=0; i<3; i++)
    {   for(j=0; j<3; j++) cout<<mat[i][j]<<"\t";
        cout<<endl;
    }
    getche();
}
