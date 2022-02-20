/*
 *  File Name: lab2exe_A.c
 *  Assignment: Lab 2 Exercise A
 *  Lab section: B04
 *  Completed by: Kartik Sharma and Aleksander Berezowski
 *  Submission Date: On or before Sept 28, 2021
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Global Constant Definitions
const double G = 9.8;   /* gravitation acceleration 9.8 m/s^2 */
const double PI = 3.141592654;

//Global Function Definitions
double degree_to_radian(double degrees);
double Projectile_travel_distance(double gravity, double v, double angle);
double Projectile_travel_time(double gravity, double v, double angle);
void create_table(double velocity);

//Main Function
int main(void)
{
    int n;
    double velocity;
    
    printf ("Please enter the velocity at which the projectile is launched (m/sec): ");
    n = scanf("%lf" ,&velocity);
    
    if(n != 1)
    {
        printf("Invlid input. Bye...");
        exit(1);
    }
    
    while (velocity < 0 )
    {
        printf ("please enter a positive number for velocity: ");
        n = scanf("%lf", &velocity);
        if(n != 1)
        {
            printf("Invlid input. Bye...");
            exit(1);
        }
    }
    
      create_table(velocity);
    return 0;
}


double degree_to_radian(double degrees)
{
	//DESCRIPTION: Converts unit "Degrees" to SI unit "Radian"
	//PROMISES: Return value is a unit in radian
	//REQUIRES: degrees must belong to all real numbers, fit within double type, and be in units of degrees
	
	return (degrees/180)*PI;
}	
	
double Projectile_travel_distance(double gravity, double velocity, double angle)
{
	//DESCRIPTION: Calculates the approximate distance traveled by a projectile
	//PROMISES: Returns value is a distance in meters
	//REQUIRES: gravity must belong to all real numbers, fit within double type, be in units of m^2/s, and not be 0
	//REQUIRES: velocity must belong to all real numbers, fit within double type, and be in units of m/2
	//REQUIRES: angle must belong to all real numbers, fit within double type, and be in radians
	
	double distance = ((velocity*velocity)/gravity)*(sin(2*degree_to_radian(angle)));
	return distance;
}	

double Projectile_travel_time(double gravity, double velocity, double angle)
{
	//DESCRIPTION: Calculates the approximate travel time to maximum horizontal distance by a projectile
	//PROMISES: Returns value is a time in seconds
	//REQUIRES: gravity must belong to all real numbers, fit within double type, be in units of m^2/s, and not be 0
	//REQUIRES: velocity must belong to all real numbers, fit within double type, and be in units of m/2
	//REQUIRES: angle must belong to all real numbers, fit within double type, and be in radians
	
	double time = (2 * velocity * sin(degree_to_radian(angle)))/gravity;
	return time;
}

void create_table(double velocity)
{
	//DESCRIPTION: Creates a table of values with columns of angle, time, and distance
	//PROMISES: Returns nothing, prints table of values
	//REQUIRES: velocity must belong to all real numbers, fit within double type, and be in units of m/2
	
	printf("Angle\t\tt\t\td\n(deg)\t\t(sec)\t\t(m)\n");
	for (double i = 0; i<=90; i+=5)
	{
		double t = Projectile_travel_time(G,velocity,i);
		double d = Projectile_travel_distance(G, velocity, i);
		
		printf("%f\t%f\t%f\n",i, t, d);
	}	
}
