package helloworldjava;

import java.util.Scanner;

/**
 *
 * @author DiGhosh
 */

class Table {
    
    synchronized void compute(int num) {
        for (int i = 1; i <= 10; i++) {
            try {
                Thread.sleep(1000) ;
            }
            catch (Exception e) {
                System.out.println("Exception " + e) ;
            }
            System.out.println(num + " X " + i + " = " + num*i) ;
        }
    }
}

class MyThread1 extends Thread {
    
    Table t ;
    int num ;

    MyThread1(Table t) {
        this.t = t ;
    }
    
    public void run () {
        t.compute(num) ;
    }
}
class MyThread2 extends Thread {

    Table t ;
    int num ;

    MyThread2(Table t) {
        this.t = t ;
    }
    
    public void run () {
        t.compute(num) ;
    }
}

public class TestSync {
    
    public static void main(String[] args) {
        Table obj = new Table () ;
        MyThread1 t1 = new MyThread1(obj) ;
        MyThread2 t2 = new MyThread2(obj) ;
        
        Scanner sc1 = new Scanner(System.in) ;
        System.out.print("Enter number 1 : ") ;
        try {
            t1.num = sc1.nextInt() ;          
        }
        catch(Exception e) {
            System.out.println("Exception thrown " + e) ;
        }
        Scanner sc2 = new Scanner(System.in) ;
        System.out.print("Enter number 1 : ") ;
        try {
            t2.num = sc2.nextInt() ;          
        }
        catch(Exception e) {
            System.out.println("Exception thrown " + e) ;
        }
        
        t1.start() ;
        t2.start() ;
    }
}
