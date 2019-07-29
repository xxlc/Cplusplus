#include <string.h>
#include <string>
#include <iostream>

using std::endl;
using std::cout;
using std::cin;

class Computer{
//class 默认的访问权限是private
public:
	void setBrand(const char *brand);
	void setPrice(float price);
	void print();	
private:
	char _brand[20];
	float _price;
};

void Computer::setBrand(const char *brand){
	strcpy(_brand,brand);
}
void Computer::setPrice(float price){
	_price = price;
}
void Computer::print(){
	cout << "brand = " << _brand << endl
		 << "price = " << _price << endl;
}

int main(){
	Computer cp1;
	cp1.setBrand("thinkpad");
	cp1.setPrice(8888);
	cp1.print();
	return 0;
}
