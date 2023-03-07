// Arrange numbers in array

#include<iostream.h>
#include<conio.h>
void main()
{   clrscr();
	const int len = 5;
	int arr[len] = { 7,42,15,43,56 };
	int large = arr[0];
	int place, mid = len/2, lp, pp, pq = 1;
	int findlarge1(int[], int, int);
	int findlarge2(int[], int, int);
	void showarr(int[], int);
	void swap(int[], int, int);
	cout<<"The original array is :\n";
	showarr(arr,len);
	cout<<endl;
	for(int i = 0; i < len; i++)
	{	if(arr[i] > large)
		{	large = arr[i];
			lp = i;
		}
	}                    					// Finds the largest number
	place = mid;
	swap(arr,place,lp);                     // Places it in the middle
	cout<<"The steps --->\n";
	showarr(arr,len);
	for(int j = 1; j < len-1; j++)
	{	large = findlarge1(arr,len,large);  // To find the next largest
		lp = findlarge2(arr,len,large);  // To find position of that
		pp = j < 3 ? -1 : -2;
		pq = pq * pp;
		place = mid + pq;              // manages the criss-cross position
		swap(arr,place,lp);
		showarr(arr,len);
	}
	cout<<"\nThe final position : \n";
	showarr(arr,len);
	getche();
}

int findlarge1(int a[], int arrl, int l)
{   int big = 0;
	for(int x = 0; x < arrl; x++)
	{	if(a[x] >= l) continue;
		if(a[x] > big) big = a[x];
	}
	return big;
}

int findlarge2(int a[], int arrl, int l)
{   for(int xx = 0; xx < arrl; xx++)
		if(a[xx] == l) return xx;// break;
	//return xx;
}

void swap(int a[], int to, int from)
{	int temp;
	temp = a[to];
	a[to] = a[from];
	a[from] = temp;
}

void showarr(int a[], int arrl)
{	for(int x = 0; x < arrl; x++)
		cout<<a[x]<<"\t";
	cout<<endl;
}
