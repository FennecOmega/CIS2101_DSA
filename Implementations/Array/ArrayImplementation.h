#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#define MAX 10
#define BV_64 64
#define BV_32 32
#define BV_8 8

// needed function operations: PUSH,POP, TOP, EMPTY, FULL, INITIALIZE, MAKENULL(?)

// DATAYPE DEFINITIONS START

typedef struct ArrayStack
{
	int data[MAX];
	int top;
} Stack;

typedef struct ArrayQueue
{
	int first;
	int last;
	int data[MAX];

} Queue;

typedef int BitVector[BV_8];

typedef int Dictionary[MAX];

// END DATATYPE DEFINITIONS

// INCLUDE FILES

#include "..\Prototypes.h"
#include ".\ArrayQueues.c"
#include ".\ArrayStacks.c"
#include ".\ArrayUID.c"

// END INCLUDE
