/*
  write a simulation program for disk sceduling using FCFS algorithm.
*/
// FCFS = First Come First Serve
#include <stdio.h>
#include <stdlib.h> //for abs()

void main()
{
    int n, i;
    int head, total_movement = 0;

    printf("Enter Total number of disk requests :");
    scanf("%d", &n);

    // int request[]={55,58,39,18,90,160,150,38,184};
    // n = 9,head = 50;

    int request[n];
    printf("Enter disk request string :\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &request[i]);
    }
    printf("Enter starting head position :");
    scanf("%d", &head);

    printf("\n Order of servicing request:\n");
    printf("%d -> ", head);
    for (i = 0; i < n; i++)
    {
        printf("%d -> ", request[i]);

        // calculate head movement
        total_movement = total_movement + abs(request[i] - head);

        // move head to current request
        head = request[i];
    }
    printf("END");

    printf("\n\nTotal number of head movements = %d\n", total_movement);
}
/*
 50 -> 55 -> 58 -> 39 -> 18 -> 90 -> 160 -> 150 -> 38 -> 184 -> END

 From  To   Movement
 50    55   5
 55    58   3
 58    39   19
 39    18   21
 18    90   72
 90    160  70
 160   150  10
 150   38   112
 38    184  146

 toatl = 5+3+19+21+72+70+10+112+146 = 458

*/