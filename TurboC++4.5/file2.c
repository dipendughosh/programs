//Finding the longest line in a file,ok

#include<stdio.h>
#include<string.h>

main()
{	FILE *fs;
	char c,str1[80],str2[80];
	int a,b,i,n,l;
	fs=fopen("f3.txt","r");
	if(fs==NULL)
	{	printf("Source file cannot be opened");
	}
	a=0;
	b=0;
	n=0;
	c=fgetc(fs);
	while(c!=EOF)
	{	if(c!='.')
			str1[a++]=c;
		else if(c=='.')
		{  if(a>b)
			{	for(i=0;i<a;i++)
					str2[i]=str1[i];
				str2[a++]='.';
				str2[a]='\0';
				b=a;
				l=n;
			}
			a=0;
		}
		if(c=='\n')
			n++;
		c=fgetc(fs);
	}
	printf("line number:%d\nLength :%d",l,b);
	puts(str2);
	fclose(fs);
	return;
}

