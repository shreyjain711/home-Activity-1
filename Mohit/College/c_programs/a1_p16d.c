#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

void push(struct Node** head_ref, int new_data)
{
    struct Node* new_node =(struct Node*) malloc(sizeof(struct Node));
    new_node->data  = new_data;
    new_node->next = (*head_ref);
    (*head_ref)    = new_node;
}

int getCount(struct Node* head)
{
    int count = 0;
    struct Node* current = head;
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;
}

int main()
{
    struct Node* head = NULL;
    int x;
    printf("Enter number of elements you want in the list\n");
    int n;scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("\nEnter element %d\n",i+1);
        scanf("%d",&x);
        push(&head, x);
    }
    printf("Number of nodes is %d", getCount(head));
    return 0;
}