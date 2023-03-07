//Pure Virtual Functions to find Area and Perimeter of different objects

#include<iostream>

using namespace std;

//Abstract Base Class
class Shape
{
//Begining of public scope
public:
	//Declaring variables
	float radius,breadth,length,base,height,area,perimeter;
	//Constructor of abstract class to initialize variables
	Shape(int c)
	{
		switch(c)
		{
			case 1:
				cout<<"Enter Base of Triangle:- ";
				cin>>Shape::base;
				cout<<"Enter Height of Triangle:- ";
				cin>>Shape::height;
				break;
			case 2:
				cout<<"Enter Radius of Circle:- ";
				cin>>Shape::radius;
				break;
			case 3:
				cout<<"Enter Length of Rectangle:- ";
				cin>>Shape::length;
				cout<<"Enter Breadth of Rectangle:- ";
				cin>>Shape::breadth;
				break;
		}
		area=0;
		perimeter=0;
	}
	//Pure virtual fuctions
	virtual void Area()=0;
	virtual void Perimeter()=0;
	//Destructor
	~Shape()
	{
	}
};

//Inherited Class Triangle
class Triangle:public Shape
{
//Begining of public scope
public:
	//Default Constructor to pass value to base class
	Triangle(int c):Shape(c)
	{
	}
	//Function prototypes
	void Area();
	void Perimeter();
	void show();	
	//Default Destructor
	~Triangle()
	{
	}
};

//Overriden function Area in the derived class
void Triangle::Area()
{
	(Shape::area)=((Shape::base)*(Shape::height))/2;
}

//Overriden function Perimeter in the derived class
void Triangle::Perimeter()
{
	(Shape::perimeter)=3*(Shape::base);
}

//Show function of the derived class
void Triangle::show()
{
	cout<<"For Triangle\n"<<"Area = "<<Shape::area
		<<"\nPerimeter = "<<Shape::perimeter<<"\n";
}

//Inherited Class Circle
class Circle:public Shape
{
//Begining of public scope
public:
	//Default Constructor to pass value to base class
	Circle(int c):Shape(c)
	{
	}
	//Function prototypes
	void Area();
	void Perimeter();
	void show();	
	//Default Destructor
	~Circle()
	{
	}
};

//Overriden function Area in the derived class
void Circle::Area()
{
	(Shape::area)=((Shape::radius)*(Shape::radius)*22)/7;
}

//Overriden function Perimeter in the derived class
void Circle::Perimeter()
{
	(Shape::perimeter)=((Shape::radius)*44)/7;
}

//Show function of the derived class
void Circle::show()
{
	cout<<"For Circle\n"<<"Area = "<<Shape::area
		<<"\nPerimeter = "<<Shape::perimeter<<"\n";
}

//Inherited Class Rectangle
class Rectangle:public Shape
{
//Begining of public scope
public:
	//Default Constructor to pass value to base class
	Rectangle(int c):Shape(c)
	{
	}
	//Function prototypes
	void Area();
	void Perimeter();
	void show();	
	//Default Destructor
	~Rectangle()
	{
	}
};

//Overriden function Area in the derived class
void Rectangle::Area()
{
	(Shape::area)=((Shape::breadth)*(Shape::length));
}

//Overriden function Perimeter in the derived class
void Rectangle::Perimeter()
{
	(Shape::perimeter)=((Shape::breadth)+(Shape::length))*2;
}

//Show function of the derived class
void Rectangle::show()
{
	cout<<"For Rectangle\n"<<"Area = "<<Shape::area
		<<"\nPerimeter = "<<Shape::perimeter<<"\n";
}

//Function to use reference of the base class to access the other class'	
void func(Shape &x) 
{
	x.Area();
	x.Perimeter();
}

//Main function
int main()
{	
	//Creating object of Triangle class
	Triangle t(1);
	//Passing object to the function func to perform required operations
	func(t);
	//Calling show function of Triangle
	t.show();
	//Creating object of Circle class
	Circle c(2);
	//Passing object to the function func to perform required operations
	func(c);
	//Calling show function of Triangle
	c.show();
	//Creating object of Gectangle class
	Rectangle r(3);
	//Passing object to the function func to perform required operations
	func(r);
	//Calling show function of Triangle
	r.show();
	return 0;
}
