#include <stdio.h>
#include <assert.h>
#include <math.h>


int bubblesort(int* x, int size);

int bubblesort(int* x, int size){

    int sortedList[size];
    int i, j;
    int counter = 0;

    for(i=0; i<size-1; i++){
        for(j=0; j<size-i-1; j++){
            int compare1, compare2;
            if(x[j]>x[j+1]){
                compare1 = x[j];
                compare2 = x[j+1];

                x[j] = compare2;
                x[j+1] = compare1;
                
                counter++;
            }
        }
    }
    return counter;
}

int main () {

    int x[]={100};

    int sizex = sizeof(x)/sizeof(x[0]);

    printf("%d", bubblesort(x, sizex));


    
    return 0;
}