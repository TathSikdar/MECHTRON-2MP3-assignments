#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

#define DEBUG 3
#define VERBOSE 1

void printBoolArray(bool* arr, int size) {
	printf("[");
	for (int i = 0; i < size; i++) {
		printf("%s", arr[i] ? "true" : "false" );
		if (i < size - 1) {
			printf(", ");
		}
	}
	printf("]\n");
}


void printArray(int* arr, int size) {
	printf("[");
	for (int i = 0; i < size; i++) {
		printf("%d", arr[i]);
		if (i < size - 1) {
			printf(", ");
		}
	}
	printf("]\n");
}


// Sorted array contains only those elements which were already in order.  
int* StalinSort (int* cheloveks, int size);
int sorted(int* cheloveks, int size);
void delreshuffle(int* cheloveks, int targetIndex, int size);

int* StalinSort (int* cheloveks, int size){
    while(!sorted(cheloveks,size)){
        for(int i=1;i<size;i++){
            if(cheloveks[i]<cheloveks[i-1]){
                delreshuffle(cheloveks,i,size);
                size--;
                // free(&(cheloveks[size-1]));
                break;
            }
        }
    }
    return cheloveks;
}

int sorted(int* cheloveks, int size){
    for(int k=1;k<size;k++){
        if(cheloveks[k-1]>cheloveks[k]){
            return 0;
        }
    }
    return 1;
}

void delreshuffle(int* cheloveks, int targetIndex, int size){
    for(int j=targetIndex;j<size-1;j++){
        cheloveks[j]=cheloveks[j+1];
    }
}

int main() {

    #if DEBUG == 0
    
    int expected1[4] = {3,4,5,4};
    printf("%d",sorted(expected1,4));

    #endif

    #if DEBUG == -1
    
    int test1[5] = {3, 4, 5, 1, 9};
    int expected1[4] = {3,4,5,9};
    printf("Test Case 1 : ");
    delreshuffle(test1, 3, 5);

    
    for(int i=0;i<5-1;i++){
        printf("%d,",test1[i]);
    }
    #endif
    
    
   #if DEBUG == 1
    int test1[5] = {3, 4, 5, 1, 9};
    int expected1[4] = {3,4,5,9};
    printf("Test Case 1 : ");
    if (!memcmp(expected1, StalinSort(test1, 5), 4*sizeof(int))) {
        printf("Passed!\n");
    } else {
        printf("Failed!\n");
        #if VERBOSE == 1
		printArray(StalinSort(test1, 5), 4);
		#endif
    }
    #endif
    
    #if DEBUG == 2
    int test2[10] = {30, 8, 73, 16, 22, 1, 0, 55, 58, 81};
    int expected2[3] = {30, 73, 81};    
    printf("Test Case 2 : ");
    if (!memcmp(expected2, StalinSort(test2, 10), 3*sizeof(int))) {
        printf("Passed!\n");
    } else {
        printf("Failed!\n");
        #if VERBOSE == 1
        printArray(StalinSort(test2, 10), 3);
        #endif
    } 
    #endif   
    
    #if DEBUG == 3
    int test3[20] = {231, 376, 596, 83, 879, 460, 569, 804, 331, 671, 533, 857, 351, 717, 133, 48, 725, 253, 15, 525};
    int expected3[4] = {231, 376, 596, 879}; 
    printf("Test Case 3 : ");
    if (!memcmp(expected3, StalinSort(test3, 20), 4*sizeof(int))) {
        printf("Passed!\n");
    } else {
        printf("Failed!\n");
        #if VERBOSE == 1
        printArray(StalinSort(test3, 20), 4);
        #endif
    }    
    #endif
}
