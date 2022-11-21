#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

int simpleParse(const char *exp);
int bedmas(char operations[], int nums[], int lenoperations);
int shufflearray(char operations[], int nums[],int lenoperations,int operationindex, int changeint);

int simpleParse(const char *exp){
    int counter=0;
    int i=0;
    char *endptr;
    char operations[]="0000000";
    int operationsindex=0;
    int literals[8]={-1,-1,-1,-1,-1,-1,-1,-1};
    int literalindex =0;
    while(exp[i]){
        if(isdigit(exp[i])){
            literals[literalindex]=(int)strtol(exp+i,&endptr,10);
            literalindex++;
            i+=endptr-(exp+i);
            continue;
        }
        else if(exp[i]==' '){
            i++;
            continue;
        }
        else{
            operations[operationsindex]=exp[i];
            operationsindex++;
        }
        i++;
    }
    return bedmas(operations,literals,operationsindex);
}

int bedmas(char operations[], int nums[], int lenoperations){
    for(int i=0;i<lenoperations;i++){
        for(int j=0;j<lenoperations ;j++){
            if(operations[j]=='*'){
                shufflearray(operations,nums,lenoperations,j,nums[j]*nums[j+1]);
                break;
            }
            else if(operations[j]=='%'){
                shufflearray(operations,nums,lenoperations,j,nums[j]%nums[j+1]);
                break;
            }
            else if(operations[j]=='/'){
                shufflearray(operations,nums,lenoperations,j,nums[j]/nums[j+1]);
                break;
            }
        }
    }
    for(int i=0;i<lenoperations;i++){
        for(int j=0;j<lenoperations ;j++){
            if(operations[j]=='+'){
                shufflearray(operations,nums,lenoperations,j,nums[j]+nums[j+1]);
                break;
            }
            else if(operations[j]=='-'){
                shufflearray(operations,nums,lenoperations,j,nums[j]-nums[j+1]);
                break;
            }
        }
    }
    return nums[0];
}

int shufflearray(char operations[], int nums[],int lenoperations,int operationindex, int changenum){
    for(int i=operationindex+1;i<lenoperations;i++){
        operations[i-1]=operations[i];
    }
    operations[lenoperations-1]='0';
    nums[operationindex]=changenum;
    for(int i=operationindex+1;i<lenoperations;i++){
        nums[i]=nums[i+1];
    }
    nums[lenoperations]=-1;
}

int main() {
    char exp1[] = "1 - 2";
    char exp2[] = "3 + 7 - 4 * 1";
    char exp3[] = "9 * 13 / 2 + 18 * 110 - 812 % 97 + 3";
    printf("%s = %d\n", exp1, simpleParse(exp1));
    printf("%s = %d\n", exp2, simpleParse(exp2));
    printf("%s = %d\n", exp3, simpleParse(exp3));
}