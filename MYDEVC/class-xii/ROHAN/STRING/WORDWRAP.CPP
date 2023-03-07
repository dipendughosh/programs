# include<conio.h>
# include<iostream.h>
# include<string.h>
# include<stdio.h>
void gaps(int);
int main()
{
	//clrscr();
	char string[150]={"Scientist have claimed to have discovered a lost world in an isolated Indonesian jungle , identifying dozens of new species of butterflies and frogs"};
	char str[20][50];
	void space(char[20][50]);
	void show(char[20][50],int);
	cout<<"\n Enterd string is............\n";puts(string);
	int len=strlen(string);
	char x;
	int row=0,col=0,count=0,size;
	do
	{
		space(str);
		row=0,col=0,count=0;
		cout<<"\n Enter size of each line.....";cin>>size;
		while(count<len)
		{
			str[row][col]=string[count++];	col++;
			if(col==size)
			{
				if(string[count]!=' ')
				{
					for(int k=col-1;str[row][k]!=' ';k--)
					{	count--;col--;};//count++;
					for(int m=col ;m<50;m++)
					{	str[row][m]='*';	}
				}
				row++;
				col=0;
			}
		}
		cout<<endl;
		show(str,(75-size));
		getche();
		cout<<"\n Enter want to continue....";cin>>x;
	}while(x=='y');
	return 0;
}
void show(char x[20][50],int blank)
{	for(int i=0;x[i][0]!='*';i++)
	{
		gaps(blank);
		for(int j=0;x[i][j]!='*';j++)
		{	cout<<x[i][j];	}
		cout<<endl;
	}
	getche();
}
void space(char x[20][50])
{
	for(int i=0;i<20;i++)
	{
		for(int j=0;j<50;j++)
			x[i][j]='*';
	}
}
void gaps(int blank)
{
	for(int i=1;i<(blank/2);i++)	cout<<" ";
}



