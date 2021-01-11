#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main(void)
{
    float dollars;
    int coins = 0;

    do
    {
        dollars = get_float("How mach change is owed?\n");
    }
    while (dollars < 0);

    int cents = round(dollars * 100);

    while (cents >= 25)
    {
        cents -= 25;
        coins++;
    }

    while (cents >= 10)
    {
        cents -= 10;
        coins++;
    }

    while (cents >= 5)
    {
        cents -= 5;
        coins++;
    }

    while (cents >= 1)
    {
        cents--;
        coins++;
    }

    printf("%i\n", coins);
}
