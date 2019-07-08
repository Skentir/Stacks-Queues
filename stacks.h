//
// Created by Kirsten S. on 2019-07-07.
//
#include "queues.h"

typedef  struct stk {
    Queue que1;
    Queue que2;
} Stack;

Stack createS(int size) {
    Stack s;
    if (size >=1) {
      s.que1 = createQ(size);
      s.que2 = createQ(size);
    } else
        printf("Size too small!\n");
    return s;
}

void push(int data, Stack *S) {
    if (!(isFullQ(S->que1))) {
        enqueue(data, &S->que1);
    }
    else
        printf("Queue is full!\n");
}

int pop (Stack *S) {
    Queue buffer;
    int x;
    if (!(isEmptyQ(S->que1))) {
        while(S->que1.itemCount > 1) {
            enqueue(x = dequeue(&S->que1), &S->que2);
        }
        buffer = S->que1;
        S->que1 = S->que2;
        S->que2 = buffer;
       // printf("front %d\n", S->que2.intArray[S->que2.front]);
        return dequeue(&S->que2);
    } else
        printf("Stack underflow!");
    return -1;
}

int isEmpty(Stack S) {
    if(isEmptyQ(S.que1))
        return 1;
    else
        return 0;
}

int isFull(Stack S) {
    if(isFullQ(S.que1))
        return 1;
    else
        return 0;
}


void display(Stack S) {
    while (!(isEmptyQ(S.que1))) {
        printf("%d\n", dequeue(&S.que1));
    }
}