#include<iostream.h>
#include<conio.h>
class time
{	int hrs,mins,secs;
	public:
	time() {hrs=0;mins=0;secs=0;};
	void gettime(int h,int m,int s)
	{	hrs = h; mins = m; secs = s;	}
	void shotime()
	{	cout<<"\nThe time is : "<<hrs<<" Hrs. "
			<<mins<<" Mins. and "<<secs<<" Secs.";
	}
	friend void addtime(time,time)
};

void addtime(time a,time b)
{   time t3;
	t3.secs = a.secs + b.secs;
	while (t3.secs >= 60) { t3.secs -= 60; t3.mins++; }
	t3.mins += (a.mins + b.mins);
	while (t3.mins >= 60) {	t3.mins -= 60; t3.hrs++ ;}
	t3.hrs += (a.hrs + b.hrs);
	cout<<endl;
	t3.shotime();
}

void main()
{	time t1,t2;
	clrscr();
	t1.gettime(15,57,27);
	t2.gettime(10,47,57);
	clrscr();
	t1.shotime();
	t2.shotime();
	addtime(t1,t2);
//	shotime();
	getche();
}




