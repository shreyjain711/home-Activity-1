#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
 
struct Node
{
    int key;
    struct Node* next;
};

void push(struct Node** head_ref, int new_key)
{
    struct Node* new_node =
            (struct Node*) malloc(sizeof(struct Node));
 
    new_node->key  = new_key;
 
    new_node->next = (*head_ref);
 
    (*head_ref)    = new_node;
}

int search(struct Node* head, int x)
{
    struct Node* current = head;
    while (current != NULL)
    {
        if (current->key == x)
            return 1;
        current = current->next;
    }
    return 0;
}

int main()
{
    struct Node* head = NULL;
    int x;
    printf("Enter how many elements you want in the list\n");
    int n;scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Enter element %d\n",i+1);
        scanf("%d",&x);
        push(&head, x);
    }
    printf("\nEnter element to be searched\n");
    scanf("%d",&x);
    search(head, x)? printf("Yes") : printf("No");
    return 0;
}