// implementation of stack using array
#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 5

//stack structure
struct stack{
    int items[MAX_SIZE];
    int top;
    int *arr;
};
//1)initialize an empty stack
void initStack(struct stack *s){
    s->top=-1;
}
int isEmpty(struct stack *s){
    if(s->top==-1){
        return 1;
    }else{
        return 0;
    }
}

int isFull(struct stack *s){
    if(s->top== MAX_SIZE-1){
        return 1;
    }else{
        return 0;
    }
}
//Push an element onto the stack(insertion)
void push(struct stack*s, int value){
    if(isFull(s)){
        printf("Stack overflow!, Cannot push %d\n", value);
    }
   s->items[ ++(s->top)]=value;
   printf("pushed %d\n", value);
};
//Pop an element
int pop(struct stack*s){
    if(isEmpty(s)){
        printf("Stack underflow! cannot pop\n");
        return -1;
    }
    return  s->items[ (s->top)--];

}

//peek
int peek(struct stack *s){
    if(isEmpty(s)){
        printf("Stack is empty\n");
        return -1;
    }
    return  s->items[ (s->top)];

}

//display
void display(struct stack *s){

    if(isEmpty(s)){
        printf("Stack is empty\n");
        return ;
    }
    printf("Stack: ");
    for(int i=0; i<=s->top; i++){
        printf("%d",s->items[i]);
    }
    printf("\n");
};



int main(){
   struct stack s;
   initStack(&s);

   push(&s, 10);
   push(&s, 20);
   push(&s, 30);

   display(&s);
   
   printf("The top element : %d\n", peek(&s));

   printf("popped: %d\n", pop(&s));
   display(&s);


    return 0;
}