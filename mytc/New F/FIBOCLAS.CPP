// Fibonacci Series creating a class

#include <iostream.h>
#include <conio.h>

class fibonacci {
	private:
		int f0,f1,f2;
	public:
		fibonacci() {
			f0 = 0; f1 = 1; f2 = f0 + f1;
			}
		void increment();
  //			f0 = f1; f1 = f2; f2 = f0 + f1;
	//		}
		void display() { cout<<f2<<"  "; }
} number;

void fibonacci::increment() {
	f0 = f1; f1 = f2; f2 = f0 + f1;
	}

void main() {
	clrscr();
	//fibonacci number;
	number.display();
	for ( int i = 0; i<15; i++){
		number.display();
		number.increment();
	}
	getche();
}





