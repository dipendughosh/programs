package test;

import java.util.Scanner;

public class CharCountInWord {

	static String str ;
	static int alphaCount[]=new int[26] ;
	
	CharCountInWord(){
		int i = 0 ;
		while(i < 26) {
			alphaCount[i] = 0 ;
		}
	}
	
	static int length(String string) {
		
		int i = 0 ,c = 0;
		try {
			for(i = 0,c = 0; 0 <= i; i++, c++) {
				string.charAt(i);
	        }
		}
		catch(Exception e) {
        }
        return c;
	}
	
	static void toUpper() {
		
		int i = 0 ;
		int len = length(str) ;
		//int len = str.length() ;
		String newStr = "" ;
		while(i < len) {
			char a = str.charAt(i) ;
			int b = a ;
			if ( a >= 'a' && a <= 'z') {
				b = b - 32 ;
				a = (char) b ;
			}
			newStr = newStr + a;
			i++ ;
		}
		str = newStr ;
	}
	
	static void getStr() {
		
		@SuppressWarnings("resource")
		Scanner scanner = new Scanner (System.in) ;
		System.out.print("Enter word - ") ;  
		str = scanner.next() ;
		toUpper() ;
		//str = str.toUpperCase() ;
	}
	
	static void countChar() {
		
		int i = 0 ;
		while(i < str.length()) {
			char a = str.charAt(i) ;
			int b = a - 65 ;
			alphaCount[b]++ ;
			i++ ;			
		}
	}
	
	static void displayResult() {
		
		System.out.println("Alphabet\tCount") ;
		for(int i = 0; i < 26; i++) {
			int n = i + 65 ;
			char c = (char) n ;
			System.out.println(c + "\t\t" + alphaCount[i]) ;
		}
	}
	
	public static void main(String[] args) {
		
		getStr() ;
		countChar() ;
		displayResult() ;		
	}

}
