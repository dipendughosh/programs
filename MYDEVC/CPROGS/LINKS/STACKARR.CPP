// Handlig array as a Stack
#include <iostream.h>
#include <stdlib.h>
#include <conio.h>
#define MAX 5
void main()
{
    int arr[MAX], index = 0, num, full = 0;
    void showstack(int[],int);
    void pushdata(int[],int&,int);
    void popdata(int[],int&);
    char more = 'y';
    do
    {   cout << "Number to push : "; cin >> num;
        pushdata(arr,index,num);
        if(index == MAX)
        {   full = 1;
            cout<<"\nThe stack is full!";
            break;
        }
        cout<<"More? "; cin >> more;
    } while(more == 'Y' || more == 'y');
    index -= 1;
    showstack(arr,index);
    do
    {
        cout<<"\nPop from stack ? "; cin >> more;
        if(more == 'y' || more == 'Y')
        {   popdata(arr,index);
            cout<<"\nAfter pop,";
            showstack(arr,index);
        }
    } while(more == 'Y' || more == 'y');
    cout<<"\nThe final ";
    showstack(arr,index);
    cout<<endl;
    system("PAUSE");
}

void pushdata(int a[],int& top,int n)
{   a[top] = n;
    top++;
}
void popdata(int a[],int& top)
{   --top;  }
void showstack(int st[],int top)
{   cout << "Stack is ";
    for(int i = top; i >= 0; i--)
        cout<<"\n"<<st[i];
}
