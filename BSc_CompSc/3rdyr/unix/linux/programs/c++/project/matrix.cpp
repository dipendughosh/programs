//Overloading operators to perform the operations on matrices

#include<iostream>

using namespace std;

//Matrix template class
template<class type>
class Matrix
{
//Begining of private scope
private:
	//Declaring variables
	type a[10][10];
	int n,m;
//Begining of public scope
public:
	//Public variables
	int i,j;
	//Default constructor
	Matrix()
	{
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
				a[i][j]=0;
			}
		}
	}
	//Parameterized constructor
	Matrix(int p,int q)
	{
		m=p;
		n=q;
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
				a[i][j]=0;
			}
		}
	}
	//Declaring function prototypes of normal as 
	//well as operator overloaded functions
	void getij();
	Matrix operator+(Matrix a);
        Matrix operator-(Matrix a);
	Matrix operator*(Matrix a);
	Matrix operator=(Matrix a);
	Matrix operator+=(Matrix a);
	Matrix operator-=(Matrix a);
	Matrix operator++(int);
	Matrix operator++();
	Matrix operator--(int);
	Matrix operator--();
	void show();
	//Destructor
	~Matrix()
	{
	}
};

//Function to enter elements
template<class type>
void Matrix<type>::getij()
{
	cout<<"Enter element:- \n";
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			cout<<"a["<<i<<"]["<<j<<"] = ";
			cin>>a[i][j];
		}
	}
}

//Overloaded '+' operator function
template<class type>
Matrix<type> Matrix<type>::operator+(Matrix ob)
{
	Matrix temp;
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			temp.a[i][j]=Matrix<type>::a[i][j]+ob.a[i][j];
	return temp;
}

//Overloaded '-' operator function
template<class type>
Matrix<type> Matrix<type>::operator-(Matrix ob)
{
	Matrix temp;
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			temp.a[i][j]=Matrix<type>::a[i][j]-ob.a[i][j];
	return temp;
}

//Overloaded '*' operator function
template<class type>
Matrix<type> Matrix<type>::operator*(Matrix ob)
{
	Matrix temp;
	int k;
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			for(k=0;k<m;k++)
				temp.a[i][j]=temp.a[i][j]+(Matrix<type>::a[i][k]*ob.a[k][j]);
	return temp;
}

//Overloaded '=' operator function
template<class type>
Matrix<type> Matrix<type>::operator=(Matrix ob)
{
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			Matrix<type>::a[i][j]=ob.a[i][j];
	return *this;
}

//Overloaded '+=' operator function
template<class type>
Matrix<type> Matrix<type>::operator+=(Matrix ob)
{
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			Matrix<type>::a[i][j]=Matrix<type>::a[i][j]+ob.a[i][j];
	return *this;
}

//Overloaded '-=' operator function
template<class type>
Matrix<type> Matrix<type>::operator-=(Matrix ob)
{
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			Matrix<type>::a[i][j]=Matrix<type>::a[i][j]-ob.a[i][j];
	return *this;
}

//Overloaded '++' postfix operator function
template<class type>
Matrix<type> Matrix<type>::operator++(int p)
{
	Matrix temp;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			temp.a[i][j]=Matrix<type>::a[i][j];
			Matrix<type>::a[i][j]++;
		}
	}
	return temp;
}

//Overloaded '++' prefix operator function
template<class type>
Matrix<type> Matrix<type>::operator++()
{
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			Matrix<type>::a[i][j]++;
	return *this;
}

//Overloaded '--' postfix operator function
template<class type>
Matrix<type> Matrix<type>::operator--(int p)
{
	Matrix temp;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			temp.a[i][j]=Matrix<type>::a[i][j];
			Matrix<type>::a[i][j]--;
		}
	}
	return temp;
}

//Overloaded '--' prefix operator function
template<class type>
Matrix<type> Matrix<type>::operator--()
{
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			Matrix<type>::a[i][j]--;
	return *this;
}

//Function to display elements
template<class type>
void Matrix<type>::show()
{
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
			cout<<"\t"<<Matrix<type>::a[i][j];
		cout<<"\n";
	}
}

