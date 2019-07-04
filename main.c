#include <stdio.h>
#include "stacks.h"
#include "queues.h"

int main() {
    int stack_size;
    printf("Creating two stacks . . .\n");
    printf("Please enter a size: ");

    do {
        scanf("%d", &stack_size);
    } while(stack_size < 2);

    Stack stk = create(stack_size);
    printf("Stacks created!\n");
    push1(1, &stk);
  //  push2(2, &stk);
  //  printf("After push %d",);
    push1(3, &stk);
 //   push2(4, &stk);
    printf("Pushed\n");
    push1(4, &stk);
 //   push2(5, &stk);

    // Problem here!!
    display1(stk);
    display2(&stk);

 //   pop1(&stk);
  //  pop2(&stk);

    display1(stk);
    display2(&stk);

    int s1_empty = isEmpty1(&stk);
    int s1_full = isFull1(&stk);

    int s2_empty = isEmpty2(&stk);
    int s2_full = isFull2(&stk);
    printf("Stack1: %d , %d\nStack2: %d , %d\n", s1_empty,s1_full,s2_empty, s1_full);
    return 0;
}