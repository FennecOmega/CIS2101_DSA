#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#define MAX 10
#define VH_MAX 1000

// needed function operations: PUSH,POP, TOP, EMPTY, FULL, INITIALIZE, MAKENULL(?)


//DATATYPE DEFINITION START

typedef int LIST;

typedef struct node
{

    int data;
    LIST link;

} Nodetype;

typedef struct virtualHeap
{
    Nodetype Nodes[VH_MAX];
    int avail;
    bool isInit;

} VirtualHeap;

typedef struct stack
{

    LIST top;
    int ctr;

} Stack;

typedef struct queue{

LIST first;
LIST last;
int ctr;

}Queue;

VirtualHeap globalHeap = {.isInit = false};

//DATATYPE DEFINITION END

// list (LAST is FIRST NODE in the LINKED LIST)

//HELPER FUNCTION START

void initVH(VirtualHeap *V)
{
    int i;
    for (i = 0; i < VH_MAX; i++)
    {
        V->Nodes[i].link = i - 1;
    }
    V->avail = VH_MAX - 1;
    V->isInit = true;
}

int AllocSpace(VirtualHeap *V)
{
    int AvailNode = V->avail;
    if (AvailNode != -1)
    {
        V->avail = V->Nodes[AvailNode].link;
    }
    return AvailNode;
}

void deallocSpace(VirtualHeap *V, int pos)
{
    if (pos > -1 && pos < VH_MAX)
    {
        V->Nodes[pos].link = V->avail;
        V->avail = pos;
    }
}

//HELPER FUNCTION END

//STACK START

void initializeStack(Stack *L)
{

    if (!globalHeap.isInit)
    {
        initVH(&globalHeap);
    }
    L->top = -1;
    L->ctr = 0;
}

bool isEmpty(Stack L)
{

    return (L.top == -1);
}

bool isFull(Stack L)
{

    return (L.ctr == MAX);
}

int isTop(Stack L)
{

    return (L.ctr != 0) ? globalHeap.Nodes[L.top].data : 0;
}

void pushStack(Stack *L, int data)
{

    if (!isFull(*L))
    {
        LIST temp = AllocSpace(&globalHeap);
        if (temp != -1)
        {
            globalHeap.Nodes[temp].data = data;
            globalHeap.Nodes[temp].link = L->top;
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
        L->top = globalHeap.Nodes[L->top].link;
        deallocSpace(&globalHeap, temp);
        L->ctr--;
    }
}

void makeNull(Stack *L)
{

    int temp;
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

// END STACK

// START QUEUE

void initQueue(Queue * Q){

if (!globalHeap.isInit)
{
    initVH(&globalHeap);
}

Q->first = -1;
Q->last = -1;
Q->ctr = 0;

}

bool isQEmpty(Queue Q){

    return (Q.first == -1) ? true : false;

}

bool isQFull(Queue Q){

    return (Q.ctr == MAX) ? true : false;

}

void EnQueue (Queue * Q, int elem){

    if(!isQFull(*Q)){

       LIST temp = AllocSpace(&globalHeap);

       if(temp != -1){
       globalHeap.Nodes[temp].data = elem;
       globalHeap.Nodes[temp].link = -1;
       Q->ctr++;
       
       if(Q->first != -1){
          globalHeap.Nodes[Q->last].link = temp;
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
    Q->first = globalHeap.Nodes[Q->first].link;
    Q->ctr--;
    deallocSpace(&globalHeap, temp);
   }
}

int Front(Queue Q){
    return globalHeap.Nodes[Q.first].data;
}

int Last(Queue Q){
    return globalHeap.Nodes[Q.last].data;
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