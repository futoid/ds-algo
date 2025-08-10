#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 10

// stack implementation using array

typedef struct
{
    int arr[MAX_SIZE];
    int top;
} Stack;

void initialize(Stack *stack)
{
    stack->top = -1;
}

bool isEmpty(Stack *stack)
{
    return stack->top == -1;
}

bool isFull(Stack *stack)
{
    return stack->top == MAX_SIZE - 1;
}

void push(int num, Stack *stack)
{
    if (isFull(stack))
    {
        printf("stack overflown\n");
        return;
    }

    stack->arr[++stack->top] = num;
    printf("pushed %d in stack\n", num);
}

void pop(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("stack underflow\n");
        return;
    }
    int poppedNum = stack->arr[stack->top--];
    printf("popped %d from stack\n", poppedNum);
}

void peak(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("stack is empty\n");
        return;
    }

    printf("peak element is %d\n", stack->arr[stack->top]);
}

int main()
{
    Stack stack;

    Stack *st = &stack;

    initialize(st);
    pop(st);
    peak(st);
    push(10, st);
    push(1, st);
    push(40, st);
    pop(st);
    push(70, st);
    push(12, st);
    push(30, st);
    push(19, st);
    pop(st);
    push(44, st);
    push(42, st);
    push(4, st);
    push(1, st);
    push(54, st);
    pop(st);
    push(2, st);
    push(24, st);
    push(22, st);

    return 0;
}