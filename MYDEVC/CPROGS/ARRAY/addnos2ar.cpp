// Insert new element into array  ==========> incorrect
#include <iostream.h>
#include <stdlib.h>
#include <conio.h>

int a[5];
int main()
{   int n,i=0,x,z;
    void show(int);
    void sort(int);
    //cout<<"How many elements : ";  cin>>n;
    n = 4;
    cout<<"Enter 4 elements.\n";
    for (;i<n;i++)
        cin>>a[i];
    show(n);
    cout<<endl;
    sort(n);
    show(n);
    while (n<5)
    {   cout<<"Enter a new element : ";  cin>>x;
        for (i=0;i<n-1;i++)
        {   if (x<a[0])
            {   for (z=n;z>=1;z--)
                    a[z]=a[z-1];
                a[0]=x;

            }
            else
            {   if (x>a[n-1])
                   a[n]=x;

                else if (x>a[i] && x<a[i+1])
                     {  for (int y=n;y>=i+2;y--)
                            a[y]=a[y-1];
                        a[i+1]=x;
                     }
              //       getche();
            }
            cout<<endl;
            //show(n);
        }
        n++;
    }
    cout<<endl;
    show(n);
    system("PAUSE");
    return 0;
}

void show(int p)
{   for (int j=0;j<p;j++)
        cout<<a[j]<<' ';
}

void sort(int p)
{   int temp;
    for (int i=0;i<p-1;i++)
    {   for (int j=i;j<p;j++)
        {   if (a[i]>a[j])
            {   temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
}

