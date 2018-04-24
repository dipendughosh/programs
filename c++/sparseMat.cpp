#include<iostream>
#include<conio.h>

using namespace std;

int main() {
	
	int a[3][3];
	int b[9][3];
	int i;
	int j;
	int k;
	
	cout<<"Enter elements :- \n";
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			cout<<"a["<<i<<"]["<<j<<"] = ";
			cin>>a[i][j];
		}	
	}
	
	cout<<"Entered Matrix :- \n";
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			cout<<a[i][j]<<"\t";
		}
		cout<<"\n";
	}
	
	k = 0;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			if(a[i][j] != 0){
				b[k][0] = i;
				b[k][1] = j;
				b[k][2] = a[i][j];
				k++;
			}
		}
	}
	
	cout<<"Sparse Matrix :- \n";
	for (i = 0; i < k; i++) {
		cout<<b[i][0]<<"\t"<<b[i][1]<<"\t"<<b[i][2]<<"\t";
		cout<<"\n";
	}
	
	getch();
	return 0;
}