#include <stdio.h>
#include <assert.h>
#include <math.h>


int insertionsort(int* x, int size);

int insertionsort(int* x, int size){
    int counter = 0;
    int i,j;
    int temp;

    for (i=0; i<size-1; i++){
        for (j=0; j+i>=0; j--){
            if (x[j+i]>x[j+i+1]){
                temp = x[j+i];
                x[j+i]=x[j+i+1];
                x[j+i+1] = temp;
                counter++;
            }
            else{
                counter++;
                break;
            }
        }
    }
    return counter;
}

int main () {

    return 0;
}