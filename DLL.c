//creating and traversal of a doubly linked list
//creation  and traversal of a singly linked list
#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node * prev; //prev node
    struct Node * next; //next node
};

//Forward traversal
void traversal(struct Node* ptr ){
    while(ptr != NULL){
        printf(" Element: %d \n", ptr-> data);
        ptr= ptr->next;
    }
};

//Reverse traversal
void reversetraversal(struct Node* ptr ){
    while(ptr != NULL){
        printf(" Element: %d \n", ptr-> data);
        ptr= ptr->prev;
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
    head->prev=NULL;
    head->next=second;

    
    //link second to third node
    second->data=11;
    second->next=third;
    second->prev=head;

    
    //terminate list
    third->data=55;
   third->prev=second;
   third->next=NULL;

   //call traversal function
   printf("Forward traversal:\n");
   traversal(head);

   printf("Reverse traversal:\n");
   reversetraversal(third);  //start from tail

    return 0;
}

