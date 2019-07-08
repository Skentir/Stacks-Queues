#include <stdlib.h>
#include <stdio.h>

typedef struct que { ;
    int size;
    int front;
    int rear;
    int itemCount;
    int *intArray;
}Queue;

Queue createQ(int size)
{
    Queue q;
    if (size >= 2) {
        q.intArray = (int*)malloc(size * sizeof(int));
        q.size = size;
        q.front = 0;
        q.rear = -1;
        q.itemCount = 0;

    } else
        printf("Size too small!\n");
    return q;
}
int peek(Queue Q) {
    return Q.intArray[Q.front];
}

int size(Queue Q) {
    return Q.itemCount;
}

int isEmptyQ(Queue Q) {
    return !size(Q);
}

int front(Queue Q) {
    if (isEmptyQ(Q))
        return 1;
    else
        return Q.intArray[Q.front];
}

int isFullQ(Queue Q) {
    if (Q.itemCount == Q.size)
        return 1;
    else
        return 0;
}

void enqueue(int data, Queue *Q) {

    if(!isFullQ(*Q)) {
        Q->rear = (Q->rear + 1) % Q->size;
        Q->intArray[Q->rear] = data;
   //     printf("enqueue %d at idx %d\n", data, Q->rear);
        Q->itemCount++;
    } else
        printf("Stack Overflow!\n");
}

int dequeue(Queue *Q) {
    int x = -1;
    if (!isEmptyQ(*Q)) {
        x = Q->intArray[Q->front];
        Q->front = (Q->front+1)% Q->size;
   //     printf("dequeue %d at idx %d\n", Q->intArray[Q->front], Q->front);
        Q->itemCount--;
        return  x;
    } else
        printf("Stack underflow!\n");
    return x;
}
/*
void displayQ(Queue Q) {
    int;

} */

