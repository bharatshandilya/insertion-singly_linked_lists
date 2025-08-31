#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* link;
};
typedef struct node node;

void TraverseList(node * p)
{
    while(p != NULL)
    {
    printf("%d\n", p -> data);
    p = p -> link;
    }
}

node* insertAtFront(node* head, int data)
{
    node* ptr = (node*) malloc (sizeof(node));
    ptr -> link = head;
    ptr -> data = data;
    head = ptr;
    return head;
}

int main()
{
    node * head = (node*) malloc (sizeof(node));
    node * second = (node*) malloc (sizeof(node));
    node * third = (node*) malloc (sizeof(node));
    node * last = (node*) malloc (sizeof(node));
    head -> data = 10;
    head -> link = second;
    second -> data = 20;
    second -> link = third;
    third -> data = 30;
    third -> link = last;
    last -> data = 40;
    last -> link = NULL;
    //Before Insertion
    TraverseList(head);
    insertAtFront(head, 5);
    //After Insertion
    TraverseList(head);
    return 0;
}