import java.util.*;
import java.lang.Math;

public class Solution {  
	public static void fillPrime(ArrayList<Integer> chprime, int high) {
		boolean[] ck = new boolean[high + 1];
		Arrays.fill(ck, true);
		ck[1] = false;
		ck[0] = false;

		for (int i = 2; (i * i) <= high; i++) {
			if (ck[i] == true) {
				for (int j = i * i; j <= Math.sqrt(high); j = j + i) {
					ck[j] = false;
				}
			}
		}
		for (int i = 2; i * i <= high; i++) {
			if (ck[i] == true) {
				chprime.add(i);
			}
		}
	}

	public static void segmentedSieve(int low, int high) {
		ArrayList<Integer> chprime = new ArrayList<Integer>();
		fillPrime(chprime, high);
		boolean[] prime = new boolean[high - low + 1];
		Arrays.fill(prime, true);
		for (int i : chprime) {
			int lower = (low / i);
			if (lower <= 1) {
				lower = i + i;
			} else if (low % i != 0) {
				lower = (lower * i) + i;
			} else {
				lower = (lower * i);
			}
			for (int j = lower; j <= high; j = j + i) {
				prime[j - low] = false;
			}
		}
		int count = 0;
		for (int i = low; i <= high; i++) {
			if (prime[i - low] == true) {
				System.out.printf("%d ", i);
				count++;
			}
		}
		System.out.println("\nSố lượng số nguyên tố trong khoảng " + low + "-" + high + " là: " + count);
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int a, b;
		System.out.println("Nhập a: ");
		a = sc.nextInt();
		System.out.println("Nhập b: ");
		b = sc.nextInt();
		segmentedSieve(a, b);
	}
}