#include <iostream.h>            //INCOMPLETE
#include <conio.h>

int main()
{   int arr[5][5];
    void east(int[5][5],int,int,int,int);
    int west(int[5][5],int,int,int,int);
    int north(int[5][5],int,int,int,int);
    int south(int[5][5],int,int,int,int);
    void shoarr(int[5][5],int);
    int i = 0,j = 0,size = 5, n = 1;
    east(arr,i,j,size,n);
    n+=size; size--;
    while(size)
    {   i++; j=size;
        south(arr,i,j,size,n); //1,4,4,6 +
                               //4,4,4,10 -
        shoarr(arr,5);
        break;
    }
    getche();
    return 0;
}

int east(int a[5][5],int r,int c,int len, int num)
{   int ln = 0;
    while(ln++<len)
    {   a[r][c] = num++;
        c++;
    }
cout<<"\nc= "<<c<<endl;
    return(a[5][5],r,c-1,len,num);
}

int south(int a[5][5],int r,int c,int len, int num)
{   int ln = 0;
    while(ln++<len)
    {   a[r][c] = num++;
        r++;
    }
    return 0;
}

void shoarr(int a[5][5],int s)
{   for(int x = 0; x < s; x++)
    {   for(int y = 0; y < s; y++)
            cout<<a[x][y]<<"\t";
        cout<<endl;
    }
}
