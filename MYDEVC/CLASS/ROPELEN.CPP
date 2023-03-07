// Adding 3 rope objects : 1 fixed length, other two variable

#include <iostream.h>
#include <stdlib.h>
#include <conio.h>
class rope
{   int feet, inches;
    public:
        rope()
        {   feet = 0, inches = 0;
        }
        rope(int f, int i)
        {   feet = f;
            inches = i;
        }
        void getlength()
        {   cout<<"Enter length :\n";
            cout<<"Feet   : "; cin>>feet;
            do
            {   cout<<"Inches : "; cin>>inches;
            } while (inches > 11 || inches < 0);
        }
        void showlength()
        {   cout<<"the length is :\n";
            cout<<feet<<" Feet and "<<inches<<" Inches";
        }
        rope addlength(rope, rope);
};
rope rope::addlength(rope one, rope two)
{   rope three;
    three.inches = one.inches + two.inches;
    if(three.inches > 11)
    {   three.feet++;
        three.inches = three.inches - 12;
    }
    three.feet = three.feet + one.feet + two.feet;
    return three;
}

int main()
{   rope ropemain(3,10),rope1, rope2;
    cout<<"\nMain rope is 3 feet and 10 inches long\n";
    cout<<"\nRope 1 : ";
    rope1.getlength();
    cout<<"\nRope 2 : ";
    rope2.getlength();
    rope temp = ropemain.addlength(rope1, rope2);
    cout<<"\nAdding these two, ";
    temp.showlength();
    cout<<"\n\nFinally, ";
    rope final = ropemain.addlength(temp,ropemain);
    final.showlength();
    cout<<endl;
    system("PAUSE");
    return 0;
}
