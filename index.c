#include <stdio.h>
#include <math.h>
int main()
{
    int n, i, j, k, flag;
    printf("\nNhap n: ");
    scanf("%d", &n);
    int A[n];
    for (i = 4; i < n; i++)
    {
        A[i] = 0;
        for (j = 2; j < i; j++)
        {
            flag = 0;
            for (k = 2; k < j; k++)
                if (j % k == 0)
                    flag == 1;
            if (flag != 1 && A[i] == 0) // j la so nguyen to
            {
                if (i % (j * j) == 0)
                    A[i] = 1;
            }
        }
    }
    for (i = 4; i < n; i++)
    {
        if (A[i] == 1)
            printf(" %d ", i);
    }
}