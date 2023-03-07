#include<iostream.h>
#include<conio.h>
#include<math.h>
void main()
{ clrscr();
  long a,del,k,rep,g,j=0,l;
  int c=0;
  cout<<" enter the no ";
  cin>>a;
  cout<<" enter the no 2 b deleted";
  cin>>del;
  cout<<" no 2 b replaced with";
  cin>>rep;
  g=a;
  l=a;
  while(a!=0)
  {a=a/10;c++;}
 // cout<<" no of elements= "<<c;
  int y=0;
  while(g!=0)
  { k=g%10;
	if(k!=del)
	 { j+=k*(pow(10,(y++)));}
	  g=g/10;
  }   long z=0;
 // cout<<" j= "<<j<<" no of elements   "<<y;
  int i=c-y;
  for(int x=0;x<i;x++)
	z=z+(rep*(pow(10,x)));
   //	cout<<"z= "<<z;
	for(int w=0;w<y;w++)
	 { z+=(j%10)*(pow(10,(i++)));
	   j=j/10;
	 }
	 cout<<"\n final no is "<<z;
	 cout<<"\n difference=";
	 if(z>l)
	  cout<<z-l;
	 else
	  cout<<l-z;
 getche();
}





