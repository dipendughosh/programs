#include<iostream.h>
#include <fstream.h>
#include <stdlib.h>
#include <conio.h>

void main()
{   clrscr();
    ifstream infile(/*"d:\\programs\\class11&12\\Files\\*/"marks2.txt");
    int roll, marks;
    char ch;
    infile.seekg(0);
    do
    {
        infile >> roll;
        infile.get(ch);
        infile >> marks;
        infile.get(ch);
        if(roll > 0)
        {   cout << "\nRoll No.: " << roll;
            cout << "\tMarks : " << marks;
	}
    } while(infile);
    infile.close();
    getche();
}
