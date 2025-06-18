#include <cs50.h>
#include <stdbool.h>
#include <stdio.h>

bool is_valid_answer(int change);

int main(void)
{
    int change;
    do
    {
        change = get_int("How much change? ");
        if (!is_valid_answer(change))
        {
            printf("Please provide a positive number.\n");
        }
    }
    while (!is_valid_answer(change));

    int a = 25;
    int b = 10;
    int c = 5;
    int d = 1;
    int counter = 0;

    do
    {
        if (change - a >= 0)
        {
            counter++;
            change = change - a;
        }
        else if (change - b >= 0)
        {
            counter++;
            change = change - b;
        }
        else if (change - c >= 0)
        {
            counter++;
            change = change - c;
        }
        else if (change - d >= 0)
        {
            counter++;
            change = change - d;
        }
    }
    while (change != 0);
    printf("%i\n", counter);
}

bool is_valid_answer(int change)
{
    return (change > 0);
}
