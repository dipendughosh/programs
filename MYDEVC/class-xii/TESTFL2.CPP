#include <fstream.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
    ifstream infile("d:\\Dev-C++\\mydevc\\class-xii\\marks2.txt");
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
    cout << endl;
    system("PAUSE");
    return 0;
}
