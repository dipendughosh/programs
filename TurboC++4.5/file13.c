//Compare files,ok
#include<stdio.h>
#include<string.h>

main()
{	FILE *fs1,*fs2;
	char ch1,ch2;
	int c=0,l=0,f=1;
	fs1=fopen("f1.txt","r");
	if(fs1==NULL)
	{	printf("Cannot open source file");
		return(0);
	}
	fs2=fopen("f2.txt","r");
	if(fs2==NULL)
	{	printf("Cannot open source file");
		return(0);
	}
	ch1=fgetc(fs1);
	ch2=fgetc(fs2);
	while(ch1!=EOF && ch2!=EOF)
	{	if(ch1!=ch2)
		{	printf("\n%d-%d",l,c);
			f=0;
		}
		if(ch1!='\n' && ch2=='\n')
		{  while(ch1!='\n')
			{	printf("\n%d-%d ",l,c);
				c++;
				ch1=fgetc(fs1);
			}
			ch1=fgetc(fs1);
			ch2=fgetc(fs2);
			//continue;
		}
		else if(ch1=='\n' && ch2!='\n')
		{	while(ch2!='\n')
			{	printf("\n%d-%d ",l,c);
				c++;
				ch2=fgetc(fs2);
			}
			ch1=fgetc(fs1);
			ch2=fgetc(fs2);
			//continue;
		}
		if(ch1=='\n' && ch2=='\n')
		{	l++;
			c=0;
		}
		c++;
		ch1=fgetc(fs1);
		ch2=fgetc(fs2);
	}
	if(f==1)
		printf("\nNo difference");
	fclose(fs1);
	fclose(fs2);
	return(0);
}



