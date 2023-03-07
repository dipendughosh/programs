// Bubble Sort using pointers ***error
// In case of arrays, the pointer points the first cell

#include<iostream.h>
#include<conio.h>

void main()
{	void display(int*);
	void swap(int*,int*);
	int num[10];
	clrscr();
	cout<<"\nEnter 10 numbers :"<<endl;
	for (int i=0; i<10; i++) cin>>num[i];
	cout<<"\nUnsorted :";
	display(num);
	for (i=0; i<10-1; i++){
		for (int j=i+1; j<10; j++) {
			if ( num[i]>num[j]) swap(num+i,num+j);
			}
		}
	cout<<"\n\nSorted :";
	display(num);
}

void display(int* x) {
	for(int z=0; z<10; z++) cout<<*(x++)<<" ";
	getche();
}

void swap(int* x,int* y) {
	int temp;
	temp =*x ; *x=*y;*y=temp;
}


