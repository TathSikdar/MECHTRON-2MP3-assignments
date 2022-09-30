#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <stdbool.h>

int LeapYearCheck (int n);

int LeapYearCheck (int n){
    
    if (n%4==0){
        return true;
    }else{
        return false;
    }

}

int main () {

    printf("%d", LeapYearCheck(2100));

    return 0;

}

