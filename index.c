#include <stdio.h>
#include <math.h>
int gcd(int l, int b)
{
    while (b > 0)
    {
        int r = l % b;
        l = b;
        b = r;
    }
    return l;
}

int isPrime(int n)
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
    int a = 1, b = 9;
    int i, j;
    for (i = a; i < b; i++)
    {
        for (j = a; j < b; j++)
        {
            int d = gcd(i, j);
            if (isPrime(d) == 1)
            {
                printf("[%d %d]\n", i, j);
            }
        }
    }
}