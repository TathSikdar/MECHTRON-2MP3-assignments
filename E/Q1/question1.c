#include<stdio.h> 
#include<math.h>

double area(double radius);
double pieceOfCake(double radius, double width); 
double pieceOfCakeComplement(double radius, double width);

double area(double radius){
	return (double) M_PI*radius*radius;
}

double pieceOfCake(double radius, double width){
	double theta=2*atan(radius/width);
	double equation = (theta-sin(theta))*radius*radius*1/2;

	return 2*equation;
}

double pieceOfCakeComplement(double radius, double width){
	return area(radius)-pieceOfCake(radius,width);
}


int main () {
	double radius = 42.5;
	double width = 8.2;

	printf("Total Cake = %f\n", area(radius));
	printf("Cake Leftover = %f\n", pieceOfCake(radius, width));
	printf("Cake Obtained = %f\n", pieceOfCakeComplement(radius, width));
}
