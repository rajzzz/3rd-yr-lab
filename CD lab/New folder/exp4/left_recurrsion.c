#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void eliminateLeftRecursion(char *production) {
    char *lhs = strtok(production, "->");
    char *rhs = strtok(NULL, "->");

    char *tokens[10];
    int n = 0;
    tokens[n++] = strtok(rhs, "|");
    while (tokens[n-1] != NULL) {
        tokens[n++] = strtok(NULL, "|");
    }
    n--;

    char alpha[10][10], beta[10][10];
    int alphaCount = 0, betaCount = 0;

    for (int i = 0; i < n; i++) {
        if (tokens[i][0] == lhs[0]) {
            strcpy(alpha[alphaCount++], tokens[i] + 1);
        } else {
            strcpy(beta[betaCount++], tokens[i]);
        }
    }

    if (alphaCount == 0) {
        printf("No left recursion detected.\n");
        return;
    }

    printf("%s -> ", lhs);
    for (int i = 0; i < betaCount; i++) {
        printf("%s%s'", beta[i], lhs);
        if (i < betaCount - 1) {
            printf(" | ");
        }
    }
    printf("\n");

    printf("%s' -> ", lhs);
    for (int i = 0; i < alphaCount; i++) {
        printf("%s%s'", alpha[i], lhs);
        if (i < alphaCount - 1) {
            printf(" | ");
        }
    }
    printf(" | ε\n");
}

int main() {
    char production[100];
    printf("Enter the production: ");
    scanf("%s", production);

    eliminateLeftRecursion(production);

    return 0;
}