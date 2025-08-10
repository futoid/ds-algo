#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 5

// enq - O(1)
// deq - O(1)

typedef struct
{
    int arr[MAX_SIZE];
    int front, rear;
} Queue;

void initialize(Queue *q)
{
    q->front = -1;
    q->rear = 0;
}

bool isFull(Queue *q)
{
    return q->rear == MAX_SIZE + 1;
}

bool isEmpty(Queue *q)
{
    return q->front == q->rear - 1;
}

void enq(int num, Queue *q)
{
    if (isFull(q))
    {
        printf("Q is full\n");
        return;
    }

    q->arr[q->rear++] = num;
    printf("%d inserterd in Q\n", num);
}

void deq(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Q is empty\n");
        return;
    }

    int removedNum = q->arr[++q->front];

    printf("%d is removed from Q\n", removedNum);
}

void printQ(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Q is empty\n");
        return;
    }

    int start = q->front + 1;
    int end = q->rear;

    printf("Elements in Q: ");
    while (start < end)
    {
        printf("%d ", q->arr[start++]);
    }
    printf("\n");
}

int main()
{
    Queue queue;
    Queue *q = &queue;

    initialize(q);
    printQ(q);
    enq(1, q);
    printQ(q);
    enq(1, q);
    enq(7, q);
    printQ(q);
    enq(6, q);
    enq(5, q);
    deq(q);
    printQ(q);
    enq(4, q);
    deq(q);
    enq(3, q);
    enq(2, q);
    deq(q);
    printQ(q);

    return 0;
}