#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#define MAX 10
#define BV_32 32
#define BV_64 64
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

// STACK START

void initializeStack(Stack *L)
{
	L->top = -1;
}

bool isEmpty(Stack L)
{

	return (L.top == -1) ? true : false;
}
bool isFull(Stack L)
{

	return (L.top == MAX - 1) ? true : false;
}
int isTop(Stack L)
{

	return (!isEmpty(L)) ? L.data[L.top] : 0;
}
void pushStack(Stack *L, int data)
{

	if (!isFull(*L))
	{
		L->data[++L->top] = data;
	}
}
void popStack(Stack *L)
{

	if (!isEmpty(*L))
	{
		L->top--;
	}
}
void makeNull(Stack *L)
{

	L->top = -1;
}

void displayStack(Stack *L)
{

	Stack temp;
	initializeStack(&temp);

	printf("CURRENT STACK\n");
	while (!isEmpty(*L))
	{

		printf("| %5d     |\n", isTop(*L));
		printf("_____________\n");
		pushStack(&temp, isTop(*L));
		popStack(L);
	}

	while (!isEmpty(temp))
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
		while (!isEmpty(*L))
		{

			pushStack(&temp, isTop(*L));
			popStack(L);
		}

		pushStack(L, data);

		while (!isEmpty(temp))
		{
			pushStack(L, isTop(temp));
			popStack(&temp);
		}
	}
}

// END STACK

// QUEUE START

void initQueue(Queue *Q)
{

	Q->first = 0;
	Q->last = (Q->first + MAX - 1) % MAX;
}

bool isQEmpty(Queue Q)
{
	return ((Q.last + 1) % MAX == Q.first) ? true : false;
}

bool isQFull(Queue Q)
{
	return ((Q.last + 2) % MAX == Q.first) ? true : false;
}

int Front(Queue Q)
{
	return Q.data[Q.first];
}
int Last(Queue Q)
{
	return Q.data[Q.last];
}

void EnQueue(Queue *Q, int data)
{
	if (!isQFull(*Q))
	{

		Q->last = (Q->last + 1) % MAX;
		Q->data[Q->last] = data;
	}
}

void DeQueue(Queue *Q)
{

	if (!isQEmpty(*Q))
	{

		Q->first = (Q->first + 1) % MAX;
	}
}

void makeQNull(Queue *Q)
{

	Q->last = (MAX + Q->first - 1) % MAX;
}

void displayQueue(Queue *Q)
{

	Queue temp;
	int ctr;
	initQueue(&temp);

	printf("CURRENT QUEUE\n");
	printf("----------------------------------\n");

	while (!isQEmpty(*Q))
	{
		printf("%d ", Front(*Q));
		EnQueue(&temp, Front(*Q));
		DeQueue(Q);
	}

	printf("\n----------------------------------\n");

	while (!isQEmpty(temp))
	{
		EnQueue(Q, Front(temp));
		DeQueue(&temp);
	}
}

void insertFirst(Queue *Q, int data)
{

	Queue temp;
	int ctr;
	initQueue(&temp);

	if (!isQFull(*Q))
	{
		EnQueue(&temp, data);
		while (!isQEmpty(*Q))
		{
			EnQueue(&temp, Front(*Q));
			DeQueue(Q);
		}

		while (!isQEmpty(temp))
		{
			EnQueue(Q, Front(temp));
			DeQueue(&temp);
		}
	}
}

// END QUEUE

// START UID

void initBitVector(BitVector * BV){

int i;
for(i = 0; i < BV_8; i++){
	(*BV)[i] = 0;
}

}

void insertBit(BitVector * BV, int bit){

if(bit < BV_8 && bit > -1){
	(*BV)[bit] = 1;
}

}

BitVector * Union(BitVector A, BitVector B){

    BitVector * C = (BitVector*)malloc(sizeof(A[0])*BV_8);
	initBitVector(C);
    int i;
	for(i = 0; i < BV_8; i++){
		(*C)[i] = A[i] || B[i]; 
	}

	return C;
}

BitVector * Intersection(BitVector A, BitVector B){

    BitVector * C = (BitVector*)malloc(sizeof(A[0])*BV_8);
	initBitVector(C);
    int i;
	for(i = 0; i < BV_8; i++){
		(*C)[i] = A[i] && B[i]; 
	}

	return C;
}

BitVector * Difference(BitVector A, BitVector B){

    BitVector * C = (BitVector*)malloc(sizeof(A[0])*BV_8);
	initBitVector(C);
    int i;
	for(i = 0; i < BV_8; i++){
		(*C)[i] = A[i] > B[i];
	}

	return C;
}

void displayBitVector(BitVector BV){

int i;

printf("Bit Vector: ");

for(i = 0; i < BV_8; i++){

	printf("%d", BV[i]);
	if((i+1) % 4 == 0){
		printf(" ");
	}
}

printf("\n");

}

//END UID