#include <stdio.h>

int main (int argc, char **argv)
{
    int i = 0, j = 0, k = 0;
    int x1 = 0, x2 = 0, x3 = 0;
    int Z = 0, temp = 0;

    for (i = 0; i <= 700; ++i)
    {
        if (i > 500)
        {
            for (j = 0; j <= 700; ++j)
            {
                if (i+j > 1200)
                {
                    for (k = 0; k <= 700; ++k)
                    {
                        if (i+j+k >= 2000)
                        {
                            temp = 24*i+26*j+18*k-1100;
                            printf ("temp = %d, i = %d, j = %d, k = %d\n", temp, i, j, k);
                            if (temp<Z || Z==0)
                            {
                                Z = temp;
                                x1 = i;
                                x2 = j;
                                x3 = k;
                            }
                        }
                    }
                }
            }
        }
    }
    printf ("x1 = %d, x2 = %d, x3 = %d, Z = %d\n", x1, x2, x3, Z);

    return 0;
}
