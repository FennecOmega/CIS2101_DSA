#ifndef Prototypes
#define Prototypes

//stacks
void initializeStack(Stack *L);
bool isEmpty(Stack L);
bool isFull(Stack L);
int isTop(Stack L);
void pushStack(Stack *L, int data);
void popStack(Stack *L);
void makeNull(Stack *L);
void displayStack(Stack *L);
void insertBottom(Stack *L, int data);

//queues
void initQueue(Queue * Q);
bool isQEmpty(Queue Q);
bool isQFull(Queue Q);
void EnQueue (Queue * Q, int elem);
void DeQueue(Queue * Q);
int Front(Queue Q);
int Last(Queue Q);
void displayQueue(Queue * Q);
void makeQNull(Queue * Q);
void insertFirst(Queue * Q, int data);

// UID
void initBitVector(BitVector * BV);
void insertBit(BitVector * BV, int bit);
void deleteBit(BitVector * BV, int bit);
bool isMember(BitVector BV, int bit);
void displayBitVector(BitVector BV);
BitVector * Union(BitVector A, BitVector B);
BitVector * Intersection(BitVector A, BitVector B);
BitVector * Difference(BitVector A, BitVector B);

#endif