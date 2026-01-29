/*
Linked file Allocation method
  1.show Bit Vector
  2.Create New File
  3.Show Directory
  4.Exit
*/
// 0 -> free block
// 1 -> allocated block

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define MAX 20

int bitVector[MAX];
int disk[MAX]; //stores next block(linked list) , -1 means end
int n;

struct Directory{
    char fname[20];
    int start;
    int size;
}dir[20];

int dirCount = 0;

//show Bit Vector
void showBitVector(){
   int i;
   printf("\n Bit Vector\n");
   for(i=0;i<n;i++){
    printf("%d  ",bitVector[i]);
   }
   printf("\n");
}
//Initialized disk randomly
void initializedDisk(){
    int i;
    srand(time(NULL));
    for(i=0;i<n;i++){
        bitVector[i] = rand()%2;
        disk[i] = -1;
    }

    printf("\nDisk initialized Randomly\n");
}

//create New File
void createFile(){
    char name[20];
    int block,i,j,first=-1,prev = -1;

    printf("\n Enter file Name :");
    scanf("%s",name);

    printf("Enter number of blocks required :");
    scanf("%d",&block);

    //count free blocks
    int freeCount = 0;
    for(i=0;i<n;i++)
      if(bitVector[i] == 0)
        freeCount++;

    if(freeCount < block){
        printf("Not enough free blocks available\n");
        return;
    }

    //Allocate blocks
    for(i=0,j=0; i<n && i<n && j<block ;i++){
        if(bitVector[i] == 0){
            bitVector[i] = 1;

            if(first == -1)
              first = i;
            else
              disk[prev] = i;

            prev = i;
            j++;
        }
    }
      disk[prev] = -1;  //END of File

      //store in directory
      strcpy(dir[dirCount].fname,name);
      dir[dirCount].start = first;
      dir[dirCount].size = block;
      dirCount++;

      printf("File created successfully! \n");
}

void showDirectory(){
    int i,temp;
    if(dirCount == 0){
        printf("\n Directory is empty");
        return;
    }
    
}

int main() {
    int choice;

    while(1) {
        printf("\n--- MENU ---");
        printf("\n1. Show Bit Vector");
        printf("\n2. Create New File");
        printf("\n3. Show Directory");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: showBitVector();
                    break;
            case 2: createFile();
                    break;
            case 3: showDirectory();
                    break;
            case 4: return 0;
            default: printf("Invalid choice!\n");
        }
    }
}
