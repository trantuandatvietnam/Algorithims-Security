# Thuật toán trong an toàn thông tin

### Bài 1 Một số gọi là Q-prime khi nó có đúng 4 ước số nguyên dương. Hãy viết chương trình in ra các số Q-Prime nhỏ hơn hoặc bằng một số N cho trước nhập từ bàn phím.

```c
#include <stdio.h>
#include <stdbool.h>
#include<math.h>

bool check(int n)
{
    int count = 0;
    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            if (n / i == i)
            {
                count++;
            }
            else
            {
                count += 2;
            }
        }
    }
    return count == 4;
}
int main()
{
    int n;
    scanf("%d", &n);
    if (n <= 4)
    {
        printf("No");
        return 0;
    }

    for (int i = 0; i <= n; i++)
    {
        if (check(i))
            printf("%d\n", i);
    }
    return 0;
}
```

### Bài 2: Viết chương trình tìm các số nguyên tố có N chữ số với N nhập từ bàn phím và 2 ≤ N ≤ 10.

```java
package ex;

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
		for (int i = low; i <= high; i++) {
			if (prime[i - low] == true) {
				System.out.printf("%d\n", i);
			}
		}
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n;
		System.out.println("Nhập n: ");
		n = sc.nextInt();
		int left = (int) Math.pow(10, n - 1);
	    int right = (int) (Math.pow(10, n) - 1);
		segmentedSieve(left, right);
	}
}
```

### Bài 3. Cho một số nguyên dương N, gọi:

- k là số ước nguyên tố của N;
- q là tổng của các ước nguyên tố của N;
- p là tổng của các ước số của N;
- s là số ước của N;

```c
#include <stdio.h>
int main()
{
    int N, p, s, q, k, i, dem, Tong, t;
    p = s = q = k = i = Tong = 0;
    printf("Nhap so N duong ");
    scanf("%d", &N);
    int a[N + 1];
    for (i = 2; i <= N; i++)
    {
        a[i] = 1;
    }
    for (p = 2; p < N; p++)
    {
        t = N / p;
        for (i = 2; i <= t; i++)
            a[p * i] = 0;
    }
    for (i = 2; i <= N; i++)
    {
        if ((a[i] == 1) && (N % i == 0))
        {
            q = q + i;
            k++;
        }
    }
    p = 0;
    for (i = 1; i <= N; i++)
    {
        if (N % i == 0)
        {
            p = p + i;
            s++;
        }
    }
    Tong = N + p + s - q - k;
    printf("Vay ket qua la %d+%d+%d-%d-%d=%d", N, p, s, q, k, Tong);
}
```

### Bài 4: Viết chương trình đếm số số nguyên tố nằm trong khoảng [A,B] với A, B nhập vào từ bàn phím.

- EXPLAIN:

1. Sử dụng sàng đơn giản để tìm ra tất cả các số nguyên tố từ 2 đến căn bậc 2 của b, và lưu trữ các số nguyên tố này trong một mảng.
2. Tạo một mảng đánh dấu: [high - low + 1]
3. Lặp lại tất cả các số nguyên tố được tìm thấy ở bước 1, Đối với số nguyên tố, hãy đánh dấu bội số của nó trong phạm vi từ [low, high]

- NX: Vì vậy, không giống như sàng đơn giản, không kiểm tra tất cả bội số của mọi số nhỏ hơn căn bậc hai của high, chỉ kiểm tra bội số của các số nguyên tố được tìm thấy ở bước 1. Và không cần space O(high), cần O (sqrt(high) + n) không gian.

```java
package ex;

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
```

### Bài 5: Viết chương trình tính tổng của các số nguyên tố nằm trong khoảng [A, B] với A, B nhập vào từ bàn phím.

```java
package ex;
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
		int total = 0;
		for (int i = low; i <= high; i++) {
			if (prime[i - low] == true) {
				total += i;
			}
		}
		System.out.println("Total: " + total);
	}
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int a, b;
		System.out.println("Enter a: ");
		a = sc.nextInt();
		System.out.println("Enter b: ");
		b = sc.nextInt();
		segmentedSieve(a, b);
	}
}
```

### Bài 6: Cặp số thân thiết

```java
package ex;

import java.util.Scanner;

public class Solution {

    static Scanner scanner = new Scanner(System.in);

    public static long sumOfDivisior(long n) {
        long sum = 1;
        for (long i = 2; i*i < n; i++) {
            if (n % i == 0) {
                if (n / i == i) {
                    sum += 1;
                }else{
                    sum += (i + (n / i));
                }
            }
        }
        return sum;
    }

    public static void main(String[] args) {
        long n;
        n = scanner.nextLong();
        for (long i = 1; i <= n; i++) {
            long a = sumOfDivisior(i);
            if (i == sumOfDivisior(a) && a != i && a < n && i < a) {
                System.out.println(i + " " + a);
            }
        }
    }
}
```

