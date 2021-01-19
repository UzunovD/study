//Problem https://cs50.harvard.edu/x/2021/psets/2/substitution/
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("%s", "Usage: ./substitution key\n");
        return 1;
    }

    if (strlen(argv[1]) != 26)
    {
        printf("%s", "Key must contain 26 characters.\n");
        return 1;
    }

    string key = argv[1];
    char key_sym;
    char dubl = '0';
    for (int i = 0, len = strlen(key); i < len; i++)
    {
        key_sym = key[i];
        if (!isalpha(key_sym) || key_sym == dubl)
        {
            printf("%s", "Key must contain alphabet characters\n");
            return 1;
        }
        dubl = key_sym;
    }

    string plaintext = get_string("plaintext: ");

    char shift;
    char src_sym;
    printf("ciphertext: ");
    for (int i = 0, len = strlen(plaintext); i < len; i++)
    {
        src_sym = plaintext[i];
        // if (src_char >= 65 && src_char <= 90)  // a simple alternative without external libraries
        if (isupper(src_sym))
        {
            shift = toupper(key[src_sym - 65]);
        }

        // if (src_char >= 97 && src_char <= 122)  // a simple alternative without external libraries
        else if (islower(src_sym))
        {
            shift = toupper(key[src_sym - 97]) + 32;
        }

        else
        {
            shift = src_sym;
        }
        printf("%c", shift);
    }
    printf("\n");
}