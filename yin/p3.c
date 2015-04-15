#include <stdio.h>

int main (int argc, char **argv)
{
    int i = 0, j = 0, k = 0;
    int x1 = 0, x2 = 0, x3 = 0;
    int Z = 0, temp = 0;

    for (k = 0; k <= 5; ++k)
    {
        for (i = 0; ; ++i)
        {
            if (2*i+3*j <=16 && 4*i+4*j <= 24)
            {
                for (j = 0; ; ++j)
                {
                    if (2*i+3*j <=16 && 4*i+4*j <= 24)
                    {
                        temp = 4*i+6*j+5*k;
                        if (temp>Z)
                        {
                            Z = temp;
                            x1 = i;
                            x2 = j;
                            x3 = k;
                        }
                    }
                    else
                    {
                        j = 0;
                        break;
                    }
                }
            }
            else
            {
                break;
            }
        }
    }
    printf ("x1 = %d, x2 = %d, x3 = %d, Z = %d\n", x1, x2, x3, Z);

    return 0;
}
