#include <stdio.h>
#include <stdlib.h>

int binhPhuongLap(int x, int n, int m)
{
    int a = 1;
    int b = x;
    while (n > 0)
    {
        if (n % 2 == 1)
            a = (a * b) % m;
        b = (b * b) % m;
        n = n / 2;
    }
    return a % m;
}

int fermat(int n, int t)
{
    if ((n != 2 && n % 2 == 0) || n < 2)
        return 0;
    if (n == 2 || n == 3)
        return 1;

    else
    {
        int r[t];
        int temp = 0, a = 2;
        for (int i = 1; i <= t; i++)
        {
            r[i] = binhPhuongLap(a, n - 1, n);
            a++;
        }
        for (int i = 1; i < t; i++)
        {
            for (int j = 2; j <= t; j++)
            {
                if (r[i] != r[j])
                    temp++;
            }
        }
        if (temp == 0)
            return 1;
        else
            return 0;
    }
}

int tinhF(int i)
{
    if (fermat(i, 3) == 1)
        return i;
    else
        return 0;
}

int main()
{
    int L, R, Tong = 0;
    printf("Nhap gioi han dau L: ");
    scanf("%d", &L);
    printf("Nhap gioi han cuoi R: ");
    scanf("%d", &R);
    printf("F[i] * F[j] =\n");
    printf("----------------------------\n");
    for (int i = L; i < R; i++)
    {
        for (int j = L + 1; j <= R; j++)
        {
            if (j > i)
            {
                printf("F[%d] * F[%d] = %d\n", i, j, tinhF(i) * tinhF(j));
                Tong = Tong + tinhF(i) * tinhF(j);
            }
        }
    }
    printf("Tong= %d", Tong);
}