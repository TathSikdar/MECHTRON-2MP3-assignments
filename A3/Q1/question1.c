#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

void reverse(char* str);
int count(char* str);

void reverse(char* str){
    int len=0;
    char switchtemp;
    int i=0;
    while(str[i]){
        len++;
        i++;
    }
    if(len%2){ //odd
        for(i=0; i<(len-1)/2; i++){
            int j=len-1-i;
            switchtemp=str[j];
            str[j]=str[i];
            str[i]=switchtemp;
        }
    }
    else{
        for(i=0; i<len/2; i++){
            int j = len-1-i;
            switchtemp=str[j];
            str[j]=str[i];
            str[i]=switchtemp;
        }
    }
}

int count(char* str){
    char vowels[]={'a','e','i','o','u'};
    int lenvowels = sizeof(vowels)/sizeof(vowels[0]);
    int counter = 0;
    int i=0;
    int j=0;   

    while(str[i]){
        for(int j=0;j<lenvowels;j++){
            if(tolower(str[i])==vowels[j]){
                counter++;
                break;
            }
        }
        i++;
    }
    return counter;
}


int main () {
    char this[]="rachel tsang";
    reverse(this);
    printf("%s",this);
    return 0;
}