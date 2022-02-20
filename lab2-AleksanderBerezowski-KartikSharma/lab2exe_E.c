 /*
 *  File Name: lab2exe_E.c
 *  Assignment: Lab 2 Exercise E
 *  Lab section: B04
 *  Completed by: Kartik Sharma and Aleksander Berezowski
 *  Submission Date: On or before Sept 28, 2021
 */


#include <stdio.h>
#include <stdlib.h>

void time_convert(int ms_time, int *minutes_ptr, double *seconds_ptr);

int main(void)
{
  int millisec;
  int minutes;
  double seconds;   
  int nscan;

  printf("Enter a time interval as an integer number of milliseconds: ");
  nscan = scanf("%d", &millisec);
  
  if (nscan != 1) {
    printf("Unable to convert your input to an int.\n");
    exit(1);
  }
  
  printf("Doing conversion for input of %d ms ... \n", millisec);

  time_convert(millisec, &minutes, &seconds);

  printf("That is equivalent to %d minute(s) and %f second(s).\n", minutes,
	 seconds);

  return 0;
}

void time_convert(int ms_time, int *minutes_ptr, double *seconds_ptr)
{
	//DESCRIPTION: Converts milliseconds to minutes and seconds
	//PROMISES: Update 2 variables with correct values in minutes and seconds via pointers
	//REQUIRES: ms_time must belong to all real numbers, fit within int type, and be in units of milliseconds
	//REQUIRES: minutes_ptr must be a pointer to an address that is an integer variable
	//REQUIRES: seconds_ptr must be a pointer to an address that is a double variable 

	*minutes_ptr = (int)ms_time/60000;
	double temp = (ms_time/100)%100;
	*seconds_ptr = temp/10;
}	