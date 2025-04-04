//concatenation of string
#include<stdio.h>

//Function to calculate string length

int stringLength(char str[]){
    int length = 0;
    while(str[length]!='\0'){
        length ++;
    }
    return length;
}

void stringConcat(char dest[], char src[]){
    int destLen = stringLength(dest);
    int i=0;
    while(src[i]!='\0'){
        dest[destLen+i]=src[i];
        i++;
    };
}
    int main(){
        char str1[100]="Hello";
        char str2[100]="World";

        stringConcat(str1,str2);
        printf("The concatenated string is : %s", str1);
        

        return 0;
    }


