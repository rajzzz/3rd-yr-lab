#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_PRODUCTIONS 20
#define MAX_LENGTH 100

typedef struct
{
    char nonTerminal[MAX_LENGTH]; // Updated to support multi-character non-terminals
    char productions[MAX_PRODUCTIONS][MAX_LENGTH];
    int productionCount;
} Grammar;

int isTerminal(const char *symbol)
{
    return !isupper(symbol[0]);
}

// Adds a symbol to the FIRST set if it is not already present
void addToFirstSet(char *first, char symbol)
{
    if (!strchr(first, symbol))
    {
        int len = strlen(first);
        first[len] = symbol;
        first[len + 1] = '\0';
    }
}

// Recursive function to find FIRST of a non-terminal
void findFirst(const char *nonTerminal, Grammar grammar[], int grammarSize, char *first)
{
    for (int i = 0; i < grammarSize; i++)
    {
        if (strcmp(grammar[i].nonTerminal, nonTerminal) == 0)
        {
            for (int j = 0; j < grammar[i].productionCount; j++)
            {
                char *production = grammar[i].productions[j];

                // If production starts with a terminal, add it to FIRST set
                if (isTerminal(production))
                {
                    addToFirstSet(first, production[0]);
                }
                else
                {
                    // Handle non-terminal or epsilon
                    for (int k = 0; production[k] != '\0'; k++)
                    {
                        char nextNonTerminal[MAX_LENGTH] = {production[k]};

                        // Check if the next symbol includes ' (e.g., E' as a non-terminal)
                        if (k + 1 < strlen(production) && production[k + 1] == '\'')
                        {
                            nextNonTerminal[1] = '\'';
                            nextNonTerminal[2] = '\0';
                            k++; // Skip the next character as it's part of the same non-terminal
                        }
                        else
                        {
                            nextNonTerminal[1] = '\0';
                        }

                        char subFirst[MAX_LENGTH] = "";
                        findFirst(nextNonTerminal, grammar, grammarSize, subFirst);

                        // Add subFirst elements to the FIRST set
                        for (int m = 0; subFirst[m] != '\0'; m++)
                        {
                            if (subFirst[m] != 'e')
                            {
                                addToFirstSet(first, subFirst[m]);
                            }
                        }

                        // If epsilon is not present in subFirst, break
                        if (!strchr(subFirst, 'e'))
                        {
                            break;
                        }
                    }
                }
            }
        }
    }
}

// Function to display FIRST sets in set notation
void displayFirstSets(Grammar grammar[], int grammarSize)
{
    for (int i = 0; i < grammarSize; i++)
    {
        char first[MAX_LENGTH] = "";
        findFirst(grammar[i].nonTerminal, grammar, grammarSize, first);

        printf("FIRST(%s) = { ", grammar[i].nonTerminal);
        for (int j = 0; j < strlen(first); j++)
        {
            printf("%c", first[j]);
            if (j < strlen(first) - 1)
            {
                printf(", ");
            }
        }
        printf(" }\n");
    }
}

int main()
{
    int grammarSize;
    Grammar grammar[MAX_PRODUCTIONS];

    printf("Enter the number of productions: ");
    scanf("%d", &grammarSize);
    getchar(); // Clear newline from input buffer
    printf("Note that epsilon is to be entered as 'e'\nAlso note that multi-character non-terminals are notsupported so 'id' would be printed as 'i' only\n");
    for (int i = 0; i < grammarSize; i++)
    {
        char input[MAX_LENGTH];
        printf("Enter production for Non-Terminal %d: ", i + 1);
        fgets(input, sizeof(input), stdin);

        // Remove newline character if present
        size_t length = strlen(input);
        if (length > 0 && input[length - 1] == '\n')
        {
            input[length - 1] = '\0';
        }

        // Parse Non-Terminal and productions
        int j = 0;
        while (input[j] != '-' && input[j + 1] != '>')
        {
            grammar[i].nonTerminal[j] = input[j];
            j++;
        }
        grammar[i].nonTerminal[j] = '\0'; // Terminate string

        grammar[i].productionCount = 0;

        char *rhs = strtok(input + j + 2, "|"); // Start after "->"
        while (rhs != NULL)
        {
            strcpy(grammar[i].productions[grammar[i].productionCount++], rhs);
            rhs = strtok(NULL, "|");
        }
    }

    // Display FIRST sets
    displayFirstSets(grammar, grammarSize);

    return 0;
}
