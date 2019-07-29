#include <string.h>
#include <iostream>
#include <string>
using std::cout;
using std::endl;

class Computer{
public:
	Computer() = default;
	Computer(const char *brand,double price)
	:_brand(new char[strlen(brand)+1]())
	,_price(price){
		strcpy(_brand,brand);
		cout << "Computer(const char*,double)" << endl;
		_totalPrice += _price;
	}
	Computer(const Computer &rhs)
	:_brand(new char[strlen(rhs._brand)+1]())
	,_price(rhs._price){
		strcpy(_brand,rhs._brand);
		cout << "Computer(const Computer &)" << endl;
		_totalPrice += _price;
	}
	Computer & operator=(const Computer &rhs){
		if(this != &rhs){
			if(_brand == nullptr){
				delete [] _brand;
			}
			_brand = new char[strlen(rhs._brand)+1]();
			strcpy(_brand,rhs._brand);
			_price = rhs._price;
			cout << "Computer& operator=(const Computer &)" << endl;
		}
		return *this;
	}
	//const成员函数是不能修改数据成员的
	//this指针两边都有const关键字进行保护
	//因此const成员函数只能调用const成员函数，不能调用非const成员函数
	void print(/* Computer const * const this */) const{
		if(_brand){
			cout << _brand << endl
			 << _price << endl;
		}
		printTotalPrice();//可调用静态成员函数
	}

	//静态成员函数，没有隐含的this指针
	//不能直接访问非静态的数据成员和成员函数
	//只能访问静态数据成员和静态成员函数
	static void printTotalPrice(){
		//cout << "_brand = " << _brand << endl;使用非法
		//cout << "_price = " << _price << endl;使用非法
		//this_print();使用非法
		cout << "_totalPrice = " << _totalPrice << endl;
	}
	~Computer(){
		if(_brand){
			delete [] _brand;
		}
		cout << "~Computer" << endl;
	}
private:
	char *_brand = nullptr;
	double _price = 0;
	static double _totalPrice;//位于全局静态区，被所有对象共享
};

//静态数据成员的初始化必须放在类之外进行
double Computer::_totalPrice = 0.0;

int main(){
	Computer pc1;
	Computer pc2("hp",5555);
	Computer pc3("thinkpad",8888);
	Computer pc4("xiaomi",6666);

	pc1.print();
	pc2.print();
	pc3.print();
	pc4.print();

	pc1 = pc4;
	pc1.print();

	Computer::printTotalPrice();
	
	return 0;
}
