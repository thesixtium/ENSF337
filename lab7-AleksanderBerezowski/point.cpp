#include"point.h"

//Add default and overload constructors

	point::point():test(0){
		x=0;
		y=0;
		z=0;
		for(int i=0; i<size;i++)
		{
			label[i]='\0';
		}
	}
	
	point::point(int val, double x, double y, double z, char* l):test(val){
		this->x=x;
		this->y=y;
		this->z=z;
		int i=0;
		while(l[i]){
			label[i]=l[i];
			i++;
		}
		label[i]='\0';
	}
//

void point::set_x(double xval){
	x=xval;
}
void point::set_y(double yval){
	y=yval;
}
void point::set_z(double zval){
	z=zval;
}
void point::set_label(char* plabel){
	int i=0;
	while(*plabel){
		label[i]=*plabel;
		plabel++;
		i++;
	}
	label[i]='\0';
		
}

double point::get_x() const{
	return x;
}
double point::get_y() const{
	return y;
}
double point::get_z() const{
	return z;
}
const char* point::get_label() const{
	return label;
}
void point::display() const{
	cout<<"Point information:"<<endl
		<<"Label:\t\t"<<label<<endl
		<<"X-coordinate:\t"<<x<<endl
		<<"Y-coordinate:\t"<<y<<endl
		<<"Z-coordinate:\t"<<z<<endl;
}
