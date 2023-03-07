//Addition of 2 long numbers ( whose sum > 256^4 i.e., 4294967296 )
#include <iostream.h>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>   // for gets()
#define MAX 50
int main()
{   char num1[MAX], num2[MAX];
    int arr1[MAX],arr2[MAX];
    void addnum(char[],int,char[],int);
    //clrscr();
    cout<<"Enter a long number : "; gets(num1);
    cout<<"Enter another       : "; gets(num2);
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    if(len1 > len2) addnum(num1,len1,num2,len2);
    else addnum(num2,len2,num1,len1);
    cout<<endl;
    system("PAUSE");
    return 0;
}
int addnum(char cnum1[],int clen1,char cnum2[],int clen2)
{   int add[MAX];
    int dig1, dig2, sum, carry = 0 ;
    int x = clen1 - 1, y = clen2 - 1;
    while(x >= 0)
    {   dig2 = 0;
        dig1 = cnum1[x] - 48;
        if(y >= 0) dig2 = cnum2[y] - 48;
        sum = dig1 + dig2 + carry;
        if(sum > 9)
        {   add[x+1] = sum - 10;
            carry = 1;
        }
        else
        {   add[x+1] = sum;
            carry = 0;
        }
        x--; y--;
    }
    carry > 0 ? add[0] = carry : add[0] = 0;
    cout<<"\nThe sum of above numbers : ";
    if(add[0] > 0) cout<<add[0];
    for( y = 1; y < clen1+1; y++) cout<<add[y];
    return 0;
}
