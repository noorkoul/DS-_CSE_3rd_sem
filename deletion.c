//Deletion 
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

//1)Deletion at the beginning
    struct Node* deletefirst(struct Node* head){
        struct Node* ptr = head;
        head= head->next;  //doosre node par head ki value
        free(ptr);
        return head;
    }
//2)Deletion at index
struct Node* deleteatindex(struct Node* head, int index){
    struct Node* p = head;
    struct Node* q = head->next;
    for(int i=0;i<index-1;i++){
        p=p->next;
        q=q->next;
    }
    p->next=q->next;
    free(q);
    return head;


};

//3)Deletion at the end
struct Node* deleteatend(struct Node* head){
    struct Node* p = head;
    struct Node* q = head->next;
  while(q-> next!=NULL){
    p=p->next;
    q=q->next;
  }
    p->next=NULL;
    free(q);
    return head;


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
   printf("\n Linked list before deletion\n");
   traversal(head);

    //head=  deletefirst(head);
   // head= deleteatindex(head, 2);
    head= deleteatend(head);

   printf("\n Linked list after deletion\n");
   traversal(head);




    return 0;
}

