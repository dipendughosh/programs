package test;

import java.util.Scanner;

public class BinSearch {

	public static int[] a;
	public static int m,lb,ub;

	public BinSearch(int size) {
		m = size;
		lb = 0;
		ub = size - 1;
		a = new int[size];
	}

	public void get_val() {
		System.out.println("Size of Array: " + m);

		System.out.println("Enter the Elements: ");
		Scanner sc = new Scanner(System.in);

		for(int i = 0; i < m; i++) {
			System.out.print("a["+i+"] = ");
			a[i] = sc.nextInt();
		}
		System.out.println("Elements of the Array ");
		for(int i = 0; i < m; i++) {
			System.out.println("a["+i+"]= "+a[i]);
		} 
	}

	public int binSearch(int a[], int lb, int ub, int key) {
		int mid = 0;
		
		if(lb > ub)
			return -1;
		if(lb <= ub) {
			mid = (lb + ub) / 2;
			System.out.println("lb = " + lb + ", ub = " + ub + ", mid = " + mid + ", key = " + key );
			if(a[mid] > key) {
				System.out.println("if------");
				return binSearch(a, lb, mid - 1, key);
			}
			else if (a[mid] < key) {
				System.out.println("else if------------");
				return binSearch(a, mid + 1, ub, key);
			}
			else {
				System.out.println("else------------");
				return mid;
			}
		}
		return -1;
	}

	public static void main(String[] args) {
		System.out.println("Enter the size of elements: ");
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		
		BinSearch ob = new BinSearch(n);
		ob.get_val();

		System.out.println("Enter the no to be searched: ");
		int key = sc.nextInt();
		
		int pos = ob.binSearch(a, lb, ub, key);
		if (pos == -1) {
			System.out.println(key + " not found");
		}
		else {
			System.out.println("value found at "+pos+"th position");
		}
	}
}