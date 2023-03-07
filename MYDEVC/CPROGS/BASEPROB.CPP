#include <iostream.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
char numarr[] = {'0','1','2','3','4','5','6','7','8','9',
                    'A','B','C','D','E','F'};
int main()
{
    char num[6];
    int base, len;
    bool checkbase(char[],int,int);
    double numtodeci(char[],int,int);
    //void numtobin(char[],int);
    cout<<"Enter a number : "; gets(num);
    cout<<"Enter base     : "; cin>>base;
    len = strlen(num);
    if(!checkbase(num,base,len))
    {   cout<<"\nIncorrect base.";
        getche();
        exit(0);
    }
    cout<<"\nDecimal equivalant of the number is : "
        <<numtodeci(num,base,len);
    cout<<endl;
    system("PAUSE");
    return 0;
}

bool checkbase(char n[], int bs, int l)
{
    int nn = 0;
    for(int i = 0; i < l; i++)
    {   for(int j = 0; j < 16; j++)
        {   if(n[i] == numarr[j])
                if(j >= nn) nn = j;
        }
    }
    if(nn >= bs) return 0;
    else return 1;
}

double numtodeci(char n[], int bs, int l)
{   double decnum = 0, x = 0;
    for(int i = l-1; i >= 0; i--)
    {   for(int j = 0; j < 16; j++)
        {   if(n[i] == numarr[j])
            {   decnum += j * pow(bs,x++);
                break;
            }
        }
    }
    return decnum;
}











