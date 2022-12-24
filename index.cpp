#include <stdio.h>
#include <stdbool.h>

// Generate all prime numbers less than n.
bool SieveOfEratosthenes(int n, bool isPrime[])
{
    // Initialize all entries of boolean array as true. A
    // value in isPrime[i] will finally be false if i is Not
    // a prime, else true bool isPrime[n+1];
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i <= n; i++)
        isPrime[i] = true;

    for (int p = 2; p * p <= n; p++)
    {
        // If isPrime[p] is not changed, then it is a prime
        if (isPrime[p] == true)
        {
            // Update all multiples of p
            for (int i = p * p; i <= n; i += p)
                isPrime[i] = false;
        }
    }
}

// Prints a prime pair with given sum
void findPrimePair(int n)
{
    // Generating primes using Sieve
    bool isPrime[n + 1];
    SieveOfEratosthenes(n, isPrime);

    // Traversing all numbers to find first
    // pair
    for (int i = 0; i < n; i++)
    {
        if (isPrime[i] && isPrime[n - i])
        {
            printf("%d  %d", i, n - i);
            return;
        }
    }
}

// Driven program
int main()
{
    int n;
    scanf("%d", &n);
    findPrimePair(n);
    return 0;
}