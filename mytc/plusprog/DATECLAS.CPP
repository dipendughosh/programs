#include<iostream.h>
#include<conio.h>
int daysinmon[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
class date
{	int dd,mm;
	public:
		date(int nd, int nm)
		{	dd = nd; mm = nm;	}
		int dttodtnum();
		date dtnumtodt(int);
		date futuredate(int);
		void showdate(date);
};

int date::dttodtnum()
{	int daynum = 0;
	for (int i = 1; i< mm; i++)
		daynum = daynum + daysinmon[i];
	return (daynum + dd);
}

date date::dtnumtodt(int dn)
{	date temp(0,0); int i = 1;
	int d = daysinmon[i];
	for ( ; ; )
	{	if ( (d + daysinmon[i+1]) > dn ) break;
		d += daysinmon[i++];
	}
	temp.mm = i;
	temp.dd = dn - d;
	cout<<"\n"<< dd <<" : "<< mm;
	return temp;
}

date date::futuredate(int n)
{	date temp2(0,0);
	temp2 = temp2.dtnumtodt(n);
	//cout<<"\n"<< dd <<" : "<< mm ;
	return temp2;
}

void date::showdate(date tarikh)
{	cout<<"\n"<< tarikh.dd <<" : "<< tarikh.mm ;	}

void main()
{	clrscr();
	date dt(28,7), date2(0,0), date3(0,0);
	int nod,totday;
	int rd = dt.dttodtnum();
	cout<< rd << " Days";
	date2 = dt.dtnumtodt(rd);
	//date2.showdate(date2);
	getche();
	cout<<"\nEnter number of days : "; cin>>nod;
	totday = rd + nod;
	cout<<"After "<< nod <<" days the date will be : ";
	//date3.futuredate(totday);
	//date3.showdate(date3);
	date3 = date3.dtnumtodt(totday);
	getche();
}
