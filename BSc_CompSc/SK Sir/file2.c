//Finding the longest line in a file

#include<stdio.h>

struct sntnc
{	char str[80];
	int a;
};

main()
{	FILE *fs;
	char c;
	struct sntnc st[20];
	int i,j,x,max;
	fs=fopen("f1.txt","r");
	if(fs==NULL)
	{	printf("Source file cannot be opened");
	}
	for(i=0;i<20;i++)
		st[i].a=0;
	j=0;
	i=0;
	c=getc(fs);
	while(c!=EOF)
	{	if(c!='.')
		{	st[i].str[j++]=c;
			st[i].a++;
		}
		else
		{	st[i].str[j++]=c;
			st[i].a++;
			j=0;
			i++;
		}
		c=getc(fs);
	}
	for(j=0;j<i;j++)
		printf("%d",st[j].a);
	max=st[0].a;
	for(j=1;j<i;j++)
	{	if(max<st[i].a)
			x=j;
	}
	for(i=0;i<st[x].a;i++)
		printf("%c",st[x].str[i]);
}
	
