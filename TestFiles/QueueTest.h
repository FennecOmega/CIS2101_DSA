#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void QueueTest(){

Queue Q;
int i;

initQueue(&Q);

printf("After Queue Initialization...\n");

printf((isQEmpty(Q)) ? "The Queue is Empty\n\n" : "The Queue is Not Empty\n\n");

printf("\n\n");

for (i = 0; i < MAX; i++)
   {
      EnQueue(&Q, i + 10);
   }

   printf("After Fully Populating Queue...\n");

   displayQueue(&Q);

   printf("\n\n");

   printf((isQFull(Q)) ? "The Queue is Full\n\n" : "The Queue is Not Full\n\n");



   printf("%d is the First Element\n\n", Front(Q));

   

   EnQueue(&Q, 20);
   printf("After EnQueue on Full Queue...\n");

   printf("%d is the Last Element\n\n", Last(Q));

   DeQueue(&Q);
   printf("After DeQueue...\n");

   printf((isQFull(Q)) ? "The Queue is Full\n\n" : "The Queue is Not Full\n\n");

   insertFirst(&Q, 200);
   printf("After Inserting at Front...\n");

   displayQueue(&Q);
   printf((isQFull(Q)) ? "The Queue is Full\n\n" : "The Queue is Not Full\n\n");

   printf("%d is the First Element\n\n", Front(Q));

   makeQNull(&Q);
   printf("After Queue makeNull...\n");

   printf((isQEmpty(Q)) ? "The Queue is Empty\n\n" : "The Queue is Not Empty\n\n");

   EnQueue(&Q, 59 + 10);
   printf("After Pushing Data to Queue...\n");

   displayQueue(&Q);

   insertFirst(&Q, 21);
   printf("After Inserting at First...\n");

   printf("\n\n");

   displayQueue(&Q);

   printf((isQEmpty(Q)) ? "The Queue is Empty\n\n" : "The Queue is Not Empty\n\n");

   printf((isQFull(Q)) ? "The Queue is Full\n\n" : "The Queue is Not Full\n\n");

   printf("%d is the First Element\n\n", Front(Q));

   makeQNull(&Q);
   printf("After Queue makeNull...\n");

   printf((isQEmpty(Q)) ? "The Queue is Empty\n\n" : "The Queue is Not Empty\n\n");

   printf("END OF PROGRAM/DRIVER FILE\n");


}