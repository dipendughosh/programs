//Multiplication of Array
#include <iostream.h>
#include <conio.h>

void main()
{   void output(int a[10][10],int n);
    void mult(int a[10][10],int b[10][10],int n);
    int i,j,n, a[10][10],b[10][10];
    cout<<"\nNo of elements of A Array : \n"; cin>>n;
    cout<<"Subscripts of A : ";
    for(i=0; i<n; i++)
       for(j=0; j<n; j++) cin>>a[i][j];
    cout<<"\nNo of elements of B Array : \n"; cin>>n;
    cout<<"Subscripts of B : ";
    for(i=0; i<n; i++)
       for(j=0; j<n; j++) cin>>b[i][j];
    cout<<"\nArray A : \n"; output(a,n);
    cout<<"\nArray B : \n"; output(b,n);
    mult(a,b,n);
    getche();
}

void mult(int a[10][10],int b[10][10],int n)
{   void output(int c[10][10],int n);
    int c[10][10];
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
        {   c[10][10] = 0;
            for (int k=0; k<n; k++)
                c[i][j] = a[i][k] * b[k][j];
        }
    cout<<"\nOutput of C Array\n";
    output(c,n);
}

void output(int x[10][10],int n)
{   for(int i=0; i<n; i++)
    {   for(int j=0; j<n; j++)
            cout<< x[i][j] <<"\t";
        cout<<endl;
    }
}
