#include <iostream.h>
#include <stdlib.h>
#include <conio.h>
#include<string.h>
#include<stdio.h>
int main()
{   char string[80],arr[80];
    int i=0,x=0,j=0,flag=0,len=0 ;
    cout<<" Enter a string :";
    gets(string);
    len=strlen(string);
    for( i=0;i<=len;i++)
    {   if(string[i]!=' ')
        {    arr[x]=string[i];
            x++;
         }
    }
    arr[x]='\0';
    puts(arr);
    for(i=len;i>=(len/2);i--)
    {   for(j=0;j<=(len/2);j++)
            {   if(arr[i]!=arr[j])
                flag=1;
             }
    }
    if(flag==1)
        cout<<"PALLINDROM ";
    else
        cout<<"NOT PALLINDROM ";

    cout<<endl;
    system("PAUSE");
    return 0;
}
