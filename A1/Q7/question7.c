#include <stdio.h>
#include <assert.h>
#include <math.h>

void mileage (void);

void mileage (void) {
    
    float totalFuel = 0;
    float totalDistance = 0;
    float inputFuel;
    float inputDistance;
    char repeat[1];

    do {
        printf("How much fuel have you used? : ");
        scanf("%f", &inputFuel);
        printf("How far did you travel? : ");
        scanf("%f", &inputDistance);
        printf("Do you have more data to enter? (y/n) : ");
        scanf("%1s", repeat);

        
        totalFuel += inputFuel;
        totalDistance += inputDistance;
    }
    while (repeat[0] == 'y');
    
    printf("Your gas mileage is %f", totalDistance/totalFuel);
}

int main () {
	mileage();
    return 0;
}

