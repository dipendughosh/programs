#include<iostream>
using namespace std;

class Shape{
	protected:
		float area;
		float len,br;
	public:
		Shape(float l,float b){
			len=l;
			br=b;
		}
		virtual void area1(void) = 0;
//		~Shape();

};
class Rec: public Shape{
	public:
		Rec(float l,float b) : Shape(l,b){
	}
	void area1(){
		area=len*br;
		cout<<"Area of the rectangle is: "<<area;
	}
};
int main(){
	Rec ob1(10,2);
	ob1.area1();
	return 0;
}
/*#include <iostream>
using namespace std;

class Polygon {
  protected:
    int width, height;
  public:
    Polygon (int a, int b) {width = a; height = b; }
    virtual int area (void) =0;
    void printarea()
      { cout << this->area() << '\n'; }
};

class Rectangle: public Polygon {
  public:
    Rectangle(int a,int b) : Polygon(a,b) {}
    int area()
      { return width*height; }
};

class Triangle: public Polygon {
  public:
    Triangle(int a,int b) : Polygon(a,b) {}
    int area()
      { return width*height/2; }
};

int main () {
  Rectangle ppoly1 = Rectangle (4,5);
  Triangle ppoly2 = Triangle (4,5);
  ppoly1.printarea();
  ppoly2.printarea();
  return 0;
}*/
