#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

void reverse(char* str);
int count(char* str);

void reverse(char* str){
    int len = sizeof(str)/sizeof(str[0]);
    char temp[len];

    for(int i=len;i>=0;i--){
        temp[len-i]=str[i-1];
    }
    str=temp;
    str[len]='\0';
}

int count(char* str){
    int len = sizeof(str)/sizeof(str[0]);
    char vowels[]={'a','e','i','o','u'};
    int lenvowels = sizeof(vowels)/sizeof(vowels[0]);
    int counter = 0;

    for(int i=0;i<len;i++){
        for(int j=0;j<lenvowels;j++){
            if(tolower(str[i])==vowels[j]){
                counter++;
                break;
            }
        }
    }
    return counter;
}


int main () {
    char this[]="McMAster";
    printf("%d",count(this));
    return 0;
}