#include <iostream>

using std::cout;
using std::endl;

class Example{
public:
	//初始化列表
	//数据成员初始化顺序只与其声明的顺序有关
	//当前初始化顺序：先‘_x’后‘_y’
	Example(int data)
	:_y(_x)
	,_x(data){
		cout << "Example()" << endl;
	}
	void print(){
		cout << "_x = " << _x << ",_y = " << _y << endl;
	}

private:
	int _x;
	int _y;
};

int main(){
	Example e(10);
	e.print();
	return 0;
}
