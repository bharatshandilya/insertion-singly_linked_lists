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

node* insertInBetween(node* head, int data, int index)
{
    node * ptr = (node*) malloc (sizeof(node));
    node * p = head;
    int i = 0;
    while(i != index-1)
    {
        p = p-> link;
        i++;
    }
    ptr -> link = p -> link;
    ptr -> data = data;
    p -> link = ptr;
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
    insertInBetween(head, 25, 2);
    //After Insertion
    TraverseList(head);
    return 0;
}