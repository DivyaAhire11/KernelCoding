/*
  1.accept available
  2.display allocation , Max
  3.display the contents of need matrix
  4.display available
*/
// Need matrix = Max - Allocation

#include <stdio.h>
#define P 5 // number of processes
#define R 3 // number of resources(A,B,C)

int allocation[P][R] = {
    {2, 3, 2},
    {4, 0, 0},
    {5, 0, 4},
    {4, 3, 3},
    {2, 2, 4}};

int max[P][R] = {
    {9, 7, 5},
    {5, 2, 2},
    {1, 0, 4},
    {4, 4, 4},
    {6, 5, 5}};

int available[R]; // available array
int need[P][R];   // need matrix

// Function to calculate Need matrix
void calculateNeed()
{
    int i, j;
    for (i = 0; i < P; i++)
    {
        for (j = 0; j < R; j++)
        {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }
}

void acceptAvailable()
{
    int j;
    printf("\n Enter Available Resources(A ,B ,C) :");
    for (j = 0; j < R; j++)
    {
        scanf("%d", &available[j]);
    }
}
void displayAllocationMax()
{
    int i, j;
    printf("\n Process\t Allocation(A,B,C)\tMax(A,B,C)\n");
    for (i = 0; i < P; i++)
    {
        printf("P%d \t", i);
        for (j = 0; j < R; j++)
            printf("%d ", allocation[i][j]);

        printf("\t\t");

        for (j = 0; j < R; j++)
            printf("%d ", max[i][j]);

        printf("\n");
    }
}

void displayNeed()
{
    int i, j;
    calculateNeed();
    printf("\n Process\tNeed(A,B,C)\n");
    for (i = 0; i < P; i++)
    {
        printf("P%d \t", i);
        for (j = 0; j < R; j++)
            printf("%d ", need[i][j]);

        printf("\n");
    }
}
void displayAvailable()
{
    int i;
    printf("\n Available Resources:\n");
    printf("A B C\n");
    for (i = 0; i < R; i++)
    {
        printf("%d ", available[i]);
    }
    printf("\n");
}

void main()
{
    int ch;

    do
    {
        printf("\n-------------MENU-------------");
        printf("\n1. Accept Available");
        printf("\n2. Display Allocation and Max");
        printf("\n3. Display Need Matrix");
        printf("\n4. Display Available");
        printf("\n5. Exit");
        printf("\n\nEnter your choice :");
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
            printf("Program Ended!");
            break;
        default:
            printf("\n Invalid Choice!");
        }
    } while (ch != 5);
}