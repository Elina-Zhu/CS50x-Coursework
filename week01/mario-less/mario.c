#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    do
    {
        n = get_int("Size: ");
    }
    while (n < 1 || n > 8);

    int x = 1;

    for (int i = 0; i < n; i++)
    {
        for (int y = 0; y < n - x; y++)
        {
            printf(" ");
        }
        for (int j = 0; j < x; j++)
        {
            printf("#");
        }
        x = x + 1;
        printf("\n");
    }
}