### Bài 7: số Emirp

```java
package ex;

import java.util.Scanner;
public class Solution {
	static Scanner sc = new Scanner(System.in);
	static boolean isPrime(int n) {
		// Corner cases
		if (n <= 1)
			return false;
		if (n <= 3)
			return true;

		// This is checked so that we can skip
		// middle five numbers in below loop
		if (n % 2 == 0 || n % 3 == 0)
			return false;
		// all prime number has format: 6k +- 1, exclude 2, 3
		for (int i = 5; i * i <= n; i = i + 6)
			if (n % i == 0 || n % (i + 2) == 0)
				return false;

		return true;
	}

	static int reverse(int n) {

		int rev = 0; // reversed number
		int rem; // remainder

		while (n > 0) {

			rem = n % 10;
			rev = (rev * 10) + rem;
			n = n / 10;
		}

		return rev;
	}

	public static void main(String[] args) {
		int n = sc.nextInt();
		for(int i = 2; i < n; i++) {
			if(isPrime(i) && isPrime(reverse(i))) {
				System.out.println(i);
			}
		}
	}
}
```

### Bài 8: Т-prime

```c
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool checkTTPrime(int n)
{
    int count = 0;
    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            if (n / i == i)
            {
                count++;
            }
            else
            {
                count += 2;
            }
        }
    }
    return count == 3;
}
int main()
{
    int n;
    scanf("%d", &n);
    if (n < 4)
    {
        printf("No");
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        if (checkTTPrime(i))
            printf("%d\n", i);
    }
    return 0;
}
```

### Bài 9: SL Số nguyên tố nhỏ hơn hoặc bằng n

```java
package ex;

import java.util.Scanner;

public class Solution {
	static Scanner sc = new Scanner(System.in);

	public static int countNumberOfPrime(int n) {
		// Create a boolean array "prime[0..n]" and initialize
		// all entries it as true. A value in prime[i] will
		// finally be false if i is Not a prime, else true.
		boolean prime[] = new boolean[n + 1];
		for (int i = 0; i <= n; i++)
			prime[i] = true;

		for (int p = 2; p * p <= n; p++) {
			// If prime[p] is not changed, then it is a prime
			if (prime[p] == true) {
				// Update all multiples of p
				for (int i = p * p; i <= n; i += p)
					prime[i] = false;
			}
		}

		// Count all prime numbers
		int count = 0;
		for (int i = 2; i <= n; i++) {
			if (prime[i] == true)
				count++;
		}
		return count;
	}

	public static void main(String[] args) {
		int n = sc.nextInt();
		System.out.println("Number: " + countNumberOfPrime(n));
	}
}
```

### Bài 10: Viết chương trình đếm số ước và số ước nguyên tố của một số N nhập vào từ bàn phím.

```java
package ex;

import java.util.Scanner;

public class Solution {
	static Scanner sc = new Scanner(System.in);

	public static boolean isPrime(int n) {
		if (n <= 1)
			return false;

		// Check if n=2 or n=3
		if (n == 2 || n == 3)
			return true;

		// Check whether n is divisible by 2 or 3
		if (n % 2 == 0 || n % 3 == 0)
			return false;

		// Check from 5 to square root of n
		// Iterate i by (i+6)
		for (int i = 5; i <= Math.sqrt(n); i = i + 6)
			if (n % i == 0 || n % (i + 2) == 0)
				return false;

		return true;
	}

	// method to print the divisors
	static void printDivisors(int n) {
		// Note that this loop runs till square root
		int coutDivisors = 0, countPrimeDivisors = 0;
		for (int i = 1; i <= Math.sqrt(n); i++) {
			if (n % i == 0) {
				// If divisors are equal, print only one
				if (n / i == i) {
					coutDivisors++;
					if (isPrime(i))
						countPrimeDivisors++;
				} else {
					coutDivisors += 2;
					if (isPrime(i)) {
						countPrimeDivisors++;
					}
					if (isPrime(n / i)) {
						countPrimeDivisors++;
					}
				}
			}
		}
		System.out.println("countPrimeDivisors: " + countPrimeDivisors);
		System.out.println("coutDivisors: " + coutDivisors);
	}

	public static void main(String[] args) {
		int n = sc.nextInt();
		printDivisors(n);
	}
}
```

### Bài 11: Viết chương trình tính tổng của các số nguyên tố nhỏ hơn hoặc bằng N với N được nhập từ bàn phím.

