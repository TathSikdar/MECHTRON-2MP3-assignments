#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <stdbool.h>


int shellsort (int *array, int size, int *h_gaps, int (*subsort)(int* array, int size));
int bubblesort(int* x, int size);
void subarraymaker(int *array, int **subarray, int *sublen, int hgap, int size);
void arraymaker(int **subarray, int *sublen, int *array,int hgap);

int bubblesort(int* x, int size) {
    int temp;
    int swaps = 0;
    for (int i = 0; i < size; i ++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (x[j] > x[j+1]) {
                temp = x[j];
                x[j] = x[j + 1];
                x[j+1] = temp;
                swaps ++;
            }
        }
    }
    return swaps;
}

void subarraymaker(int *array, int **subarray, int *sublen, int hgap, int size){
    
    for(int i=0;i<size;i++){
        subarray[i%(hgap+1)][sublen[i%(hgap+1)]]=array[i];
        sublen[i%(hgap+1)]++;
    }
}

void arraymaker(int **subarray, int *sublen, int *array,int hgap){
    int k=0;
    for(int i=0; i<sublen[0]; i++){
        for(int j=0; j<=hgap; j++){
            if(i<sublen[j]){
                array[k]=subarray[j][i];
                k++;
            }
        }
    }
}

int shellsort(int *array, int size, int *h_gaps, int (*subsort)(int* array, int size)){
        int counter = 0;
        int i=0;
        int currenth= h_gaps[i];
        while(1){
            int **subarray=(int**)malloc((currenth+1)*sizeof(int *));
            for (int j=0;j<currenth+1;j++){subarray[j]=malloc((size/currenth+1)*sizeof(int));}
            int *sublen=malloc((currenth+1)*sizeof(int));
            for (int j=0; j<currenth+1; j++){sublen[j] = 0;}

            subarraymaker(array,subarray,sublen,currenth, size);
            for(int j=0; j<currenth+1;j++){
                counter+=(*subsort)(subarray[j],sublen[j]);
            }
            
            arraymaker(subarray,sublen,array, currenth);
            
            //free
            for (int j=0;j<currenth+1;j++){free(subarray[j]);}
            free(subarray);
            free(sublen);
            
            if (currenth==1){
                break;
            }
            currenth= h_gaps[++i];
            
        }
        
        
        counter+=(*subsort)(array, size);
        
        return counter;
}

int main () {
    int array[] = {1,2,3,4,5,6,7,8,9,8};
    
    int size=10;
    int hgap[]={5,2,1};
    int n=shellsort(array,size,hgap,bubblesort);

    printf("\n%d",n);

    return 0;
}