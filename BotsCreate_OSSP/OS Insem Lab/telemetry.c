
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *buffer;
    int capacity = 3;
    int count = 0;

    buffer = (int *)calloc(capacity, sizeof(int));

    if (buffer == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Initial zero-initialized values:\n");
    for (int i = 0; i < capacity; i++) {
        printf("%d ", buffer[i]);
    }

    printf("\nEnter 3 initial market tick values:\n");
    for (int i = 0; i < capacity; i++) {
        scanf("%d", &buffer[i]);
        count++;
    }

    printf("Market tick values: ");
    for (int i = 0; i < count; i++) {
        printf("%d ", buffer[i]);
    }

    int newCapacity = capacity * 2;
    int *temp = (int *)realloc(buffer, newCapacity * sizeof(int));

    if (temp == NULL) {
        printf("\nMemory reallocation failed!\n");
        free(buffer);
        return 1;
    }

    buffer = temp;
    capacity = newCapacity;

    printf("\nBuffer expanded to %d elements.\n", capacity);
    printf("Enter 3 more market tick values:\n");

    for (int i = count; i < capacity; i++) {
        scanf("%d", &buffer[i]);
        count++;
    }

    printf("Expanded market tick buffer:\n");
    for (int i = 0; i < count; i++) {
        printf("%d ", buffer[i]);
    }

    free(buffer);
    buffer = NULL;

    printf("\nMemory freed successfully.\n");

    return 0;
}
