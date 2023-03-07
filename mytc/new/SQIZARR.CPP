#include<conio.h>
#include<iostream.h>
void main()
{   clrscr();
	int length=10,s,flag=0;
	int a[10]={5,7,0,9,9,0,9,89,5,5};
	cout<<"Original array \n";
	for(int j=0;j<10;j++)
		cout<<a[j]<<"\t";
	cout<<"\n\n\n";
	for (int z=0;z<10;z++)
	{   //flag=0;
		s=a[z];
		cout<<s<<"  ";
		for(int i=z+1;i<length;i++)
		{   if(a[i]==s)
			{   cout<<i<<" "<<a[i];getch();
				for(int j=i+1;j<length;j++)
				{	a[j-1]=a[j];
				}

				flag++;
				cout<<flag<<endl;
			}
		}

	}
	length-=flag;
	cout<<"Length = "<<length;
	cout<<"Array after deletion\n";
	for(int kj=0;kj<length;kj++)
		cout<<a[kj]<<"\t";
	getch();
}
