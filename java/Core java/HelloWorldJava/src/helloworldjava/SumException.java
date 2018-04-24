package helloworldjava;

/*WAP to create a user defined exception to handle the exception raised when the sum of the numbers is greater than 20*/
/*WAP to except 2 integer inputs from the user and if the products of the 2 inputs is a prime create an user defined exception to handle the same else if odd or even.*/

import java.io.* ;
import java.util.* ;

class SumException {
    
    public static void main(String args[]) {
        int num1 = 0 ;
        int num2 = 0 ;
        int result = 0;
        
        Scanner sc1 = new Scanner(System.in) ;
        System.out.print("Enter number 1 : ") ;
        try {
            num1 = sc1.nextInt() ;          
        }
        catch(Exception e) {
            System.out.println("Exception thrown " + e);
        }
        
        Scanner sc2 = new Scanner(System.in) ;
        System.out.print("Enter number 2 : ") ;
        try {
            num2 = sc2.nextInt() ;          
        }
        catch(Exception e) {
            System.out.println("Exception thrown " + e);
        }
        
        try {
            result = sum(num1, num2) ;
            TestException.validateSum(result) ;
        }
        catch(Exception e) {
            System.out.println("Exception thrown " + e);
        }
        
        try {
            result = product(num1, num2) ;
            System.out.println("Prod " + result);
            TestException.validateProduct(result) ;
        }
        catch(Exception e) {
            System.out.println("Exception thrown " + e);
        }
    }
	
    static int sum(int num1, int num2) {
        int sum = num1 + num2 ;
        return sum ;
    }
    
    static int product(int num1, int num2) {
        int product = num1 * num2 ;
        return product ;
    }
}

class TestException {
    
    static void validateSum(int val) throws InvalidException {
        if (val > 20) {
            throw new InvalidException("Sum is greater than 20.") ;
        }
        else {
            System.out.println("Sum = " + val);
        }
    }
    
    static void validateProduct(int val) throws InvalidException {
        boolean flag = false ;
        
        for (int i = 2 ; i <= val/2; i++) {
            if ((val % i) == 0) {
                flag = true ;
                break ;
            }
        }
        if (!flag) {
            throw new InvalidException("Product is Prime.") ;
        }
        else {
            System.out.println("Product = " + val);
            if ((val % 2) == 0) {
                throw new InvalidException("Product is Even.") ;
            }
            else {
                throw new InvalidException("Product is Odd.") ;
            }
        }
    }
}

class InvalidException extends Exception {

    InvalidException(String s) {
        super(s) ;
    }
}