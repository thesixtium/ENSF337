/*
 *  File Name: lab1_exe_D.c
 *  Assignment: Lab 1 Exercise D
 *  Lab section: B04
 *  Completed by: Aleksander Berezowski
 *  Submission Date: On or before Sept 23, 2021
 */

//Header Files
#include <stdio.h>
#include <math.h>

int main(){
	//Variables
	double input, sinAnswer, taylorAnswer;
	
	//Get input 
	printf("Input Angle in Radians:");
	scanf("%lf",&input);
	
	//Calculate answers
	sinAnswer = sin(input);
	taylorAnswer = input 
					- ( pow(input, 3) / 6)
					+ ( pow(input, 5) / 120) 
					- ( pow(input, 7) / 5040);
	
	//Print answers 
	printf("Sin Value: %f \nTaylor Value: %f \n", sinAnswer, taylorAnswer);

	return 0;
}