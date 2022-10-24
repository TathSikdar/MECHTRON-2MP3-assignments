#include <stdio.h>
#include <assert.h>
#include <math.h>


int bubblesort(int* x, int size);

int bubblesort(int* x, int size){

    int i, j;
    int counter = 0;
    int temp;

    for(i=0; i<size-1; i++){
        for(j=0; j<size-i-1; j++){
            if(x[j]>x[j+1]){
                temp = x[j];

                x[j] = x[j+1];
                x[j+1] = temp;
                
                counter++;
            }
        }
    }
    return counter;
}

int main () {
 
    return 0;
}