//char array
#include<stdio.h>
#include<conio.h>

struct fre
{	char b;
	int cnt;
};

void main()
{       struct fre x[20];
	char str[20];
	int i,j,y=0,flag=0,len;
	clrscr();
	printf("Enter string:-\n");
	gets(str);
	len=strlen(str);
	for(i=0;i<len;i++)
		if(str[i]>=65 && str[i]<=90)
			str[i]=str[i]+32;
	for(i=0;i<len;i++)
	{	for(j=0;j<y;j++)
		{	if(x[j].b==str[i])
			{	flag=1;
				break;
			}
		}
		x[y].cnt=0;
		if(flag==0)
		{       x[y].b=str[i];
			for(j=0;j<len;j++)
			{	if(x[y].b==str[j])
					x[y].cnt++;
			}
			y++;
		}
		flag=0;
	}
	for(i=0;i<y;i++)
		printf("%c\t%d\n",x[i].b,x[i].cnt);
	getch();
}