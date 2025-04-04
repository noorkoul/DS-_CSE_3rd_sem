//compare
#include<stdio.h>

int strComp(char str1[],char str2[]){
    int i=0;
    while(str1[i]!='\0' &&str2[i]!='\0' ){

        if (str1[i]!= str2[i]){
            return str1[i]-str2[i];
        }

        i++;

        return str1[i]-str2[i];
    }
}

int main(){
    char str1[100]="Hello";
    char str2[100]="World";

   int compResult=strComp(str1,str2);
   if(compResult==0){
    printf("%s is equal to %s", str1,str2);
   }else if(compResult<0){
    printf("%s is less than %s",str1,str2);
   }else{
    printf("%s is greater than %s",str1,str2);
   }
    

    return 0;
}
