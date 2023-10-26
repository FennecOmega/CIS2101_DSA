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

void deleteBit(BitVector * BV, int bit){
   if(bit < BV_8 && bit > -1){
	(*BV)[bit] = 0;
   }
}

bool isMember(BitVector BV, int bit){
return BV[bit];
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
