//Creating single linked list
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node*link;
};

int main(){
    struct node* Head=NULL;//Creating the head pointer
    Head=(struct node*)malloc(sizeof(struct node));

    Head->data=45;
    Head->link=NULL;

    struct node* current= malloc(sizeof(struct node));

    current->data=98;
    current->link=NULL;

    //Updating head
    Head->link=current;

    //Adding the third node
    current=malloc(sizeof(struct node)); //reusing current pointer
    current->data=3;
    current->link=NULL;

    //Updating the link part of second node
    Head->link->link=current;



    return 0;
};