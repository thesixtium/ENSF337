/*
*  File Name: lab3exe_D.c
*  Assignment: Lab 3 Exercise D
*  Lab section: B04
*  Completed by: Aleksander Berezowski
*  Submission Date: On or before Oct 14, 2021
*/

#include <stdio.h>
#include <stdlib.h>

void pascal_triangle(int n);
/* REQUIRES: n > 0 and n <= 20
 PROMISES: displays a pascal_triangle. the first 5 line of the function's output
 should have the following format:
 row 0:  1
 row 1:  1   1
 row 2:  1   2   1
 row 3:  1   3   3   1
 row 4:  1   4   6   4   1
 */

int main() {
    int nrow;
    // These are ALL of the variables you need!
    printf("Enter the number of rows (Max 20): ");
    scanf("%d", &nrow);
    if(nrow <= 0 || nrow > 20) {
        printf("Error: the maximum number of rows can be 20.\n");
        exit(1);
    }
    
    pascal_triangle(nrow);
    return 0;
}

void pascal_triangle(int n) {
	//DESCRIPTION: Prints a pascal's triangle of n rows 
	//PROMISES: Prints a correctly assembled pascal's triangle with no return
	//REQUIRES: n must belong to all whole numbers, fit within int type, n >= 1
	
	//Variable definitions
	int i; //y-coord
	int j; //x-coord 
	int currentArray[n]; //n length array used to print values
	int previousArray[n]; //n length array used tostore previous values 
	
	//Clears both arrays incase of memory garbage
	for(i=0; i<n; i++){
		currentArray[i] = 0;
		previousArray[i] = 0;
	}
	
	//Loop through each line of the triangle (n lines)
	for(i=0; i<n; i++){
		
		//Copies currentArray to previousArray
		for(j=0; j<n; j++){
			previousArray[j] = currentArray[j];
		}
		
		//Assembles currentArray for line i
		for(j=0; j<n; j++){
			if(j==0){
				//If on first index, set it equal to one
				currentArray[j] = 1;
			} else {
				//If on any other index, calculate the value
				currentArray[j] = previousArray[j-1] + previousArray[j];
			}
		}
	
		//Display line i by printing currentArray
		for(j=0; j<n; j++){
			//Only print non-0 numbers (makes it look cleaner)
			if(currentArray[j] != 0){
				printf("%d\t", currentArray[j]);
			}
		}
		printf("\n");

	}
}






