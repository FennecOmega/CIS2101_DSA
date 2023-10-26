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

//INCLUDE PROTOTYPES AND IMPLEMENTATION FILES

#include ".\Implementations\Prototypes.h"
#include ".\LinkedList\LinkedListQueues.c"
#include ".\LinkedList\LinkedListStacks.c"
#include ".\LinkedList\LinkedListUID.c"

//END INCLUDE

