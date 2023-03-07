#include <iostream.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <stdio.h>

class data
{   private:
    char name[20];int roll;
    public:
    data()
    {
    }
    void getdata()
    {   cout<<"\nEnter Roll no. ->";
        cin>>roll;
        cout<<"\nEnter Name ->";
        gets(name);
    }
    ~data()
    {
    }
};


class science : private data
{   private:
    int phy,mat,che,bio,com,total1;
    public:
    science()
    {
    }
    void getdata()
    {   data::getdata();
        cout<<"\nEnter physics marks->";
        cin>>phy;
        cout<<"\nEnter chemistry marks->";
        cin>>che;
        cout<<"\nEnter mathematics marks->";
        cin>>mat;
        cout<<"\nEnter biology marks->";
        cin>>bio;
        cout<<"\nEnter computer marks->";
        cin>>com;
     }
     void total()
     {  total1=phy+mat+che+bio+com;
        cout<<"\nTotal="<<total1;
        total1=total1/5;
        if(total1>=85)
        {   cout<<"\nELIGIBLE";
        }
        else
        {   cout<<"\nNOT ELIGIBLE";
        }
     }
     ~science()
     {
     }
};

class comerce : private data
{   private:
    int mat,acc,eco,com,ant,total1;
    public:
    comerce()
    {
    }
    void getdata()
    {   data::getdata();
        cout<<"\nEnter accounts marks->";
        cin>>acc;
        cout<<"\nEnter economics marks->";
        cin>>eco;
        cout<<"\nEnter mathematics marks->";
        cin>>mat;
        cout<<"\nEnter commerse marks->";
        cin>>com;
        cout<<"\nEnter eunterpraunership marks->";
        cin>>ant;
     }
     void total()
     {  total1=acc+mat+eco+ant+com;
        cout<<"\nTotal="<<total1;
        total1=total1/5;
        if(total1>=80)
        {   cout<<"\nELIGIBLE";
        }
        else
        {   cout<<"\nNOT ELIGIBLE";
        }
     }
     ~comerce()
     {
     }
};

class humanities : private data
{   private:
    int pol,his,geo,hom,evs,total1;
    public:
    humanities()
    {
    }
    void getdata()
    {   data::getdata();
        cout<<"\nEnter political science marks->";
        cin>>pol;
        cout<<"\nEnter history marks->";
        cin>>his;
        cout<<"\nEnter geography marks->";
        cin>>geo;
        cout<<"\nEnter home sience marks->";
        cin>>hom;
        cout<<"\nEnter environmental science marks->";
        cin>>evs;
     }
     void total()
     {  total1=pol+his+geo+hom+evs;
        cout<<"\nTotal="<<total1;
        total1=total1/5;
        if(total1>=70)
        {   cout<<"\nELIGIBLE";
        }
        else
        {   cout<<"\nNOT ELIGIBLE";
        }
     }
     ~humanities()
     {
     }
};

class common : private science,comerce,humanities
{   private:
    char cho;
    public:
    common()
    {
    }
    void choice()
    {   cout<<"\nEnter stream (s/c/h)->";
        cin>>cho;
    }
    void check()
    {	switch(cho)
	   {	case 's':
    			science::getdata();
    			science::total();
        		break;
    		case 'c':
    			comerce::getdata();
    			comerce::total();
    			break;
    		case 'h':
    			humanities::getdata();
    			humanities::total();
    			break;
      		case 'e':
    			cout<<"\nEixting program..........";
    			getche();
    			exit(0);
    			break;
    		default:
    			cout<<"\nWRONG CHOICE-->";
    			break;
    	}
    }
    ~common()
    {
    }
};

class menu : private common
{   public:
	menu()
	{
	}
	void format()
	{   cout<<"\n  MENU";
		cout<<"\ns.SCIENCE";
		cout<<"\nc.COMMERCE";
		cout<<"\nh.HUMANITIES";
		cout<<"\ne.EIXT";
		common::choice();
		common::check();
	}
	~menu()
	{
	}
};

int main()
{
    menu object;
    object.format();
    cout<<endl;
    system("PAUSE");
    return 0;
}
