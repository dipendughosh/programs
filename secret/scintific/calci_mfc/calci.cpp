#include <afxwin.h>
#include <stdlib.h>
#include <math.h>
#include "resource.h"
#include "verylong.h"
#define pi 3.1415926535897932384626433832795/180

CString str,edi,answ,sav1,sav2;
CString temp;
int bk,id,len,er=0;
double res;
FILE *fp,*sk;

//very long calculation variables
int f1;
char vla[32000]="",vlb[32000]="",vlc[32000]="";

class mydialog1:public CDialog
{
public:
	mydialog1(int n):CDialog(n)
	{
	}

	void solve()
	{
		CString xsol,ysol;
		CString a1,b1,c1,a2,b2,c2;
		double x1,y1,z1,x2,y2,z2,x,y;
		char *endptr;

		GetDlgItemText(3011,a1);
		GetDlgItemText(3012,b1);
		GetDlgItemText(3013,c1);
		GetDlgItemText(3014,a2);
		GetDlgItemText(3015,b2);
		GetDlgItemText(3016,c2);

		x1=strtod(a1,&endptr);
		y1=strtod(b1,&endptr);
		z1=strtod(c1,&endptr);
		x2=strtod(a2,&endptr);
		y2=strtod(b2,&endptr);
		z2=strtod(c2,&endptr);
		
		x=(y1*z2-y2*z1)/(y1*x2-x1*y2);
		y=(x2*z1-x1*z2)/(y1*x2-x1*y2);

		xsol.Format("%lf",x);
		ysol.Format("%lf",y);

		if(xsol=="-1.#IND00" || xsol=="-1.#INF00" || ysol=="-1.#IND00" || ysol=="-1.#INF00")
		{
			xsol="Invalid Input";
			ysol="Invalid Input";
		}

		SetDlgItemText(3017,xsol);
		SetDlgItemText(3018,ysol);
	}

	void reset()
	{
		int i,n=3011;
		for(i=0;i<8;i++)
			SetDlgItemText(n+i,"");
	}
	DECLARE_MESSAGE_MAP()
};

BEGIN_MESSAGE_MAP(mydialog1,CDialog)
	ON_COMMAND(3019,solve)
	ON_COMMAND(30110,reset)
END_MESSAGE_MAP()

class mydialog2:public CDialog
{
public:
	mydialog2(int n):CDialog(n)
	{
	}

	void solve()
	{
		//Crout's method
		CString a1,e1,c1,d1,a2,e2,c2,d2,a3,e3,c3,d3,xsol,ysol,zsol;
		double a11,a12,a13,b1,a21,a22,a23,b2,a31,a32,a33,b3;
		double x11,x12,x13,y1,x21,x22,x23,y2,x31,x32,x33,y3;
		double x,y,z;
		char *endptr;

		GetDlgItemText(3021,a1);
		GetDlgItemText(3022,e1);
		GetDlgItemText(3023,c1);
		GetDlgItemText(3024,d1);
		GetDlgItemText(3025,a2);
		GetDlgItemText(3026,e2);
		GetDlgItemText(3027,c2);
		GetDlgItemText(3028,d2);
		GetDlgItemText(3029,a3);
		GetDlgItemText(30210,e3);
		GetDlgItemText(30211,c3);
		GetDlgItemText(30212,d3);

		a11=strtod(a1,&endptr);
		a12=strtod(e1,&endptr);
		a13=strtod(c1,&endptr);
		b1=strtod(d1,&endptr);
		a21=strtod(a2,&endptr);
		a22=strtod(e2,&endptr);
		a23=strtod(c2,&endptr);
		b2=strtod(d2,&endptr);
		a31=strtod(a3,&endptr);
		a32=strtod(e3,&endptr);
		a33=strtod(c3,&endptr);
		b3=strtod(d3,&endptr);
		
		x11=a11;
		x21=a21;
		x31=a31;
		x12=a12/a11;
		x13=a13/a11;
		y1=b1/a11;
		x22=a22-x12*x21;
		x23=(a23-x13*x21)/x22;
		y2=(b2-y1*x21)/x22;
		x32=a32-x12*x31;
		x33=a33-x23*x32-x13*x31;
		y3=(b3-y2*x32-y1*x31)/x33;
		
		z=y3;
		y=y2-x23*z;
		x=y1-x13*z-x12*y;
		xsol.Format("%lf",x);
		ysol.Format("%lf",y);
		zsol.Format("%lf",z);

		if(xsol=="-1.#IND00" || xsol=="-1.#INF00" || ysol=="-1.#IND00" 
					|| ysol=="-1.#INF00" || zsol=="-1.#IND00" || zsol=="-1.#INF00")
		{
			xsol="Invalid Input";
			ysol=xsol;
			zsol=xsol;
		}

		SetDlgItemText(30213,xsol);
		SetDlgItemText(30214,ysol);
		SetDlgItemText(30215,zsol);
	}

	void reset()
	{
		int i,n=3021;
		for(i=0;i<9;i++)
			SetDlgItemText(n+i,"");
		n=30210;
		for(i=0;i<6;i++)
			SetDlgItemText(n+i,"");
	}

	DECLARE_MESSAGE_MAP()
};
BEGIN_MESSAGE_MAP(mydialog2,CDialog)
	ON_COMMAND(30216,solve)
	ON_COMMAND(30217,reset)
END_MESSAGE_MAP()

class mydialog3:public CDialog
{
public:
	mydialog3(int n):CDialog(n)
	{
	}

	void solve()
	{
		CString a1,b1,c1,x1sol,x2sol,xre,xim;
		double a,b,c;
		double d,r1,x1,x2;
		char *endptr;

		GetDlgItemText(3031,a1);
		GetDlgItemText(3032,b1);
		GetDlgItemText(3033,c1);
		a=strtod(a1,&endptr);
		b=strtod(b1,&endptr);
		c=strtod(c1,&endptr);
		d=(b*b)-(4*a*c);
		if(d<0) 
		{
			d=-d;
			r1=sqrt(d);
			x1=-b/(2*a);
			x2=r1/(2*a);
			xre.Format("%lf",x1);
			xim.Format("%lf",x2);
			x1sol=xre + " + " + xim + " i";
			x2sol=xre + " - " + xim + " i";
		}
		else if(d>=0)
		{
			r1=sqrt(d);
			x1=(-b+r1)/(2*a);
			x2=(-b-r1)/(2*a);
			x1sol.Format("%lf",x1);
			x2sol.Format("%lf",x2);
		}
		if(a==0.000000)
		{
			x1=-c/b;
			x2=x1;
			x1sol.Format("%lf",x1);
			x2sol.Format("%lf",x2);
		}
		if(x1sol=="-1.#IND00" || x2sol=="-1.#IND00")
		{
			x1sol="Invalid Input";
			x2sol=x1sol;
		}
		SetDlgItemText(3034,x1sol);
		SetDlgItemText(3035,x2sol);
	}

	void reset()
	{
		int i,n=3030;
		for(i=0;i<6;i++)
			SetDlgItemText(n+i,"");
	}

	DECLARE_MESSAGE_MAP()
};
BEGIN_MESSAGE_MAP(mydialog3,CDialog)
	ON_COMMAND(3036,solve)
	ON_COMMAND(3037,reset)
END_MESSAGE_MAP()

class mydialog4:public CDialog
{
public:
	mydialog4(int n):CDialog(n)
	{
	}
	
	void solve()
	{
		//Bisection method
		CString a3,a2,aone,a0,x1sol,x2sol,x3sol;
		double a,b,c,d;
		long double x,a1,b1,d1,xn,x1,x2,n;
		char *endptr;
		int itr=0,i=0;

		GetDlgItemText(3041,a3);
		GetDlgItemText(3042,a2);
		GetDlgItemText(3043,aone);
		GetDlgItemText(3044,a0);
		a=strtod(a3,&endptr);
		b=strtod(a2,&endptr);
		c=strtod(aone,&endptr);
		d=strtod(a0,&endptr);

		if((a3=="" && a2=="" && aone=="")||(a==0 && b==0 && c==0))
		{
			SetDlgItemText(3045,"Invalid Input");
			SetDlgItemText(3046,"Invalid Input");
			SetDlgItemText(3047,"Invalid Input");
			return;
		}

		else if(b==0 && c==0 && d==0)
		{
			SetDlgItemText(3045,"0");
			SetDlgItemText(3046,"0");
			SetDlgItemText(3047,"0");
			return;
		}

		else if(a==0 && b==0)
		{
			x1=-d/c;
			x1sol.Format("%Lf",x1);
			SetDlgItemText(3045,x1sol);
			SetDlgItemText(3046,"Not Defined");
			SetDlgItemText(3047,"Not Defined");
			return;
		}

		else if(a==0)
		{
			double q1,q2,i1;
			a=b;
			b=c;
			c=d;
			d=(b*b)-(4*a*c);
			if(d<0)
			{
				q1=-b/(2*a);
				i1=sqrt(-d)/(2*a);
				x1sol.Format("%lf + %lf i",q1,i1);
				x2sol.Format("%lf - %lf i",q1,i1);
				SetDlgItemText(3045,x1sol);
				SetDlgItemText(3046,x2sol);
				SetDlgItemText(3047,"Not Defined");
				return;
			}
			else
			{
				q1=(-b+sqrt(d))/(2*a);
				q2=(-b-sqrt(d))/(2*a);
				x1sol.Format("%lf",q1);
				x2sol.Format("%lf",q2);
				SetDlgItemText(3045,x1sol);
				SetDlgItemText(3046,x2sol);
				SetDlgItemText(3047,"Not Defined");
				return;
			}
		}

		else if(d==0)
		{
			double q1,q2,i1;
			d=(b*b)-(4*a*c);
			if(d<0)
			{
				q1=-b/(2*a);
				i1=sqrt(-d)/(2*a);
				x1sol.Format("%lf + %lf i",q1,i1);
				x2sol.Format("%lf - %lf i",q1,i1);
				SetDlgItemText(3045,x1sol);
				SetDlgItemText(3046,x2sol);
				SetDlgItemText(3047,"0");
				return;
			}
			else
			{
				q1=(-b+sqrt(d))/(2*a);
				q2=(-b-sqrt(d))/(2*a);
				x1sol.Format("%lf",q1);
				x2sol.Format("%lf",q2);
				SetDlgItemText(3045,x1sol);
				SetDlgItemText(3046,x2sol);
				SetDlgItemText(3047,"0");
				return;
			}
		}
		
		while(func(i,a,b,c,d)*func(i+1,a,b,c,d)>0)
		{
			a1=i;
			b1=i+1;
			i++;
			if(i==3276700)break;
		}
		a1=i;
		b1=i+1;
		if(a1>32767)
		{
			i=0;
			while(func(i,a,b,c,d)*func(i-1,a,b,c,d)>0)
			{
				a1=i;
				b1=i-1;
				i--;
			}
			a1=i;
			b1=i-1;
		}
		bisect(&x,a1,b1,&itr);
		do
		{
			if(func(a1,a,b,c,d)*func(x,a,b,c,d)<0)
			b1=x;
			else
			a1=x;
			bisect(&xn,a1,b1,&itr);
			x=xn;
		}while(itr<100);
		c=(a*xn+b)*xn+c;
		b=a*xn+b;
		d1 = b*b-(4*a*c);
		if(d1==0)
		{
			x1=-b/(2.0*a);
			x2=x1;
			x1sol.Format("%Lf",x1);
			x2sol.Format("%Lf",x2);
			x3sol.Format("%Lf",xn);
		}
		else if(d1>0)
		{
			x1=(-b+sqrt(d1))/(2.0*a);
			x2=(-b-sqrt(d1))/(2.0*a);
			x1sol.Format("%Lf",x1);
			x2sol.Format("%Lf",x2);
			x3sol.Format("%Lf",xn);
		}
		else if(d1<0)
		{
			n=sqrt(-d1)/(2.0*a);
			x1=-b/(2.0*a);
			x1sol.Format("%Lf + %Lf i",x1,n);
			x2sol.Format("%Lf - %Lf i",x1,n);
			x3sol.Format("%Lf",xn);
		}
		SetDlgItemText(3045,x1sol);
		SetDlgItemText(3046,x2sol);
		SetDlgItemText(3047,x3sol);
	}

