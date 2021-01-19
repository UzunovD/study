//Problem https://cs50.harvard.edu/x/2021/psets/2/caesar/
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>


int main(int argc, string argv[])
{
    // check CLI argument
    int key;
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;  //Exit
    }
    else
    {
        char symbol;
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            symbol = argv[1][i];
            if (symbol < 48 || symbol > 57)
            {
                printf("Usage: ./caesar key\n");
                return 1;  //Exit
            }
        }
        key = atoi(argv[1]);
    }

    //Get plaintext from user
    string plaintext = get_string("plaintext: ");

    //prepare answer
    int length = strlen(plaintext);
    printf("ciphertext: ");
    char answer[length];
    for (int i = 0; i < length; i++)
    {
        char src_char = plaintext[i];
        char shift;
        // if (src_char >= 65 && src_char <= 90)  // a simple alternative without external libraries
        if (isupper(src_char))
        {
            shift = (src_char + key - 65) % 26 + 65;
        }

        // else if (src_char >= 97 && src_char <= 122)  // a simple alternative without external libraries
        else if (islower(src_char))
        {
            shift = (src_char + key - 97) % 26 + 97;
        }

        else
        {
            shift = src_char;
        }
        answer[i] = shift;
    }
    printf("ciphertext: %s\n", answer);
}