```java
package ex;

import java.util.Scanner;

public class Solution {
	static Scanner sc = new Scanner(System.in);

	public static int totalNumberOfPrime(int n) {
		// Create a boolean array "prime[0..n]" and initialize
		// all entries it as true. A value in prime[i] will
		// finally be false if i is Not a prime, else true.
		boolean prime[] = new boolean[n + 1];
		for (int i = 0; i <= n; i++)
			prime[i] = true;

		for (int p = 2; p * p <= n; p++) {
			// If prime[p] is not changed, then it is a prime
			if (prime[p] == true) {
				// Update all multiples of p
				for (int i = p * p; i <= n; i += p)
					prime[i] = false;
			}
		}

		// Count all prime numbers
		int total = 0;
		for (int i = 2; i <= n; i++) {
			if (prime[i] == true)
				total += i;
		}
		return total;
	}

	public static void main(String[] args) {
		int n = sc.nextInt();
		System.out.println("Number: " + totalNumberOfPrime(n));
	}
}
```

### Bài 12: Viết chương trình tìm bốn số nguyên tố liên tiếp, sao cho tổng của chúng là số nguyên tố nhỏ hơn hoặc bằng N (với N được nhập vào từ bàn phím).

```c
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int SieveOfEratosthenes(int n, int arr[])
{
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));
    for (int p = 2; p * p <= n; p++)
    {
        if (prime[p] == true)
        {
            for (int i = p * p; i <= n; i += p)
            {
                prime[i] = false;
            }
        }
    }

    int k = 0;
    for (int p = 2; p <= n; p++)
    {
        if (prime[p])
        {
            arr[k] = p;
            k++;
        }
    }
    return k;
}
int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    int k = SieveOfEratosthenes(n, arr);
    for (int i = 0; i < k - 3; i++)
    {
        int a1 = arr[i];
        int a2 = arr[i + 1];
        int a3 = arr[i + 2];
        int a4 = arr[i + 3];
        if (a1 + a2 + a3 + a4 <= n)
        {
            printf("%d %d %d %d", a1, a2, a3, a4);
            return;
        }
    }
    return 0;
}
```

### Bài 13: Viết chương trình tìm hai số nguyên tố nhỏ hơn hoặc bằng N với N nhập vào từ bàn phím, sao cho tổng và hiệu của chúng đều là số nguyên tố.

```c
#include <stdio.h>
#include <stdlib.h>
int kiemtraSNT(int n)
{
    // Check if n=1 or n=0
    if (n <= 1)
        return 0;
    // Check if n=2 or n=3
    if (n == 2 || n == 3)
        return 1;
    // Check whether n is divisible by 2 or 3
    if (n % 2 == 0 || n % 3 == 0)
        return 0;
    // Check from 5 to square root of n
    // Iterate i by (i+6)
    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return 0;

    return 1;
}

int main()
{
    int n;
    printf("Nhap n: ");
    scanf("%d", &n);
    if (n < 2)
    {
        printf("\nNhap n>=2. Moi nhap lai.");
        printf("Nhap n: ");
        scanf("%d", &n);
    }
    int i, j;
    for (i = 2; i <= n; i++)
    {
        if (kiemtraSNT(i) == 1)
        {
            for (j = i; j <= n; j++)
            {
                if (kiemtraSNT(j) == 1)
                {
                    int tong = i + j;
                    int hieu = abs(i - j);
                    if (kiemtraSNT(tong) == 1 && kiemtraSNT(hieu) == 1)
                    {
                        printf("\nHai so nguyen to can tim la: %d va %d", i, j);
                    }
                }
            }
        }
    }
    return 0;
}
```

### Bài 14: Viết chương trình tìm số nguyên tố có ba chữ số, biết rằng nếu viết số đó theo thứ tự ngược lại thì ta được một số là lập phương của một số tự nhiên.

```java
package ex;

import java.util.*;
import java.lang.Math;

public class Solution {

	static int reverse(int n) {

		int rev = 0; // reversed number
		int rem; // remainder

		while (n > 0) {

			rem = n % 10;
			rev = (rev * 10) + rem;
			n = n / 10;
		}

		return rev;
	}

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
		for (int i = low; i <= high; i++) {
			if (prime[i - low] == true && Math.cbrt(reverse(i)) == Math.round(Math.cbrt(reverse(i)))) {
				System.out.println(i);
			}
		}
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int left = (int) Math.pow(10, 2);
		int right = (int) (Math.pow(10, 3) - 1);
		segmentedSieve(left, right);
	}
}
```

### Bài 15 Viết chương trình Hai số nguyên tố sinh đôi là hai số nguyên tố hơn kém nhau 2 đơn vị. Tìm hai số nguyên tố sinh đôi nhỏ hơn hoặc bằng N, với N được nhập vào từ bàn phím.

