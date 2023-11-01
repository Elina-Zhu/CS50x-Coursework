#include <cs50.h>
#include <stdio.h>

int first(long number);
int second(int last_digit);

int main(void)
{
    long number = get_long("Number: ");
    int sum_for_test = first(number);
    //printf("%i\n", sum_for_test);
    int a = number / (long)10000000000000;
    int b = number / (long)100000000000000;
    int c = number / (long)1000000000000000;
    int d = number / (long)1000000000000;
    //printf("%i, %i\n", c, d);

    //Luhn's Algorithm
    if (sum_for_test % 10 == 0)
    {
        if (a == 34 || a == 37)
        {
            printf("AMEX\n");
        }
        else if (b > 50 && b < 56)
        {
            printf("MASTERCARD\n");
        }
        else if (c == 4 || d == 4)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}

int first(long number)
{
    int sum = 0;
    bool is_every_other_digit = false;
    while (number > 0)
    {
        if (is_every_other_digit == true)
        {
            int last_digit = number % 10;
            int second_sum = second(last_digit);
            sum = sum + second_sum;
        }
        else
        {
            int last_digit = number % 10;
            sum = sum + last_digit;
        }
        is_every_other_digit = !is_every_other_digit;
        number = number / 10;
    }
    return sum;
}

int second(int last_digit)
{
    int multipy = last_digit * 2;
    int sum = 0;
    while (multipy > 0)
    {
        int last_digit_2 = multipy % 10;
        sum = sum + last_digit_2;
        multipy = multipy / 10;
    }
    return sum;
}