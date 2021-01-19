//Problem https://cs50.harvard.edu/x/2021/labs/2/
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Determining the winner
    string winner = "Player 1 wins!";
    if (score1 < score2)
    {
        winner = "Player 2 wins!";
    }
    else if (score1 == score2)
    {
        winner = "Tie!";
    }
    printf("%s\n", winner);
}

int compute_score(string word)
{
    // compute score
    int summ = 0;
    char symbol;
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        symbol = toupper(word[i]);
        if (symbol >= 65 && symbol <= 90)
        {
            summ += POINTS[symbol - 65];
        }
    }
    return summ;
}
