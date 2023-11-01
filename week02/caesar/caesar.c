#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool only_digits(string key);

int main(int argc, string argv[])
{
    // Check if there is only one command-line argument
    if (argc == 2 && only_digits(argv[1]))
    {
        // Convert argv[1] from string to int
        int k = atoi(argv[1]);

        // Prompt user for plaintext
        string text = get_string("plaintext:  ");
        printf("ciphertext: ");

        // Rotate the characters in the plaintext
        for (int i = 0, length = strlen(text); i < length; i++)
        {
            if (text[i] >= 'a' && text[i] <= 'z')
            {
                printf("%c", (((text[i] - 'a') + k) % 26) + 'a');
            }
            else if (text[i] >= 'A' && text[i] <= 'Z')
            {
                printf("%c", (((text[i] - 'A') + k) % 26) + 'A');
            }
            else
            {
                printf("%c", text[i]);
            }
        }
        printf("\n");
        return 0;
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}

// Check if every character in argv[1] is a digit
bool only_digits(string key)
{
    for (int i = 0, length = strlen(key); i < length; i++)
    {
        if (!isdigit(key[i]))
        {
            return false;
        }
    }
    return true;
}