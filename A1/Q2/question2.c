#include <stdio.h>
#include <assert.h>
#include <math.h>

float onethird (int n);

float onethird (int n) {

int i;
float counter = 0;

    for (i=1; i<=n; i++) {
        counter += pow(i,2);
    }

    counter /= pow(n,3);
    return counter;

}

int main () {

    return 0;

}

