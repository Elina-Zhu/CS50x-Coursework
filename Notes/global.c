#include <cs50.h>
#include <stdio.h>

void change(void);
int x = 2;

int main(void)
{
    //change();
    printf("%i\n", x);
}

void change(void)
{
    x += 2;
}