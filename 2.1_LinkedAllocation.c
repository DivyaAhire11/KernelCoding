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
}