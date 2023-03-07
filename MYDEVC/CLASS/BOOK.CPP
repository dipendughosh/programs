#include <iostream.h>
#include <stdlib.h>
#include <conio.h>
class books
{   private:
        int code[5];
        int price[5];
        int flag;
    public:
        void search(int p)
        {   for(int i=0;i<5;i++)
             {  flag=0;
                if(p==code[i])
                {   cout<<"Price : "<<price[i];
                    flag=1;
                    break;
                }
            }
            if(flag==0) cout<<"\nSORRY ";
        }
        void input()
        {   for(int j=0;j<5;j++)
            {   cout<<"Code ?? "; cin>>code[j];
                cout<<"Price ?? "; cin>>price[j];
            }
        }
};

int main()
{   books b;
    int c;
    b.input();
    cout<<"Enter the code : ";  cin>>c;
    b.search(c);
    cout<<endl;
    system("PAUSE");
    return 0;
}
