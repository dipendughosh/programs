// Step1: skips 1 no.; Step2: skips 2 nos. and so on...
#include <iostream.h>
#include <conio.h>
void main()
{
    clrscr();
    int arr[50],i = 0,k = 0,l = 50,dob=0;
    void disparr(int[],int);
    for(; i<l; i++) arr[i] = i+1;
    int skip = 2;
    cout<<"\nPlease enter your date of birth....";cin>>dob;
    dob++;
    l=dob;
    do
    {   k = 0;
	for(i = 0; i<l; i+=skip) arr[k++] = arr[i];
	//cout<<"\nAfter skipping "<<skip-1<<" : \n";  // Showing steps
	//disparr(arr,k);
	l = k;
	skip++;
    } while(skip<=l);
    cout<<"\nHence Lucky Numbers  :\n";
    disparr(arr,k);
    getche();
}

void disparr(int a[],int n)
{   for(int d = 0; d<n; d++) cout<<a[d]<<" ";
    cout<<endl;
}
