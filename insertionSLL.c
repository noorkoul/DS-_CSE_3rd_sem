//insertion in a singly linked list
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


//For insertion(at the beginning)
struct Node * insertatfirst(struct Node*head, int data){
    struct Node*ptr=(struct Node *)malloc(sizeof(struct Node));
    ptr->next=head;
    ptr->data=data;
    return ptr;
}
//insert at a certain position
struct Node * insertatK(struct Node*head, int data, int index){
    struct Node*ptr=(struct Node *)malloc(sizeof(struct Node));
    struct Node *p=head;
    int i=0;
    while(i!=index-1){
        p=p->next;
        i++;
    }
    ptr->data=data;
    ptr->next=p->next;
    p->next=ptr;
    return head;
}
//insert at end
struct Node * insertatend(struct Node*head, int data){
    struct Node*ptr=(struct Node *)malloc(sizeof(struct Node));
    ptr->data=data;
    struct Node *p=head;
    while(p->next!=NULL){
        p=p->next;
    }
    p->next=ptr;
    ptr->next=NULL;
    return head;


    ptr->next=head;
    return ptr;
}



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
   printf("Linked list before insertion\n");
   traversal(head);
   head= insertatfirst(head, 78);
   head= insertatK(head, 89, 2);
   head= insertatend(head,90);
   printf("Linked list after insertion\n");

   
   traversal(head);


    return 0;
}

