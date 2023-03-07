// Printing String as Rhombus
#include <iostream.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>
#define MAX 30
int main()
{   char str[MAX];
    void addstar(char [],int), shostr(char[],int);
    int len,mid,i,j,k;
    cout<<"Enter a string : "; gets(str);
    len = strlen(str);
    if (len % 2 == 0 )
    {   addstar(str,len);
        ++len;
    }
    mid = len / 2 ;
    for (i = 0; i < mid+1; i++)
    {   for (j = 0; j < len; j++)
        {   if (j > mid-i && j < mid+i)
                cout<<str[j]<<" ";
            else cout<<"  ";
        }
        cout<<endl;
    }
    for (k = i; k >= 0; k--)
    {   for (j = 0; j < len; j++)
        {   if (j > mid-k && j < mid+k)
                cout<<str[j]<<" ";
            else cout<<"  ";
        }
        cout<<endl;
    }
    getche();
    return 0;
}

void addstar(char string[],int l)
{   int mid = l / 2;
    for(int x = l; x >= mid; x--)
        string[x+1] = string[x];
    string[mid] = '*';
    string[l+2] = '\0';
}
