#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a, b, m, n, d, last, i, j, count;
    printf("Nhap m ");
    scanf("%d", &m);
    printf("Nhap n ");
    scanf("%d", &n);
    printf("Nhap d ");
    scanf("%d", &d);
    if (d > n)
        printf("Khong ton tai");
    a = b = j = 0;
    last = n / d;

    for (i = 2; i <= last; i++)
    {
        a = d;
        b = d * i;
        printf("Cap so %d %d\n", a, b);
    }

    for (i = 2; i <= last; i++)
    {
        a = d * i;
        if ((a > m) && (a < n))
        {
            for (j = 1; j <= last; j++)
            {
                b = d * j;
                if ((b < n) && (j % i != 0))
                    printf("Cap so %d %d\n", a, b);
            }
        }
    }
}