#include <iostream.h>
#include <stdlib.h>
#include <conio.h>
#include <iomanip.h>
class mat
{   int arr[5][5], x,y,p ;
    public:
        mat()
        {   for(x = 0; x<5; x++)
                for(y = 0; y<5; y++)
                    arr[x][y] = 111;
        }
        void show()
        {   for(x = 0; x<5; x++)
            {   for(y = 0; y<5; y++)
                {   setw(4);
                    cout<<arr[x][y]<<"  ";
                }
                cout<<endl;
            }
        }
        int right(int r,int c,int n,int t)
        {   //p = 1;
            cout<<r<<c<<n<<"   "<<arr[0][24];
            getche();
            for(p = 0; p<t; p++)
            {   arr[r][c] = n;
                cout<<endl<<"arr["<<r<<"]["<<c<<"]= "<<arr[r][c];
                c++; n++;
                cout<<endl<<"c= "<<c<<" r= "<<r<<" arr["
                <<r<<"]["<<c<<"]= "<<arr[r][c];
                getche();
            }
            return (r+1,c-1,n-1);
        }
        int down(int r,int c,int n,int t)
        {   for (p =0;p<t;p++)
            {   arr[r][c] = n++;
                r++;
            }
            return(r-1,c-1,n-1);
        }
        int left(int r,int c,int n,int t)
        {   for(p = 0;p<t;p++)
            {   arr[r][c] = n++;
                c--;
            }
            return(r-1,c+1,n-1);
        }
        int up(int r,int c,int n,int t)
        {   for(p = 0;p<t;p++)
            {   arr[r][c] = n++;
                r--;
            }
            return(r+1,c+1,n-1);
        }
};
int main()
{   mat obj;
    int rot = 1, row = 0, col = 0,i = 1,times = 5;
    while(i<=25)
    {   switch(rot)
        {   case 1 : obj.right(row,col,i,times);
                     --times;
                     break;
            case 2 : obj.down(row,col,i,times);
                     break;
            case 3 : obj.left(row,col,i,times);
                     --times;
                     break;
            case 4 : obj.up(row,col,i,times);
                     break;
        }
        rot += 1;
        if (rot>4) rot = 1;

        cout<<"\nrot = "<<rot;
        getche();
    }
    obj.show();
    cout<<endl;
    system("PAUSE");
    return 0;
}
