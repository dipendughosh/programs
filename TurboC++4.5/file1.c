//Reverse the letters of the words of the file,ok

#include<stdio.h>


main()
{	FILE *fs,*ft;
	char stk[30],c;
	int tp;
	fs=fopen("f1.txt","r");
	if(fs==NULL)
	{	printf("Source file cannot be read");
	}
	ft=fopen("f2.txt","a");
	if(ft==NULL)
	{	printf("Destination file cannot be read");
	}
	tp=-1;
	c=fgetc(fs);
	while(c!=EOF)
	{	if(c==' ' || c=='\n' || c=='.' || c==',' || c==';' || c=='\t' || c=='?')
		{	while(tp!=-1)
				fputc(stk[tp--],ft);
			fputc(c,ft);
			c=fgetc(fs);
			//continue;
		}
		else
		{	stk[++tp]=c;
			c=fgetc(fs);
		}
	}
	fclose(fs);
	fclose(ft);
	//kill(fs);
	//rename("f2.txt","f1.txt");
	//getch();
   return(0);
}
		
