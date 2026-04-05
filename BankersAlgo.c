#include <stdio.h>

#define P 5 // Processes
#define R 3 // Resources

int allocation[P][R] = {
    {2, 3, 2},
    {4, 0, 0},
    {5, 0, 4},
    {4, 3, 3},
    {2, 2, 4}
};

int max[P][R] = {
    {9, 7, 5},
    {5, 2, 2},
    {1, 0, 4},
    {4, 4, 4},
    {6, 5, 5}
};

int available[R];
int need[P][R];

// Calculate Need Matrix
void calculateNeed()
{
    for (int i = 0; i < P; i++)
        for (int j = 0; j < R; j++)
            need[i][j] = max[i][j] - allocation[i][j];
}

// Accept Available Resources
void acceptAvailable()
{
    printf("\nEnter Available Resources (A B C): ");
    for (int i = 0; i < R; i++)
        scanf("%d", &available[i]);
}

// Display Allocation & Max
void displayAllocationMax()
{
    printf("\nProcess\tAllocation\tMax\n");
    for (int i = 0; i < P; i++)
    {
        printf("P%d\t", i);
        for (int j = 0; j < R; j++)
            printf("%d ", allocation[i][j]);

        printf("\t\t");

        for (int j = 0; j < R; j++)
            printf("%d ", max[i][j]);

        printf("\n");
    }
}

// Display Need Matrix
void displayNeed()
{
    calculateNeed();
    printf("\nProcess\tNeed\n");
    for (int i = 0; i < P; i++)
    {
        printf("P%d\t", i);
        for (int j = 0; j < R; j++)
            printf("%d ", need[i][j]);
        printf("\n");
    }
}

// Display Available
void displayAvailable()
{
    printf("\nAvailable Resources:\n");
    for (int i = 0; i < R; i++)
        printf("%d ", available[i]);
    printf("\n");
}

// Banker's Safety Algorithm
void checkSafeSequence()
{
    int work[R], finish[P] = {0};
    int safeSeq[P];
    int count = 0;

    // Copy available to work
    for (int i = 0; i < R; i++)
        work[i] = available[i];

    calculateNeed();

    while (count < P)
    {
        int found = 0;

        for (int i = 0; i < P; i++)
        {
            if (finish[i] == 0)
            {
                int j;
                for (j = 0; j < R; j++)
                {
                    if (need[i][j] > work[j])
                        break;
                }

                if (j == R)
                {
                    // Process can execute
                    for (int k = 0; k < R; k++)
                        work[k] += allocation[i][k];

                    safeSeq[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }

        if (!found)
        {
            printf("\nSystem is NOT in safe state!\n");
            return;
        }
    }

    printf("\nSystem is in SAFE state.\nSafe Sequence: ");
    for (int i = 0; i < P; i++)
        printf("P%d ", safeSeq[i]);
    printf("\n");
}

// Main Menu
int main()
{
    int ch;

    do
    {
        printf("\n------ MENU ------");
        printf("\n1. Accept Available");
        printf("\n2. Display Allocation & Max");
        printf("\n3. Display Need");
        printf("\n4. Display Available");
        printf("\n5. Check Safe Sequence");
        printf("\n6. Exit");

        printf("\nEnter choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            acceptAvailable();
            break;
        case 2:
            displayAllocationMax();
            break;
        case 3:
            displayNeed();
            break;
        case 4:
            displayAvailable();
            break;
        case 5:
            checkSafeSequence();
            break;
        case 6:
            printf("\nProgram Ended.\n");
            break;
        default:
            printf("\nInvalid choice!\n");
        }

    } while (ch != 6);

    return 0;
}