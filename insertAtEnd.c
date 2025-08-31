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
    insertAtEnd(head, 50);
    //After Insertion
    TraverseList(head);
    return 0;
}