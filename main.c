#include "stacks.h"

int main() {
    /* insert 5 items */
    Stack pika = createS(6);
    push(1, &pika);
    push(2, &pika);
    push(3, &pika);
    push(4, &pika);
    push(5, &pika);
    display(pika);

    printf("\n\nPop 5 \n");
    int x = pop(&pika);
    int y = pop(&pika);
    printf("x: %d, y: %d\n", x, 0);
    display(pika);

return 0;
}