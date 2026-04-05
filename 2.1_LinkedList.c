#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 20
#define MAX_FILES 10

int bitVector[MAX];
int disk[MAX]; // stores next block (linked list)
int n;

struct Directory
{
    char fname[20];
    int start;
    int size;
} dir[MAX_FILES];

int dirCount = 0;

// Show Bit Vector
void showBitVector()
{
    printf("\nBit Vector:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", bitVector[i]);
    }
    printf("\n");
}

// Initialize Disk
void initializeDisk()
{
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        bitVector[i] = rand() % 2; // random allocation
        disk[i] = -1;
    }
    printf("\nDisk initialized.\n");
}

// Create File
void createFile()
{
    char name[20];
    int blocks;

    // Directory full check
    if (dirCount >= MAX_FILES)
    {
        printf("\nDirectory is full!\n");
        return;
    }

    printf("\nEnter file name: ");
    scanf("%s", name);

    // Duplicate check
    for (int i = 0; i < dirCount; i++)
    {
        if (strcmp(dir[i].fname, name) == 0)
        {
            printf("\nFile already exists!\n");
            return;
        }
    }

    printf("Enter number of blocks needed: ");
    scanf("%d", &blocks);

    // Validation
    if (blocks <= 0)
    {
        printf("\nInvalid number of blocks!\n");
        return;
    }

    int freeCount = 0;
    for (int i = 0; i < n; i++)
    {
        if (bitVector[i] == 0)
            freeCount++;
    }

    if (freeCount < blocks)
    {
        printf("\nNot enough free blocks!\n");
        return;
    }

    int first = -1, prev = -1;

    // Allocate blocks
    for (int i = 0, j = 0; i < n && j < blocks; i++)
    {
        if (bitVector[i] == 0)
        {
            bitVector[i] = 1;

            if (first == -1)
                first = i;
            else
                disk[prev] = i;

            prev = i;
            j++;
        }
    }

    disk[prev] = -1;

    // Add to directory
    strcpy(dir[dirCount].fname, name);
    dir[dirCount].start = first;
    dir[dirCount].size = blocks;
    dirCount++;

    printf("\nFile '%s' created successfully.\n", name);
}

// Show Directory
void showDirectory()
{
    if (dirCount == 0)
    {
        printf("\nDirectory is empty.\n");
        return;
    }

    printf("\nFile Name\tStart\tSize\tBlocks\n");

    for (int i = 0; i < dirCount; i++)
    {
        printf("%s\t\t%d\t%d\t", dir[i].fname, dir[i].start, dir[i].size);

        int temp = dir[i].start;
        while (temp != -1)
        {
            printf("%d ", temp);
            temp = disk[temp];
        }
        printf("\n");
    }
}

int main()
{
    int choice;

    printf("Enter total number of blocks (max %d): ", MAX);
    scanf("%d", &n);

    // Limit check
    if (n > MAX || n <= 0)
    {
        printf("\nInvalid disk size!\n");
        return 0;
    }

    initializeDisk();

    do
    {
        printf("\n------ MENU ------");
        printf("\n1. Show Bit Vector");
        printf("\n2. Create New File");
        printf("\n3. Show Directory");
        printf("\n4. Exit");

        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            showBitVector();
            break;
        case 2:
            createFile();
            break;
        case 3:
            showDirectory();
            break;
        case 4:
            printf("\nProgram Ended.\n");
            break;
        default:
            printf("\nInvalid Choice!\n");
        }

    } while (choice != 4);

    return 0;
}