#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    char lhs;
    char rhs[MAX][MAX];
    int rhs_count;
} Production;

Production productions[MAX];
int production_count = 0;

char stack[MAX];
int top = -1;
char start_symbol;

void push(char c) {
    stack[++top] = c;
}

void pop() {
    if (top >= 0) top--;
}

void display_stack() {
    printf("\t\t");
    for (int i = 0; i <= top; i++) {
        printf("%c", stack[i]);
    }
}

int is_non_terminal(char c) {
    return c >= 'A' && c <= 'Z';
}

int reduce() {
    for (int i = 0; i < production_count; i++) {
        for (int j = 0; j < productions[i].rhs_count; j++) {
            int len = strlen(productions[i].rhs[j]);
            if (top + 1 >= len) {
                int match = 1;
                for (int k = 0; k < len; k++) {
                    if (stack[top - len + 1 + k] != productions[i].rhs[j][k]) {
                        match = 0;
                        break;
                    }
                }
                if (match) {
                    for (int k = 0; k < len; k++) {
                        pop();
                    }
                    push(productions[i].lhs);
                    printf("Reduce by %c -> %s\t", productions[i].lhs, productions[i].rhs[j]);
                    display_stack();
                    printf("\n");
                    return 1;
                }
            }
        }
    }
    return 0;
}

void shift_reduce_parse(char *input) {
    int i = 0;
    printf("Action\t\t\t\t\tStack\n");
    printf("------\t\t\t\t\t-----\n");
    while (i < strlen(input)) {
        if (strncmp(&input[i], "id", 2) == 0) {
            push('i');
            push('d');
            printf("Shift\tid\t\t");
            display_stack();
            printf("\n");
            i += 2;
        } else {
            push(input[i]);
            printf("Shift\t%c\t\t", input[i]);
            display_stack();
            printf("\n");
            i++;
        }

        while (reduce()) {
            // Reduction steps are printed inside the reduce function
        }
    }

    // Final acceptance check
    if (top == 0 && stack[top] == start_symbol) {
        printf("\t\tAccepted\n");
    } else {
        printf("\t\tNot Accepted\n");
    }
}

void add_production(char lhs, char *rhs) {
    int i;
    for (i = 0; i < production_count; i++) {
        if (productions[i].lhs == lhs) {
            strcpy(productions[i].rhs[productions[i].rhs_count++], rhs);
            return;
        }
    }
    productions[production_count].lhs = lhs;
    strcpy(productions[production_count].rhs[productions[production_count].rhs_count++], rhs);
    production_count++;
}

int main() {
    char input[MAX];
    printf("Enter the number of productions: ");
    int n;
    scanf("%d", &n);
    getchar(); // to consume the newline character

    for (int i = 0; i < n; i++) {
        char lhs;
        char rhs[MAX];
        printf("Enter production %d (format: A->abc|d): ", i + 1);
        scanf("%c->%s", &lhs, rhs);
        getchar(); // to consume the newline character

        if (i == 0) {
            start_symbol = lhs; // Set the start symbol to the LHS of the first production
        }

        char *token = strtok(rhs, "|");
        while (token != NULL) {
            add_production(lhs, token);
            token = strtok(NULL, "|");
        }
    }

    printf("Enter the input string: ");
    scanf("%s", input);

    shift_reduce_parse(input);

    return 0;
}