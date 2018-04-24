package helloworldjava;

//import java.io.* ;
import java.util.* ;

class CustomException {
    
    public static void main(String args[]) {
        int age ;
        
        Scanner sc = new Scanner(System.in) ;
        System.out.println("Enter age : ") ;
        try {
            age = sc.nextInt() ;
            TestException1.validate(age) ;
        }
        catch(Exception e) {
            System.out.println("Exception thrown " + e);
        }
    }
}

class TestException1 {
    
    static void validate(int age) throws InvalidAgeException {
        if (age < 18) {
            throw new InvalidAgeException("Not a valid age") ;
        }
        else {
            System.out.println("Valid Age");
        }
    }
}

class InvalidAgeException extends Exception {

    InvalidAgeException(String s) {
        super(s) ;
    }
}