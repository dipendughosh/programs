#include <iostream.h>
#include <stdlib.h>
#include <conio.h>

int main()
{   char *p[]={"kapil",
            "sachin"};
    char *x;
    int len=strlen(*p);
    x=p[1];
    p[1]=p[0];
    p[0]=x;
//    *x=p;
/*    cout.write(p[0],6).put("\n");
    cout.write(p[1],5);*/
   /* while(*p!=NULL)
    {   cout<<*p;
        p++;
    }*/

//    cout<<*p/*<<"\n"<<++*p<<"\n"<<*p[1]*/;
    for (int i=0;i<len;i++)
    {    cout<<*p;
         p++;
    }
    cout<<endl;
    system("PAUSE");
    return 0;
}
