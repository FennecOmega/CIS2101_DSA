#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define BV_64 64
#define BV_32 32
#define BV_8 8

typedef unsigned char BitVector;
// typedef unsigned int BitVector;
// typedef unsigned long long int BitVector;

void initBitVector(BitVector * BV){

*BV = 0;

}

void insertBit(BitVector * BV, int bit){

*BV = *BV | 1 << bit;

}

void deleteBit(BitVector * BV, int bit){

*BV = *BV & ~(1 << bit);

}

bool isMember(BitVector BV, int bit){

return BV & (1 << bit);

}

void displayBitVector(BitVector BV){

    BitVector mask;
    int i;

    for(mask = 1, i = 1; mask != 0; mask <<= 1, i++){
        printf("%d", (BV & mask) ? 1 : 0);
        if(i % 4 == 0){
            printf(" ");
        }
    }
    printf("\n");

}

BitVector * Union(BitVector A, BitVector B){

  BitVector * C = (BitVector*)malloc(sizeof(BitVector));
  *C = (A | B);
  return C;

}

BitVector * Intersection(BitVector A, BitVector B){

    BitVector * C = (BitVector*)malloc(sizeof(BitVector));
    *C = A & B;
    return C;

    
}

BitVector * Difference(BitVector A, BitVector B){

    BitVector * C = (BitVector*)malloc(sizeof(BitVector));
    *C = A & ~(B);
    return C;
    
}

void BitVectorTest(){

BitVector A, B, U;

initBitVector(&A);
initBitVector(&B);
initBitVector(&U);


BitVector * C;

int i;
for(i = 0; i < BV_8; i++){
    insertBit(&U, i);
}

printf("Universal Bit Vector:\n\n");
displayBitVector(U);

insertBit(&A, 1);
insertBit(&A, 7);
insertBit(&A, 4);
insertBit(&A, 5);
insertBit(&A, 2);

insertBit(&B, 4);
insertBit(&B, 3);
insertBit(&B, 5);
insertBit(&B, 6);
insertBit(&B, 2);

printf("Existing Bit Vectors:\n\n");
displayBitVector(A);
displayBitVector(B);

deleteBit(&B, 3);
deleteBit(&A, 1);

printf("Existing Bit Vectors:\n\n");
displayBitVector(A);
displayBitVector(B);



printf((isMember(A, 7)) ? "7 is a member of A\n" : "7 is not a member of A\n");
printf((isMember(A, 3)) ? "3 is a member of A\n" : "3 is not a member of A\n");
printf((isMember(B, 5)) ? "5 is a member of B\n" : "5 is not a member of B\n");
printf((isMember(B, 1)) ? "1 is a member of B\n" : "1 is not a member of B\n");

C = Union(A, B);
printf("Union Bit Vector between A and B:\n\n");
displayBitVector(*C);

C = Intersection(A, B);
printf("Intersection Bit Vector between A and B:\n\n");
displayBitVector(*C);

C = Difference(A, B);
printf("Difference Bit Vector between A and B:\n\n");
displayBitVector(*C);
    
}