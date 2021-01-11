#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long card_number;
    long min = 1000000000000;
    long max = 9999999999999999;
    //get card number from user
    do
    {
        card_number = get_long("Input card number:\n");
    }
    while (card_number < min && card_number > max);

    int digit;
    int divisor = 10;
    int count = 0;
    int check_sum = 0;
    int st_with;

    // calculate check_sum and length of card number
    while (card_number > 0)
    {
        digit = card_number % divisor;
        card_number /= divisor;
        count++;
        if (count % 2 == 0)
        {
            digit *= 2;
        }
        check_sum += digit / divisor + digit % divisor;
        if (card_number < 100 && card_number > 10)
        {
            st_with = card_number;
        }
        if (card_number == 4)
        {
            st_with = card_number;
        }
    }

    //validate
    string answer = "INVALID";
    bool last_digt = check_sum % divisor == 0;

    if (count == 16 && (st_with == 22 || st_with == 51 || st_with == 52 || st_with == 53 || st_with == 54 || st_with == 55)
        && last_digt)
    {
        answer = "MASTERCARD";
    }
    else if (count == 15 && (st_with == 34 || st_with == 37) && last_digt)
    {
        answer = "AMEX";
    }
    else if ((count == 13 || count == 16) && st_with == 4 && last_digt)
    {
        answer = "VISA";
    }
    printf("%s\n", answer);
}