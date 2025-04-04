//creating and traversal of a doubly linked list

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
//1)Insert at beginning
struct Node* insertatfirst(struct Node*head, int data){
    struct Node*ptr=(struct Node*)malloc(sizeof(struct Node));
    ptr->data=data;
    ptr->next=head;
    ptr->prev=NULL;

    if(head!=NULL){
        head->prev=ptr;
    }
    return ptr;
}

//2)Insert at index
struct Node* insertatindex(struct Node*head, int data, int index){
    struct Node*ptr=(struct Node*)malloc(sizeof(struct Node));
    struct Node*p=head;
    int i=0;
    while(i!=index-1 && p!=NULL){
        p=p->next;
        i++;
    }
    if(p==NULL){
        printf("Invalid position!\n");
        return head;
    }
    ptr->data=data;
    ptr->next=p->next;
    ptr->prev=p;

    if(p->next!=NULL){
        p->next->prev=ptr;
    }
    p->next=ptr;
    return head;
}
//3)Insert at end
struct Node* insertatend(struct Node*head, int data
){
    struct Node*ptr=(struct Node*)malloc(sizeof(struct Node));
    ptr->data=data;
    ptr->next=NULL;

    if(head==NULL){  //base case(if list is empty)
        ptr->prev=NULL;
        return ptr;
    }
    struct Node*p=head;
    
    while(p->next!=NULL){
        p=p->next;
    }
    p->next=ptr;
    ptr->prev=p;
  
    return head;
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

   
   printf("List before insertion:\n");
   traversal(head);
    
   head=insertatfirst(head, 2);
   head=insertatindex(head,89,2);
   head=insertatend(head,99);

   printf("List after insertion:\n");
   traversal(head);

   
    return 0;
}

