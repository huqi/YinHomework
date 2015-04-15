#include "stdio.h"

int main (int argc, char **argv)
{
    int i = 0, j = 0;
    int x1 = 0, x2 = 0;
    int Z = 0;
    int temp = 0;

    for (i = 0; i <= 8; ++i)
    {
        for (j = 0; j <= 10; ++j)
        {
            if (5*i + 3*j >= 45)
            {
                temp = 40*i + 36*j;

                if (temp<Z || Z==0)
                {
                    Z = temp;
                    x1 = i;
                    x2 = j;
                }
            }
        }
    }

    printf ("x1 = %d, x2 = %d, Z = %d\n", x1, x2, Z);

    return 0;
}
