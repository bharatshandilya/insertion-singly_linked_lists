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

node* insertAtEnd(node * head, int data)
{
    node* ptr = (node*) malloc (sizeof(node));
    ptr -> data = data;
    if(head == NULL)
    {
        ptr -> link = NULL;
        return ptr;
    }
    else
    {
        node * p = head;
        while(p -> link != NULL)
        {
           p= p -> link;
        }
        p -> link = ptr;
        ptr -> link = NULL;
    }
        return(head);
}

node* insertAfterNode(node* head, node* prevNode, int data)
{
    node* ptr = (node*) malloc (sizeof(node));
    ptr -> data = data;
    ptr -> link = prevNode -> link;
    prevNode -> link = ptr;
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
    //TraverseList(head);
    //After Insertion:
    //insertAtFront(head, 5);
    //insertInBetween(head, 25, 2);
    //insertAtEnd(head, 50);
    //insertAfterNode(head, third, 35);
    //TraverseList(head);
    return 0;
}