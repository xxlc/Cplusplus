#include <iostream>
using std::cout;
using std::endl;

class Point{
public:
	Point() = default;//使用默认构造函数时需在定义变量时赋初值
	Point(int x,int y):_x(x),_y(y){}
	void print();
private:
	//赋初值用于默认构造函数
	int _x = 0;
	int _y = 0;
};
void Point::print(){
	cout << "(" << _x << ", " << _y << ")" << endl;
}

int main(){
	cout << "调用有参构造函数" << endl;
	Point p1(10,20);
	p1.print();
	
	cout << "调用默认构造函数" << endl;
	Point p2;
	p2.print();

	return 0;
}
