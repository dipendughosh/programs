//input nikhil,2,2: output ik.
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<iostream.h>

void main()
{	clrscr();
	int no1,no2,a=0,num=0,sub=0;
	char w[21],n[15],n2[15];
	cout<<"Enter a word : " ;
	gets(w);
	cout<<"\nPosition of the letter : "; cin>>no1;
	cout<<"\nNumber of letters : "; cin>>no2;
	int i=no1-1;
	while(num<no2)
	{	n[a++]=w[i++];
		num++;
	}
	n[a]='\0';
	cout<<endl;
	for(int p=0;n[p]!='\0';p++) cout<<n[p];
	for(int q=0;q<no1-1;q++) n2[sub++]=w[q];
	for(int k=no1+no2-1;w[k]!='\0';k++) n2[sub++]=w[k];
	n2[sub]='\0';
	puts(n2);
	getch();
}