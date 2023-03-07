#include <fstream.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
    ofstream outfile;
    outfile.open("d:\\Dev-C++\\mydevc\\class-xii\\marks2.txt", ios::out);
    char ans = 'y';
    int roll, marks;
    do
    {
        cout<<"\nEnter Roll No.: "; cin>>roll;
        cout<<"\nEnter Marks   : "; cin>>marks;
        outfile<<roll<<'\n'<<marks<<'\n';
        cout<<"\nMore ? "; cin>>ans;
    }
    while(ans == 'y' || ans == 'Y');
    outfile.close();
    cout<<endl;
    system("PAUSE");
    return 0;
}
