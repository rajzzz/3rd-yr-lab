#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define NAME_LENGTH 20

typedef struct {
    int id; // Unique identifier for the record
    char name[NAME_LENGTH]; // Name associated with the record
} Record;

void writeIndexed();
void readIndexed();
void writeHashed();
void readHashed();
void writeSequential();
void readSequential();

int main() {
    int choice;
    while (1) {
        printf("\n1. Write Indexed File");
        printf("\n2. Read Indexed File");
        printf("\n3. Write Hashed File");
        printf("\n4. Read Hashed File");
        printf("\n5. Write Sequential File");
        printf("\n6. Read Sequential File");
        printf("\n7. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                writeIndexed();
                break;
            case 2:
                readIndexed();
                break;
            case 3:
                writeHashed();
                break;
            case 4:
                readHashed();
                break;
            case 5:
                writeSequential();
                break;
            case 6:
                readSequential();
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice. Please try again.");
        }
    }
    return 0;
}

void writeIndexed() {
    FILE *file = fopen("indexed.txt", "w");
    FILE *indexFile = fopen("index.txt", "w");
    if (!file || !indexFile) {
        printf("Error opening file!\n");
        return;
    }

    Record records[MAX_RECORDS];
    int recordCount = 0;
    char addMore;

    do {
        printf("Enter ID: ");
        scanf("%d", &records[recordCount].id);
        printf("Enter Name: ");
        scanf("%s", records[recordCount].name);
        recordCount++;

        printf("Do you want to add another record? (y/n): ");
        scanf(" %c", &addMore);
    } while (addMore == 'y' && recordCount < MAX_RECORDS);

    for (int i = 0; i < recordCount; i++) {
        fprintf(file, "%d %s\n", records[i].id, records[i].name); // Write the record
        fprintf(indexFile, "%d %ld\n", records[i].id, ftell(file) - sizeof(Record)); // Write ID and position to index
    }

    fclose(file);
    fclose(indexFile);
    printf("Records written to indexed.txt and index.txt.\n");
}

void readIndexed() {
    FILE *file = fopen("indexed.txt", "r");
    FILE *indexFile = fopen("index.txt", "r");
    if (!file || !indexFile) {
        printf("Error opening file!\n");
        return;
    }

    Record record;
    printf("\nIndexed Records:\n");
    while (fscanf(file, "%d %s", &record.id, record.name) != EOF) {
        printf("ID: %d, Name: %s\n", record.id, record.name);
    }

    fclose(file);
    fclose(indexFile);
}

void writeHashed() {
    FILE *file = fopen("hashed.txt", "a");
    if (!file) {
        printf("Error opening file!\n");
        return;
    }

    Record records[MAX_RECORDS];
    int recordCount = 0;
    char addMore;

    do {
        printf("Enter ID: ");
        scanf("%d", &records[recordCount].id);
        printf("Enter Name: ");
        scanf("%s", records[recordCount].name);
        recordCount++;

        printf("Do you want to add another record? (y/n): ");
        scanf(" %c", &addMore);
    } while (addMore == 'y' && recordCount < MAX_RECORDS);

    for (int i = 0; i < recordCount; i++) {
        fprintf(file, "%d %s\n", records[i].id, records[i].name); // Write the record
    }

    fclose(file);
    printf("Records written to hashed.txt.\n");
}

void readHashed() {
    FILE *file = fopen("hashed.txt", "r");
    if (!file) {
        printf("Error opening file!\n");
        return;
    }

    Record record;
    printf("\nHashed Records:\n");
    while (fscanf(file, "%d %s", &record.id, record.name) != EOF) {
        printf("ID: %d, Name: %s\n", record.id, record.name);
    }

    fclose(file);
}

void writeSequential() {
    FILE *file = fopen("sequential.txt", "a");
    if (!file) {
        printf("Error opening file!\n");
        return;
    }

    Record records[MAX_RECORDS];
    int recordCount = 0;
    char addMore;

    do {
        printf("Enter ID: ");
        scanf("%d", &records[recordCount].id);
        printf("Enter Name: ");
        scanf("%s", records[recordCount].name);
        recordCount++;

        printf("Do you want to add another record? (y/n): ");
        scanf(" %c", &addMore);
    } while (addMore == 'y' && recordCount < MAX_RECORDS);

    for (int i = 0; i < recordCount; i++) {
        fprintf(file, "%d %s\n", records[i].id, records[i].name); // Write the record
    }

    fclose(file);
    printf("Records written to sequential.txt.\n");
}

void readSequential() {
    FILE *file = fopen("sequential.txt", "r");
    if (!file) {
        printf("Error opening file!\n");
        return;
    }

    Record record;
    printf("\nSequential Records:\n");
    while (fscanf(file, "%d %s", &record.id, record.name) != EOF) {
        printf("ID: %d, Name: %s\n", record.id, record.name);
    }

    fclose(file);
}
