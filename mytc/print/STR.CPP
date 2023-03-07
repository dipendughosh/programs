//to find the sentence having the max no of letters.
#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<ctype.h>
void main()
{	 char str[200],g[50];
	 int c=0;
	 clrscr();
	 cout<<" enter the string  ";
	 gets(str);
  int l=strlen(str);
  for(int i=0;i<l;i++)
   { if((str[i]=='.') || (str[i]=='!'))
	{if((isupper(str[i+1])>0) || (str[i+1]==' '))
	  cout<<str[i]<<endl;
	}
	else
	 cout<<str[i];
	if(i==(l-1))
	 cout<<str[i];
   }

   int check=0,j=0;
   char copy[50]; int l1;
   for(i=0;i<l;i++)
   { //c=0;
		if((str[i]!='.') && (str[i]!='!'))
		{	c++;
			g[j++]=str[i];
			continue;
		}
	   if(c>check)
	   {   check=c;
		   strcpy(copy,g);
		   cout<<c;getche();
		 }
		 c=0;j=0;
   }
   //	 cout<<endl<<"\nCheck = "<<check;
   for(i=0;i<check;i++)
	 cout<<copy[i];
  getche();
}