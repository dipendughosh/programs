#include <iostream.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct person
{   char name[];
}p[2];

int main()
{   clrscr();
	int i,j,c;
    void change(person);
    int check(person,person);
    void swap(person,person);
	for (i=0;i<2;i++)
    {   cout<<"Enter name "<<i+1<<" : "; gets(p[i].name);
		//change(p[i]);
    }
    for (i=0;i<4;i++)
	{   for (j=i+1;j<2;j++)
        {   c=check(p[i],p[j]);
            if (c) swap(p[i],p[j]);
        }
    }
	for (i=0;i<2;i++)
	{	cout<<endl;
		puts(p[i].name);
	}


	getch();
    cout<<endl;
    system("PAUSE");
    return 0;
}

int check(person p1,person p2)
{   int len1,len2,x=0,l,i;
    len1=strlen(p1.name);
    len2=strlen(p2.name);
    if (len1<len2) l=len1;
    else l=len2;
    for (i=0;i<l;i++)
    {   if (p1.name[x]==p2.name[x])
        {   x++;
            continue;
        }
        else if (p1.name[x]<p2.name[x])
                return 0;
             else if (p1.name[x]>p2.name[x])
                    return 1;
    }
    return 0;
}

void swap(person p1,person p2)
{   person p;
    p=p1;
    p1=p2;
    p2=p;
}

void change(person p)
{   int len=strlen(p.name);
    for (int i=0;i<len;i++)
       if (p.name[i]>90)
           p.name[i]-=32;
}
