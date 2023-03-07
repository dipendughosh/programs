//**************INCOMPLETE***************
//TO MULTIPLY (IN LONG FASHION) A 3 & 4 DIGIT NOS.
#include<iostream.h>
#include<conio.h>
#include<stdio.h>
void main()
{	clrscr();
	int num1,num2,num,i,j,k,ch,step[4][7],copy,no1,no2;
	cout<<"enter a 4 digit no ";	cin>>num1;
	cout<<"enter a 3 digit no ";	cin>>num2;
	//initialising array
	for(i=0;i<4;i++)
	{	for(j=0;j<7;j++)
			step[i][j]=0;
	}

	copy=num1;	 i=0;	k=6;
	while(num2)
	{	no2 = num2 % 10	;
		j = k;
		num1 = copy;
		while ( num1 )
		{	no1 = num1 % 10;
			ch= no1 * no2;
			step[i][j] += ch;
			num = step[i][j];
			step[i][j] = step[i][j] % 10;
			cout<<i<<"\t"<<j<<"\t = "<<step[i][j]<<"\n";	getche();
			step[i][j--] = num / 10;
			num1 /=10;
		}
		cout<<"\n";
		num2 /= 10;
		i++;	k--;
		cout<<"\n checking val in 0,5 /n "<<step[0][5]<<"\n";
	}
	cout<<"\n the array step is  \n ";
	for(i=0 ; i<3; i++)
	{	for( j=0; j<7; j++)
		{	cout<<step[i][j]<<"\t";
		}
	cout<<"\n";
	}

	i = 0;	  j = 6;
	while(j)
	{	step[3][j] += step[i][j] + step[i+1][j] + step[i+2][j];
		num = step[3][j];
		step[3][j] = step[3][j] % 10;
		step[i][j--] = num / 10;

	}
	/*for(i=0 ; i<3; i++)
	{	for( j=0; j<6; j++)
		{	cout<<step[i][j]<<"\t";
			//getche();
		}
		cout<<"\n";
	}    */
	getche();
}