	long double func(long double x,long double a,long double b,long double c,long double d)
	{
		return a*x*x*x+b*x*x+c*x+d;
	}

	void bisect(long double *x,long double a1,long double b1,int *itr)
	{
		*x=(a1+b1)/2;
		++(*itr);
	}

	void reset()
	{
		int i,n=3041;
		for(i=0;i<7;i++)
			SetDlgItemText(n+i,"");
	}

	DECLARE_MESSAGE_MAP()
};
BEGIN_MESSAGE_MAP(mydialog4,CDialog)
	ON_COMMAND(3048,solve)
	ON_COMMAND(3049,reset)
END_MESSAGE_MAP()

class mydialog5:public CDialog
{
public:
	mydialog5(int n):CDialog(n)
	{
	}

	void mult()
	{	
		CString o11,o12,o22;
		int m,n,p;
		int i,j=0,k=0,l;
		CString te;

		GetDlgItemText(3051,o11);
		GetDlgItemText(3052,o12);
		SetDlgItemText(3053,o12);
		GetDlgItemText(3054,o22);
		m=atoi(o11);
		n=atoi(o12);
		p=atoi(o22);
		
		CString matA,matB;
		CString eA[100],eB[100];
		double ela[100],elb[100];
		GetDlgItemText(3055,matA);
		GetDlgItemText(3056,matB);

		matA.TrimLeft();
		matA.TrimRight();
		matB.TrimLeft();
		matB.TrimRight();
		
		matA=matA+" ";
		matB=matB+" ";
		
		char *endptr;
		l=matA.GetLength();
		for(i=0;i<l;i++)
		{
			te=matA.Mid(i,1);
			if(te==" ")
			{
				te.Format("%d",i);
				eA[j]=matA.Mid(k,i-k);
				k=i+1;
				ela[j]=strtod(eA[j],&endptr);
				j++;
			}
		}
		if(j!=(m*n))
		{
			SetDlgItemText(3057,"Number of elements illegal in matrix A");
			return;
		}
		j=0;
		k=0;
		l=matB.GetLength();
		for(i=0;i<l;i++)
		{
			te=matB.Mid(i,1);
			if(te==" ")
			{
				te.Format("%d",i);
				eB[j]=matB.Mid(k,i-k);
				k=i+1;
				elb[j]=strtod(eB[j],&endptr);
				j++;
			}
		}
		if(j!=(n*p))
		{
			SetDlgItemText(3057,"Number of elements illegal in matrix B");
			return;
		}

		double A[10][10],B[10][10],C[10][10];
		k=0;
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
				A[i][j]=ela[k];
				k++;
			}
		}
		k=0;
		for(i=0;i<n;i++)
		{
			for(j=0;j<p;j++)
			{
				B[i][j]=elb[k];
				k++;
			}
		}
		
		double s;
		for(i=0;i<m;i++)
		for(j=0;j<p;j++)
		{
			s=0;
			C[i][j]=0;
			for(k=0;k<n;k++)
				s+=A[i][k]*B[k][j];
			C[i][j]=s;
		}

		CString out="";
		for(i=0;i<m;i++)
		{
			for(j=0;j<p;j++)
			{
				te.Format("%lf",C[i][j]);
				out=out + te + "   ";
			}
			out=out + "\r\n\r\n";
		}
		SetDlgItemText(3057,out);
	}

	void reset()
	{
		int n=3051;
		int i;
		for(i=0;i<=6;i++)
			SetDlgItemText(n+i,"");
	}
	
	DECLARE_MESSAGE_MAP()
};
BEGIN_MESSAGE_MAP(mydialog5,CDialog)
	ON_COMMAND(3058,mult)
	ON_COMMAND(3059,reset)
END_MESSAGE_MAP()

class mydialog6:public CDialog
{
public:
	mydialog6(int n):CDialog(n)
	{
	}
	
	void adj()
	{
		CString matA,te;
		int i,j=0,k=0,l;
		CString eA[100];
		double ela[100];
		GetDlgItemText(3061,matA);

		matA.TrimLeft();
		matA.TrimRight();
		matA=matA+" ";
		
		char *endptr;
		l=matA.GetLength();
		for(i=0;i<l;i++)
		{
			te=matA.Mid(i,1);
			if(te==" ")
			{
				te.Format("%d",i);
				eA[j]=matA.Mid(k,i-k);
				k=i+1;
				ela[j]=strtod(eA[j],&endptr);
				j++;
			}
		}
		if(j>9)
		{
			SetDlgItemText(3062,"Number of elements in matrix A is > 9");
			return;
		}
		else if(j<9)
		{
			SetDlgItemText(3062,"Number of elements in matrix A is < 9");
			return;
		}

		double a11,a12,a13,a21,a22,a23,a31,a32,a33;
		double b11,b12,b13,b21,b22,b23,b31,b32,b33;
		double C[3][3];
		a11=ela[0];
		a12=ela[1];
		a13=ela[2];
		a21=ela[3];
		a22=ela[4];
		a23=ela[5];
		a31=ela[6];
		a32=ela[7];
		a33=ela[8];
		b11=a22*a33-a23*a32;
		b12=a23*a31-a21*a33;
		b13=a21*a32-a22*a31;
		b21=a13*a32-a12*a33;
		b22=a11*a33-a13*a31;
		b23=a12*a31-a11*a32;
		b31=a23*a12-a22*a13;
		b32=a21*a13-a23*a11;
		b33=a22*a11-a21*a12;
		C[0][0]=b11;
		C[0][1]=b21;
		C[0][2]=b31;
		C[1][0]=b12;
		C[1][1]=b22;
		C[1][2]=b32;
		C[2][0]=b13;
		C[2][1]=b23;
		C[2][2]=b33;

		CString out="\r\n";
		for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
			{
				te.Format("%lf",C[i][j]);
				out=out + te + "   ";
			}
			out=out + "\r\n\r\n\r\n";
		}
		SetDlgItemText(3062,out);
	}

	void reset()
	{
		SetDlgItemText(3061,"");
		SetDlgItemText(3062,"");
	}

	DECLARE_MESSAGE_MAP()
};
BEGIN_MESSAGE_MAP(mydialog6,CDialog)
	ON_COMMAND(3063,adj)
	ON_COMMAND(3064,reset)
END_MESSAGE_MAP()

class mydialog7:public CDialog
{
public:
	mydialog7(int n):CDialog(n)
	{
	}
	
	void inv()
	{
		CString matA,te;
		int i,j=0,k=0,l;
		CString eA[100];
		double ela[100];
		GetDlgItemText(3071,matA);

		matA.TrimLeft();
		matA.TrimRight();
		matA=matA+" ";
		
		char *endptr;
		l=matA.GetLength();
		for(i=0;i<l;i++)
		{
			te=matA.Mid(i,1);
			if(te==" ")
			{
				te.Format("%d",i);
				eA[j]=matA.Mid(k,i-k);
				k=i+1;
				ela[j]=strtod(eA[j],&endptr);
				j++;
			}
		}
		if(j>9)
		{
			SetDlgItemText(3072,"Number of elements in matrix A is > 9");
			return;
		}
		else if(j<9)
		{
			SetDlgItemText(3072,"Number of elements in matrix A is < 9");
			return;
		}

		double a11,a12,a13,a21,a22,a23,a31,a32,a33;
		double b11,b12,b13,b21,b22,b23,b31,b32,b33;
		double C[3][3];
		double det;
		a11=ela[0];
		a12=ela[1];
		a13=ela[2];
		a21=ela[3];
		a22=ela[4];
		a23=ela[5];
		a31=ela[6];
		a32=ela[7];
		a33=ela[8];
		b11=a22*a33-a23*a32;
		b12=a23*a31-a21*a33;
		b13=a21*a32-a22*a31;
		b21=a13*a32-a12*a33;
		b22=a11*a33-a13*a31;
		b23=a12*a31-a11*a32;
		b31=a23*a12-a22*a13;
		b32=a21*a13-a23*a11;
		b33=a22*a11-a21*a12;
		det=a11*(a22*a33-a23*a32)-a12*(a21*a33-a23*a31)+a13*(a21*a32-a22*a31);
		if(det==0)
		{
			SetDlgItemText(3072,"Matrix non-Invertible");
			return;
		}
		C[0][0]=b11/det;
		C[0][1]=b21/det;
		C[0][2]=b31/det;
		C[1][0]=b12/det;
		C[1][1]=b22/det;
		C[1][2]=b32/det;
		C[2][0]=b13/det;
		C[2][1]=b23/det;
		C[2][2]=b33/det;
		CString out="\r\n";
		for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
			{
				te.Format("%lf",C[i][j]);
				out=out + te + "   ";
			}
			out=out + "\r\n\r\n\r\n";
		}
		SetDlgItemText(3072,out);
	}

	void reset()
	{
		SetDlgItemText(3071,"");
		SetDlgItemText(3072,"");
	}

	DECLARE_MESSAGE_MAP()
};
BEGIN_MESSAGE_MAP(mydialog7,CDialog)
	ON_COMMAND(3073,inv)
	ON_COMMAND(3074,reset)
END_MESSAGE_MAP()

class mydialog8:public CDialog
{
public:
	mydialog8(int n):CDialog(n)
	{
	}

	int OnInitDialog()
	{
		CDialog::OnInitDialog();
		CheckRadioButton(3081,3083,3082);
		return TRUE;
	}

