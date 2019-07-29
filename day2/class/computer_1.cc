#include <string.h>
#include <string>
#include <iostream>

using std::endl;
using std::cout;
using std::cin;

class Computer{
public:
	//默认构造函数
	Computer() = default;
	//带参构造函数
	Computer(const char *brand,float price)
	: _brand( new char[strlen(brand)+1]() )
	, _price(price){
		strcpy(_brand,brand);
		cout << "Computer(const char*,float)" << endl;
	}
	//拷贝构造函数
	//1. 拷贝构造函数的引用符号不能删除，否则会进入无限递归调用
	//	 Computer(const Computer rhs)
	//2. 参数中的const关键字不能删除，删除后当传递过来的是一个右值时，
	//	 就无法编译通过。例如传递是一个函数的返回值，由于函数的返回值
	//	 属于函数自身的栈空间，随函数结束而结束，则无法取地址
	Computer(Computer &rhs)
	: _brand( new char[strlen(rhs._brand)+1] )
	, _price(rhs._price){
		strcpy(_brand, rhs._brand);
		cout << "Computer(const Computer &rhs)" << endl;
	}
	//赋值函数
	Computer & operator=(const Computer &rhs){
		if(this != &rhs){
			cout << "Computer & operator=(const Computer &)" << endl;
			if(_brand){
				delete [] _brand;//回收原有空间
			}
			//重新申请空间
			_brand = new char[strlen(rhs._brand)+1]();
			strcpy(_brand,rhs._brand);
			_price = rhs._price;
		}
		return *this;
	}
	//析构函数
	~Computer(){
		//析构函数的作用是用来清理对象开辟的资源
		if(_brand)
			delete [] _brand;
		cout << "~Computer()" << endl;
	}
	void print();

private:
	char *_brand = NULL;
	float _price = 0;
};

void Computer::print(){
	if(_brand!=NULL){
		//cout << ptr << endl;
		//其中ptr为char型空指针时程序会崩溃
		cout << "brand = " << _brand << endl
			 << "price = " << _price << endl;
	}else{
		cout << "_brand == NULL" << endl;
	}
}

int main(){
	cout << "----------------默认构造函数-------------" << endl;
	Computer cp1;
	cp1.print();

	cout << "----------------带参构造函数-------------" << endl;
	Computer cp2("Think Pad",8888);
	cp2.print();

	cout << "----------------new Computer(\"hp\",5555)" << endl;
	Computer *p = new Computer("hp",5555);
	p->print();
	delete p;//释放空间,将自动会调用析构函数

	cout << "----------------复制构造函数-------------" << endl;
	Computer cp3(cp2);
	cp3.print();

	cout << "----------------赋值函数-----------------" << endl;
	cp1 = cp2;
	cp1.print();
	return 0;
}