//Main function
main()
{
	//Declaring variables
	int m,n,p,q;
	char ch;
	cout<<"\nMAIN MENU";
	cout<<"\n'i' for integer";
	cout<<"\n'f' for float";
	cout<<"\nEnter your choice : ";
	cin>>ch;
	cout<<"Enter number of rows of 1st matrices: ";
	cin>>m;
	cout<<"Enter number columns of 1st matrices: ";
	cin>>n;
	cout<<"Enter number of rows of 2nd matrices: ";
	cin>>p;
	cout<<"Enter number columns of 2nd matrices: ";
	cin>>q;
	if(ch=='i')
	{
		//Declaring objects
		Matrix<int> ob1(m,n),ob2(p,q);
		//Displaying entered matrices
		cout<<"\nFor 1st matrix ";
		ob1.getij();
		cout<<"\nFor 2nd matrix ";
		ob2.getij();
		cout<<"\nA =";
		ob1.show();
		cout<<"\nB =";
		ob2.show();
		//Checking if addition and subtraction are possible
		if(m != p && n != q)
		{
			cout<<"Cannot perform Addition,Subtraction\n";
		}
		else
		{	
			Matrix<int>ob3(m,n);
			ob3=ob1+ob2;
			cout<<"\nC = A + B\nC =";
			ob3.show();
			ob3=ob1-ob2;
			cout<<"\nC = A - B\nC =";
			ob3.show();
		}
		//Checking if multiplication possible
		if(n != p)
		{
			cout<<"Cannot perform Multiplication";
		}
		else
		{
			Matrix<int> ob4(m,q);
			ob4=ob1*ob2;
			cout<<"\nC = A * B\nC =";
			ob4.show();
		}
		//Assigning values
		Matrix<int> ob5(m,n);
		ob5=ob1;
		cout<<"\nC = A\nC =";
		ob5.show();
		//Postfix and prefix increment and decrement
		cout<<"\nA =";
		ob1.show();
		++ob1;
		cout<<"\n++A\nA =";
		ob1.show();
		ob5=ob1++;
		cout<<"\nC = A++\nC =";
		ob5.show();
		cout<<"\nA =";
		ob1.show();
		Matrix<int> ob6(p,q);
		cout<<"\nB =";
		ob2.show();
		--ob2;
		cout<<"\n--B";
		ob2.show();
		ob6=ob2--;
		cout<<"\nC = B--\nC =";
		ob6.show();
		cout<<"\nB =";
		ob2.show();
		//Shorthand notations
		if(m != p && n != q)
		{
			cout<<"Cannot perform '-=' and '-='\n";
		}
		else
		{
			ob1+=ob2;
			cout<<"\nA += B\nA = \n";
			ob1.show();
			ob2-=ob1;
			cout<<"\nB -= A\nB = \n";
			ob2.show();
		}
	}
	else if(ch=='f')
	{
		//Declaring objects
		Matrix<float> ob1(m,n),ob2(p,q);
		//Displaying entered matrices
		cout<<"\nFor 1st matrix ";
		ob1.getij();
		cout<<"\nFor 2nd matrix ";
		ob2.getij();
		cout<<"\nA =";
		ob1.show();
		cout<<"\nB =";
		ob2.show();
		//Checking if addition and subtraction are possible
		if(m != p && n != q)
		{
			cout<<"Cannot perform Addition,Subtraction\n";
		}
		else
		{	
			Matrix<float>ob3(m,n);
			ob3=ob1+ob2;
			cout<<"\nC = A + B\nC =";
			ob3.show();
			ob3=ob1-ob2;
			cout<<"\nC = A - B\nC =";
			ob3.show();
		}
		//Checking if multiplication possible
		if(n != p)
		{
			cout<<"Cannot perform Multiplication";
		}
		else
		{
			Matrix<float> ob4(m,q);
			ob4=ob1*ob2;
			cout<<"\nC = A * B\nC =";
			ob4.show();
		}
		//Assigning values
		Matrix<float> ob5(m,n);
		ob5=ob1;
		cout<<"\nC = A\nC =";
		ob5.show();
		//Postfix and prefix increment and decrement
		cout<<"\nA =";
		ob1.show();
		++ob1;
		cout<<"\n++A\nA =";
		ob1.show();
		ob5=ob1++;
		cout<<"\nC = A++\nC =";
		ob5.show();
		cout<<"\nA =";
		ob1.show();
		Matrix<float> ob6(p,q);
		cout<<"\nB =";
		ob2.show();
		--ob2;
		cout<<"\n--B";
		ob2.show();
		ob6=ob2--;
		cout<<"\nC = B--\nC =";
		ob6.show();
		cout<<"\nB =";
		ob2.show();
		//Shorthand notations
		if(m != p && n != q)
		{
			cout<<"Cannot perform '-=' and '-='\n";
		}
		else
		{
			ob1+=ob2;
			cout<<"\nA += B\nA = \n";
			ob1.show();
			ob2-=ob1;
			cout<<"\nB -= A\nB = \n";
			ob2.show();
		}
	}
	else
		cout<<"\nERROR in choice!\n";
	return 0;
}

