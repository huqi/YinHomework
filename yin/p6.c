#include <stdio.h>

int main(int argc, char **argv)
{
    float L = 0, x = 0;
    float result = 1000;

    for (L = 51; L < 56; L += 0.01)
    {
        x = 0;
        for (x = 0; x < L/2; x += 0.01)
        {
            float temp = (10.52 * L - 11.4 * x)/x;
            if (temp > 0 && temp < result)
            {
                result = temp;
                printf ("L == %.2f, x == %.2f, result == %.2f\n", L, x, result);
            }
        }
    }
}
