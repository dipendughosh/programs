#include <fstream.h>
#include <stdlib.h>
#include <conio.h>

void main()
{   char buff[50],ch;
    ofstream outfile("tttt.txt");
    for(int i =0;i<10;i++)
        outfile<<"i*5"<<"\n";
    outfile<<" a test program\n";
    ifstream infile("tttt.txt");
    while(infile)
    {   infile.get(ch);
        cout<<ch;
    }
    cout<<endl;
    system("PAUSE");
}
