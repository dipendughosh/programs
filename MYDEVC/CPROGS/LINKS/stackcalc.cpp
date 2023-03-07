#include <iostream.h>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>
class stack
{   private:
    char starr[50];
    int top;
    public:
        stack() { top = -1; }
        void push(char data) { starr[++top] = data ;}
        void pop() { top--; }
        /*void getstack()
        {   cout<<"Enter Expression : "; gets(starr);
            top = strlen(starr);
        } */
        void shostack()
        {   cout<<"\nThe stack is :\n";
            for(int x=top;x>=0;x--) cout<<starr[x]<<endl;
        }
        int topcell() { return top; }
        char whattop() { return starr[top]; }
};

void main()
{   stack one,two;
    char exp[50];
    gets(exp);
    for(int i=strlen(exp);i>=0;i--) one.push(exp[i]);
    int t,num1,num2,retnum,sum = 0;
    char temp,chr1,chr2;
    //one.getstack();
    one.shostack();getche();
    do
    {   t = one.topcell();
        //cout<<"\ntopcell--> "<<t; getche();
        temp = one.whattop();
        //cout<<"\nt is "<<t<<"\ttemp is "<<temp<<endl;
        one.pop();
        cout<<"\nPopped from one ---->";
        one.shostack();getche();
        if(isdigit(temp))
        {
            cout<<"digit "<<temp;
            two.push(temp);
            cout<<"\nPushed in two <====";
            getche();
        }
        else
        {   chr1 = two.whattop();
            num1 = chr1-48;
            two.pop();
            cout<<"\nPopped from two ====>";
            chr2 = two.whattop();
            num2 = chr2-48;
            two.pop();
            cout<<"\nPopped from two ====>";
            switch(temp)
            {   //case '^' : retnum = pow(num2,num1); break;
                case '*' : retnum = num2*num1; break;
                case '/' : retnum = num2/num1; break;
                case '+' : retnum = num2+num1; break;
                case '-' : retnum = num2-num1; break;
            }
            cout<<"\t"<<retnum;
            getche();
            two.push(retnum);
            cout<<"\nPushed to two <====";
            cout<<" two.top now ==>>"<<two.topcell();
            sum += retnum;
            //cout<<"\t"<<sum;
            getche();
        }
    } while(one.topcell()>=0);
    cout<<"\nThe Answer is : "<< sum;
    cout<<endl;
    system("PAUSE");
}
