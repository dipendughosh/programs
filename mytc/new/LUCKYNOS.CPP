# include<conio.h>
# include<iostream.h>
# include<stdio.h>
void main()
{	int arr[10] = { 4,89,7,6,2,7,4,21,14,5 };
	int num, i = 0, ctr = 0, rep = 0, j;
	clrscr();
	for(j=0; j<10; j++) cout<<arr[j]<<"\t";
	cout<<"Enter a number : ";
	cin>>num;
	do
	{   if(arr[i] == 0)
		{	i < 10 ? i++ : 0 ;
			continue;
		}
		if (ctr == num)
		{	arr[i] = 0;
			rep++;
			ctr = 1;
			cout<<"\tctr=num "<<ctr<<"\t"<<num<<"\t"<<i;
		}
		i < 10 ? i++ : 0;
		ctr++;
		cout<<"ctr!=num "<<ctr<<"\t"<<num<<"\t"<<i<<endl;
		getch();
	}
	while (rep<10);
	for(j=0; j<10; j++)
		if (arr[j] != 0) cout<<arr[j];
	getch();
}