	void det()
	{
		int rad,noe;
		rad=GetCheckedRadioButton(3081,3083);
		if(rad==3081)noe=4;
		else if(rad==3082)noe=9;
		else if(rad==3083)noe=16;

		CString detA,te;
		int i,j=0,k=0,l;
		CString eA[100];
		double ela[100];
		GetDlgItemText(3084,detA);
		detA.TrimLeft();
		detA.TrimRight();
		detA=detA+" ";
		
		char *endptr;
		l=detA.GetLength();
		for(i=0;i<l;i++)
		{
			te=detA.Mid(i,1);
			if(te==" ")
			{
				te.Format("%d",i);
				eA[j]=detA.Mid(k,i-k);
				k=i+1;
				ela[j]=strtod(eA[j],&endptr);
				j++;
			}
		}
		if(j<noe)
		{
			SetDlgItemText(3085,"No. of elements is less");
			return;
		}
		else if(j>noe)
		{
			SetDlgItemText(3085,"No. of elements is more");
			return;
		}
		else SetDlgItemText(3085,"");

		double det;
		double a11,a12,a13,a14,a21,a22,a23,a24,a31,a32,a33,a34,a41,a42,a43,a44;
		CString out;
		if(noe==4)
		{
			a11=ela[0];
			a12=ela[1];
			a21=ela[2];
			a22=ela[3];
			det=a11*a22-a12*a21;
			out.Format("%lf",det);
			SetDlgItemText(3085,out);
		}
		else if(noe==9)
		{
			a11=ela[0];
			a12=ela[1];
			a13=ela[2];
			a21=ela[3];
			a22=ela[4];
			a23=ela[5];
			a31=ela[6];
			a32=ela[7];
			a33=ela[8];
			det=a11*(a22*a33-a23*a32)-a12*(a21*a33-a23*a31)+a13*(a21*a32-a22*a31);
			out.Format("%lf",det);
			SetDlgItemText(3085,out);
		}
		else if(noe==16)
		{
			double d1,d2,d3,d4;
			a11=ela[0];
			a12=ela[1];
			a13=ela[2];
			a14=ela[3];
			a21=ela[4];
			a22=ela[5];
			a23=ela[6];
			a24=ela[7];
			a31=ela[8];
			a32=ela[9];
			a33=ela[10];
			a34=ela[11];
			a41=ela[12];
			a42=ela[13];
			a43=ela[14];
			a44=ela[15];
			d1=a22*(a33*a44-a34*a43)-a23*(a32*a44-a34*a42)+a24*(a32*a43-a33*a42);
			d2=a21*(a33*a44-a34*a43)-a23*(a31*a44-a34*a41)+a24*(a31*a43-a33*a41);
			d3=a21*(a32*a44-a34*a42)-a22*(a31*a44-a34*a41)+a24*(a31*a42-a32*a41);
			d4=a21*(a32*a43-a33*a42)-a22*(a31*a43-a33*a41)+a23*(a31*a42-a32*a41);
			det=a11*d1-a12*d2+a13*d3-a14*d4;
			out.Format("%lf",det);
			SetDlgItemText(3085,out);
		}
	}

	void reset()
	{
		SetDlgItemText(3084,"");
		SetDlgItemText(3085,"");
	}
	
	DECLARE_MESSAGE_MAP()
};
BEGIN_MESSAGE_MAP(mydialog8,CDialog)
	ON_COMMAND(3086,det)
	ON_COMMAND(3087,reset)
END_MESSAGE_MAP()

class mydialog9:public CDialog
{
private:
	CComboBox *combo;
	int com;

public:
	mydialog9(int n):CDialog(n)
	{
	}

	void find()
	{
		CString xv,av,nv,out;
		double x,a,n,res;
		char *endptr;
		GetDlgItemText(3091,xv);
		GetDlgItemText(3092,av);
		GetDlgItemText(3093,nv);
		x=strtod(xv,&endptr);
		a=strtod(av,&endptr);
		n=strtod(nv,&endptr);
		int rad;
		rad=GetCheckedRadioButton(1101,1118);
		if(rad==1101) res=log(a)*pow(a,x);
		else if(rad==1102) res=-sin(x);
		else if(rad==1103) res=-1/sqrt(1-x*x);
		else if(rad==1104) res=-1/(sin(x)*tan(x));
		else if(rad==1105) res=-1/(x*sqrt(x*x-1));
		else if(rad==1106) res=sinh(x);
		else if(rad==1107) res=-1/(sin(x)*sin(x));
		else if(rad==1108) res=-1/(1+x*x);
		else if(rad==1109) res=exp(x);
		else if(rad==1110) res=1/x;
		else if(rad==1111) res=tan(x)/cos(x);
		else if(rad==1112) res=1/(x*sqrt(x*x-1));
		else if(rad==1113) res=cos(x);
		else if(rad==1114) res=1/sqrt(1-x*x);
		else if(rad==1115) res=cosh(x);
		else if(rad==1116) res=1/(cos(x)*cos(x));
		else if(rad==1117) res=1/(1+x*x);
		else if(rad==1118) res=n*pow(x,n-1);
		else 
		{
			SetDlgItemText(3094,"Select Function");
			return;
		}
		out.Format("%lf",res);
		SetDlgItemText(3094,out);
		if(out=="-1.#IND00"||out=="1.#INF00") SetDlgItemText(3094,"Undefined");
	}

	void reset()
	{
		SetDlgItemText(3091,"");
		SetDlgItemText(3092,"");
		SetDlgItemText(3093,"");
		SetDlgItemText(3094,"");
	}

	DECLARE_MESSAGE_MAP()
};
BEGIN_MESSAGE_MAP(mydialog9,CDialog)
	ON_COMMAND(3095,find)
	ON_COMMAND(3096,reset)
END_MESSAGE_MAP()

class mydialog10:public CDialog
{
public:
	mydialog10(int n):CDialog(n)
	{
	}

	void find()
	{
		CString xv1,xv2,av,bv,nv,out;
		double x1,x2,a,b,n,res;
		char *endptr;
		GetDlgItemText(30101,xv1);
		GetDlgItemText(30102,xv2);
		GetDlgItemText(30103,av);
		GetDlgItemText(30104,bv);
		GetDlgItemText(30105,nv);
		x1=strtod(xv1,&endptr);
		x2=strtod(xv2,&endptr);
		a=strtod(av,&endptr);
		b=strtod(bv,&endptr);
		n=strtod(nv,&endptr);
		int rad;
		rad=GetCheckedRadioButton(1201,1227);
		if(rad==1201)res=atan(x2)-atan(x1);
		else if(rad==1202)res=(1/a)*(atan(x2/a)-atan(x1/a)); 
		else if(rad==1203)res=(1/(2*a))*(log((x2-a)/(x2+a))-log((x1-a)/(x1+a)));
		else if(rad==1204)res=log(x2+sqrt(x2*x2-a*a))-log(x1+sqrt(x1*x1-a*a));
		else if(rad==1205)res=log(x2+sqrt(x2*x2+a*a))-log(x1+sqrt(x1*x1+a*a));
		else if(rad==1206)res=(1/acos(x2))-(1/acos(x1));
		else if(rad==1207)res=(1/a)*((1/acos(x2/a))-(1/acos(x1/a)));
		else if(rad==1208)res=asin(x2)-asin(x1);
		else if(rad==1209)res=asin(x2/a)-asin(x1/a);
		else if(rad==1210)res=log(x2/x1);
		else if(rad==1211)res=(pow(a,x2)-pow(a,x1))/log(a);
		else if(rad==1212)res=sin(x2)-sin(x1);
		else if(rad==1213)res=log(tan(x2/2)/tan(x1/2));
		else if(rad==1214)res=1/sin(x1)-1/sin(x2);
		else if(rad==1215)res=1/tan(x1)-1/tan(x2);
		else if(rad==1216)res=log(sin(x2)/sin(x1));
		else if(rad==1217)res=(1/sqrt(a*a+b*b))*(exp(a*x2)*cos(b*x2-atan(b/a))-exp(a*x1)*cos(b*x1-atan(b/a)));
		else if(rad==1218)res=(1/sqrt(a*a+b*b))*(exp(a*x2)*sin(b*x2-atan(b/a))-exp(a*x1)*sin(b*x1-atan(b/a)));
		else if(rad==1219)res=log(tan(0.78539816339744830961566084581988+x2/2)/tan(0.78539816339744830961566084581988+x1/2));
		else if(rad==1220)res=(1/cos(x2))-(1/cos(x1));
		else if(rad==1221)res=tan(x2)-tan(x1);
		else if(rad==1222)res=cos(x1)-cos(x2);
		else if(rad==1223)res=(x2*sqrt(a*a-x2*x2)/2 + a*a*asin(x2/a)/2)-(x1*sqrt(a*a-x1*x1)/2 + a*a*asin(x1/a)/2);
		else if(rad==1224)res=(x2*sqrt(x2*x2-a*a)/2 - a*a*log(x2+sqrt(x2*x2-a*a))/2)-(x1*sqrt(x1*x1-a*a)/2 - a*a*log(x1+sqrt(x1*x1-a*a))/2);
		else if(rad==1225)res=(x2*sqrt(x2*x2+a*a)/2 + a*a*log(x2+sqrt(x2*x2+a*a))/2)-(x1*sqrt(x1*x1+a*a)/2 + a*a*log(x1+sqrt(x1*x1+a*a))/2);
		else if(rad==1226)res=log(cos(x1)/cos(x2));
		else if(rad==1227)res=(pow(x2,n+1)-pow(x1,n+1))/(n+1);
		else 
		{
			SetDlgItemText(30106,"Select Function");
			return;
		}
		out.Format("%lf",res);
		SetDlgItemText(30106,out);
		if(out=="-1.#IND00"||out=="1.#INF00") SetDlgItemText(30106,"Undefined");
	}
	void reset()
	{
		SetDlgItemText(30101,"");
		SetDlgItemText(30102,"");
		SetDlgItemText(30103,"");
		SetDlgItemText(30104,"");
		SetDlgItemText(30105,"");
		SetDlgItemText(30106,"");
	}
	
	DECLARE_MESSAGE_MAP()
};
BEGIN_MESSAGE_MAP(mydialog10,CDialog)
	ON_COMMAND(30107,find)
	ON_COMMAND(30108,reset)
END_MESSAGE_MAP()

class mydialog11:public CDialog
{
public:
	mydialog11(int n):CDialog(n)
	{
	}

	int OnInitDialog()
	{
		CDialog::OnInitDialog();
		CheckRadioButton(30114,30117,30114);
		CheckRadioButton(50115,50116,50115);
		return TRUE;
	}

