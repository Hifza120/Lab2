#include<iostream>
using namespace std;
class Shape{
public:
	virtual double  area() = 0;

};
class Circle : public Shape {
	double radius;
public:
	Circle(double r) :radius(r){}
	void setRadius(double r){
		this->radius = r;
	}
	double getRadius()const{
		return  radius;
	}
	double area(){
		return radius*radius*3.14;
	}
};
class Rectangle : public Shape{
	double length;
	double width;
public:
	Rectangle(double l, double w) :length(l), width(w){}
	void setLength(double length){
		this->length = length;
	}
	void setWidth(double Width){
		this->width = Width;
	}

	double getlength()const{
		return length;
	}

	double getWidth()const{
		return width;
	}
	double area(){
		return length*width;
	}
};
int main(){
	Shape*S1;
	Circle  C(2);
	S1 = &C;
	cout <<"Area "<< S1->area() << endl;
	Shape *S2;
	Rectangle R(10, 20);
	S2 = &R;
	cout <<"Area"<< S2->area() << endl;

	return 0;
}