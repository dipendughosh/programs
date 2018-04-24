package helloworldjava;

import java.io.* ; 

class HelloWorldJava {
    HelloWorldJava () {
        System.out.println("HelloWorldJava Constructor");
    }
    //{System.out.println("Hello World") ;}
    public static void main(String[] args) {
	String str = "Hello World" ;
        {System.out.println(str) ;}
	/*int x = 10 ;
	int y = 20 ;
	int z = 0 ;*/
	Compute c1 = new Compute(1000, 2000, 9876) ;
	Compute c = new Compute() ;
	Compute c2 = new Compute(c1) ;
        int res = c.compute1(10, 20) ;
        Display d = new Display() ;
	d.display1(res) ;
        res = c.compute1(1, 2, 0) ;
        d.display1(res) ;
        res = c.compute1(100, 20.0) ;
        d.display1(res) ;
	//c.display();
	/*z = x * y ;
	
	System.out.println("x = " + x) ;
	System.out.print("y = " + y) ;
	System.out.println(" ") ;
	System.out.println("x = " + x + " y = " + y + " z = " + z) ;*/
		
		
	char a = 'a' ;
	String str1 = "Dipendu" ;
	String str2 = "Ghosh" ;
	System.out.println("str1 = " + str1 + " str2 = " + str2 ) ;
	System.out.println("str1.toUpperCase() = " + str1.toUpperCase() + " str2.toLowerCase() = " + str2.toLowerCase() ) ;
	String doNotDoThis = new String ("Bad Method") ;
	System.out.println("doNotDoThis " + doNotDoThis) ;
	String doNotDoThis2 ;
	doNotDoThis2 = "Bad Method 2" ;
	System.out.println("doNotDoThis2 " + doNotDoThis2) ;
    }
}

class Compute {
    int result ;
    int a = 0 ;
    int b = 0 ;
    Compute () {
		HelloWorldJava h = new HelloWorldJava() ;
        result = 123456 ;
        a = 50 ;
        b = 60 ;
        a = a * b ;
        System.out.println("Compute Constructor 1 result " + result + " a " + a + " b " + b) ;        
    }
    Compute (int x, int y, int z) {
        result = z ;
        a = x ;
        b = y ;
        a = a * b ;
        System.out.println("Compute Constructor 2 result " + result + " a " + a + " b " + b) ;        
    }
    Compute (Compute c) {
        result = c.result ;
        a = c.a; ;
        b = c.b; ;
        //a = a * b ;
        System.out.println("Compute Constructor 3 result " + result + " a " + a + " b " + b + " c " + c.toString()) ;        
    }
    //void compute1 (int x, int y) {
    //Method overloading
    int compute1 (int x, int y) {
        int z ;
        System.out.println("Compute 1 result " + result + " a " + a + " b " + b) ;
        z = x * y ;
        result = z ;
        //return z ;
        return result ;
    }
    //Method overloading
    int compute1 (int x, double y) {
        int z ;
        System.out.println("Compute 2 result " + result + " a " + a + " b " + b) ;
        z = x * (int)y ;
        result = z ;
        //return z ;
        return result ;
    }
    //Method overloading
    int compute1 (int x, int y, int z) {
        //int z ;
        System.out.println("Compute 3 result " + result + " a " + a + " b " + b) ;
        z = x * y ;
        result = z ;
        System.out.println("Compute 3") ;
        //return z ;
        return result ;
    }
/*void display () {
    System.out.println("Result is " + result) ;
}*/
} 

class Display {
    void display1(int res) {
    System.out.println("Result is " + res) ;
    }
}