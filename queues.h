//
// Created by Kirsten S. on 2019-07-04.
//
#include <stdio.h>

typedef struct que {
    Stack queue;
    int queue_size;
} Queue;

/* Queue Operations
 * enqueue() - removes an element from the queue and returns it
 * dequeue() - adds an element on top of the queue
 * front() - checks the oldest element of the queue
 * isEmpty() - checks if stack is empty
 * isFull() - checks if stack is full
 * */
Queue createQueue(int size) {
    Queue Q; Stack stack;
    if (size >= 2) {
        Q.queue_size = size;
        stack = createStack(size * 2);
        Q.queue = stack;
    } else
        printf("Size is too small for a queue!\n");
    return Q;
}

void enqueue(int data, Queue *Q) {
    int i;
    /* If contents of stack 1 are moved to stack 2  because of dequeue*/
    if (!(isEmpty2(Q->queue)) && Q->queue.top1 + 1 != Q->queue_size) {
        for (i = Q->queue.top2; i < Q->queue.stack_size ; i++)
            push1(pop2(&Q->queue), &Q->queue);
        push1(data, &Q->queue);
    } /* If stack 1 is not yet full, then add it */
    else if (!(isFull1(Q->queue)) && Q->queue.top1 + 1 != Q->queue_size)
    {
        push1(data, &Q->queue);
    } else
        printf("Queue is full\n");
}
int dequeue(Queue *Q) {
    int i;
    /* If dequeue is repeatedly called */
    if (!(isEmpty2(Q->queue)))
    {
        return pop2(&Q->queue);
    } else {
        /* If stack 1 is not empty, push all of it to stack 2 and pop the last elemennt */
        if (!(isEmpty1(Q->queue)))
        {
            for (i = Q->queue.top1; i >= 0; i--)
                push2(pop1(&Q->queue), &Q->queue);
            return pop2(&Q->queue);
        } else
            return -1;
    }
}

int front(Queue Q) { // FIX!!
    int i;
    /* If dequeue is repeatedly called */
    if (!(isEmpty2(Q.queue))) {
        return top2(Q.queue);
    } else {
        /* If stack 1 is not empty, push all of it to stack 2 and pop the last elemennt */
        if (!(isEmpty1(Q.queue))) {
            for (i = Q.queue.top1; i >= 0; i--)
                push2(pop1(&Q.queue), &Q.queue);
            return top2(Q.queue);
        } else
            return -1;
    }
}

int isFull(Queue Q) {
    if (isFull1(Q.queue))
        return 1;
    else return 0;
}

int isEmpty(Queue Q) {
    if (isEmpty1(Q.queue))
        return 1;
    else
        return 0;
}
