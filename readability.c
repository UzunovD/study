// Problem https://cs50.harvard.edu/x/2021/psets/2/readability/
#include <cs50.h>
#include <string.h>
#include <math.h>
#include <stdio.h>

int main(void)
{
    // Get the text from user
    string text = get_string("Text:\n");
    int letters = 0;
    int words = 1;
    int sentence = 0;

    // analyze the text
    for (int i = 0, n = strlen(text); i < n; i++) //strlen(text) - перед циклом ~ тут все ок
    {
        if ((text[i] >= 65 && text[i] <= 90) || (text[i] >= 97 && text[i] <= 122))
        {
            letters++;
        }
        else if (text[i] == 32)
        {
            words++;
        }
        else if (text[i] == 33 || text[i] == 46 || text[i] == 63)
        {
            sentence++;
        }
    }

    // Compute a grade level
    float index = 0;
    index = 0.0588 * letters / words * 100 - 0.296 * sentence / words * 100 - 15.8;
    int grade = round(index);

    //Prepare an answer
    if (grade < 1)
    {
        printf("Before Grade 1\n");

    }
    else if (grade > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}
