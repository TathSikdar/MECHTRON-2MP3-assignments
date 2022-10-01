#include <stdio.h>
#include <assert.h>
#include <math.h>

int multiples (int x, int y, int N);

int multiples (int x, int y, int N){
    int i;
    int sum = 0;
    
    for (i=1; i<=N; i++){
        if (i%x == 0 || i%y ==0){
            sum += i;
        }
    }

    return sum;
}

int main () {

    return 0;
    
}
