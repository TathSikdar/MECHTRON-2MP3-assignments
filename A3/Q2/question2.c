#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <stdbool.h>

void removeDups(int* in, int size);

void removeDups(int* in, int size){
    int temp[size];
    int index = 0;

    for(int i=0;i<size;i++){
        temp[i]=0;
        int counter=0;
        for(int j=0;j<size;j++){
            if(temp[j]==in[i]){
                counter++;
            }
        }
        if(counter==0){
            temp[index]=in[i];
            index++;
        }
    }

    
    for(int i=0;i<size;i++){
        in[i]=temp[i];
    }
}



int main () {

    int this[]={1,2,2,2,3,3,4,2,4,5,6,6,6};
    int size=sizeof(this)/sizeof(this[0]);

    removeDups(this, size);



    for(int i=0;i<size;i++){
        
        printf("%d,",this[i]);
    }





    printf("%p",this);

    return 0;
}