	void calc()
	{
		CString sx,sy,su,sv;
		double x,y,u,v;
		char *endptr;
		int rad;
		GetDlgItemText(30111,sx);
		GetDlgItemText(30112,sy);
		GetDlgItemText(30118,su);
		GetDlgItemText(30119,sv);
		x=strtod(sx,&endptr);
		y=strtod(sy,&endptr);
		u=strtod(su,&endptr);
		v=strtod(sv,&endptr);

		rad=GetCheckedRadioButton(50115,50116);
		if(rad==50116)
		{
		CString r1[100],r2[100],w1,w2,te;
		double ra1[100],ra2[100];
		GetDlgItemText(30113,w1);
		GetDlgItemText(50110,w2);
		int i,j=0,k=0,l;
		do
		{
			l=w1.GetLength();
			te=w1.Right(1);
			if(te==" ")
			w1=w1.Left(l-1);
		}while(te==" ");
		w1=w1+" ";
		
		char *endptr;
		l=w1.GetLength();
		for(i=0;i<l;i++)
		{
			te=w1.Mid(i,1);
			if(te==" ")
			{
				te.Format("%d",i);
				r1[j]=w1.Mid(k,i-k);
				k=i+1;
				ra1[j]=strtod(r1[j],&endptr);
				j++;
			}
		}
		if(j>2)
		{
			SetDlgItemText(50111,"Illegal data entry in");
			SetDlgItemText(50112,"A");
			return;
		}
		j=0;
		k=0;
		do
		{
			l=w2.GetLength();
			te=w2.Right(1);
			if(te==" ")
			w2=w2.Left(l-1);
		}while(te==" ");
		w2=w2+" ";
		
		l=w2.GetLength();
		for(i=0;i<l;i++)
		{
			te=w2.Mid(i,1);
			if(te==" ")
			{
				te.Format("%d",i);
				r2[j]=w2.Mid(k,i-k);
				k=i+1;
				ra2[j]=strtod(r2[j],&endptr);
				j++;
			}
		}
		if(j>2)
		{
			SetDlgItemText(50111,"Illegal data entry in");
			SetDlgItemText(50112,"B");
			return;
		}
		x=ra1[0]*cos(ra1[1]*pi);
		y=ra1[0]*sin(ra1[1]*pi);
		u=ra2[0]*cos(ra2[1]*pi);
		v=ra2[0]*sin(ra2[1]*pi);
		sx.Format("%lf",x);
		SetDlgItemText(30111,sx);
		sy.Format("%lf",y);
		SetDlgItemText(30112,sy);
		su.Format("%lf",u);
		SetDlgItemText(30118,su);
		sv.Format("%lf",v);
		SetDlgItemText(30119,sv);
		}
		
		CString res;
		long double re,im,moda,modb,mod;
		double an1,an2,an;
		int op;
		rad=GetCheckedRadioButton(30114,30117);
		if(rad==30114)op=1;
		else if(rad==30115)op=2;
		else if(rad==30116)op=3;
		else if(rad==30117)op=4;
		moda=sqrt(x*x+y*y);
		modb=sqrt(u*u+v*v);
		an1=atan2(y,x);
		an2=atan2(v,u);
		CString maga,magb,mag;
		maga.Format("%Lf /_%lf",moda,(an1*180*180)/pi);
		magb.Format("%Lf /_%lf",modb,(an2*180*180)/pi);
		SetDlgItemText(30113,maga);
		SetDlgItemText(50110,magb);
		if(op==1)
		{
			re=x+u;
			im=y+v;
			if(im>0)
				res.Format("%Lf + %Lf i",re,im);
			else if(im<0)
				res.Format("%Lf - %Lf i",re,-im);
			else if(im==0)
				res.Format("%Lf",re);
			SetDlgItemText(50111,res);
		}
		else if(op==2)
		{
			re=x-u;
			im=y-v;
			if(im>0)
				res.Format("%Lf + %Lf i",re,im);
			else if(im<0)
				res.Format("%Lf - %Lf i",re,-im);
			else if(im==0)
				res.Format("%Lf",re);
			SetDlgItemText(50111,res);
		}
		else if(op==3)
		{
			re=u*x-v*y;
			im=u*y+v*x;
			if(im>0)
				res.Format("%Lf + %Lf i",re,im);
			else if(im<0)
				res.Format("%Lf - %Lf i",re,-im);
			else if(im==0)
				res.Format("%Lf",re);
			SetDlgItemText(50111,res);
		}
		else if(op==4)
		{
			re=(u*x+v*y)/(modb*modb);
			im=(u*y-v*x)/(modb*modb);
			if(im>0)
				res.Format("%Lf + %Lf i",re,im);
			else if(im<0)
				res.Format("%Lf - %Lf i",re,-im);
			else if(im==0)
				res.Format("%Lf",re);
			if(modb==0)
				res="Can't divide by 0";
			SetDlgItemText(50111,res);
		}
		an=atan2(im,re);
		mod=sqrt(re*re+im*im);
		mag.Format("%Lf /_%lf",mod,(an*180*180)/pi);
		if(modb==0 && op==4)mag="Undefined";
		SetDlgItemText(50112,mag);
		CheckRadioButton(50115,50116,50115);
	}

	void reset()
	{
		SetDlgItemText(30111,"");
		SetDlgItemText(30112,"");
		SetDlgItemText(30113,"");
		SetDlgItemText(30118,"");
		SetDlgItemText(30119,"");
		SetDlgItemText(50110,"");
		SetDlgItemText(50111,"");
		SetDlgItemText(50112,"");
	}

	DECLARE_MESSAGE_MAP()
};
BEGIN_MESSAGE_MAP(mydialog11,CDialog)
	ON_COMMAND(50113,calc)
	ON_COMMAND(50114,reset)
END_MESSAGE_MAP()

class mydialog14:public CDialog
{
public:
	mydialog14(int n):CDialog(n)
	{
	}

	int OnInitDialog()
	{
		CDialog::OnInitDialog();
		CheckRadioButton(30132,30134,30134);
		return TRUE;
	}

	void calc()
	{
		verylong vea,veb,vec;
		CString oa,ob;
		int rad,l1,l2,l3;;
		GetDlgItemText(30131,oa);
		GetDlgItemText(30135,ob);
		l1=oa.GetLength();
		l2=ob.GetLength();
		oa.Format("%ld",l1);
		SetDlgItemText(1601,oa);
		oa.Format("%ld",l2);
		SetDlgItemText(1602,oa);
		rad=GetCheckedRadioButton(30132,30134);
		if(rad==30132)
		{
			f1=0;
			GetDlgItemText(30131,oa);
			GetDlgItemText(30135,ob);
			l1=oa.GetLength();
			l2=ob.GetLength();
			if(l1>=31999 || l2>=31999)
			{
				SetDlgItemText(30136,"Sorry,the Calculation might exceed the range of Calculator");
				return;
			}
			strcpy(vla,oa);
			vea.getvl();
			f1=1;
			strcpy(vlb,ob);
			veb.getvl();
			vec=vea+veb;
			vec.putvl();
			SetDlgItemText(30136,vlc);
		}
		else if(rad==30133)
		{
			f1=0;
			GetDlgItemText(30131,oa);
			GetDlgItemText(30135,ob);
			l1=oa.GetLength();
			l2=ob.GetLength();
			if(l1+l2>31999)
			{
				SetDlgItemText(30136,"Sorry,the Calculation might exceed the range of Calculator");
				return;
			}
			strcpy(vla,oa);
			vea.getvl();
			f1=1;
			strcpy(vlb,ob);
			veb.getvl();
			vec=vea*veb;
			vec.putvl();
			SetDlgItemText(30136,vlc);
		}
		else if(rad==30134)
		{
			verylong fact=1;
			unsigned long numb,j;
			GetDlgItemText(30131,oa);
			numb=atol(oa);
			if(numb>9080)
			{
				SetDlgItemText(30136,"Sorry,the Calculation might exceed the range of Calculator");
				return;
			}
			for(j=numb;j>0;j--)
			fact=fact*j;
			fact.putvl();
			SetDlgItemText(30136,vlc);
		}
		CString oc;
		GetDlgItemText(30136,oc);
		l3=oc.GetLength();
		oa.Format("%ld",l3);
		SetDlgItemText(1603,oa);
	}

	void reset()
	{
		SetDlgItemText(30131,"");
		SetDlgItemText(30135,"");
		SetDlgItemText(30136,"");
		SetDlgItemText(1601,"");
		SetDlgItemText(1602,"");
		SetDlgItemText(1603,"");
	}

	DECLARE_MESSAGE_MAP()
};
BEGIN_MESSAGE_MAP(mydialog14,CDialog)
	ON_COMMAND(30137,calc)
	ON_COMMAND(30138,reset)
END_MESSAGE_MAP()


class mydialog15:public CDialog
{
public:
	mydialog15(int n):CDialog(n)
	{
	}

	void calc()
	{
		CString data,te;
		int i,j=0,k=0,l;
		CString eA[1000];
		double ela[1000],sum=0;
		GetDlgItemText(30141,data);
		data.TrimLeft();
		data.TrimRight();
		data=data+" ";
		
		char *endptr;
		l=data.GetLength();
		for(i=0;i<l;i++)
		{
			te=data.Mid(i,1);
			if(te==" ")
			{
				te.Format("%d",i);
				eA[j]=data.Mid(k,i-k);
				k=i+1;
				ela[j]=strtod(eA[j],&endptr);
				sum+=ela[j];
				j++;
			}
		}
		CString out;
		double mean=(double)sum/j;
		out.Format("%lf",sum);
		SetDlgItemText(30143,out);
		out.Format("%lf",mean);
		SetDlgItemText(30142,out);
	}

	void reset()
	{
		SetDlgItemText(30141,"");
		SetDlgItemText(30142,"");
		SetDlgItemText(30143,"");
	}
	
	DECLARE_MESSAGE_MAP()
};
BEGIN_MESSAGE_MAP(mydialog15,CDialog)
	ON_COMMAND(30144,calc)
	ON_COMMAND(30145,reset)
END_MESSAGE_MAP()

class mydialog16:public CDialog
{
public:
	mydialog16(int n):CDialog(n)
	{
	}

	int OnInitDialog()
	{
		CDialog::OnInitDialog();
		FILE *re;
		re=fopen("read.txt","r");
		if(re==NULL)
		{
			SetDlgItemText(4011,"Help File read.txt not found.");
			return TRUE;
		}
		CString dis="";
		char ch;
		do
		{
			ch=fgetc(re);
			if(ch=='\n')dis=dis+"\r";
			if(ch!=EOF)dis+=ch;
		}while(ch!=EOF);
		SetDlgItemText(4011,dis);
		fclose(re);
		return TRUE;
	}
};

