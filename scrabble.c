#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int player1(char p1[], int len1);
int player2(char p2[], int len2);

const int MAX = 26;

int points[MAX] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
char correct_letter[MAX] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M','N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

int main(void)
{
    string p1 = get_string("Player 1: ");
    int len1 = strlen(p1);
    string p2 = get_string("Player 2: ");
    int len2 = strlen(p2);
    int PL1 = player1(p1, len1);
    int PL2 = player2(p2, len2);
    if (PL1 > PL2)
    {
        printf("Player 1 wins.\n");
    }
    else if (PL2 > PL1)
    {
        printf("Player 2 wins.\n");
    }
    else
    {
        printf("Tie\n");
    }
}

int player1(char p1[], int len1)
{
    int result = 0;
    for (int i = 0; i < len1; i++)
    {
        int counter = 0;
        p1[i] = toupper(p1[i]);
        while (p1[i] != correct_letter[counter] && counter < MAX)
        {
            counter++;
        }
        if (counter < MAX)
        {
            result += points[counter];
        }
    }
    return result;
}

int player2(char p2[], int len2)
{
    int result = 0;
    for (int i = 0; i < len2; i++)
    {
        int counter = 0;
        p2[i] = toupper(p2[i]);
        while (p2[i] != correct_letter[counter] && counter < MAX)
        {
            counter++;
        }
        if (counter < MAX)
        {
            result += points[counter];
        }
    }
    return result;
}
