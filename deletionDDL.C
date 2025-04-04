//Deletion
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
//1)deletion at the beggining
struct Node* deleteatbeginning(struct Node*head){
    if(head==NULL)
    return NULL;

    struct Node* ptr=head;
    head=head->next;

    if(head!=NULL){
        head->prev=NULL;
    }
    free(ptr);
    return head;
}
//2)Delete at a particular index
struct Node* deleteatindex(struct Node* head, int index){
    if(head==NULL)
    return NULL;
    struct Node*p= head;
    for(int i=0;i<index && p!=NULL; i++){
        p=p->next;
    }

    if (p==NULL)
    return head;
    if(p->prev!=NULL){
        p->prev->next=p->next;
    }else{
        head=p->next;
    }
    if(p->next!=NULL){
        p->next->prev=p->prev;
};
free(p);
return head;

}

//3)delete at end
struct Node* deleteatend(struct Node* head){
    if(head==NULL)
    return NULL;
    struct Node*p= head;
    while(p->next!=NULL){
        p=p->next;
    }
    if(p->prev!=NULL){
        p->prev->next=NULL;
    }else{
        head=NULL;
    }
free(p);
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

   //call traversal function
   printf("list before deletion:\n");
   traversal(head);
   
   head=deleteatbeginning(head);
   head=deleteatindex(head,2);
   head=deleteatend(head);


   printf("List after deletion:\n");
   traversal(head);

   

    return 0;
}
