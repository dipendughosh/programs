//package helloworldjava;

import java.io.*;

public class FileWriterTest {
    public static void main(String[] args) {
        try {
            FileWriter out = new FileWriter("text.txt") ;
            BufferedWriter b = new BufferedWriter(out) ;
            PrintWriter p = new PrintWriter(b) ;
            
            p.println("Hello World in a file.") ;
            p.close() ;
            
            
        }
        catch(Exception e) {
            System.out.println(e);
        }
    }
}
