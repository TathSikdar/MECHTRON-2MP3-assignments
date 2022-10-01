#include <stdio.h>
#include <assert.h>
#include <math.h>

int FactorialWhile (int n);
int FactorialDoWhile (int n);

int FactorialWhile (int n) {
    int counter = 1;

    if (n==0) {
        return counter;
    }else{
        while (n>1) {
            counter *= n--;
        }
        return counter;
    }
}

int FactorialDoWhile (int n) {
    int counter = 1;

    if (n==0) {
        return counter;
    }else{
        do{
            counter *= n--;
        }
        while (n>1);
    }
}

int main () {

    printf("%d\n",FactorialWhile(10));
    printf("%d", FactorialDoWhile(10));
    return 0;

}

