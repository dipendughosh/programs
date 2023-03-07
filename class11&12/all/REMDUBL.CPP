#include <iostream.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <stdio.h>

void main()
{   clrscr();
    char str[80];
    int i=0,len,j;
    void squize(char [80],int,int);
    cout<<"\nEnter string :";
    gets(str);
    while(str[i]!='\0')
    {   len=strlen(str);
	if(str[i]==' ')
	{       squize(str,len,i);
	}
	i++;
    }
    i=0;
    while(str[i]!='\0')
    {   len=strlen(str);
	for(j=i+1;j<len;j++)
	{   if(str[i]==str[j])
	    {       squize(str,len,j);
	    }
	}
	i++;
    }
    i=0;
    while(str[i]!='\0')
    {   cout<<str[i];
	i++;
    }
/*    cout<<endl;
    system("PAUSE");
    return 0;*/
    getche();
}
void squize(char string[80],int l,int y)
{   int j;
    for(j=y;j<l-1;j++)
    {   string[j]=string[j+1];
    }
    string[j]='\0';
}
