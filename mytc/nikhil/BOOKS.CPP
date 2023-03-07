#include<string.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<iostream.h>
#include<process.h>

class stock
{  	private:
		char title[51];
		char publisher[51];
		char author[51];
		int price;
		int stock_pos;
		int ch;
		int copies;
		int rec;
	public:
        void input();
        void cust_inquiry();
		int search(char[],char[]);
		//void order();
};

void stock::input()
{	cout<<"\nEnter the details for BOOK \n";
	cout<<"Enter the title of the book ...";  gets(title);
	cout<<"Enter the author of the book...";  gets(author);
	cout<<"Enter the publisher's name...";  gets(publisher);
	cout<<"Enter the price of the book ...";  cin>>price;
	cout<<"Enter the stock position ...";   cin>>stock_pos;

}

int stock::search(char p[],char q[])
{   if((strcmp(q,author)==0) || (strcmp(p,title)==0))
    {	cout<<"\n\nBOOK DETAILS...\n";
		cout<<"Title : ";  puts(title);
		cout<<"Author : ";  puts(author);
		cout<<"Publisher : ";  puts(publisher);
		cout<<"Price : Rs. "<<price;
		//rec=j;
        return 1;
	}
	else return 0;
}
/*void stock::order()
{   int flag=0;
    cout<<"\nEnter the number of copies required....";
	cin>>copies;
	for(int k=0;k<3;k++)
	{	if(copies==stock_pos[k] || copies<stock_pos[k])
		{	cout<<"\nThe total price you have to pay is "
				<<(copies*(price[rec]));
			flag=1;
		}
	}
	if(flag==0) cout<<"\nSORRY!! The requested number of copies are not available.";
} */


void main()
{   clrscr();
	stock library[3];
    for(int x=0;x<3;x++)  library[x].input();
    char t[51],a[51];
    cout<<"\t\tCUSTOMER SEARCH.....\n";
	cout<<"Enter the title of the book ";
	gets(t);
	cout<<"Enter the author's name ";
	gets(a);
    for(int y=0;y<3;y++)
    {   if((library[y].search(t,a)))  break;
        else
        {   if(y==2)
            { cout<<"\nSORRY !!! There is no such book in our stock.";
              getch();
              exit(0);
            }
        }
    }
 	getch();
}
