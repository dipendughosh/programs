//INCOMPLETE!!
#include<iostream.h>
#include<conio.h>
void main()
{   clrscr();
	int asc,i,j,c;
	asc=65;    //ASCII OF A = 65
	char m1[4][5];
	for(i=0;i<4;i++)
	{	for(j=0;j<5;j++)
		{	if((i+j)>=4)
			{
				c=49;      //ASCII OF 1 = 49
				for(c=49;c<=asc-16;c++)
				{	cout<<"\n"<<"   i= "<<i<<"   j= "<<j<<"   c= "<<c;	getche();
					m1[i][j]=c;
					//c+=1;
				}
			}
			else
				m1[i][j]=asc;
		 }
		 asc++;
	 }
	asc=49;      //ASCII OF 1 = 49
	char m2[4][5];
	for(i=0;i<4;i++)
	{	for(j=0;j<5;j++)
		{	if((i+j)>=4)
			{
				c=65;       //ASCII OF A=65
				while(c<=asc-16)
					m2[i][j]=c++;
			}
			else
				m2[i][j]=asc;
		 }
		 asc++;
	 }
	cout<<" \nMATRIX ONE\n";
	for(i=0;i<4;i++)
	{	for(j=0;j<5;j++)
			cout<<m1[i][j]<<"\t";
		cout<<endl;
	}
	cout<<"\n MATRIX TWO \n";
	for(i=0;i<4;i++)
	{	for(j=0;j<5;j++)
			cout<<m2[i][j]<<"\t";
		cout<<endl;
	}
	getche();
}