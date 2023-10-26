void initQueue(Queue * Q){

Q->first = NULL;
Q->last = NULL;
Q->ctr = 0;

}

bool isQEmpty(Queue Q){

    return (Q.first == NULL) ? true : false;

}

bool isQFull(Queue Q){

    return (Q.ctr == MAX) ? true : false;

}

void EnQueue (Queue * Q, int elem){

    if(!isQFull(*Q)){

       LIST temp = (LIST)malloc(sizeof(struct node));

       if(temp != NULL){
       temp->link = NULL;
       temp->data = elem;
       Q->ctr++;
       
       if(Q->first != NULL){
          Q->last->link = temp;
          Q->last = temp;
       }else{
        Q->first = temp;
        Q->last = temp;
       }

    }

    }
}

void DeQueue(Queue * Q){
   if(!isQEmpty(*Q)){
    LIST temp = Q->first;
    Q->first = Q->first->link;
    Q->ctr--;
    free(temp);
   }
}

int Front(Queue Q){
    return (Q).first->data;
}

int Last(Queue Q){
    return (Q).last->data;
}

void displayQueue(Queue * Q)
{

    Queue temp;
    initQueue(&temp);

    printf("CURRENT QUEUE\n");
    printf("----------------------------------\n");

    while (Q->ctr > 0)
    {

        
        printf("%d ", Front(*Q));
        EnQueue(&temp, Front(*Q));
        DeQueue(Q);
    }

    printf("\n----------------------------------\n");

    while (temp.ctr > 0)
    {
        EnQueue(Q, Front(temp));
        DeQueue(&temp);
    }
}

void makeQNull(Queue * Q)
{

    if (!isQEmpty(*Q))
    {
        while (Q->ctr > 0)
        {
            DeQueue(Q);
        }
    }
}

void insertFirst(Queue * Q, int data)
{

    Queue temp;
    initQueue(&temp);
    if (!isQFull(*Q))
    {
        EnQueue(&temp, data);

        while (Q->ctr > 0)
        {

            EnQueue(&temp, Front(*Q));
            DeQueue(Q);
        }
        
        while (temp.ctr > 0)
        {
            EnQueue(Q, Front(temp));
            DeQueue(&temp);
        }
    }
}