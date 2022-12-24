#include <bits/stdc++.h>
using namespace std;

int isPrime(int n)
{
    if (n <= 3)
        return n > 1;
    if (n % 2 == 0 || n % 3 == 0)
        return 0;
    for (int i = 5; i * i <= n; i += 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return 0;
    return 1;
}

int gcd(int a, int b)
{
    while (b)
    {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int modPower(int a, int b, int m)
{
    a %= m;
    int res = 1;
    while (b > 0)
    {
        if (b % 2)
            res = res * a % m;
        a = a * a % m;
        b /= 2;
    }
    return res;
}

bool isCarmichaelNumber(int n)
{
    if (isPrime(n))
    {
        return false;
    }
    else
    {
        bool flag = false;
        for (int b = 2; b < n; b++)
        {
            if (gcd(b, n) == 1)
            {
                if (modPower(b, n - 1, n) == 1)
                {
                    flag = true;
                }
                else
                {
                    flag = false;
                    break;
                }
            }
        }
        return flag;
    }
}

int main()
{
    int n;
    cin >> n;
    for (int i = 4; i < n; i++)
    {
        if (isCarmichaelNumber(i))
        {
            cout << i << " ";
        }
    }
    cout << endl;
    system("pause");
    return 0;
}