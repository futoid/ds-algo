#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insert(Node **head, int data)
{
    Node *node = createNode(data);
    node->next = *head;
    *head = node;
    printf("Inserted %d\n", data);
}

void insertAtEnd(Node **head, int data)
{
    Node *node = createNode(data);
    if (*head == NULL)
    {
        *head = node;
        return;
    }
    Node *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = node;
    printf("Inserted %d\n at the end", data);
}

void insertAtN(Node **head, int data, int n)
{
    if (n == 0)
    {
        insert(head, data);
        return;
    }
    Node *temp = *head;
    int i = 0;
    while (i < n - 1 && temp != NULL)
    {
        temp = temp->next;
        i++;
    }
    if (temp == NULL)
    {
        printf("n out of range\n");
        return;
    }
    Node *node = createNode(data);
    node->next = temp->next;
    temp->next = node;
    printf("Inserted %d at %d\n", data, n);
}

void delete(Node **head)
{
    if (*head == NULL)
    {
        printf("LL is empty\n");
        return;
    }
    Node *temp = *head;
    printf("Deleted first element %d\n", temp->data);
    *head = temp->next;
    free(temp);
}

void deleteAtEnd(Node **head)
{
    if (*head == NULL)
    {
        printf("LL is empty\n");
        return;
    }
    if ((*head)->next == NULL)
    {
        free(*head);
        *head = NULL;
        return;
    }
    Node *temp = *head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    printf("Deleted end element %d\n", temp->next->data);
    free(temp->next);
    temp->next = NULL;
}

void deleteAtN(Node **head, int n)
{
    if (*head == NULL)
    {
        printf("LL is empty\n");
        return;
    }
    if (n == 0)
    {
        delete(head);
        return;
    }
    Node *temp = *head;
    int i = 0;
    while (i < n - 1 && temp->next != NULL)
    {
        temp = temp->next;
        i++;
    }
    if (temp->next == NULL)
    {
        printf("n out of range\n");
        return;
    }
    Node *toDelete = temp->next;
    printf("Deleted %d at %dpost\n", temp->data, n);
    temp->next = toDelete->next;
    free(toDelete);
}

void printLL(Node *head)
{
    Node *temp = head;
    printf("LL: [");
    while (temp)
    {
        printf("%d", temp->data);
        if (temp->next)
            printf(" -> ");
        temp = temp->next;
    }
    printf("]\n");
}

int main()
{
    Node *head = NULL;
    Node **h = &head;

    insert(h, 10);
    insert(h, 20);
    insertAtEnd(h, 30);
    insertAtN(h, 25, 2);
    printLL(head);

    delete(h);
    printLL(head);

    deleteAtEnd(h);
    printLL(head);

    deleteAtN(h, 1);
    printLL(head);

    insert(h, 1);
    printLL(head);

    deleteAtN(h, 1);
    printLL(head);

    return 0;
}