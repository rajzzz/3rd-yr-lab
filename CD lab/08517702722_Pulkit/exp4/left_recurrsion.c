#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

void removeLeftRecursion(char nonTerminal, char alpha[][MAX], char beta[][MAX], int alphaCount, int betaCount)
{
    printf("Left Recursive Grammar detected!\n");

    // New Non-Terminal for recursive rules, append `'` to the non-terminal
    char newNonTerminal[MAX];
    sprintf(newNonTerminal, "%c'", nonTerminal);

    // Print the modified production rule without left recursion
    printf("The modified grammar is:\n");
    printf("%c -->", nonTerminal);
    for (int i = 0; i < betaCount; i++)
    {
        printf(" %s%s", beta[i], newNonTerminal);
        if (i < betaCount - 1)
        {
            printf(" |");
        }
    }
    printf("\n");

    printf("%s -->", newNonTerminal);
    for (int i = 0; i < alphaCount; i++)
    {
        printf(" %s%s", alpha[i], newNonTerminal);
        if (i < alphaCount - 1)
        {
            printf(" |");
        }
    }
    printf(" | e\n"); // Adding epsilon (denoted as 'e')
}

int main()
{
    char input[MAX], nonTerminal, production[MAX];
    char alpha[MAX][MAX], beta[MAX][MAX]; // Stores alpha (left-recursive) and beta (non-left-recursive) parts
    int alphaCount = 0, betaCount = 0;

    // Take the production rule as input
    printf("Enter the production rule (e.g., A-->Aa|b): ");
    fgets(input, MAX, stdin);
    input[strcspn(input, "\n")] = '\0'; // Remove trailing newline character

    // Extract the non-terminal and the production part
    sscanf(input, "%c-->%s", &nonTerminal, production);

    // Validate the input
    if (!isupper(nonTerminal))
    {
        printf("Invalid non-terminal. It should be an uppercase letter.\n");
        return 1;
    }

    // Split the production into tokens separated by '|'
    char *token = strtok(production, "|");

    while (token != NULL)
    {
        if (token[0] == nonTerminal)
        {
            // Left recursive part (alpha)
            strcpy(alpha[alphaCount++], token + 1);
        }
        else
        {
            // Non-left recursive part (beta)
            strcpy(beta[betaCount++], token);
        }
        token = strtok(NULL, "|");
    }

    // Check if left recursion exists
    if (alphaCount == 0)
    {
        printf("No Left Recursion present.\n");
    }
    else
    {
        removeLeftRecursion(nonTerminal, alpha, beta, alphaCount, betaCount);
    }

    return 0;
}
