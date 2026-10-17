
#include <stdio.h>

#define P 5
#define R 3

int allocation[P][R] = {
    {0, 1, 0},
    {2, 0, 0},
    {3, 0, 2},
    {2, 1, 1},
    {0, 0, 2}
};

int maximum[P][R] = {
    {7, 5, 3},
    {3, 2, 2},
    {9, 0, 2},
    {2, 2, 2},
    {4, 3, 3}
};

int available[R] = {3, 3, 2};
int need[P][R];
int finished[P] = {0};
int sequence[P];

int safeCount = 0;
int blockedCount = 0;

void printSequence(int depth) {
    for (int i = 0; i < depth; i++) {
        printf("P%d", sequence[i]);

        if (i < depth - 1)
            printf(" -> ");
    }
}

void findSequences(int depth, int work[]) {
    // All processes have completed
    if (depth == P) {
        safeCount++;

        printf("Safe sequence %d: ", safeCount);
        printSequence(depth);
        printf("\n");
        return;
    }

    int extended = 0;

    for (int i = 0; i < P; i++) {
        if (finished[i])
            continue;

        int possible = 1;

        // Check whether process i can finish
        for (int j = 0; j < R; j++) {
            if (need[i][j] > work[j]) {
                possible = 0;
                break;
            }
        }

        if (possible) {
            extended = 1;
            finished[i] = 1;
            sequence[depth] = i;

            // Release resources after process finishes
            for (int j = 0; j < R; j++)
                work[j] += allocation[i][j];

            findSequences(depth + 1, work);

            // Backtrack: restore previous resources
            for (int j = 0; j < R; j++)
                work[j] -= allocation[i][j];

            finished[i] = 0;
        }
    }

    // No unfinished process can proceed on this branch
    if (!extended) {
        blockedCount++;

        printf("Blocked partial sequence %d: ", blockedCount);

        if (depth == 0)
            printf("(none)");
        else
            printSequence(depth);

        printf(" | Remaining processes: ");

        int first = 1;

        for (int i = 0; i < P; i++) {
            if (!finished[i]) {
                if (!first)
                    printf(", ");

                printf("P%d", i);
                first = 0;
            }
        }

        printf("\n");
    }
}

int main() {
    int work[R];

    printf("NEED MATRIX:\n");

    for (int i = 0; i < P; i++) {
        for (int j = 0; j < R; j++) {
            need[i][j] =
                maximum[i][j] - allocation[i][j];

            printf("%d ", need[i][j]);
        }

        printf("\n");
    }

    printf("\nAvailable resources: ");

    for (int j = 0; j < R; j++) {
        printf("%d ", available[j]);
        work[j] = available[j];
    }

    printf("\n\nChecking all possible process orders...\n\n");

    findSequences(0, work);

    printf("\n========== FINAL RESULT ==========\n");
    printf("Safe sequences: %d\n", safeCount);
    printf("Blocked partial sequences: %d\n", blockedCount);

    if (safeCount > 0)
        printf("System state: SAFE\n");
    else
        printf("System state: UNSAFE\n");

    return 0;
}

