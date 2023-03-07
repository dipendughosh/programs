#include<iostream>
using namespace std;

namespace ns1
{
	int i=10;
	class cls
	{
		public:
		int i;
		cls(int x=20)
		{
			cls::i=x;
		}
	};
	namespace ns2
	{
		int i=30;
	}
}

//int i=40;

int main()
{
/*	int i=50;
	ns1::cls ob;
	cout<<"Without using USING-\n";
	//cout<<i<<"\n"//50
	cout<<::i<<"\n"//40
	    <<ns1::i<<"\n"//10
	    <<ns1::ns2::i<<"\n"//30
	    <<ob.i<<"\n";//20*/
	using namespace ns1;
	cout<<"Using USING-\n";
	cls ob1;
	cout<<i<<"\n"//10
	    <<ns2::i<<"\n"//30
	    <<ob1.i<<"\n";//20
	return 0;
}
