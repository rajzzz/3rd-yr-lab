#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PRODUCTIONS 20
#define MAX_LENGTH 100

typedef struct {
    char nonTerminal;
    char productions[MAX_PRODUCTIONS][MAX_LENGTH];
    int productionCount;
} Grammar;

Grammar grammar[MAX_PRODUCTIONS];
int grammarSize = 0;

// Function to parse a single line production and populate the grammar structure
void parseGrammarInput() {
    printf("Enter the number of productions: ");
    scanf("%d", &grammarSize);
    getchar(); // Consume newline

    for (int i = 0; i < grammarSize; i++) {
        char input[MAX_LENGTH];
        printf("Enter production for Non-Terminal %d (e.g., E->TA|e): ", i + 1);
        fgets(input, sizeof(input), stdin);

        // Remove newline character
        size_t length = strlen(input);
        if (length > 0 && input[length - 1] == '\n') {
            input[length - 1] = '\0';
        }

        // Parse LHS and RHS
        grammar[i].nonTerminal = input[0];
        grammar[i].productionCount = 0;
        
        char *rhs = strtok(input + 3, "|"); // Start after "->"
        while (rhs != NULL) {
            strcpy(grammar[i].productions[grammar[i].productionCount++], rhs);
            rhs = strtok(NULL, "|");
        }
    }
}

// Check if a production contains two consecutive non-terminals
int containsConsecutiveNonTerminals(char *production) {
    int length = strlen(production);
    for (int i = 0; i < length - 1; i++) {
        if (isupper(production[i]) && isupper(production[i + 1])) {
            return 1; // Consecutive non-terminals found
        }
    }
    return 0; // No consecutive non-terminals
}

// Check if any production contains epsilon ('e')
int containsEpsilon(char *production) {
    return (strcmp(production, "e") == 0);
}

// Function to check if the grammar is operator-precedent
int isOperatorPrecedentGrammar() {
    for (int i = 0; i < grammarSize; i++) {
        for (int j = 0; j < grammar[i].productionCount; j++) {
            char *production = grammar[i].productions[j];
            
            if (containsConsecutiveNonTerminals(production)) {
                printf("Consecutive non-terminals found in production: %c -> %s\n", grammar[i].nonTerminal, production);
                return 0; // Not operator-precedent
            }
            if (containsEpsilon(production)) {
                printf("Epsilon found in production: %c -> %s\n", grammar[i].nonTerminal, production);
                return 0; // Not operator-precedent
            }
        }
    }
    return 1; // Operator-precedent grammar
}

int main() {
    parseGrammarInput();

    // Display grammar rules
    printf("\nGrammar:\n");
    for (int i = 0; i < grammarSize; i++) {
        printf("%c -> ", grammar[i].nonTerminal);
        for (int j = 0; j < grammar[i].productionCount; j++) {
            printf("%s", grammar[i].productions[j]);
            if (j < grammar[i].productionCount - 1) {
                printf(" | ");
            }
        }
        printf("\n");
    }

    // Check if grammar is operator-precedent
    printf("\nChecking if the grammar is operator-precedent...\n");
    if (isOperatorPrecedentGrammar()) {
        printf("The grammar is an operator-precedent grammar.\n");
    } else {
        printf("The grammar is NOT an operator-precedent grammar.\n");
    }

    return 0;
}
