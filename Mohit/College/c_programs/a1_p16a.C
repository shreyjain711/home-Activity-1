#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node *next;
};

void push(struct Node** head_ref, int new_data)
{
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data  = new_data;
    new_node->next = (*head_ref);
    (*head_ref)    = new_node;
}

void printList(struct Node *node)
{
  while (node != NULL)
  {
     printf("%d\n", node->data);
     node = node->next;
  }
}

int main()
{
  struct Node* head = NULL;
  int x,n;
  printf("Enter no. of elements to be added to the list");
  scanf("%d",&n);
  for(int i=0;i<x;i++){
    push(&head, x);
  }
  printf("\n Created Linked list is: ");
  printList(head);
  return 0;
}
