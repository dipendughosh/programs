#include <iostream.h>
#include <conio.h>
#include <stdlib.h>

void main()
{   int n=44;
    cout<<"n = "<<n<<endl;
    cout<<"&n = "<<&n;
    int* pn=&n;
    cout<<"\nAfter int*pn =&n \n";
    cout<<"n = "<<n<<"\tpn= "<<pn<<"\t&pn= "<<&pn<<"\t*pn= "<<*pn;
    *pn=77;
    cout<<"\nafter *pn = 77\n";
    cout<<"n = "<<n<<"\tpn= "<<pn<<"\t&pn= "<<&pn<<"\t*pn= "<<*pn;
    int* q=&n;
    cout<<"\nafter int*q = &n\n";
    cout<<"n = "<<n<<"\tpn= "<<pn<<"\t&pn= "<<&pn<<"\t*pn= "<<*pn;
    cout<<"\nq= "<<q<<"\t\t&q= "<<&q<<"\t*q= "<<*q;
    getche();
    return 0;
}
