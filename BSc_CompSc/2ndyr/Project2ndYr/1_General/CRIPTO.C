//Program to perform Cryptography
#include<stdio.h>
#include<conio.h>


void main()
{       //Declaring variables
	char str[100],str1[100];
	int len,i;
	//clrscr();
	printf("\nEnter string - ");
	fflush(stdin);
	gets(str);
	len=strlen(str);
	//Loop for performing cryptography
	for(i=0;i<len;i++)
	{       str1[i]=str[i]+5;
		if(str1[i]>'9' && str1[i]<='A' && str1[i]<='a')
			str1[i]='0'+str1[i]-'9'-1;
		else if(str1[i]>'Z' && str1[i]<='a')
			str1[i]='A'+str1[i]-'Z'-1;
		else if(str1[i]>'z')
			str1[i]='a'+str1[i]-'z'-1;
		else if((str[i]<'A' || str[i]>'Z') && (str[i]<'a' || str[i]>'z') && (str[i]<'0' || str[i]>'9'))
			str1[i]=str1[i]-5;
	}
	str1[i]='\0';
	printf("\nThe string after cryptography is -\n");
	puts(str1);
	getch();
	printf("\nAll alphabets and digits are changed to their fifth succsesors,\nspecial characters are unchanged");
	getch();
}

