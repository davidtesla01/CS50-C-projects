#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool is_digit(string key);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key");
        return 1;
    }

    string key = argv[1];

    if (is_digit(key) == false)
    {
        printf("Usage: ./caesar key");
        return 1;
    }

    int k = atoi(key); // convert string to an int (1 becomes 1, if function not used then 1 would
                       // be treated as 49 per ASCII)

    string p = get_string("Plaintext:  ");
    int string_len = strlen(p);
    printf("Ciphertext: ");

    int length = string_len;
    char c[length];

    for (int i = 0; i < string_len; i++)
    {
        if (isalpha(p[i]))
        {
            if (isupper(p[i]))
            {
                c[i] = (k + (p[i] - 'A')) % 26;
                printf("%c", c[i] + 'A');
            }
            else if (islower(p[i]))
            {
                c[i] = (k + (p[i] - 'a')) % 26;
                printf("%c", c[i] + 'a');
            }
        }
        else
        {
            printf("%c", p[i]);
        }
    }
    printf("\n");
}

// function definitions
bool is_digit(string key)
{
    for (int i = 0; i < strlen(key); i++)
    {
        if (!isdigit(key[i]))
        {
            return false;
        }
    }
    return true;
}

// k = key
// c = ciphertext
// p = plaintext
// c[i] = (k + p[i]) % 26
