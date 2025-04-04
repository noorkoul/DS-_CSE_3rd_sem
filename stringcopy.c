#include<stdio.h>

//Function to calculate string length

int stringCopy(char dest[], char src[]){
    int i = 0;
    while(src[i]!='\0'){
        dest[i]=src[i];
        i ++;
    }
    dest[i]='\0'; //terminate dest string
}

int main(){
    char str1[100]="Hello";
    char str2[100];

    stringCopy(str2, str1);
    printf("The copied string: %s", str2);

    return 0;
}