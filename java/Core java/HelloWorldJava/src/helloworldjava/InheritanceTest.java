package helloworldjava;

import java.io.* ; 

class Child extends InheritanceTest {
    Child (int x) {
        super(x) ;
        y = 100 ;
	System.out.println("Child Constructor x = " + x) ;        
    }
    //Override
    void display () {
        System.out.println("Child display") ;
    }
}

class InheritanceTest {
    InheritanceTest (int x) {
        System.out.println("InheritanceTest Parent Constructor x = " + x) ;
    }
    int y = 10 ;
    public static void main(String[] args) {
	//InheritanceTest i = new InheritanceTest() ;
        Child c = new Child(10) ;
        c.display() ;
        //i.display() ;
    }
    
    void display () {
        System.out.println("InheritanceTest display") ;
    }
}