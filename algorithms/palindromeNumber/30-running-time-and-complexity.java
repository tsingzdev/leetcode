// https://www.hackerrank.com/challenges/30-running-time-and-complexity/problem

import java.io.*;
import java.util.*;

public class Solution {

	public static boolean isPrime(int n) {
		boolean flag = true;
		if (n<=1)
			flag = false;
		//if (n==2)
		//    flag = true;
		if (n>1) {
			for (int i=2; i*i<=n; i++) {
				if(n%i==0) {
					flag = false; //  not prime
					break;                    
				} 

			}
		}
		return flag;    

	}

	public static void main(String[] args) {
		/* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
		Scanner sc=new Scanner(System.in);
		int N=sc.nextInt();
		int[] a = new int[N] ;                

		for (int i = 0; i<N; i++) {
			a[i]=sc.nextInt();
			if (isPrime(a[i])) {
				System.out.println("Prime");
			} else {
				System.out.println("Not prime");
			}
		}
	}
}