class myframe:public CFrameWnd
{
private:
	CButton b[38];
	CEdit ip,op;
	CFont myfont;
	int radio1,radio2,radio3,radio4;
	
public:
	myframe()
	{
		CString mywindowclass;
		HBRUSH mybrush;
		mybrush=::CreateSolidBrush(RGB(255,0,0));
		mywindowclass=AfxRegisterWndClass(
			CS_HREDRAW|CS_VREDRAW,
			AfxGetApp()->LoadCursor(IDC_CURSOR1),
			mybrush,
			AfxGetApp()->LoadIcon(IDI_ICON1));
		LoadAccelTable(MAKEINTRESOURCE(IDR_ACCELERATOR1));
		Create(mywindowclass,"EFY Calculator",WS_OVERLAPPED|WS_CAPTION|
			WS_SYSMENU|WS_MINIMIZEBOX,CRect(300,100,600,550),0,MAKEINTRESOURCE(IDR_MENU1));
		str="";
		edi="";
		answ="";
		radio2=!radio2;
		radio3=!radio3;
		radio4=!radio4;
	}
	int OnCreate(LPCREATESTRUCT l)
	{
		CFrameWnd::OnCreate(l);

		ip.CreateEx(WS_EX_CLIENTEDGE|WS_EX_LEFT,"EDIT","",
			WS_CHILD|WS_VISIBLE|WS_DLGFRAME|ES_AUTOVSCROLL|ES_MULTILINE,
			CRect(15,5,275,105),this,38);
		ip.SetFocus();

		op.CreateEx(WS_EX_CLIENTEDGE|WS_EX_RIGHT,"EDIT","",
			WS_CHILD|WS_VISIBLE|WS_DLGFRAME|ES_AUTOHSCROLL|ES_READONLY,
			CRect(15,110,275,150),this,39);

		myfont.CreateFont(30,15,0,0,0,0,0,0,0,0,0,0,0,
			"Agency FB");
		op.SetFont(&myfont,TRUE);

		b[0].Create("0",BS_PUSHBUTTON|WS_CHILD|WS_VISIBLE|WS_BORDER,CRect(15,360,50,390),
			this,1);

		b[1].Create(".",BS_PUSHBUTTON|WS_CHILD|WS_VISIBLE|WS_BORDER,CRect(60,360,95,390),
			this,2);

		b[2].Create("pi",BS_PUSHBUTTON|WS_CHILD|WS_VISIBLE|WS_BORDER,CRect(105,360,140,390),
			this,3);

		b[3].Create("sqrt",BS_PUSHBUTTON|WS_CHILD|WS_VISIBLE|WS_BORDER,CRect(150,360,185,390),
			this,4);

		b[4].Create("+",BS_PUSHBUTTON|WS_CHILD|WS_VISIBLE|WS_BORDER,CRect(195,360,230,390),
			this,5);

		b[5].Create("=",BS_PUSHBUTTON|WS_CHILD|WS_VISIBLE|WS_BORDER,CRect(240,360,275,390),
			this,6);
	
		b[6].Create("1",BS_PUSHBUTTON|WS_CHILD|WS_VISIBLE|WS_BORDER,CRect(15,320,50,350),
			this,7);

		b[7].Create("2",BS_PUSHBUTTON|WS_CHILD|WS_VISIBLE|WS_BORDER,CRect(60,320,95,350),
			this,8);

		b[8].Create("3",BS_PUSHBUTTON|WS_CHILD|WS_VISIBLE|WS_BORDER,CRect(105,320,140,350),
			this,9);

		b[9].Create("Cos",BS_PUSHBUTTON|WS_CHILD|WS_VISIBLE|WS_BORDER,CRect(150,320,185,350),
			this,10);

		b[10].Create("-",BS_PUSHBUTTON|WS_CHILD|WS_VISIBLE|WS_BORDER,CRect(195,320,230,350),
			this,11);

		b[11].Create("Ans",BS_PUSHBUTTON|WS_CHILD|WS_VISIBLE|WS_BORDER,CRect(240,320,275,350),
			this,12);
	
		b[12].Create("4",BS_PUSHBUTTON|WS_CHILD|WS_VISIBLE|WS_BORDER,CRect(15,280,50,310),
			this,13);

		b[13].Create("5",BS_PUSHBUTTON|WS_CHILD|WS_VISIBLE|WS_BORDER,CRect(60,280,95,310),
			this,14);

		b[14].Create("6",BS_PUSHBUTTON|WS_CHILD|WS_VISIBLE|WS_BORDER,CRect(105,280,140,310),
			this,15);

		b[15].Create("Sin",BS_PUSHBUTTON|WS_CHILD|WS_VISIBLE|WS_BORDER,CRect(150,280,185,310),
			this,16);

		b[16].Create("*",BS_PUSHBUTTON|WS_CHILD|WS_VISIBLE|WS_BORDER,CRect(195,280,230,310),
			this,17);

		b[17].Create("^",BS_PUSHBUTTON|WS_CHILD|WS_VISIBLE|WS_BORDER,CRect(240,280,275,310),
			this,18);
	
		b[18].Create("7",BS_PUSHBUTTON|WS_CHILD|WS_VISIBLE|WS_BORDER,CRect(15,240,50,270),
			this,19);

		b[19].Create("8",BS_PUSHBUTTON|WS_CHILD|WS_VISIBLE|WS_BORDER,CRect(60,240,95,270),
			this,20);

		b[20].Create("9",BS_PUSHBUTTON|WS_CHILD|WS_VISIBLE|WS_BORDER,CRect(105,240,140,270),
			this,21);

		b[21].Create("Tan",BS_PUSHBUTTON|WS_CHILD|WS_VISIBLE|WS_BORDER,CRect(150,240,185,270),
			this,22);

		b[22].Create("/",BS_PUSHBUTTON|WS_CHILD|WS_VISIBLE|WS_BORDER,CRect(195,240,230,270),
			this,23);

		b[23].Create("e^",BS_PUSHBUTTON|WS_CHILD|WS_VISIBLE|WS_BORDER,CRect(240,240,275,270),
			this,24);

		b[24].Create("log",BS_PUSHBUTTON|WS_CHILD|WS_VISIBLE|WS_BORDER,CRect(15,200,50,230),
			this,25);

		b[25].Create("ln",BS_PUSHBUTTON|WS_CHILD|WS_VISIBLE|WS_BORDER,CRect(60,200,95,230),
			this,26);

		b[26].Create("Pri",BS_PUSHBUTTON|WS_CHILD|WS_VISIBLE|WS_BORDER,CRect(105,200,140,230),
			this,27);
					
		b[27].Create("Fact",BS_PUSHBUTTON|WS_CHILD|WS_VISIBLE|WS_BORDER,CRect(150,200,185,230),
			this,28);

		b[28].Create("Bk",BS_PUSHBUTTON|WS_CHILD|WS_VISIBLE|WS_BORDER,CRect(195,200,230,230),
			this,29);

		b[29].Create("ON",BS_PUSHBUTTON|WS_CHILD|WS_VISIBLE|WS_BORDER,CRect(240,200,275,230),
			this,30);

		b[30].Create("Inv",BS_AUTOCHECKBOX|WS_CHILD|WS_VISIBLE|WS_BORDER,CRect(10,162,55,187),
			this,31);
		
		b[31].Create("Hyp",BS_AUTOCHECKBOX|WS_CHILD|WS_VISIBLE|WS_BORDER,CRect(60,162,110,187),
			this,32);
		
		b[32].Create("",BS_GROUPBOX|WS_CHILD|WS_VISIBLE,CRect(5,148,115,193),
			this,33);

		b[33].Create("Deg",BS_AUTORADIOBUTTON|WS_CHILD|WS_VISIBLE|WS_BORDER,CRect(175,162,225,187),
			this,34);
		b[33].SetCheck(1);
		
		b[34].Create("Rad",BS_AUTORADIOBUTTON|WS_CHILD|WS_VISIBLE|WS_BORDER,CRect(230,162,280,187),
			this,35);
		
		b[35].Create("",BS_GROUPBOX|WS_CHILD|WS_VISIBLE,CRect(170,148,285,193),
			this,36);

		b[36].Create("SUM",BS_PUSHBUTTON|WS_CHILD|WS_VISIBLE|WS_BORDER,CRect(120,159,165,189),
			this,37);

		return 0;
	}

	void on0()
	{
		ip.GetWindowText(edi);
		str=edi;
		str=str+"0";
		ip.SetWindowText(str);
	}

	void on1()
	{
		ip.GetWindowText(edi);
		len=edi.GetLength();
		temp=edi.Right(1);
		if(temp=="=") edi=edi.Left(len-1);
		str=edi;
		str=str+"1";
		ip.SetWindowText(str);
	}

	void on2()
	{
		ip.GetWindowText(edi);
		len=edi.GetLength();
		temp=edi.Right(1);
		if(temp=="=") edi=edi.Left(len-1);
		str=edi;
		str=str+"2";
		ip.SetWindowText(str);
	}

	void on3()
	{
		ip.GetWindowText(edi);
		len=edi.GetLength();
		temp=edi.Right(1);
		if(temp=="=") edi=edi.Left(len-1);
		str=edi;
		str=str+"3";
		ip.SetWindowText(str);
	}

	void on4()
	{
		ip.GetWindowText(edi);
		len=edi.GetLength();
		temp=edi.Right(1);
		if(temp=="=") edi=edi.Left(len-1);
		str=edi;
		str=str+"4";
		ip.SetWindowText(str);
	}

	void on5()
	{
		ip.GetWindowText(edi);
		len=edi.GetLength();
		temp=edi.Right(1);
		if(temp=="=") edi=edi.Left(len-1);
		str=edi;
		str=str+"5";
		ip.SetWindowText(str);
	}

	void on6()
	{
		ip.GetWindowText(edi);
		len=edi.GetLength();
		temp=edi.Right(1);
		if(temp=="=") edi=edi.Left(len-1);
		str=edi;
		str=str+"6";
		ip.SetWindowText(str);
	}

	void on7()
	{
		ip.GetWindowText(edi);
		len=edi.GetLength();
		temp=edi.Right(1);
		if(temp=="=") edi=edi.Left(len-1);
		str=edi;
		str=str+"7";
		ip.SetWindowText(str);
	}

	void on8()
	{
		ip.GetWindowText(edi);
		len=edi.GetLength();
		temp=edi.Right(1);
		if(temp=="=") edi=edi.Left(len-1);
		str=edi;
		str=str+"8";
		ip.SetWindowText(str);
	}

	void on9()
	{
		ip.GetWindowText(edi);
		len=edi.GetLength();
		temp=edi.Right(1);
		if(temp=="=") edi=edi.Left(len-1);
		str=edi;
		str=str+"9";
		ip.SetWindowText(str);
	}

	void poi()
	{
		ip.GetWindowText(edi);
		len=edi.GetLength();
		temp=edi.Right(1);
		if(temp=="=") edi=edi.Left(len-1);
		str=edi;
		len=str.GetLength();
		temp=str.Mid(len-1,1);
		if(temp==".")str=str.Left(len-1);
		else str=str+".";
		ip.SetWindowText(str);
	}

	void pief()
	{
		ip.GetWindowText(edi);
		len=edi.GetLength();
		temp=edi.Right(1);
		if(temp=="=") edi=edi.Left(len-1);
		str=edi;
		str=str+"3.1415926535897932384626433832795";
		ip.SetWindowText(str);
	}

	void root()
	{
		ip.GetWindowText(edi);
		len=edi.GetLength();
		temp=edi.Right(1);
		if(temp=="=") edi=edi.Left(len-1);
		str=edi;
		len=str.GetLength();
		temp=str.Mid(len-1,1);
		if(temp=="^")str=str.Left(len-1);
		else str=str+"^0.5";
		ip.SetWindowText(str);
	}

	void plus()
	{
		ip.GetWindowText(edi);
		len=edi.GetLength();
		temp=edi.Right(1);
		if(temp=="=") edi=edi.Left(len-1);
		str=edi;
		len=str.GetLength();
		temp=str.Mid(len-1,1);
		if(temp=="+"||temp=="-"||temp=="*"||temp=="/")str=str.Left(len-1);
		else str=str+"+";
		ip.SetWindowText(str);
	}

	void minu()
	{
		ip.GetWindowText(edi);
		len=edi.GetLength();
		temp=edi.Right(1);
		if(temp=="=") edi=edi.Left(len-1);
		str=edi;
		len=str.GetLength();
		temp=str.Mid(len-1,1);
		if(temp=="+"||temp=="-"||temp=="*"||temp=="/")str=str.Left(len-1);
		else str=str+"-";
		ip.SetWindowText(str);
	}

	void mult()
	{
		ip.GetWindowText(edi);
		len=edi.GetLength();
		temp=edi.Right(1);
		if(temp=="=") edi=edi.Left(len-1);
		str=edi;
		len=str.GetLength();
		temp=str.Mid(len-1,1);
		if(temp=="+"||temp=="-"||temp=="*"||temp=="/")str=str.Left(len-1);
		else str=str+"*";
		ip.SetWindowText(str);
	}

	void divi()
	{
		ip.GetWindowText(edi);
		len=edi.GetLength();
		temp=edi.Right(1);
		if(temp=="=") edi=edi.Left(len-1);
		str=edi;
		len=str.GetLength();
		temp=str.Mid(len-1,1);
		if(temp=="+"||temp=="-"||temp=="*"||temp=="/")str=str.Left(len-1);
		else str=str+"/";
		ip.SetWindowText(str);
	}

	void cosi()
	{
		ip.GetWindowText(edi);
		len=edi.GetLength();
		temp=edi.Right(1);
		if(temp=="=") edi=edi.Left(len-1);
		str=edi;
		if(b[30].GetCheck()==1){b[31].SetCheck(0); str=str+"iCos";}
		else if(b[31].GetCheck()==1){b[30].SetCheck(0); str=str+"cosh";}
		else str=str+"Cos";
		ip.SetWindowText(str);
	}

	void sine()
	{
		ip.GetWindowText(edi);
		len=edi.GetLength();
		temp=edi.Right(1);
		if(temp=="=") edi=edi.Left(len-1);
		str=edi;
		if(b[30].GetCheck()==1){b[31].SetCheck(0); str=str+"iSin";}
		else if(b[31].GetCheck()==1){b[30].SetCheck(0); str=str+"sinh";}
		else str=str+"Sin";
		ip.SetWindowText(str);
	}

