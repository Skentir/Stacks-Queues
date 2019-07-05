#include <stdio.h>
#include "stacks.h"
#include "queues.h"

int main()
{ /*
#if 1
    int s_size;
    printf("Creating two stacks . . .\n");
    printf("Please enter a size: ");

    do {
        scanf("%d", &s_size);
    } while(s_size < 2);


    Stack stk = createStack(s_size);
    printf("Stacks created!\n\n");
    push1(1, &stk);
    push1(2, &stk);
//	push2(&stk, 5);
//	push2(&stk, 6);
//	push2(&stk, 7);

    push1(8, &stk);

    printf("\nStack 1:");
    display1(stk);
    printf("\nStack 2:");
    display2(stk);

    // if you wanna both ss to be empty pop everything
    //  printf("\n%d", pop1(&stk));
    //printf("\n%d", pop1(&stk));
//    printf("\n%d", pop2(&stk));
//    printf("\n%d", pop2(&stk));


    int s1_empty = isEmpty1(stk);
    int s1_full = isFull1(stk);

    int s2_empty = isEmpty2(stk);
    int s2_full = isFull2(stk);
    printf("\nStack 1: %d , %d", s1_empty,s1_full);
    printf("\nStack 2: %d , %d\n", s2_empty, s2_full);

#endif

#if 0 */
    int q_size;
    printf("Creating queue . . .\n");
    printf("Please enter a size: ");

	do {
    	scanf("%d", &q_size);
   } while(q_size < 2);


    Queue que = createQueue(q_size);
    printf("Queue created!\n\n");
    enqueue(1, &que);
		display1(que.queue);
	enqueue(2,&que);
	enqueue(3, &que);
		display1(que.queue);
	int num = dequeue(&que);
		display2(que.queue);


	int q_isFull = isFull(que);
	int q_isEmpty = isEmpty(que);
//	int front = front(que); FIX!!
	printf("\n\n Empty: %d, Full: %d, dequeue num = %d\n", q_isEmpty, q_isFull, num);
//#endif


    return 0;
}
