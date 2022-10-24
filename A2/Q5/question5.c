#include <stdio.h>
#include <assert.h>
#include <math.h>


int binsearch(int* x, int y, int size);

int binsearch(int* x, int y, int size){

    int a = 0;
    int b = size-1;
    int m = floor((a+b)/2.0);
    int counter = 0;

    do{

        if (y==x[a]||y==x[b]||y==x[m]){
            return ++counter;
        }
        else if (x[m]<y){
            a=floor((a+b)/2.0+1);
        }
        else if (x[m]>y){
            b=floor((a+b)/2.0-1);
        }
        counter++;

        m = floor((a+b)/2.0);
    }
    while (b-a>2);

    return -1;
}

int main () {

    return 0;
}