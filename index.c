#include <stdio.h>
#include <math.h>
int main()
{
    int x, n;
    printf("Nhap x: ");
    scanf("%d", &x);
    for (n = 4; n <= x; n++)
    {
        int m, i, j, dem, a[10], b[10], permission = 0;
        j = 0;
        int check = 1;
        m = n;
        for (i = 2; i <= m; i++)
        {
            dem = 0;
            while ((m % i) == 0)
            {
                m /= i;
                dem++;
            }
            if (dem >= 1)
            {
                a[j] = i;
                b[j] = dem;
                if (b[j] >= 2)
                    check = 0;
                j++;
            }
        }
        if ((check == 0) | (j < 3))
        {
            permission = 1;
        }
        for (i = 0; i <= j - 1; i++)
        {
            if (((n % a[i]) == 0) && ((n - 1) % (a[i] - 1) != 0))
            {
                permission = 1;
            }
            else if ((n % a[i]) == 0 && ((n - 1) % (a[i] - 1) == 0) && check != 0 && permission != 1)
                permission = 0;
        }
        if (permission == 0 && check != 0)
            printf(" %d ", n);
    }
}
