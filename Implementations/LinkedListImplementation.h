#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#define MAX 10
#define BV_64 64
#define BV_32 32
#define BV_8 8

//DATATYPE DEFINITION START

typedef struct node
{
    int data;
    struct node *link;
} nodetype, *LIST;

typedef struct Lstack
{
    LIST top;
    int ctr;

} Stack;

typedef struct Lqueue {

LIST first;
LIST last;
int ctr;

} Queue;

typedef LIST BitVector;

//DATATYPE DEFINITION END

//START STACK

void initializeStack(Stack *L)
{

    L->top = NULL;
    L->ctr = 0;
}

bool isEmpty(Stack L)
{
    return (L.top == NULL);
}

bool isFull(Stack L)
{

    return (L.ctr == MAX);
}

int isTop(Stack L)
{

    return (isEmpty(L)) ? 0 : (L).top->data;
}

void pushStack(Stack *L, int data)
{

    if (!isFull(*L))
    {
        LIST temp = (LIST)malloc(sizeof(nodetype));
        if (temp != NULL)
        {
            temp->data = data;
            temp->link = L->top;
            L->top = temp;
            L->ctr++;
        }
    }
}

void popStack(Stack *L)
{

    if (!isEmpty(*L))
    {
        LIST temp = L->top;
        L->top = L->top->link;
        free(temp);
        L->ctr--;
    }
}

void makeNull(Stack *L)
{

    if (!isEmpty(*L))
    {
        while (L->ctr > 0)
        {
            popStack(L);
        }
    }
}

void displayStack(Stack *L)
{

    Stack temp;
    initializeStack(&temp);

    printf("CURRENT STACK\n");
    while (L->ctr > 0)
    {

        printf("| %5d     |\n", isTop(*L));
        printf("_____________\n");
        pushStack(&temp, isTop(*L));
        popStack(L);
    }

    while (temp.ctr > 0)
    {
        pushStack(L, isTop(temp));
        popStack(&temp);
    }
}

void insertBottom(Stack *L, int data)
{

    Stack temp;
    initializeStack(&temp);
    if (!isFull(*L))
    {
        while (L->ctr > 0)
        {

            pushStack(&temp, isTop(*L));
            popStack(L);
        }
        pushStack(L, data);

        while (temp.ctr > 0)
        {
            pushStack(L, isTop(temp));
            popStack(&temp);
        }
    }
}

//END STACK

// QUEUE START

void initQueue(Queue * Q){

Q->first = NULL;
Q->last = NULL;
Q->ctr = 0;

}

bool isQEmpty(Queue Q){

    return (Q.first == NULL) ? true : false;

}

bool isQFull(Queue Q){

    return (Q.ctr == MAX) ? true : false;

}

void EnQueue (Queue * Q, int elem){

    if(!isQFull(*Q)){

       LIST temp = (LIST)malloc(sizeof(struct node));

       if(temp != NULL){
       temp->link = NULL;
       temp->data = elem;
       Q->ctr++;
       
       if(Q->first != NULL){
          Q->last->link = temp;
          Q->last = temp;
       }else{
        Q->first = temp;
        Q->last = temp;
       }

    }

    }
}

void DeQueue(Queue * Q){
   if(!isQEmpty(*Q)){
    LIST temp = Q->first;
    Q->first = Q->first->link;
    Q->ctr--;
    free(temp);
   }
}

int Front(Queue Q){
    return (Q).first->data;
}

int Last(Queue Q){
    return (Q).last->data;
}

void displayQueue(Queue * Q)
{

    Queue temp;
    initQueue(&temp);

    printf("CURRENT QUEUE\n");
    printf("----------------------------------\n");

    while (Q->ctr > 0)
    {

        
        printf("%d ", Front(*Q));
        EnQueue(&temp, Front(*Q));
        DeQueue(Q);
    }

    printf("\n----------------------------------\n");

    while (temp.ctr > 0)
    {
        EnQueue(Q, Front(temp));
        DeQueue(&temp);
    }
}

void makeQNull(Queue * Q)
{

    if (!isQEmpty(*Q))
    {
        while (Q->ctr > 0)
        {
            DeQueue(Q);
        }
    }
}

void insertFirst(Queue * Q, int data)
{

    Queue temp;
    initQueue(&temp);
    if (!isQFull(*Q))
    {
        EnQueue(&temp, data);

        while (Q->ctr > 0)
        {

            EnQueue(&temp, Front(*Q));
            DeQueue(Q);
        }
        
        while (temp.ctr > 0)
        {
            EnQueue(Q, Front(temp));
            DeQueue(&temp);
        }
    }
}

//END QUEUE

//START UID