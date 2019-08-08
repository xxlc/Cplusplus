#include <iostream>
using std::cout;
using std::endl;
const static double PI = 3.1415926;

class Circle{	//Circle类
public:
	Circle() = default;
	Circle(double r)
	: _r(r){	cout << "Circle(double)" << endl;	}

	double getArea(){
		// 获取圆的面积
		return PI*_r*_r;
	}
	double getPerimeter(){
		// 获取圆的周长
		return 2*PI*_r;
	}
	void show(){
		cout << "the r of Circle = " << _r << endl;
		cout << "the area of Circle = " << getArea() << endl;
		cout << "the perimeter of Circle = " << getPerimeter() << endl;
	}
private:
	double _r = 0;
};
class Cylinder		//Cylinder类
: private Circle{
public:
	Cylinder(double r, double h)
	: Circle(r)
	, _h(h){	cout << "Cylinder(double, double)" << endl;	}
	
	double getVolume(){
		// 获取圆柱体的体积
		return getArea()*_h;
	}
	void showVolume(){
		// 将圆柱体的体积输出到屏幕
		cout << "The Volume of Cylinder = " << getVolume() << endl;
	}
private:
	double _h;
};

int main(){
	Circle c1(3.0);
	c1.show();
	Cylinder c2(3.0, 2);
	c2.showVolume();
	return 0;
}
