#include <stdio.h>
#include <stdlib.h>
 
struct Node
{
    int data;
    struct Node *next;
};

void push(struct Node** head, int new_data)
{
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data  = new_data;
    new_node->next = (*head);
    (*head)    = new_node;
}

void deleteNode(struct Node **head, int key)
{
    struct Node* temp = *head, *prev;
    if (temp != NULL && temp->data == key)
    {
        *head = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) return;
    prev->next = temp->next;
    free(temp);
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
    for(int i=0;i<10;i++){
        push(&head, i);
    }
    puts("Created Linked List: ");
    printList(head);
    deleteNode(&head, 3);
    puts("\nLinked List after Deletion of 3: ");
    printList(head);
    return 0;
}
