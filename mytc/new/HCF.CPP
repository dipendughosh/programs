# include <conio.h>
# include <iostream.h>
int main()
{   
    int n1,n2,c,d,hcf,i;
    cout<<"\nEnter 1st number:";
    cin>>n1;
    cout<<"\nEnter 2nd number:";
    cin>>n2;
    if (n1>n2)
    {     c=n1;
          d=n2;
    }
    else
    {     c=n2;
          d=n1;
    }
    for(i=1;i<=d;i++)
    {	if ((c%i==0)&&(d%i==0))
          	hcf=i;
    }
    cout<<"\n 	H C F=  "<<hcf;
    getch();
    return(0);
}

