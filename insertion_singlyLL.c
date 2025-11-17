#include <stdlib.h>
#include <stdio.h>

struct Node {
    int data;
    struct Node* next;
};

void linkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d->", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL");
}

int main() {

    struct Node *head = (struct Node*) malloc(sizeof(struct Node));
    struct Node *second = (struct Node*) malloc(sizeof(struct Node));
    struct Node *third = (struct Node*) malloc(sizeof(struct Node));
    head->data = 2;
    head->next = second;
    
    second->data=9;
    second->next=third;
    
    third->data=15;
    third->next=NULL;
    
    
    //INSERT AT BEGINNING
    struct Node *begptr = (struct Node*) malloc(sizeof(struct Node));
    begptr->data = 8;
    begptr->next = head;   // new node points to previous head
    head = begptr;         // update head to new node
    
    //INSERT AT END
    struct Node *endptr = (struct Node*) malloc(sizeof(struct Node));
    endptr->data=0;
    endptr->next=NULL;
    
        // travel to the last node
    struct Node *temp = head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=endptr;
    
    //INSERT AT CUSTOM
    int pos=30;
    struct Node *custptr = (struct Node*) malloc(sizeof(struct Node));
    custptr->data = 50;
    custptr->next = NULL;
    
    temp = head;
    int i=1;
    while(i<pos-1 && temp!=NULL){
        temp=temp->next;
        i++;
    }
    if(temp==NULL){
    printf("invalid positon");
    return 0;
    }
    
    custptr->next=temp->next;
    temp->next=custptr;

    linkedListTraversal(head);

    return 0;
}
