//Occurance of a word in a file,with line number,ok
#include<stdio.h>
#include<string.h>

main()
{	FILE *fs;
	char c,str1[80],str2[80],fname[80];
	int a,len1,len2,i,count=0,l1=0,l2=0,x=0;
	printf("Enter file name : ");
	gets(fname);
	fs=fopen(fname,"r");
	if(fs==NULL)
	{	printf("\nSource file cannot be opened");
		return;
	}
	printf("\nEnter word to search - ");
	gets(str1);
	a=0;
	c=fgetc(fs);
	while(c!=EOF)
	{	if(c==' ' || c=='.' || c==',' || c==';' || c=='?' || c=='\n')
		{	str2[a]='\0';
			len1=strlen(str1);
			len2=strlen(str2);
			if(len1==len2)
			{	for(i=0;i<len1;i++)
				{	if(str1[i]!=str2[i])
						break;
				}
				if(i==len1)
				{	count++;
					if(l1==l2)
						x++;
					else
					{	if(x!=0)
							printf("\n%d,%d",x,l1);
						else
							printf("\n%d",l1);
						x=0;
					}
					l2=l1;
				}
			}
			a=0;
		}
		else
			str2[a++]=c;
		if(c=='\n')
			l1++;
		c=fgetc(fs);
	}
   str2[a]='\0';
	len1=strlen(str1);
	len2=strlen(str2);
	if(len1==len2)
	{	for(i=0;i<len1;i++)
		{	if(str1[i]!=str2[i])
				break;
		}
		if(i==len1)
			count++;
	}
	if(count==0)
		printf("NO match");
	else
		printf("\nMatches %d times",count);
	fclose(fs);
	return;
}
