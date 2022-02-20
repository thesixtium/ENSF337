/*
 *  File Name: lab1_exe_B.c
 *  Assignment: Lab 1 Exercise B
 *  Lab section: B04
 *  Completed by: Aleksander Berezowski
 *  Submission Date: On or before Sept 23, 2021
 */

#include <stdio.h>
#include <math.h>

int main(){
	double num1 = -34.5;
	double num2 = 98.7;
	double sum, sumSquared;   
	
	// Add num1 and num2 together and save to sum; print results
	sum = num1 + num2;
	printf("Sum: %f \n", sum);

	// Square the sum, used math header file; print results
	sumSquared = pow(sum, 2);
	printf( "The sum squared is: %f \n", sumSquared);
	
	// Double sum; print results
	sumSquared = sumSquared * 2;
	printf( "The sum squared is now: %f \n",  sumSquared);

	return 0;
}