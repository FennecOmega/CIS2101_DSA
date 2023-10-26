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