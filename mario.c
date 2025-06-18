#include <cs50.h>
#include <stdbool.h>
#include <stdio.h>

void print_row(int a);

bool is_valid_answer(int height);

void print_space(int b);

int i;
int space;
int main(void)
{
    int height;
    do
    {
        height = get_int("How tall? ");
        if (!is_valid_answer(height))
        {
            printf("Please provide a positive number.\n");
        }
    }
    while (!is_valid_answer(height));

    int loop = height; // kako bi definisao loop, a da se ne spusta broj svaki krug onda definisemo
                       // loop variable

    for (i = 0; i < loop; i++) // i pocinje kao nula, i dodaje jedan svaki krug dok ne dodje do
                               // onoliko koliko je dato, kada dodje, onda printuje current i broj puta
    {
        space = height - 1;
        print_space(space);
        height--;
        print_row(i + 1); // i + 1 jednako a
    }
}

void print_row(int a)
{
    for (int c = 0; c < a; c++)
    {
        printf("#");
    }
    printf("\n");
}
bool is_valid_answer(int height)
{
    return (height > 0);
}

void print_space(int b)
{
    for (int d = 0; d < b; d++)
    {
        printf(" ");
    }
}
