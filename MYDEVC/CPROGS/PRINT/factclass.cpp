#include <iostream.h>
#include <conio.h>
#include <math.h>
class number
{   float num,simp,fact,nn;
    public:
        void factor(float num)
        {   fact = 1; nn = num;
            while(num) fact = fact * num--;
            fact = nn / fact;
            if (iseven(nn)) fact = fact * -1;
        }

        void sum()
        {   simp = simp + fact; }

        void show()
        {   cout<<"\nResult is : "<<simp; }

        int iseven(float p)
        {   float x = p/2, y = p/2;
            if (x != y) return 0;
        }
};
number obj;

int main()
{   float n;
    cout<<"Enter a number : "; cin>>n;
    for (int i=1; i<=n; i++)
    {   obj.factor(i);
        obj.sum();
    }
    obj.show();
    getche();
    return 0;
}
