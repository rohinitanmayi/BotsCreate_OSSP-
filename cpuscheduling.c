#include <stdio.h>

int main()
{
    int choice;

    while (1)
    {
        printf("\nCPU Scheduling Algorithms\n");
        printf("1. FCFS\n");
        printf("2. SJF\n");
        printf("3. SRTF\n");
        printf("4. Priority Non-Preemptive\n");
        printf("5. Priority Preemptive\n");
        printf("6. Round Robin\n");
        printf("7. Exit\n");

        printf("Select one of the CPU Scheduling Algo: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("FCFS Selected\n");
                break;

            case 2:
                printf("SJF Selected\n");
                break;

            case 3:
                printf("SRTF Selected\n");
                break;

            case 4:
                printf("Priority Non-Preemptive Selected\n");
                break;

            case 5:
                printf("Priority Preemptive Selected\n");
                break;

            case 6:
                printf("Round Robin Selected\n");
                break;

            case 7:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid Choice!\n");
        }
    }

    return 0;
}
