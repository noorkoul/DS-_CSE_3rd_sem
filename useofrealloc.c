//Display integers
#include<stdio.h>
#include<stdlib.h>

int main(){
    int i;
    int *ptr = (int*)malloc(2*sizeof(int));

    if(ptr==NULL){
        printf("Memory is not available");
        exit(1);
    }
    //getting the input
    printf("Enter 2 integers: ");
    for(i=0;i<2;i++){
        scanf("%d", ptr+i);
    }
    //use of realloc
    ptr = (int*)realloc(ptr,4*sizeof(int));

    if(ptr==NULL){
        printf("Memory is not available");
        exit(1);
    }
    //enter two more integers
    printf("Enter 2 more integers: ");
    for(i=2;i<4;i++){
        scanf("%d", ptr+i);
    }
    //to print all integers on the screen
    for(i=0;i<4;i++){
        printf("%d",*(ptr+i));//dereferncing 


}

return 0;

}