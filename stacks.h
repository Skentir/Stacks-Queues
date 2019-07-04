//
// Created by Kirsten S. on 2019-07-04.
//
#include <stdio.h>
#ifndef STACKS_STACKS_N_QUEUES_H
#define STACKS_STACKS_N_QUEUES_H

#endif //STACKS_STACKS_N_QUEUES_H

typedef  struct stk {
    int size;
    int *stack_data;
    int top1;
    int top2;

} Stack;

typedef struct que {
    int QMAX;
    int *queue_data;
    int front;
    int back;
    int numInQueue;
} Queue;

/* Stack Operations
 * create() - creates 2 stacks
 * pop() - removes an element on top of the stack and returns it
 * push() - adds an element on top of the stack
 * top() - checks the value on top of the stack
 * isEmpty() - checks if stack is empty
 * isFull() - checks if stack is full
 * */
Stack create(int size) {
    Stack stack; int arr[size];
    if (size > 1) {
        stack.size = size;
        stack.stack_data = arr;
        stack.top1 = -1;
        stack.top2 = size;
    } else
        printf("Size is too small for two stacks.\n");
    return stack;
}
void push1(int data, Stack *stack) {
    if (stack->top1 < stack->top2 && stack->top1 < stack->size) {
        (stack->top1)++;
        stack->stack_data[stack->top1] = data;
        printf("%d at top %d\n",  stack->stack_data[stack->top1], stack->top1);
    }
    else
        printf("Stack 1 is full.\n");
}
void push2(int data, Stack *stack) {
    if (stack->top2 > stack->top1 && stack->top2 >= 0) {
        (stack->top2)--;
        stack->stack_data[stack->top2] = data;
        printf("%d at top %d\n",  stack->stack_data[stack->top2], stack->top2);
    }
    else
        printf("Stack 2 is full.\n");
}

int pop1(Stack *stack) {
    int num;
    if (stack->top1 == -1) {
        printf("Stack underflow\n");
        return NULL;
    } else {
        num = stack->stack_data[stack->top1];
        stack->top1--;
        return num;
    }
}

int pop2(Stack *stack) {
    int num;
    if (stack->top2 > stack->size) {
        printf("Stack underflow\n");
        return NULL;
    } else {
        num = stack->stack_data[stack->top2];
        stack->top2++;
        return num;
    }
}

int isFull1(Stack *stack) {
    if (stack->top1 == -1)
        return 1;
    else
        return 0;
}

int isFull2(Stack *stack) {
    if (stack->top2 == stack->size-1)
        return 1;
    else
        return 0;
}

int isEmpty1(Stack *stack) {
    if (stack->top1 == stack->top2)
        return 1;
    else if (stack->top1 > stack->top2)
        return 1;
    else if(stack->top1 >= stack->size)
        return 1;
    else
        return 0;
}

int isEmpty2(Stack *stack) {
    if (stack->top2 == stack->top1)
        return 1;
    else if(stack->top2 < stack->top1)
        return 1;
    else if (stack->top2 < 0)
        return 1;
    else
        return 0;
}

void display1(Stack stk) {
    int i;
    for (i=stk.top1; i >= 0; i--)
        printf("%d @ idx %d\n", stk.stack_data[i], i);
    printf("\n");
}

void display2(Stack *stk) {
    int i;
    for (i=stk->top2; i < stk->size; i++)
        printf("%d @ idx %d\n", stk->stack_data[i], i);
    printf("\n");
}