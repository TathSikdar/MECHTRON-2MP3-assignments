#include <stdio.h>
#include <assert.h>
#include <math.h>

float compoundInterest (float p, int a, int n);

float compoundInterest (float p, int a, int n){

    return a*pow(1+p,n);

}

int main () {

    return 0;
    
}