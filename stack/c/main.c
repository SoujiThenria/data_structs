#include <stdio.h>
#include <stdlib.h>

typedef struct __stack_element {
    int data;
    struct __stack_element *next;
} element;

int 
push(element **_head, int _data)
{
    element *new_element = calloc(1, sizeof(element));
    if (new_element == NULL) {
        return -1;
    }
    new_element->data = _data;
    new_element->next = *_head;
    *_head = new_element;
    return 0;
}

element *
pop(element **_head)
{
    if (*_head == NULL) {
        return NULL;
    }

    element *e = *_head;
    *_head = e->next;
    return e;
}

int
main(void)
{
    printf("C-Program implementing a stack\n");

    element *stack_head = NULL;

    if (push(&stack_head, 10) < 0)
        fprintf(stderr, "ERROR: cannot push\n");
    if (push(&stack_head, 20) < 0)
        fprintf(stderr, "ERROR: cannot push\n");
    if (push(&stack_head, 30) < 0)
        fprintf(stderr, "ERROR: cannot push\n");
    if (push(&stack_head, 20) < 0)
        fprintf(stderr, "ERROR: cannot push\n");
    if (push(&stack_head, 50) < 0)
        fprintf(stderr, "ERROR: cannot push\n");

    for (element *i = pop(&stack_head); i != NULL; i = pop(&stack_head))
        printf("pop: %d\n", i->data);

    return 0;
}
