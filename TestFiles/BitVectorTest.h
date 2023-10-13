#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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


C = Union(A, B);
printf("Union Bit Vector between A and B:\n\n");
displayBitVector(C);

C = Intersection(A, B);
printf("Intersection Bit Vector between A and B:\n\n");
displayBitVector(C);

C = Difference(A, B);
printf("Difference Bit Vector between A and B:\n\n");
displayBitVector(C);
    
}