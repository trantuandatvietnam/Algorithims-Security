#include <stdio.h>
#include <math.h>
int main()
{
    int n, i, j, p, t, check;
    printf("\nNhap n: ");
    scanf("%d", &n);
    int a[n];
    int b[n];
    j = 0;
    for (i = 2; i <= n; i++)
    {
        a[i] = 1;
    }
    for (p = 2; p < n; p++)
    {
        t = n / p;
        for (i = 2; i <= t; i++)
            a[p * i] = 0;
    }
    for (i = 2; i <= n; i++)
    {
        if (a[i] == 1)
        {
            b[j] = i;
            j++;
        }
    }

    for (i = 1; i < j; i++)
    {
        check = b[i] - b[i - 1];
        if (check == 2)
            printf("\n 2 cap so do la: %d %d", b[i - 1], b[i]);
    }
}
