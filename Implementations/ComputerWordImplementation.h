#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define BV_64 64
#define BV_32 32
#define BV_8 8

typedef unsigned char BitVector;

void initBitVector(BitVector * BV){

*BV = 0;

}

void insertBit(BitVector * BV, int bit){

BitVector mask;
mask = 1 << bit;
*BV = *BV | mask;

}

void displayBitVector(BitVector BV){

    BitVector mask;
    int i;

    for(mask = 1 << BV_8 - 1, i = 1; mask != 0; mask >>= 1, i++){
        printf("%d", BV | mask);
        if(i % 4 == 0){
            printf(" ");
        }
    }

}

BitVector * Union(BitVector A, BitVector B){

  BitVector * C = (BitVector*)malloc(sizeof(BitVector));
  *C = A | B;
  return C;

}

BitVector * Intersection(BitVector A, BitVector B){

    BitVector * C = (BitVector*)malloc(sizeof(BitVector));
    *C = A & B;
    return C;

    
}

BitVector * Difference(BitVector A, BitVector B){

    BitVector * C = (BitVector*)malloc(sizeof(BitVector));
    *C = A & B;
    return C;
    
}