//INCOMPLETE ,WRONG
#include<iostream.h>
#include<conio.h>
#define MAX 15
void main()
{   //const int MAX = 15;
	clrscr();
	int arr[MAX] = { 12,13,13,15,17,20,20,20,21,22,22,25,27,29,29 };
	void shoarr(int[],int);
	int n = 0, s = 0 ;
	cout<<"\n entire array :\n";
	shoarr(arr,MAX);
	do
	{   //cout<<"\narr[n] = "<<arr[n]<<"\t";
		if(arr[n] != arr[++n])
		{	s++; 	//cout<<"s = "<<s<<endl;
			continue;
		}
		//cout<<"\nn = "<<n<<endl; getche();
		while(arr[n] == arr[++n]) continue;
		arr[s] = arr[n];
	} while(n < MAX);
	cout<<"\n packed array :\n";
	shoarr(arr,s);
	getche();
}

void shoarr(int a[],int p)
{	for(int x=0; x < p; x++) cout<<a[x]<<" ";
}