	void tang()
	{
		ip.GetWindowText(edi);
		len=edi.GetLength();
		temp=edi.Right(1);
		if(temp=="=") edi=edi.Left(len-1);
		str=edi;
		if(b[30].GetCheck()==1){b[31].SetCheck(0); str=str+"iTan";}
		else if(b[31].GetCheck()==1){b[30].SetCheck(0); str=str+"tanh";}
		else str=str+"Tan";
		ip.SetWindowText(str);
	}

	void loga()
	{
		ip.GetWindowText(edi);
		len=edi.GetLength();
		temp=edi.Right(1);
		if(temp=="=") edi=edi.Left(len-1);
		str=edi;
		str=str+"log";
		ip.SetWindowText(str);
	}

	void nalo()
	{
		ip.GetWindowText(edi);
		len=edi.GetLength();
		temp=edi.Right(1);
		if(temp=="=") edi=edi.Left(len-1);
		str=edi;
		str=str+"Ln";
		ip.SetWindowText(str);
	}

	void expo()
	{
		ip.GetWindowText(edi);
		len=edi.GetLength();
		temp=edi.Right(1);
		if(temp=="=") edi=edi.Left(len-1);
		str=edi;
		str=str+"e^";
		ip.SetWindowText(str);
	}

	void powe()
	{
		ip.GetWindowText(edi);
		len=edi.GetLength();
		temp=edi.Right(1);
		if(temp=="=") edi=edi.Left(len-1);
		str=edi;
		len=str.GetLength();
		temp=str.Mid(len-1,1);
		if(temp=="^")str=str.Left(len-1);
		else str=str+"^";
		ip.SetWindowText(str);
	}

	void prime()
	{
		op.SetWindowText("Enter an integer");
		ip.SetFocus();
		er=2;
	}

	void fact()
	{
		ip.GetWindowText(edi);
		len=edi.GetLength();
		temp=edi.Right(1);
		if(temp=="=") edi=edi.Left(len-1);
		str=edi;
		len=str.GetLength();
		temp=str.Mid(len-1,1);
		if(temp=="!")str=str.Left(len-1);
		else str=str+"Fac";
		ip.SetWindowText(str);
	}

	void sig()
	{
		ip.GetWindowText(edi);
		len=edi.GetLength();
		temp=edi.Right(1);
		if(temp=="=") edi=edi.Left(len-1);
		str=edi;
		str=str+"{";
		ip.SetWindowText(str);
	}

	void bkspc()
	{
		ip.GetWindowText(edi);
		str=edi;
		len=str.GetLength();
		str=str.Left(len-1);
		ip.SetWindowText(str);
	}

	void ans()
	{
		ip.GetWindowText(edi);
		str=edi;
		str=str+answ;
		ip.SetWindowText(str);
	}

