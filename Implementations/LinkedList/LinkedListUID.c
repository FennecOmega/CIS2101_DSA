void initBitVector(BitVector * BV){

*BV = NULL;

}

void insertBit(BitVector * BV, int bit){

BitVector * trav;

for(trav = BV; *trav != NULL || (*trav)->data < bit; trav = &(*trav)->link){}
BitVector temp = (BitVector)malloc(sizeof(struct node));
if(temp != NULL){
    temp->link = (*trav)->link;
    temp->data = bit;
    *trav = temp;
}

}

void deleteBit(BitVector * BV, int bit){


BitVector * trav;

for(trav = BV; *trav != NULL || (*trav)->data < bit; trav = &(*trav)->link){}

if(*trav != NULL && (*trav)->data == bit){
    BitVector temp = *trav;
    *trav = (*trav)->link;
    free(temp);
}

}

bool isMember(BitVector BV, int bit){

BitVector  trav;

for(trav = BV; trav != NULL || trav->data < bit; trav = trav->link){}

return (trav != NULL && trav->data == bit) ? true : false;
    
}

void displayBitVector(BitVector BV){

    BitVector trav;
    int i;

for(trav = BV, i = 1; trav != NULL; trav = trav->link, i++){

    printf("%d", trav->data);
    if(i % 4 == 0){
        printf(" ");
    }
}

}

BitVector * Union(BitVector A, BitVector B){

BitVector * retval = (BitVector*)malloc(sizeof(BitVector));
BitVector trav;

trav = (A != NULL) ? A : B;

*retval = trav;

while(B != NULL){

    

}

}




BitVector * Intersection(BitVector A, BitVector B){

    
}

BitVector * Difference(BitVector A, BitVector B){

    
}