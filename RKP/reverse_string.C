//Reverse a string
#include<stdio.h>
#include<conio.h>
#include<string.h>

int main()
{   //Declaring variables
	char str[80],str1[80];
	int len,i,j;
//	clrscr();
	//Entering data
	printf("Enter a string - ");
	gets(str);
	//Finding length of the string entered
	len=strlen(str);
	//Loop for reversing the string
	for(i=len-1,j=0;i>=0;j++,i--)
		str1[j]=str[i];
	//Displaying the reversed string
	puts(str1);
	getch();
	return(0);
}

