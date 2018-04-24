/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package helloworldjava;
import java.io.*;
import java.util.*;

/**
 *
 * @author DiGhosh
 */
public class CollectionSet {

    public static void main(String args[])
    {
        TreeSet<String> al = new TreeSet<>();
        //LinkedList<String> li = new LinkedList<>();        //ArrayList<String> al = new ArrayList<String>();
        //ArrayList al = new ArrayList();
        
        queue.add("my") ;
        queue.add("name") ;
        queue.add("is") ;
        queue.add("mohan") ;
        System.out.println("head: ", queue.element()) ;
        System.out.println("head: ", queue.peek()) ;
        
        al.add("My");
        al.add("name");
        al.add("My");
        al.add("Mohan");
  
        
        Iterator i = al.iterator();
        while(i.hasNext())
        {
            System.out.println(i.next());
        }
        
        queue.remove() ;
        queue.poll() ;
        
        while(i.hasNext()) {
            Student s = i.next() ;
            System.out.println(s.rollno) ;
        }
    }  
}