//
// Created by Kirsten S. on 2019-07-04.
//
#include <stdio.h>
#ifndef STACKS_STACKS_N_QUEUES_H
#define STACKS_STACKS_N_QUEUES_H

#endif //STACKS_STACKS_N_QUEUES_H
#define MAX 100


typedef  struct stak {
    int stack_size;
    int stack_data[MAX];
    int top1;
    int top2;

} Stack;

/* Stack Operations
 * create() - creates 2 stacks
 * pop() - removes an element on top of the stack and returns it
 * push() - adds an element on top of the stack
 * top() - checks the value on top of the stack
 * isEmpty() - checks if stack is empty
 * isFull() - checks if stack is full
 * */
Stack createStack(int size) {
    Stack stack;
    if (size >= 1) {
        stack.stack_size = size;
        stack.top1 = -1;
        stack.top2 = size;
    } else
        printf("Size is too small for two stacks.\n");
    return stack;
}

int isFull1(Stack stack) {
    if (stack.top1+1 == stack.top2 || stack.top1 == stack.stack_size-1)
        return 1;
    else
        return 0;
}

int isFull2(Stack stack) {
    printf("%d , %d\n", stack.top2-1, stack.top1);
    if (stack.top2-1 == stack.top1 || stack.top2 == 0)
        return 1;
    else
        return 0;
}

void push1(int data, Stack *stack) {

    if (!(isFull1(*stack))) {
        (stack->top1)++;
        stack->stack_data[stack->top1] = data;
    }
    else
        printf("Stack 1 is full.\n");
}
void push2(int data, Stack *stack) {
    if (!(isFull2(*stack))) {
        (stack->top2)--;
        stack->stack_data[stack->top2] = data;
    }
    else
        printf("Stack 2 is full.\n");
}

int pop1(Stack *stack) {
    int num;
    if (stack->top1 == -1) {
        printf("Stack underflow\n");
        return -1;
    } else {
        num = stack->stack_data[stack->top1];
        stack->top1--;
        return num;
    }
}

int pop2(Stack *stack) {
    int num;
    if (stack->top2 > stack->stack_size) {
        printf("Stack underflow\n");
        return -1;
    } else {
        num = stack->stack_data[stack->top2];
        stack->top2++;
        return num;
    }
}

int isEmpty1(Stack stack) {
    if (stack.top1 == -1)
        return 1;
    else
        return 0;
}

int isEmpty2(Stack stack) {
    if (stack.top2 == stack.stack_size)
        return 1;
    else
        return 0;
}

int top1(Stack stk) {
    if (stk.top1 != -1 || stk.top1 != stk.stack_size)
        return stk.stack_data[stk.top1];
    else
        return -1;
}

int top2(Stack stk) {
    if (stk.top2 != stk.stack_size || stk.top1 != -1)
        return stk.stack_data[stk.top2];
    else
        return -1;
}

void display1(Stack stk) {
    int i;
    for (i=stk.top1; i >= 0; i--)
        printf("%d @ idx %d\n", stk.stack_data[i], i);
    printf("\n");
}

void display2(Stack stk) {
    int i;
    for (i=stk.top2; i < stk.stack_size; i++)
        printf("%d @ idx %d\n", stk.stack_data[i], i);
    printf("\n");
}
