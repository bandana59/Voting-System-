#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// Structure to store candidate details
struct Candidate {
    char name[50];
    int votes;
};

// Global array of candidates
struct Candidate candidates[MAX];
int candidateCount = 0;

// Function Prototypes
void initializeCandidates();  // NEW
void addCandidate();
void searchCandidate();
void castVote();
void showResults();
void saveToFile();
void loadFromFile();

int main() {
    int choice;

    loadFromFile(); // Load data from file when program starts

    if (candidateCount == 0) {
        initializeCandidates(); // Add default candidates if file is empty
    }

    while (1) {
        printf("\n\n---- Voting System Menu ----\n");
        printf("1. Add Candidate\n");
        printf("2. Search Candidate\n");
        printf("3. Cast Vote\n");
        printf("4. Show Results\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // consume newline character

        switch (choice) {
            case 1: addCandidate(); break;
            case 2: searchCandidate(); break;
            case 3: castVote(); break;
            case 4: showResults(); break;
            case 5: saveToFile(); exit(0);
            default: printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

// 🔹 Function to initialize default candidates
void initializeCandidates() {
    char *defaultNames[] = {"Sandhya", "Bandana", "Neha", "Priyanka"};
    int n = sizeof(defaultNames) / sizeof(defaultNames[0]);

    for (int i = 0; i < n; i++) {
        strcpy(candidates[candidateCount].name, defaultNames[i]);
        candidates[candidateCount].votes = 0;
        candidateCount++;
    }
    printf("\nDefault candidates added.\n");
}

// Function to add a candidate
void addCandidate() {
    if (candidateCount >= MAX) {
        printf("Cannot add more candidates.\n");
        return;
    }
    printf("Enter candidate name: ");
    fgets(candidates[candidateCount].name, 50, stdin);
    candidates[candidateCount].name[strcspn(candidates[candidateCount].name, "\n")] = '\0';
    candidates[candidateCount].votes = 0;
    candidateCount++;
    printf("Candidate added successfully!\n");
}

// Function to search a candidate by name
void searchCandidate() {
    char searchName[50];
    printf("Enter name to search: ");
    fgets(searchName, 50, stdin);
    searchName[strcspn(searchName, "\n")] = '\0';

    for (int i = 0; i < candidateCount; i++) {
        if (strcmp(candidates[i].name, searchName) == 0) {
            printf("Candidate found: %s with %d votes\n", candidates[i].name, candidates[i].votes);
            return;
        }
    }
    printf("Candidate not found.\n");
}

// Function to cast vote
void castVote() {
    char voteName[50];
    printf("Enter candidate name to vote: ");
    fgets(voteName, 50, stdin);
    voteName[strcspn(voteName, "\n")] = '\0';

    for (int i = 0; i < candidateCount; i++) {
        if (strcmp(candidates[i].name, voteName) == 0) {
            candidates[i].votes++;
            printf("Vote casted successfully for %s!\n", candidates[i].name);
            return;
        }
    }
    printf("Candidate not found. Vote not counted.\n");
}

// Function to display voting results
void showResults() {
    printf("\n---- Voting Results ----\n");
    for (int i = 0; i < candidateCount; i++) {
        printf("%s - %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

// Function to save data to file
void saveToFile() {
    FILE *file = fopen("candidates.txt", "w");
    if (file == NULL) {
        printf("Error saving file.\n");
        return;
    }

    fprintf(file, "%d\n", candidateCount);
    for (int i = 0; i < candidateCount; i++) {
        fprintf(file, "%s\n%d\n", candidates[i].name, candidates[i].votes);
    }

    fclose(file);
    printf("Data saved to file.\n");
}

// Function to load data from file
void loadFromFile() {
    FILE *file = fopen("candidates.txt", "r");
    if (file == NULL) return; // No file yet

    fscanf(file, "%d\n", &candidateCount);
    for (int i = 0; i < candidateCount; i++) {
        fgets(candidates[i].name, 50, file);
        candidates[i].name[strcspn(candidates[i].name, "\n")] = '\0';
        fscanf(file, "%d\n", &candidates[i].votes);
    }

    fclose(file);
}
