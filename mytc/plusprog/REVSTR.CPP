// reverse the stringin one array only
#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
void main()
{ clrscr();
  char str[20],temp;
  cout<<" enter the string ";
  gets(str);
  int l=strlen(str);
  int f=l/2;
  for(int y=0;y<f;y++)
   { temp=str[y];
	 str[y]=str[l-1];
	 str[l-1]=temp;
	 l--;
   }
   puts(str);
   getche();
}
