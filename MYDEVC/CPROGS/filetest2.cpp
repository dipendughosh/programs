//file which prints roll no.s
#include <fstream.h>
#include <stdlib.h>
#include <conio.h>
//#include <string.h>

int main()
{   char str[80];
    int i,roll;
    ofstream outfile("tata.dat");
    for (i=0;i<3;i++)
    {   //cout<<"Enter name : "; cin>>str;
        cout<<"Enter roll : "<<i<<"\t"; cin>>roll;
        //outfile<<str<<"\n";
        outfile<<roll<<"\n";
    }
    cout<<endl;
    outfile.close();
    ifstream infile("tata.dat");
    while (infile)
    {   //infile.getline(str,80);
        infile>>roll;
        //cout<<str;
        cout<<"\t"<<roll<<"\n"; getche();
    }
    cout<<endl;
    system("PAUSE");
    return 0;
}
