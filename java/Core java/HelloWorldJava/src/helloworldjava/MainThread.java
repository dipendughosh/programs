package helloworldjava;

import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;

class TestThread1 implements Runnable {
    int num ;
    
    public void run () {
        table() ;
    }
    
    synchronized public void table () {
        for (int i = 1; i <= 10; i++) {
            try {
                Thread.sleep(1000) ;
            }
            catch (Exception e) {
                System.out.println("Exception " + e) ;
            }
            //System.out.println("Thread 1 " + Thread.currentThread().getName() + " " + i + " is running ") ;
            System.out.println(num + " X " + i + " = " + num*i) ;
        }
    }
    /*public void run (int var) {
        System.out.println("Run second " + var) ;
    }*/
}

class TestThread2 implements Runnable {
    int num ;
    
    public void run () {
        table() ;
    }
    
    synchronized public void table () {
        for (int i = 1; i <= 10; i++) {
            try {
                Thread.sleep(1000) ;
            }
            catch (Exception e) {
                System.out.println("Exception " + e) ;
            }
            //System.out.println("Thread 2 " + Thread.currentThread().getName()  + " " +  i + " is running ") ;
            System.out.println(num + " X " + i + " = " + num*i) ;
        }
    }
}

class MainThread {
    
    public static void main(String[] args) {
        TestThread1 t1 = new TestThread1() ;
        TestThread2 t2 = new TestThread2() ;
        Thread t3 = new Thread(t1) ;
        Thread t4 = new Thread(t2) ;
        System.out.println("t1 old name - " + t3.getName() + " t1 id " + t3.getId()) ;
        System.out.println("t2 old name - " + t4.getName() + " t1 id " + t4.getId()) ;
        t3.setName("Thread 1") ;
        t4.setName("Thread 2") ;
        System.out.println("t1 new name - " + t3.getName()) ;
        System.out.println("t2 new name - " + t4.getName()) ;
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
        t3.start() ;
        /*try {
            t3.join(100) ;
        } catch (InterruptedException ex) {
            Logger.getLogger(MainThread.class.getName()).log(Level.SEVERE, null, ex) ;
        }*/
        t4.start() ;
        //t1.run(8);
    }
}