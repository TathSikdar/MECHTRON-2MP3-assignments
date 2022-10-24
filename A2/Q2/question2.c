#include <stdio.h>
#include <assert.h>
#include <math.h>

int juggler(int n);

int juggler(int n){
    
    float temp = n;
    if (n%2){   //Odd
        n = floor(powf(temp,1.5));
    } else{     //Even
        n = floor(powf(temp,0.5));
    }
    
    if (n==1){
        return 1;
    } else{
        return juggler(n)+1;
    }
}

int main () {

    
    return 0;
}