```java
package ex;

import java.util.*;
import java.lang.Math;

public class Solution {

	public static boolean isPrime(int n) {
		if (n <= 1)
			return false;

		// Check if n=2 or n=3
		if (n == 2 || n == 3)
			return true;

		// Check whether n is divisible by 2 or 3
		if (n % 2 == 0 || n % 3 == 0)
			return false;

		// Check from 5 to square root of n
		// Iterate i by (i+6)
		for (int i = 5; i <= Math.sqrt(n); i = i + 6)
			if (n % i == 0 || n % (i + 2) == 0)
				return false;

		return true;
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		for(int i = 2; i <= n - 2; i++) {
			if(isPrime(i) && isPrime(i + 2)) {
				System.out.println(i + " " + (i + 2));
			}
		}
	}
}
```

### Bài 16: Viết chương trình tìm các số nguyên tố từ một mảng sinh ngẫu nhiên có kích thước N, với N nhập vào từ bàn phím.

```c
#include <stdio.h>
#include <math.h>
int main()
{
    int check, n, i, j, ra;

    printf("Nhap so n: ");
    scanf("%d", &n);
    for (j = 0; j < n; j++)
    {
        check = 1;
        ra = rand();
        printf("%d", ra);
        for (i = 2; i < sqrt(ra); i++)
        {
            if (ra % i == 0)
                check = 0;
        }
        if (check == 1)
            printf(" Day la so nguyen to\n");
        else
            printf(" Day khong phai la so nguyen to\n");
    }
}
```

### Bài 17:

- Viết chương trình tìm số nguyên dương x nhỏ nhất và nhỏ hơn N nhập từ bàn phím sao cho giá trị của biểu thức Ax^2 + Bx + C là một số nguyên tố với A,B,C là các số nguyên nhập vào từ bàn phím.

```c
#include <stdio.h>
#include <math.h>
int main()
{
    int check, n, i, j, ra, x, A, B, C;

    printf("Nhap so n: ");
    scanf("%d", &n);
    printf("Nhap A: ");
    scanf("%d", &A);
    printf("Nhap B: ");
    scanf("%d", &B);
    printf("Nhap C: ");
    scanf("%d", &C);
    for (x = 1; x < n; x++)
    {
        check = 1;
        ra = A * x * x + B * x + C;
        for (i = 2; i < sqrt(ra); i++)
        {
            if (ra % i == 0)
                check = 0;
        }
        if (check == 1)
        {
            printf("%d la so nguyen to cua tong A.x^2+B.x+C=%d\n", x, ra);
            break;
        }
        if ((check == 0) && (x == (n - 1)))
            printf("Khong co gia tri thoa man");
    }
}

```

### Bài 18:

- Áp dụng thuật toán đã được học để viết chương trình tính tổng của hai số nguyên lớn,
  hiển thị dưới mạng mảng và dạng số nguyên.
- Bài này đã code trên java

### Bài 19:

- Viết chương trình in ra các số nguyên dương x nằm trong khoảng [m,l] sao cho giá trị
  của biểu thức Ax^2 + Bx + C là một số nguyên tố. Với A,B,C, m,l là các số nguyên nhập từ bàn phím (m<l).

```c
#include <stdio.h>
#include <math.h>
int main()
{
    int check, m, l, i, j, ra, x, A, B, C, check2;

    check2 = 0;

    printf("Nhap so m: ");
    scanf("%d", &m);
    printf("Nhap so l>m nhe: ");
    scanf("%d", &l);
    printf("Nhap A: ");
    scanf("%d", &A);
    printf("Nhap B: ");
    scanf("%d", &B);
    printf("Nhap C: ");
    scanf("%d", &C);
    for (x = m; x <= l; x++)
    {
        check = 1;
        ra = A * x * x + B * x + C;
        for (i = 2; i < sqrt(ra); i++)
        {
            if (ra % i == 0)
                check = 0;
        }
        if (check == 1)
        {
            printf("%d la so nguyen to cua tong A.x^2+B.x+C=%d\n", x, ra);
            check2 = 1;
        }
    }
    if ((check2 == 0) && ((x - 1) == l))
        printf("Khong co gia tri thoa man");
}
```

### Bài 20:

- Viết chương trình in ra các cặp số (A,B) nằm trong khoảng (M,N) sao cho ước số chung
  lớn nhất của A và B có giá trị là một số D cho trước. Với M,N,D nhập vào từ bàn phím. (0<M,N,D < 1000).

```java
package ex;

import java.util.*;
import java.lang.Math;

public class Solution {
	static Scanner sc = new Scanner(System.in);
	// Pollard’s Rho Algorithm
	public static int gcd(int l, int b) {
		while (b > 0) {
			int r = l % b;
			l = b;
			b = r;
		}
		return l;
	}

	public static void main(String[] args) {
		int m, n, d;
		m = sc.nextInt();
		n = sc.nextInt();
		d = sc.nextInt();

		for(int i = m; i <= n - d; i++) {
			for(int j = i + d; j <= n; j+=d) {
				if(gcd(i, j) == d) {
					System.out.println(i + "-" + j);
				}
			}
		}
	}
}
```
