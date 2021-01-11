#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Get hight of pyramids from user
    int answer = 0;
    do
    {
        answer = get_int("Input the positive number:\n");
    }
    while (answer < 1 || answer > 8);

    // Print pyramids
    void printf_hash(int n);

    for (int n = 0; n < answer; n++)
    {
        for (int j = 1; j < answer - n; j++)
        {
            printf(" ");
        }

        printf_hash(n);

        printf("  ");

        printf_hash(n);

        printf("\n");
    }
}

void printf_hash(int n)
{
    for (int k = 0; k <= n; k++)
    {
        printf("#");
    }
}