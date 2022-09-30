#include <stdio.h>
#include <assert.h>
#include <math.h>

float compoundInterest (float p, int a, int n);

float compoundInterest (float p, int a, int n){

    return a*pow(1+p,n);

}

int main () {
    
    float s = compoundInterest(0.05,20,5);

    printf("%d", s);

    return 0;
}