	void equ()
	{
		ip.GetWindowText(edi);
		sav1=edi;
		str=edi;
		str=str.SpanExcluding("=");
		if(str=="")str+="0";
		str=str+"=";
		ip.SetWindowText(str);
		
		int i=0,x=0,cst=0;
		CString on="",out[1000],oper[1000];
		double dig[1000];
		char *endptr;

		if(er==2)
		{
			int pri,j;
			len=str.GetLength();
			out[0]=str.Left(len-1);
			dig[0]=strtod(out[0],&endptr);
			pri=(int) dig[0];
			for(j=2;j<pri;j++)
			if(pri%j==0)break;
			if(j==pri)op.SetWindowText("Number is Prime");
			else op.SetWindowText("No. is not Prime");
			res=dig[0];
		}

		do
		{
			len=str.GetLength();
			on=str.Mid(i,1);
			if(on=="+"||on=="-"||on=="*"||on=="/"||on=="="||on=="^")
			{
				out[x]=str.Left(i);
				oper[x]=on;
				str=str.Right(len-i-1);
				x++;
				i=0;
			}
			else if(on=="c"||on=="s"||on=="t"||on=="i")
			{
				CString tr;
				out[x]=str.Left(i);
				oper[x]=on;
				tr=str.Mid(i+1,1);
				if(tr=="C")oper[x]=oper[x]+"C";
				else if(tr=="S")oper[x]=oper[x]+"S";
				else if(tr=="T")oper[x]=oper[x]+"T";
				str=str.Right(len-i-4);
				x++;
				i=0;
			}
			else if(on=="C"||on=="S"||on=="T"||on=="l"||on=="F")
			{
				out[x]=str.Left(i);
				oper[x]=on;
				str=str.Right(len-i-3);
				x++;
				i=0;
			}
			else if(on=="L"||on=="e")
			{
				out[x]=str.Left(i);
				oper[x]=on;
				str=str.Right(len-i-2);
				x++;
				i=0;
			}
			else if(on=="{")
			{
				out[x]=str.Left(i);
				oper[x]=on;
				str=str.Right(len-i-1);
				x++;
				i=0;
			}
			else i++;
		}while(on!="=");

		str="";
		int j,mi=0;
		do
		{
			for(i=0;i<x;i++)
			{
				if(out[i]=="" && oper[i]=="-")
				{
					out[i]="-"+out[i+1];
					oper[i]=oper[i+1];
					for(j=i+1;j<x;j++)
					{
						out[j]=out[j+1];
						oper[j]=oper[j+1];
					}
					x--;
					mi=1;
				}
				else mi=0;
			}
		}while(mi==1);

		for(i=0;i<x;i++)
			dig[i]=strtod(out[i],&endptr);
	
		for(i=1;i<x;i++)
		{
			if(oper[i-1]=="+")
			{
				res=dig[i-1]+dig[i];
				dig[i]=res;
			}

			else if(oper[i-1]=="-")
			{
				res=dig[i-1]-dig[i];
				dig[i]=res;
			}

			else if(oper[i-1]=="*")
			{
				res=dig[i-1]*dig[i];
				dig[i]=res;
			}

			else if(oper[i-1]=="/")
			{
				cst=0;
				if(oper[i]=="C"||oper[i]=="S"||oper[i]=="T"||oper[i]=="l"||
					oper[i]=="L"||oper[i]=="e"||oper[i]=="F"||oper[i]=="{"||oper[i]=="c"||
					oper[i]=="s"||oper[i]=="t"||oper[i]=="iC"||oper[i]=="iS"||oper[i]=="iT")cst=1;
				if(cst!=1)
				{
					if(dig[i]==0)
					{
						op.SetWindowText("Can't divide by 0");
						er=1;
					}
					else
					{
						res=dig[i-1]/dig[i];
						dig[i]=res;
					}
				}
			}

			else if(oper[i-1]=="^")
			{
				res=pow(dig[i-1],dig[i]);
				temp.Format("%lf",dig[i-1]);
				if((dig[i-1]==0 || temp=="-0.000000") && dig[i]==0)
				{
					op.SetWindowText("Error : 0^0");
					er=6;
				}
				dig[i]=res;
			}

			else if(oper[i-1]=="C")
			{
				if(i>1 && oper[i-2]=="+")
				{
					if(b[33].GetCheck()==1) dig[i]=cos(dig[i]*pi);
					else dig[i]=cos(dig[i]);
					res=dig[i-2]+dig[i];
				}
				else if(i>1 && oper[i-2]=="-")
				{
					if(b[33].GetCheck()==1) dig[i]=cos(dig[i]*pi);
					else dig[i]=cos(dig[i]);
					res=dig[i-2]-dig[i];
				}
				else if(i>1 && oper[i-2]=="*")
				{
					if(b[33].GetCheck()==1) dig[i]=cos(dig[i]*pi);
					else dig[i]=cos(dig[i]);
					res=dig[i-2]*dig[i];
				}
			
				else if(i>1 && oper[i-2]=="/")
				{
					if(b[33].GetCheck()==1) dig[i]=cos(dig[i]*pi);
					else dig[i]=cos(dig[i]);
					if(dig[i]==0)
					{
						op.SetWindowText("Can't divide by 0");
						er=1;
					}
					else
					{
						res=dig[i-2]/dig[i];
						dig[i]=res;
					}
				}
				else if(i>1 && oper[i-2]=="^")
				{
					if(b[33].GetCheck()==1) dig[i]=cos(dig[i]*pi);
					else dig[i]=cos(dig[i]);
					res=pow(dig[i-2],dig[i]);
				}
				else 
				{
					if(b[33].GetCheck()==1) res=cos(dig[i]*pi);
					else res=cos(dig[i]);
				}
				dig[i]=res;
			}
			
			else if(oper[i-1]=="c")
			{
				if(i>1 && oper[i-2]=="+")
				{
					dig[i]=cosh(dig[i]);
					res=dig[i-2]+dig[i];
				}
				else if(i>1 && oper[i-2]=="-")
				{
					dig[i]=cosh(dig[i]);
					res=dig[i-2]-dig[i];
				}
				else if(i>1 && oper[i-2]=="*")
				{
					dig[i]=cosh(dig[i]);
					res=dig[i-2]*dig[i];
				}
			
				else if(i>1 && oper[i-2]=="/")
				{
					dig[i]=cosh(dig[i]);
					if(dig[i]==0)
					{
						op.SetWindowText("Can't divide by 0");
						er=1;
					}
					else
					{
						res=dig[i-2]/dig[i];
						dig[i]=res;
					}
				}
				else if(i>1 && oper[i-2]=="^")
				{
					dig[i]=cosh(dig[i]);
					res=pow(dig[i-2],dig[i]);
				}
				else 
					res=cosh(dig[i]);
				dig[i]=res;
			}

			else if(oper[i-1]=="S")
			{
				if(i>1 && oper[i-2]=="+")
				{
					if(b[33].GetCheck()==1) dig[i]=sin(dig[i]*pi);
					else dig[i]=sin(dig[i]);
					res=dig[i-2]+dig[i];
				}
				else if(i>1 && oper[i-2]=="-")
				{
					if(b[33].GetCheck()==1) dig[i]=sin(dig[i]*pi);
					else dig[i]=sin(dig[i]);
					res=dig[i-2]-dig[i];
				}
				else if(i>1 && oper[i-2]=="*")
				{
					if(b[33].GetCheck()==1) dig[i]=sin(dig[i]*pi);
					else dig[i]=sin(dig[i]);
					res=dig[i-2]*dig[i];
				}
				else if(i>1 && oper[i-2]=="/")
				{
					if(b[33].GetCheck()==1) dig[i]=sin(dig[i]*pi);
					else dig[i]=sin(dig[i]);
					if(dig[i]==0)
					{
						op.SetWindowText("Can't divide by 0");
						er=1;
					}
					else
					{
						res=dig[i-2]/dig[i];
						dig[i]=res;
					}
				}
				else if(i>1 && oper[i-2]=="^")
				{
					if(b[33].GetCheck()==1) dig[i]=sin(dig[i]*pi);
					else dig[i]=sin(dig[i]);
					res=pow(dig[i-2],dig[i]);
				}
				else 
				{
					if(b[33].GetCheck()==1) res=sin(dig[i]*pi);
					else res=sin(dig[i]);
				}
				dig[i]=res;
			}

			else if(oper[i-1]=="s")
			{
				if(i>1 && oper[i-2]=="+")
				{
					dig[i]=sinh(dig[i]);
					res=dig[i-2]+dig[i];
				}
				else if(i>1 && oper[i-2]=="-")
				{
					dig[i]=sinh(dig[i]);
					res=dig[i-2]-dig[i];
				}
				else if(i>1 && oper[i-2]=="*")
				{
					dig[i]=sinh(dig[i]);
					res=dig[i-2]*dig[i];
				}
			
				else if(i>1 && oper[i-2]=="/")
				{
					dig[i]=sinh(dig[i]);
					if(dig[i]==0)
					{
						op.SetWindowText("Can't divide by 0");
						er=1;
					}
					else
					{
						res=dig[i-2]/dig[i];
						dig[i]=res;
					}
				}
				else if(i>1 && oper[i-2]=="^")
				{
					dig[i]=sinh(dig[i]);
					res=pow(dig[i-2],dig[i]);
				}
				else 
				{
					res=sinh(dig[i]);
				}
				dig[i]=res;
			}

			else if(oper[i-1]=="T")
			{
				if(b[33].GetCheck()==1 && dig[i]==(int)dig[i] && (int)dig[i]%90==0 && (int)dig[i]%20!=0 && (int)dig[i]!=0)
				{
					op.SetWindowText("Indeterminate");
					er=3;
				}
				else if(i>1 && oper[i-2]=="+")
				{
					if(b[33].GetCheck()==1) dig[i]=tan(dig[i]*pi);
					else dig[i]=tan(dig[i]);
					res=dig[i-2]+dig[i];
				}
				else if(i>1 && oper[i-2]=="-")
				{
					if(b[33].GetCheck()==1) dig[i]=tan(dig[i]*pi);
					else dig[i]=tan(dig[i]);
					res=dig[i-2]-dig[i];
				}
				else if(i>1 && oper[i-2]=="*")
				{
					if(b[33].GetCheck()==1) dig[i]=tan(dig[i]*pi);
					else dig[i]=tan(dig[i]);
					res=dig[i-2]*dig[i];
				}
				else if(i>1 && oper[i-2]=="/")
				{
					if(b[33].GetCheck()==1) dig[i]=tan(dig[i]*pi);
					else dig[i]=tan(dig[i]);
					if(dig[i]==0)
					{
						op.SetWindowText("Can't divide by 0");
						er=1;
					}	
					else
					{
						res=dig[i-2]/dig[i];
						dig[i]=res;
					}
				}
				else if(i>1 && oper[i-2]=="^")
				{
					if(b[33].GetCheck()==1) dig[i]=tan(dig[i]*pi);
					else dig[i]=tan(dig[i]);
					res=pow(dig[i-2],dig[i]);
				}
				else
				{	
					if(b[33].GetCheck()==1) res=tan(dig[i]*pi);
					else res=tan(dig[i]);
				}
				dig[i]=res;
			}

			else if(oper[i-1]=="t")
			{
				if(i>1 && oper[i-2]=="+")
				{
					dig[i]=tanh(dig[i]);
					res=dig[i-2]+dig[i];
				}
				else if(i>1 && oper[i-2]=="-")
				{
					dig[i]=tanh(dig[i]);
					res=dig[i-2]-dig[i];
				}
				else if(i>1 && oper[i-2]=="*")
				{
					dig[i]=tanh(dig[i]);
					res=dig[i-2]*dig[i];
				}
			
				else if(i>1 && oper[i-2]=="/")
				{
					dig[i]=tanh(dig[i]);
					if(dig[i]==0)
					{
						op.SetWindowText("Can't divide by 0");
						er=1;
					}
					else
					{
						res=dig[i-2]/dig[i];
						dig[i]=res;
					}
				}
				else if(i>1 && oper[i-2]=="^")
				{
					dig[i]=tanh(dig[i]);
					res=pow(dig[i-2],dig[i]);
				}
				else 
				{
					res=tanh(dig[i]);
				}
				dig[i]=res;
			}

			else if(oper[i-1]=="iC"||oper[i-1]=="iS"||oper[i-1]=="iT")
			{
				if(dig[i]>1 && oper[i-1]=="iC")
				{
					op.SetWindowText("illegal iCos");
					return;
				}
				if(dig[i]>1 && oper[i-1]=="iS")
				{
					op.SetWindowText("illegal iSin");
					return;
				}
				if(i>1 && oper[i-2]=="+")
				{
					if(b[33].GetCheck()==1)
					{
						if(oper[i-1]=="iC") dig[i]=acos(dig[i])*180*180/pi;
						else if(oper[i-1]=="iS") dig[i]=asin(dig[i])*180*180/pi;
						else if(oper[i-1]=="iT") dig[i]=atan(dig[i])*180*180/pi;
					}
					else 
					{
						if(oper[i-1]=="iC") dig[i]=acos(dig[i]);
						else if(oper[i-1]=="iS") dig[i]=asin(dig[i]);
						else if(oper[i-1]=="iT") dig[i]=atan(dig[i]);
					}
					res=dig[i-2]+dig[i];
				}
				else if(i>1 && oper[i-2]=="-")
				{
					if(b[33].GetCheck()==1)
					{
						if(oper[i-1]=="iC") dig[i]=acos(dig[i])*180*180/pi;
						else if(oper[i-1]=="iS") dig[i]=asin(dig[i])*180*180/pi;
						else if(oper[i-1]=="iT") dig[i]=atan(dig[i])*180*180/pi;
					}
					else 
					{
						if(oper[i-1]=="iC") dig[i]=acos(dig[i]);
						else if(oper[i-1]=="iS") dig[i]=asin(dig[i]);
						else if(oper[i-1]=="iT") dig[i]=atan(dig[i]);
					}
					res=dig[i-2]-dig[i];
				}
				else if(i>1 && oper[i-2]=="*")
				{
					if(b[33].GetCheck()==1)
					{
						if(oper[i-1]=="iC") dig[i]=acos(dig[i])*180*180/pi;
						else if(oper[i-1]=="iS") dig[i]=asin(dig[i])*180*180/pi;
						else if(oper[i-1]=="iT") dig[i]=atan(dig[i])*180*180/pi;
					}
					else 
					{
						if(oper[i-1]=="iC") dig[i]=acos(dig[i]);
						else if(oper[i-1]=="iS") dig[i]=asin(dig[i]);
						else if(oper[i-1]=="iT") dig[i]=atan(dig[i]);
					}
					res=dig[i-2]*dig[i];
				}
			
				else if(i>1 && oper[i-2]=="/")
				{
					if(b[33].GetCheck()==1)
					{
						if(oper[i-1]=="iC") dig[i]=acos(dig[i])*180*180/pi;
						else if(oper[i-1]=="iS") dig[i]=asin(dig[i])*180*180/pi;
						else if(oper[i-1]=="iT") dig[i]=atan(dig[i])*180*180/pi;
					}
					else 
					{
						if(oper[i-1]=="iC") dig[i]=acos(dig[i]);
						else if(oper[i-1]=="iS") dig[i]=asin(dig[i]);
						else if(oper[i-1]=="iT") dig[i]=atan(dig[i]);
					}
					if(dig[i]==0)
					{
						op.SetWindowText("Can't divide by 0");
						er=1;
					}
					else
					{
						res=dig[i-2]/dig[i];
						dig[i]=res;
					}
				}
				else if(i>1 && oper[i-2]=="^")
				{
					if(b[33].GetCheck()==1)
					{
						if(oper[i-1]=="iC") res=acos(dig[i])*180*180/pi;
						else if(oper[i-1]=="iS") res=asin(dig[i])*180*180/pi;
						else if(oper[i-1]=="iT") res=atan(dig[i])*180*180/pi;
					}
					else 
					{
						if(oper[i-1]=="iC") res=acos(dig[i]);
						else if(oper[i-1]=="iS") res=asin(dig[i]);
						else if(oper[i-1]=="iT") res=atan(dig[i]);
					}
					res=pow(dig[i-2],dig[i]);
				}
				else 
				{
					if(b[33].GetCheck()==1)
					{
						if(oper[i-1]=="iC") res=acos(dig[i])*180*180/pi;
						else if(oper[i-1]=="iS") res=asin(dig[i])*180*180/pi;
						else if(oper[i-1]=="iT") res=atan(dig[i])*180*180/pi;
					}
					else 
					{
						if(oper[i-1]=="iC") res=acos(dig[i]);
						else if(oper[i-1]=="iS") res=asin(dig[i]);
						else if(oper[i-1]=="iT") res=atan(dig[i]);
					}
				}
				dig[i]=res;
			}

			else if(oper[i-1]=="l")
			{
				if(dig[i]<=0)
				{
					op.SetWindowText("Invalid log");
					er=4;
				}
				else if(i>1 && oper[i-2]=="+")
				{
					dig[i]=log10(dig[i]);
					res=dig[i-2]+dig[i];
				}
				else if(i>1 && oper[i-2]=="-")
				{
					dig[i]=log10(dig[i]);
					res=dig[i-2]-dig[i];
				}
				else if(i>1 && oper[i-2]=="*")
				{
					dig[i]=log10(dig[i]);
					res=dig[i-2]*dig[i];
				}
				else if(i>1 && oper[i-2]=="/")
				{
					dig[i]=log10(dig[i]);
					if(dig[i]==0)
					{
						op.SetWindowText("Can't divide by 0");
						er=1;
					}
					else
					{
						res=dig[i-2]/dig[i];
						dig[i]=res;
					}
				}
				else if(i>1 && oper[i-2]=="^")
				{
					dig[i]=log10(dig[i]);
					res=pow(dig[i-2],dig[i]);
				}
				else res=log10(dig[i]);
				dig[i]=res;
			}

			else if(oper[i-1]=="L")
			{
				if(dig[i]<=0)
				{
					op.SetWindowText("Invalid Ln");
					er=4;
				}
				else if(i>1 && oper[i-2]=="+")
				{
					dig[i]=log(dig[i]);
					res=dig[i-2]+dig[i];
				}
				else if(i>1 && oper[i-2]=="-")
				{
					dig[i]=log(dig[i]);
					res=dig[i-2]-dig[i];
				}
				else if(i>1 && oper[i-2]=="*")
				{
					dig[i]=log(dig[i]);
					res=dig[i-2]*dig[i];
				}
				else if(i>1 && oper[i-2]=="/")
				{
					dig[i]=log(dig[i]);
					if(dig[i]==0)
					{
						op.SetWindowText("Can't divide by 0");
						er=1;
					}
					else
					{
						res=dig[i-2]/dig[i];
						dig[i]=res;
					}
				}
				else if(i>1 && oper[i-2]=="^")
				{
					dig[i]=log(dig[i]);
					res=pow(dig[i-2],dig[i]);
				}
				else res=log(dig[i]);
				dig[i]=res;
			}

			else if(oper[i-1]=="e")
			{
				if(i>1 && oper[i-2]=="+")
				{
					dig[i]=exp(dig[i]);
					res=dig[i-2]+dig[i];
				}
				else if(i>1 && oper[i-2]=="-")
				{
					dig[i]=exp(dig[i]);
					res=dig[i-2]-dig[i];
				}
				else if(i>1 && oper[i-2]=="*")
				{
					dig[i]=exp(dig[i]);
					res=dig[i-2]*dig[i];
				}
				else if(i>1 && oper[i-2]=="/")
				{
					dig[i]=exp(dig[i]);
					res=dig[i-2]/dig[i];
					dig[i]=res;
				}
				else if(i>1 && oper[i-2]=="^")
				{
					dig[i]=exp(dig[i]);
					res=pow(dig[i-2],dig[i]);
				}
				else res=exp(dig[i]);
				dig[i]=res;
			}
			
			else if(oper[i-1]=="F")
			{
				long int fa,numb;
				fa=(long int)dig[i];
				if(dig[i]<0)
				{
					op.SetWindowText("Invalid Factorial");
					return;
				}
				if(dig[i]>=13)
				{
					MessageBox("In order to find factorials > 12 use Advanced>Very Long Calculations","Please Note");
					op.SetWindowText("Input Error");
					return;
				}
				if(fa==0)fa=1;
				if(fa>=1)
					for(numb=fa-1;numb>0;numb--)
						fa=fa*numb;
				if(i>1 && oper[i-2]=="+")
				{
					dig[i]=fa;
					res=dig[i-2]+dig[i];
				}
				else if(i>1 && oper[i-2]=="-")
				{
					dig[i]=fa;
					res=dig[i-2]-dig[i];
				}
				else if(i>1 && oper[i-2]=="*")
				{
					dig[i]=fa;
					res=dig[i-2]*dig[i];
				}
				else if(i>1 && oper[i-2]=="/")
				{
					dig[i]=fa;
					res=dig[i-2]/dig[i];
					dig[i]=res;
				}
				else if(i>1 && oper[i-2]=="^")
				{
					dig[i]=fa;
					res=pow(dig[i-2],dig[i]);
				}
				else res=fa;
				dig[i]=res;
			}

			else if(oper[i-1]=="{")
			{
				long int su,si=0,numb;
				su=(long int)dig[i];
				if(dig[i]<0)
				{
					op.SetWindowText("Invalid Sum");
					return;
				}				
				if(su>=1)
					for(numb=1;numb<=su;numb++)
						si+=numb;
				if(i>1 && oper[i-2]=="+")
				{
					dig[i]=si;
					res=dig[i-2]+dig[i];
				}
				else if(i>1 && oper[i-2]=="-")
				{
					dig[i]=si;
					res=dig[i-2]-dig[i];
				}
				else if(i>1 && oper[i-2]=="*")
				{
					dig[i]=si;
					res=dig[i-2]*dig[i];
				}
				else if(i>1 && oper[i-2]=="/")
				{
					dig[i]=si;
					res=dig[i-2]/dig[i];
					dig[i]=res;
				}
				else if(i>1 && oper[i-2]=="^")
				{
					dig[i]=si;
					res=pow(dig[i-2],dig[i]);
				}
				else res=si;
				dig[i]=res;
			}
		}
		
		if(x==1)res=dig[0];
		if(er==0)
		{
			str.Format("%lf",res);
			if(str=="-1.#IND00")str="illegal operation";
			op.SetWindowText(str);
			answ=str;
		}
		er=0;
		op.GetWindowText(sav2);
	}

