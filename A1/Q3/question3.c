#include <stdio.h>
#include <assert.h>
#include <math.h>

int multiples (int x, int y, int N);

int multiples (int x, int y, int N){
    int i;
    int sum = 0;

    for (i=1; i<=N; i++){
        if (x*i<=N) {
            sum += x*i;
        }
        else{
            break;
        }
    }
    
    for (i=1; i<=N; i++){
        if(y*i<=N) {
            sum+= y*i;
        }
        else{
            break;
        }
    }

    return sum;
}

int main () {
    int thisone = multiples(2,3,10);

    printf("%d", thisone);

    return 0;
}

// x=2, y=3

// 2*_=multiple of 2

// 1,2,3,4,5,6,7,8,9,10
// /,^,