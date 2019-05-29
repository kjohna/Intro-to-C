#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

typedef struct Queue
{
    unsigned int length;
    unsigned int capacity;
    int *storage;
} Queue;

/*
    Creates a queue by allocating the appropriate amount of memory for an
    instance of the Queue struct, and initializes all of the fields of the
    struct. Also allocates memory for the queue's storage structure. 
*/
Queue *createQueue(unsigned capacity)
{
    struct Queue *new_queue = malloc(sizeof(Queue));
    new_queue->length = 0;
    new_queue->capacity = capacity;
    new_queue->storage = malloc(sizeof(int) * capacity);
    return new_queue;
}

/*
    Adds the given item to the end of the queue. If the queue does
    not have room, expand the queue's available storage so that it 
    does have room for the additional item.
*/
void enqueue(Queue *q, int item)
{
    // check if there's space
    if (q->length + 1 == q->capacity)
    {
        // if not enough space, resize
        unsigned int new_size = q->capacity + sizeof(int);
        unsigned int old_ptr = q->storage;
        printf("resizing from %d to %d\n", q->capacity, new_size);
        q->storage = realloc(q->storage, new_size);
        printf("old %d, new %d\n", old_ptr, q->storage);
        q->capacity = new_size;
    }
    // add value to end
    q->storage[q->length] = item;
    q->length++;
}

/*
    Removes the item at the front of the queue and returns it. 
    If the queue is empty, this function should return -1.
*/
int dequeue(Queue *q)
{
    // if nothing in the queue, return NULL
    if (!q->length)
    {
        return -1;
    }
    printf("deque!\n");
    unsigned int i;
    // get the item
    int rv = q->storage[0];
    // shift remaining items, decrease length
    for (i = 0; i < q->length; i++)
    {
        q->storage[i] = q->storage[i + 1];
    }
    q->length--;

    return rv;
}

/*
    Frees the memory used to hold the queue instance and its
    associated storage. 
*/
void destroyQueue(Queue *q)
{
    if (q->storage != NULL)
    {
        printf("free storage\n");
        free(q->storage);
    }
    if (q != NULL)
    {
        printf("free queue\n");
        free(q);
    }
}

#ifndef TESTING
int main(void)
{
    Queue *q = createQueue(4);

    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);
    enqueue(q, 5);
    enqueue(q, 6);

    printf("%d\n", dequeue(q));
    printf("%d\n", dequeue(q));
    printf("%d\n", dequeue(q));
    printf("%d\n", dequeue(q));
    printf("%d\n", dequeue(q));
    printf("%d\n", dequeue(q));

    destroyQueue(q);

    return 0;
}
#endif