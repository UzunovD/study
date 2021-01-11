#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int strt_pop_size;
    do
    {
        strt_pop_size = get_int("Input starting population size: \n");
    }
    while (strt_pop_size < 9);

    int end_pop_size;
    do
    {
        end_pop_size = get_int("Input ending population size: \n");
    }
    while (end_pop_size < strt_pop_size);

    int n_years = 0;

    while (strt_pop_size < end_pop_size)
    {
        strt_pop_size += strt_pop_size / 3 - strt_pop_size / 4;
        n_years++;
    }

    printf("Years: %i\n", n_years);
}