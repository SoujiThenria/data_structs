#include <stdio.h>
#include <stdlib.h>

typedef struct queue {
    int *data;
    size_t length;
    size_t elements;
} queue;

void
push(queue *q, int v)
{
    if (q->length == q->elements) {
        q->data = realloc(q->data, q->length + 10);
        q->length+=10;
    }
    q->data[q->elements] = v;
    q->elements++;
}

int
pop(queue *q)
{
    int r, i;

    if (q->elements == 0)
        return 0;

    r = q->data[0];
    q->elements--;

    for (i = 0; i < q->elements; i++)
        q->data[i] = q->data[i+1];

    return r;
}

int
main(void)
{
    printf("A queue implementation in C\n");
    queue q;
    q.data = calloc(10, sizeof(int));
    q.length = 10;
    q.elements = 0;

    push(&q, 10);
    push(&q, 20);
    push(&q, 30);
    push(&q, 40);

    printf("10 - %d\n", pop(&q));
    printf("20 - %d\n", pop(&q));
    printf("30 - %d\n", pop(&q));
    push(&q, 11);
    push(&q, 12);
    printf("40 - %d\n", pop(&q));
    printf("11 - %d\n", pop(&q));
    printf("12 - %d\n", pop(&q));
    printf("0 - %d\n", pop(&q));

    return 0;
}
