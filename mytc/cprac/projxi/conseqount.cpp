
//*****counting occurance of consecutive letters *****//
# include<iostream.h>
# include<conio.h>
# include<string.h>
# include<stdio.h>
void main()
{
//	clrscr();
	char sen[1000],ch,ch2;
	int i,j,length = 0,num = 0;
	cout<<"\nEnter a sentence ";
	gets(sen);
	cout<<"\nThe ORIGINAL sentence is :\n";
	puts(sen);
	for(i = 0;i<strlen(sen)-1;i++)
	{
		ch = sen[i];
        ch2 = sen[i+1];
        int cnt = ((int)ch)+1;
		if(((int)ch2) == cnt)
			num++;
	}
	cout<<"\nThere are "<<num<<" consecutive letters in the sentence "; 
	getche();
}



