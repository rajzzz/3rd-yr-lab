#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

// Function to check for left factoring
void leftFactoring(char *input)
{
    char nonTerminal;
    char productions[MAX][MAX], commonPrefix[MAX], newProduction[MAX][MAX];
    int i, j, k, len, commonLen = 0, prodCount = 0;

    // Split the input into non-terminal and productions
    sscanf(input, "%c --> %[^\n]", &nonTerminal, input);

    // Splitting the production rules by '|'
    char *token = strtok(input, "|");
    while (token != NULL)
    {
        strcpy(productions[prodCount++], token);
        token = strtok(NULL, "|");
    }

    // Find the common prefix
    len = strlen(productions[0]);
    for (i = 1; i < prodCount; i++)
    {
        for (j = 0; j < len && j < strlen(productions[i]); j++)
        {
            if (productions[0][j] != productions[i][j])
                break;
        }
        len = j; // Update length to the smallest common prefix
    }

    // If len is 0, no left factoring
    if (len == 0)
    {
        printf("No Left Factoring present\n");
        return;
    }

    // Copy the common prefix
    strncpy(commonPrefix, productions[0], len);
    commonPrefix[len] = '\0';

    // Generate the new grammar
    printf("Left Factoring Grammar:\n");
    printf("%c --> %s%c'\n", nonTerminal, commonPrefix, nonTerminal);
    printf("%c' --> ", nonTerminal);

    for (i = 0; i < prodCount; i++)
    {
        if (strlen(productions[i]) == len)
        {
            printf("e"); // if the production is just the common prefix, append epsilon
        }
        else
        {
            printf("%s", productions[i] + len); // print the remaining part of the production
        }
        if (i < prodCount - 1)
        {
            printf(" | ");
        }
    }
    printf("\n");
}

int main()
{
    char input[MAX];

    // Example input
    printf("Enter production rule (A --> aB|aC|aD): ");
    fgets(input, MAX, stdin);
    input[strlen(input) - 1] = '\0'; // Remove trailing newline

    leftFactoring(input);

    return 0;
}
