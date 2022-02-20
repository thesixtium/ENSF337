#ifndef POINT_H
#define POINT_H

#include<iostream>

#define size 5
using namespace std;
/*
namespace structs{
struct point{
	double x,y,z;
};
}
*/
class point{
	private:
		double x, y, z;
		char label[size];
		const int test;
	public:
	// Add constructors prototypes
		point();
		point(int val, double x, double y, double z, char*l);
		
		void set_x(double x);
		void set_y(double y);
		void set_z(double z);
		void set_label(char *l);
		double get_x() const;
		double get_y() const;
		double get_z() const;
		const char* get_label() const;
		
		
		void display() const;
	
};

#endif