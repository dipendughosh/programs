//Finding the lines less than 20 characters in a file,ok

#include<stdio.h>


main()
{	FILE *fs;
	char c,str1[80];
	int a,i;
	fs=fopen("f3.txt","r");
	if(fs==NULL)
	{	printf("Source file cannot be opened");
   	return;
	}
	a=0;
	c=fgetc(fs);
	while(c!=EOF)
	{	if(c=='.')
		{	if(a<20)
			{	for(i=0;i<a;i++)
					printf("%c",str1[i]);
				printf("\n");
			}
			a=0;
		}
		else
      	str1[a++]=c;
		c=fgetc(fs);
	}
   getch();
   fclose(fs);
   return;
}

