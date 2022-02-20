#include"point.h"

int main(){
	/*
	//structs::point p1={1,1,1};
	point p;
	point p1(1,10,20,30,"M1");
	//cout<<p1.x<<endl<<p1.y<<endl<<p1.z<<endl;
	cout<<p.get_x()<<endl<<p.get_y()<<endl<<p.get_z()<<endl;
	cout<<p1.get_x()<<endl<<p1.get_y()<<endl<<p1.get_z()<<endl<<p1.get_label()<<endl;
	*/
	
	point p1[10];  //points(x,y,z,label)
	
	for(int i=0; i<10;i++)
	{	
		p1[i].display();
	}
	
	return 0;
}