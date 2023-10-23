#include <stdio.h>
#include <stdlib.h>

typedef struct __element {
    int data;
    struct __element *next;
} element;

// Add a new element to the end of the list.
int
add(element **_head, int _data)
{
    element *n = malloc(sizeof(element));
    element *last = NULL;
    if (n == NULL) {
        return -1;
    }
    n->data = _data;

    if (*_head == NULL) {
        *_head = n;
        return 0;
    }

    for (last = *_head; last->next != NULL; last = last->next) {}
    last->next = n;

    return 0;
}

// Removes an item from the list.
// TODO: It is inefficient af, but it's simple :)
int
delete(element **_head, int _data)
{
    element *e = NULL;
    element *b = NULL;

    for (e = *_head; e != NULL; e = e->next)
        if (e->data == _data)
            break;

    if (e == NULL)
        return -1;

    for (b = *_head; b->next != e; b = b->next) {}
    b->next = e->next;
    free(e);

    return 0;
}

// Finds the first occurrence of the value.
const element *
find(const element *_head, int _data)
{
    const element *e = NULL;
    for (e = _head; e != NULL; e = e->next) {
        if (e->data == _data)
            return e;
    }
    return NULL;
}

int
main(void)
{
    element *head = NULL;
    const element *e = NULL;

    // Add a bunch of elements to the list.
    if (add(&head, 10) < 0)
        fprintf(stderr, "ERROR\n");
    if (add(&head, 30) < 0)
        fprintf(stderr, "ERROR\n");
    if (add(&head, 10) < 0)
        fprintf(stderr, "ERROR\n");
    if (add(&head, 20) < 0)
        fprintf(stderr, "ERROR\n");

    // Find the 20 in the list.
    if ((e = find(head, 20)) != NULL)
        printf("Found: %d\n", e->data);
    else
        printf("Failed to find 20\n");

    // Removes the 20 from the list and tries to remove it again, 
    // which should fail.
    if (delete(&head, 20) < 0)
        printf("Failed to remove 20\n");
    if (delete(&head, 20) < 0)
        printf("Failed to remove 20\n");

    // Try to find the 20 a second time, this should fail.
    if ((e = find(head, 20)) != NULL)
        printf("Found: %d\n", e->data);
    else
        printf("Failed to find 20\n");

    return 0;
}
