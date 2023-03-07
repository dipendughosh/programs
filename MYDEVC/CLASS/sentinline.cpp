// programme of 2003 is incomplete
#include <iostream.h>
#include <conio.h>
class format
{   char txt[100];
    int len;
    public:
        format() {}
        void readstring()
            {   cin.getline(txt,100);
                len = strlen(txt);
            }
        char charat(int index)
            {   return str(index);  }
        void writechar(char c)
            {   cout<<c<<endl;  }
        int isupper(char c)
            {   if(c >= 65 && c <= 90) return 1;
                else return 0;
            }
        int isendofsentence(char,int);
        void formatstr();
};
void format::isendofsentence(char str,int i)
{   cin.getline(str,100);}

void main()
{
     format a;
     a.
    getche();
}
