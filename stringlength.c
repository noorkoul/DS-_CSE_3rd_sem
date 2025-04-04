#include<stdio.h>

//Function to calculate string length

int stringLength(char str[]){
    int length = 0;
    while(str[length]!='\0'){
        length ++;
    }
    return length;
}

int main(){
    char str[100]="Hello";

    printf("The length of %s: %d\n", str,stringLength(str));

    return 0;
}