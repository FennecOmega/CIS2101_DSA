
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

//temporary fix for BitVector issue
typedef unsigned char BitVector;

// INCLUDE FILES

#include "..\Prototypes.h"
#include ".\CursorUtilities.c"
#include ".\CursorStacks.c"
#include ".\CursorQueues.c"

// END INCLUDE