	void on()
	{
		res=0;
		er=0;
		str="";
		ip.SetWindowText(str);
		op.SetWindowText(str);
		ip.SetFocus();
	}

	void skins(int id)
	{
		sk=fopen("config.ini","w");
		switch(id)
		{
		case 101:
			radio1=1;
			radio2=0;
			radio3=0;
			radio4=0;
			bk=1;
			fprintf(sk,"%d",bk);
			break;

		case 102:
			radio1=0;
			radio2=1;
			radio3=0;
			radio4=0;
			bk=2;
			fprintf(sk,"%d",bk);
			break;

		case 103:
			radio1=0;
			radio2=0;
			radio3=1;
			radio4=0;
			bk=3;
			fprintf(sk,"%d",bk);
			break;

		case 104:
			radio1=0;
			radio2=0;
			radio3=0;
			radio4=1;
			bk=4;
			fprintf(sk,"%d",bk);
			break;
		}
		fclose(sk);
	}

	void setradiomark(CCmdUI *item)
	{
		if(item->m_nID==101)
			item->SetRadio(radio1);
		else if(item->m_nID==102)
			item->SetRadio(radio2);
		else if(item->m_nID==103)
			item->SetRadio(radio3);
		else if(item->m_nID==104)
			item->SetRadio(radio4);

		RedrawWindow(NULL,NULL,RDW_INVALIDATE|RDW_ERASE);
	}

	void manual()
	{
		mydialog16 d(IDD_DIALOG16);
		d.DoModal();
	}

	void about()
	{
		MessageBox("Developed in Visual C++ 6.0 by\nAbhishek Kr. Singh\nElectrical & Electronics Engg.(VI)\nBirla Institute of Technology\nMesra,Ranchi.\nINDIA\nEmail: abhi2421@yahoo.com","About");
	}

	int OnEraseBkgnd(CDC *d)  
	{
		CBitmap mybitmap;
		CDC mymemdc;

		
		sk=fopen("config.ini","r");
		if(sk==NULL) 
		{
			bk=1;
			sk=fopen("config.ini","w");
			fprintf(sk,"%d",bk);
		}
		else fscanf(sk,"%d",&bk);
		fclose(sk);

		if(bk==2){mybitmap.LoadBitmap(IDB_BITMAP2);id=102;skins(id);}
		else if(bk==3){mybitmap.LoadBitmap(IDB_BITMAP3);id=103;skins(id);}
		else if(bk==4){mybitmap.LoadBitmap(IDB_BITMAP4);id=104;skins(id);}
		else {mybitmap.LoadBitmap(IDB_BITMAP1);id=101;skins(id);}
	
		mymemdc.CreateCompatibleDC(d);
		mymemdc.SelectObject(&mybitmap);

		d->BitBlt(0,0,300,450,&mymemdc,0,0,SRCCOPY);	
		return 1;

	}

	void saveit()
	{
		int mr;
		mr=MessageBox("Calculation will be saved to calci.txt","Please note...",MB_OKCANCEL|MB_ICONQUESTION);
		if(mr==IDABORT||mr==IDCANCEL)
			return;
		fp=fopen("calci.txt","a");
		fputs(sav1,fp);
		fputs(" = ",fp);
		fputs(sav2,fp);
		fputs("\n",fp);
		fclose(fp);
		MessageBox("Calculation has been saved to calci.txt","Please note...");
	}

	void twovareq()
	{
		mydialog1 d(IDD_DIALOG1);
		d.DoModal();
	}

	void thrvareq()
	{
		mydialog2 d(IDD_DIALOG2);
		d.DoModal();
	}

	void twodeg()
	{
		mydialog3 d(IDD_DIALOG3);
		d.DoModal();
	}

	void thrdeg()
	{
		mydialog4 d(IDD_DIALOG4);
		d.DoModal();
	}

	void matmul()
	{
		mydialog5 d(IDD_DIALOG5);
		d.DoModal();
	}

	void matadj()
	{
		mydialog6 d(IDD_DIALOG6);
		d.DoModal();
	}

	void matinv()
	{
		mydialog7 d(IDD_DIALOG7);
		d.DoModal();
	}

	void detval()
	{
		mydialog8 d(IDD_DIALOG8);
		d.DoModal();
	}

	void diff()
	{
		mydialog9 d(IDD_DIALOG9);
		d.DoModal();
	}

	void integ()
	{
		mydialog10 d(IDD_DIALOG10);
		d.DoModal();
	}

	void compl()
	{
		mydialog11 d(IDD_DIALOG11);
		d.DoModal();
	}

	void verl()
	{
		mydialog14 d(IDD_DIALOG14);
		d.DoModal();
	}

	void stat()
	{
		mydialog15 d(IDD_DIALOG15);
		d.DoModal();
	}

	DECLARE_MESSAGE_MAP()
};
BEGIN_MESSAGE_MAP(myframe,CFrameWnd)

ON_WM_CREATE()
ON_COMMAND(1,on0)
ON_COMMAND(2,poi)
ON_COMMAND(3,pief)
ON_COMMAND(4,root)
ON_COMMAND(5,plus)
ON_COMMAND(6,equ)
ON_COMMAND(7,on1)
ON_COMMAND(8,on2)
ON_COMMAND(9,on3)
ON_COMMAND(10,cosi)
ON_COMMAND(11,minu)
ON_COMMAND(12,ans)
ON_COMMAND(13,on4)
ON_COMMAND(14,on5)
ON_COMMAND(15,on6)
ON_COMMAND(16,sine)
ON_COMMAND(17,mult)
ON_COMMAND(18,powe)
ON_COMMAND(19,on7)
ON_COMMAND(20,on8)
ON_COMMAND(21,on9)
ON_COMMAND(22,tang)
ON_COMMAND(23,divi)
ON_COMMAND(24,expo)
ON_COMMAND(25,loga)
ON_COMMAND(26,nalo)
ON_COMMAND(27,prime)
ON_COMMAND(28,fact)
ON_COMMAND(29,bkspc)
ON_COMMAND(30,on)
ON_COMMAND(37,sig)

ON_COMMAND_RANGE(101,104,skins)
ON_UPDATE_COMMAND_UI_RANGE(101,104,setradiomark)

ON_COMMAND(201,saveit)

ON_COMMAND(301,twovareq)
ON_COMMAND(302,thrvareq)
ON_COMMAND(303,twodeg)
ON_COMMAND(304,thrdeg)
ON_COMMAND(305,matmul)
ON_COMMAND(306,matadj)
ON_COMMAND(307,matinv)
ON_COMMAND(308,detval)
ON_COMMAND(309,diff)
ON_COMMAND(310,integ)
ON_COMMAND(311,compl)
ON_COMMAND(313,verl)
ON_COMMAND(314,stat)

ON_COMMAND(401,manual)
ON_COMMAND(402,about)

ON_WM_ERASEBKGND()

END_MESSAGE_MAP()

void verylong::putvl()
{
	strcpy(vlc,strrev(vlstr));
}
void verylong::getvl()
{
	if(f1==0)strcpy(vlstr,vla);
	else if(f1==1)strcpy(vlstr,vlb);
	vlen=strlen(vlstr);
	strrev(vlstr);
}

verylong verylong::operator + (verylong v)
{
	char temp[SZ];
	int maxlen=(vlen>v.vlen)?vlen:v.vlen;
	int carry=0;
	for(int j=0;j<maxlen;j++)
	{
		int d1=(j>vlen-1)?0:vlstr[j]-'0';
		int d2=(j>v.vlen-1)?0:v.vlstr[j]-'0';
		int digitsum=d1 + d2 + carry;
		if(digitsum>=10)
		{	digitsum -=10;carry=1;}
		else
			carry=0;
		temp[j]=digitsum+'0';
	}
	if(carry==1)
		temp[j++]='1';
	temp[j]='\0';
	return verylong(temp);
}
verylong verylong::operator * (verylong v)
{
	verylong pprod;
	verylong tempsum;
	for(int j=0;j<v.vlen;j++)
	{
		int digit=v.vlstr[j]-'0';
		pprod=multdigit(digit);
		for(int k=0;k<j;k++)
			pprod=mult10(pprod);
		tempsum=tempsum + pprod;
	}
	return tempsum;
}
verylong verylong::mult10(verylong v)
{
	char temp[SZ];
	for(int j=v.vlen-1;j>=0;j--)
		temp[j+1]=v.vlstr[j];
	temp[0]='0';
	temp[v.vlen+1]='\0';
	return verylong(temp);
}
verylong verylong::multdigit(int d2)
{
	char temp[SZ];
	int carry=0;
	for(int j=0;j<vlen;j++)
	{
		int d1=vlstr[j]-'0';
		int digitprod=d1 * d2;
		digitprod+=carry;
		if(digitprod>=10)
		{
			carry=digitprod/10;
			digitprod -=carry * 10;
		}
		else
			carry=0;
		temp[j]=digitprod + '0';
	}
	if(carry!=0)
		temp[j++]=carry + '0';
	temp[j]='\0';
	return verylong(temp);
}

class myapp:public CWinApp
{
public:
	int InitInstance()
	{
		myframe *p;
		p=new myframe;
		p -> ShowWindow(1);
		m_pMainWnd=p;
		return 1;
	}
};
myapp a;