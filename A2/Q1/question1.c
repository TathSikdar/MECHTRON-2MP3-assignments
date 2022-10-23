#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

double mean(int* x, int size);
double median(int* x, int size);
int mode(int* x, int size);
void bubbleSort(int* x, int size);

double mean(int* x, int size){

    double counter = 0;

    for (int i=0; i<size; i++){
        counter += *x;
        x++;
    }

    return counter/size;
}

void bubbleSort(int* x, int size){

    int sortedList[size];
    int i, j;

    for(i=0; i<size-1; i++){
        for(j=0; j<size-1; j++){
            int compare1, compare2;
            if(x[j]>x[j+1]){
                compare1 = x[j];
                compare2 = x[j+1];

                x[j] = compare2;
                x[j+1] = compare1;
            }
        }
    }
}

double median(int* x, int size){
    bubbleSort(x, size);
    
    if(size%2){
        int index = floor(size/2);
        double median = x[index];
        return median;
    }
    else{
        int index = size/2-1;
        double median = (x[index]+x[index+1])/2.0;
        return median;
    }
}

int mode(int* x, int size){
    int maxValue, maxCount=0;
    int i,j;

    for(i=0; i<size; i++){
        int value = x[i];
        int count = 0;
        for(j=0; j<size; j++){
            if(x[i]==x[j]){
                count++;
            }
        }
        if(count>maxCount){
            maxCount = count;
            maxValue = value;
        }
    }
    return maxValue;    
}

int main () {

    int x[] = {1,3,4,1,3,3,3,3,2,2,2,9};
    int sizex = sizeof(x)/sizeof(x[0]);

    printf("%d",mode(x,sizex));

    return 0;
}
