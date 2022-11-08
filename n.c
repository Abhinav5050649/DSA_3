#include "stdio.h"
#include "stdint.h"
#include "stdlib.h"
#include "string.h"

typedef struct Node
{
    int data;
    Node* next;
}
Node;

Node* newNode(int a)
{
    Node *n = malloc(sizeof(Node));
    n->data = a;
    n->next = NULL;

    return n;
}

int main()
{

    return 0;
}