//creation  and traversal of a singly linked list
#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node * next;
};

//crreating function for traversal
void traversal(struct Node* ptr ){
    while(ptr != NULL){
        printf(" Element: %d \n", ptr-> data);
        ptr= ptr->next;
    }
};

int main(){
    struct Node* head;
    struct Node* second;
    struct Node* third;

    //Allocate memory of nodes to the heap
    head= (struct Node*)malloc(sizeof(struct Node));
    second= (struct Node*)malloc(sizeof(struct Node));
    third= (struct Node*)malloc(sizeof(struct Node));

    //link first node to second
    head->data=7;
    head->next=second;

    
    //link second to third node
    second->data=11;
    second->next=third;

    
    //terminate list
    third->data=55;
   third->next=NULL;

   //call traversal function
   traversal(head);


    return 0;
}

