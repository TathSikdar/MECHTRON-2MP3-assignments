#include<stdio.h>

int getRekt (int n, int* numAdditions, int* numSubtractions) ;

int getRekt (int n, int* numAdditions, int* numSubtractions){

	int racaman[n];

	racaman[0]=0;

	int inList = 0;

	for(int i=1; i<n;i++){
		inList=0;
		if(racaman[i-1]-i<=0){
			racaman[i]=racaman[i-1]+i;
			(*numAdditions)++;
		}
		else{
			for(int j=0;j<i;j++){
				if (racaman[i-1]-i==racaman[j]){
					racaman[i]=racaman[i-1]+i;
					(*numAdditions)++;
					inList=1;
					break;
				}
			}
			if(!inList){
			racaman[i]=racaman[i-1]-i;
			(*numSubtractions)++;
			}
		}
	}
	return racaman[n-1];
}









int main () {
	int additions;
	int subtractions;

	int correct_recaman[20] =      {0, 1, 3, 6, 2, 7, 13, 20, 12, 21, 11, 22, 10, 23, 9, 24,  8, 25, 43};
	int correct_additions[20] =    {0, 1, 2, 3, 3, 4,  5,  6,  6,  7,  7,  8,  8,  9, 9, 10, 10, 11, 12};
	int correct_subtractions[20] = {0, 0, 0, 0, 1, 1,  1,  1,  2,  2,  3,  3,  4,  4, 5,  5,  6,  6,  6};

	int x;

	for (int i = 1; i <= 19; i++) {
		additions = 0;
		subtractions = 0;
		x = getRekt(i,&additions,&subtractions);
		printf("For n = %d...\n", i);
		if (x == correct_recaman[i-1]) {
			printf("\tThe return value (%d) is correct.\n", x);
		} else {
			printf("\tThe return value (%d) is incorrect and should be %d.\n", x, correct_recaman[i-1]);
		} 
		if (additions == correct_additions[i-1]) {
			printf("\tThe number of additions (%d) is correct.\n", additions);
		} else {
			printf("\tThe number of additions (%d) is incorrect and should be %d.\n", additions, correct_additions[i-1]);
		} 
		if (subtractions == correct_subtractions[i-1]) {
			printf("\tThe number of subtractions (%d) is correct.\n", subtractions);
		} else {
			printf("\tThe number of subtractions (%d) is incorrect and should be %d.\n", subtractions, correct_subtractions[i-1]);
		} 
	}
}
