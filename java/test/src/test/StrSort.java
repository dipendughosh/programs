package test;

import java.util.Arrays;
import java.util.Comparator;

public class StrSort {

	public StrSort() {
		// TODO Auto-generated constructor stub
	}

	public static void main(String[] args) {
		/*String a[]=new String[5];
		a[0]="aaa";
		a[1]="bbb";
		a[2]="ccc";
		a[3]="ddd";
		a[4]="eee";
		for(int i=0;i<5;i++) {
			System.out.println("a["+i+"]="+a[i]);
		}
		System.out.println();*/
		
		String S = "No one could disentangle correctly";
		String W[] = S.split(" ");
		//Arrays.sort(W, (a, b)->Integer.compare(a.length(), b.length()));
		Arrays.sort(W);
		for(int i=0;i<W.length;i++) {
			System.out.println("W["+i+"]="+W[i]);
		}
		System.out.println("");
		Arrays.sort(W, Comparator.comparingInt(String::length));
		for(int i=0;i<W.length;i++) {
			System.out.println("W["+i+"]="+W[i]);
		}

	}

}
