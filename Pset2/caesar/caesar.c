#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{

    // Make sure program was run with just one command-line argument
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Make sure every character in argv[1] is a digit

    int n = strlen(argv[1]);
    for (int i = 0; i < n; i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    // Convert argv[1] from a `string` to an `int`
    // atoi : convert string to int

    int key = atoi(argv[1]);
    string plain = get_string("plaintext:  ");

    // Prompt user for plaintext

    printf("ciphertext: ");

    // For each character in the plaintext:

    for (int j = 0; j < strlen(plain); j++)
    {
        if (isupper(plain[j]))
        {
            printf("%c", (plain[j] - 65 + key) % 26 + 65);
        }
        else if (islower(plain[j]))
        {
            printf("%c", (plain[j] - 97 + key) % 26 + 97);
        }
        else
        {
            printf("%c", plain[j]);
        }
    }

    printf("\n");
}
