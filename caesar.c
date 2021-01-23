//Problem https://cs50.harvard.edu/x/2021/psets/2/caesar/
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>

viod get_ciphertext(key);
int main(int argc, string argv[])
{
    // check CLI argument
    int key;
    char cipher = argv[1]; //1. (см ниже). Это чтоб код было понятнее читать, имя переменной конечно нормально надо дать.
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;  //Exit
    }
    else
    {
        char symbol;
        for (int i = 0, n = strlen(cipher); i < n; i++) // strlen каждый раз считает на каждый проход for. Может её лучше заранее посчитать перед циклом?
        {
            symbol = cipher[i]; //1. аргументы лучше в начале определять см выше
            if (symbol < 48 || symbol > 57)
            {
                printf("Usage: ./caesar key\n");
                return 1;  //Exit
            }
        }
        key = atoi(cipher);
    }
    get_ciphertext(key);
}


viod get_ciphertext(key)
{
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
