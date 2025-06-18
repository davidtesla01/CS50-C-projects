#include <cs50.h>
#include <stdio.h>

#define AMEXL34 340000000000000
#define AMEXU34 349999999999999
#define AMEXL37 370000000000000
#define AMEXU37 379999999999999
#define MCL 5100000000000000
#define MCU 5599999999999999
#define VISAL13 4000000000000
#define VISAU13 4999999999999
#define VISAL16 4000000000000000
#define VISAU16 4999999999999999

int every_other_digit(long credit_card);
int multiply_2(int last_digit);
int counter;

int main(void)
{
    long credit_card = get_long("Credit Card? ");
    int sum_every_2 = every_other_digit(credit_card);
    int final = sum_every_2 % 10;
    if (final == 0 && counter == 15 &&
        ((credit_card >= AMEXL34 && credit_card <= AMEXU34) ||
         (credit_card >= AMEXL37 && credit_card <= AMEXU37)))
    {
        printf("AMEX\n");
    }
    else if (final == 0 && counter == 16 && credit_card >= MCL && credit_card <= MCU)
    {
        printf("MASTERCARD\n");
    }
    else if (final == 0 && ((counter == 13 && credit_card >= VISAL13 && credit_card <= VISAU13) ||
                            (counter == 16 && credit_card >= VISAL16 && credit_card <= VISAU16)))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
int every_other_digit(long credit_card)
{
    int sum = 0;
    counter = 0;
    bool is_every_other = false;
    while (credit_card > 0)
    {
        if (is_every_other == true)
        {
            int last_digit = credit_card % 10;
            int product = multiply_2(last_digit);
            sum = sum + product;
            counter++;
        }
        else
        {
            int last_digit = credit_card % 10;
            sum = sum + last_digit;
            counter++;
        }
        is_every_other = !is_every_other;
        credit_card = credit_card / 10;
    }
    return sum;
}

int multiply_2(int last_digit)
{
    int multiply = last_digit * 2;
    int sum = 0;
    while (multiply > 0)
    {
        int last_digit_mult = multiply % 10;
        sum = sum + last_digit_mult;
        multiply = multiply / 10;
    }
    return sum;
}
