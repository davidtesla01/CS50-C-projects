#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc != 2) // check input number
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    if (strlen(argv[1]) != 26) // check number
    {
        printf("Key must contaon 26 characters\n");
        return 1;
    }
    for (int z = 0; z < strlen(argv[1]); z++) // check if all alpha
    {
        if (!isalpha(argv[1][z]))
        {
            printf("Key must contain only alphabetic characters\n");
            return 1;
        }
    }
    for (int x = 0; x < strlen(argv[1]); x++)
    {
        for (int y = x + 1; y < strlen(argv[1]); y++)
        {
            if (tolower(argv[1][x]) == tolower(argv[1][y]))
            {
                printf("Key must not repeat characters\n");
                return 1;
            }
        }
    }

    string text = get_string("plaintext:  ");

    string k = argv[1];

    printf("ciphertext: ");

    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            if (isupper(text[i]))
            {
                int p = text[i] - 'A';
                printf("%c", toupper(k[p]));
            }
            else if (islower(text[i]))
            {
                int p = text[i] - 'a';
                printf("%c", tolower(k[p]));
            }
        }
        else
        {
            printf("%c", text[i]);
        }
    }
    printf("\n");
    return 0;
}
