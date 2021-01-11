#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int answer = 0;
    do 
    {
        answer = get_int("Input the positive number:\n");
    }
    while (answer < 1 || answer > 8);
    
    string spase = " ";
    string hash = "#";
    for (int n = 0; n < answer; n++)
    {
        for (int j = 1; j < answer - n; j++)
        {
            printf("%s", spase);            
        }
        for (int k = 0; k <= n; k++)
        {
            printf("%s", hash);            
        }
        
        printf("\n");
    }
}