/*
 *  File Name: lab1_exe_E.c
 *  Assignment: Lab 1 Exercise E
 *  Lab section: B04
 *  Completed by: Aleksander Berezowski
 *  Submission Date: On or before Sept 23, 2021
 */

//Header files
#include <stdio.h>
#include <math.h>

int main(){
	//Define variables
	double a, b, c, rootFirstPart, rootSecondPart, underRoot, denominator;
	
	//Get inputs
	printf("Quadradic Coefficient A:");
	scanf("%lf",&a);
	
	printf("Quadradic Coefficient B:");
	scanf("%lf",&b);
	
	printf("Quadradic Coefficient C:");
	scanf("%lf",&c);
	
	
	//Calculate roots
	underRoot = pow(b, 2) - 4 * a * c;
	denominator = 2 * a;
	if (underRoot > 0){
		rootFirstPart = -b / denominator; 
		rootSecondPart = sqrt(underRoot) / denominator;
		printf("Root 1: %f \nRoot 2: %f \n", 
				rootFirstPart + rootSecondPart, 
				rootFirstPart - rootSecondPart);
	} else {
		rootFirstPart = -b / denominator; 
		rootSecondPart = sqrt(-underRoot) / denominator;
		printf("Root 1: %f + %fi\nRoot 2: %f - %fi\n", 
				rootFirstPart, 
				rootSecondPart, 
				rootFirstPart, 
				rootSecondPart);
	}
	
	
	
	return 0;
}

