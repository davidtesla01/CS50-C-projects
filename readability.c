#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int get_index(string text);

int main(void)
{
    string text = get_string("Text: ");
    int text_index = get_index(text);
    if (text_index > 1 && text_index < 16)
    {
        printf("Grade %i\n", text_index);
    }
    else if (text_index <= 1)
    {
        printf("Before Grade 1\n");
    }
    else if (text_index >= 16)
    {
        printf("Grade 16+\n");
    }
}

int get_index(string text)
{
    int letters = strlen(text);
    int loop = letters;
    int words = 0;
    int sentences = 0;
    for (int i = 0; i < loop; i++)
    {
        if (text[i] == ' ')
        {
            words++;
        }
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            sentences++;
        }
        if ((text[i] < 65 && text[i] > '\0') || (text[i] > 90 && text[i] < 97) || (text[i] > 122))
        {
            letters--;
        }
    }
    words += 1;
    float L = (float) letters / (float) words * 100;
    float S = (float) sentences / (float) words * 100;
    int index = round(0.0588 * L - 0.296 * S - 15.8);
    return index;
}
