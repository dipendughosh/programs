// Adding 2 long numbers (structural)
#include <iostream.h>
#include <stdlib.h>
#include <conio.h>
#define size 80
struct number
{   int digit;
    number *next;
};
class longnum
{
    char numarr[size];
    public:
    number *top,*newnode,*tempnum,*tempnode;
    int count;
    longnum(){  top = NULL; }
    number *creanode(int n)
    {
        tempnode = new number;
        tempnode->digit = n;
        tempnode->next = NULL;
        return tempnode;
    }
    void push(number*);
    void show(number*);
    void getnum()
    {
        cout<<"Enter number : ";
        cin.getline(numarr,size,'\n');
    }
    void makestak()
    {   int dig, i = 0;
        while(numarr[i] != '\0')
        {   dig = (int)numarr[i] - 48;
            newnode = creanode(dig);
            push(newnode);
            ++i;
        }
        count = i;
    }
};

void longnum::push(number *nn)
{   if(top == NULL) top = nn;
    else
    {   tempnum = top;
        top = nn;
        nn->next = tempnum;
    }
}
void longnum::show(number *np)
{   while(np != NULL)
    {   cout<<np->digit;
        np = np->next;
    }
}

void main()
{
    longnum obj1,obj2,obj3,a,b;
    obj1.getnum();
    obj1.makestak();
    cout<<endl;
    obj2.getnum();
    obj2.makestak();
    cout<<endl;
    if(obj1.count >= obj2.count)
    {    a = obj1; b = obj2;}
    else
    {    a = obj2; b = obj1;  }

    int newdig = 0, carry = 0, flag = 1;
    while(a.top != NULL)
    {
        if(flag == 1) newdig = a.top->digit + b.top->digit + carry;
        else newdig = a.top->digit + carry;
        if(newdig > 9)
        {   newdig = newdig-10;
            carry = 1;
        }
        else carry = 0;
        obj3.newnode = obj3.creanode(newdig);
        obj3.push(obj3.newnode);
        a.top = a.top->next;
        if(flag == 1)
        {   if(b.top->next == NULL) flag = 0;
            else b.top = b.top->next;
        }
    }
    if(carry > 0)
    {   obj3.newnode = obj3.creanode(carry);
        obj3.push(obj3.newnode);
    }
    cout<<"The sum is  : ";
    obj3.show(obj3.top);
    cout<<endl;
    system("PAUSE");
}

