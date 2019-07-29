#include <string.h>
#include <string>
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

class String
{
	public:
		//默认构造函数
		String() = default;
		//带参数的构造函数
		String(const char *pstr)
			:_pstr(new char[strlen(pstr)+1]()){
				strcpy(_pstr,pstr);
			}
		//复制构造函数
		String(const String & rhs)
			:_pstr(new char[strlen(rhs._pstr)+1]()){
				strcpy(_pstr,rhs._pstr);
			}
		//赋值函数
		String & operator=(const String & rhs){
			if(this != &rhs){
				if(_pstr){
					delete [] _pstr;
				}
				_pstr = new char[strlen(rhs._pstr)+1]();
				strcpy(_pstr,rhs._pstr);
			}
			return *this;
		}
		//析构函数
		~String(){
			if(_pstr){
				delete [] _pstr;
			}
		};
		void print();
	private:
		char * _pstr = NULL;
};
void String::print(){
	if(_pstr){
		cout << _pstr << endl;
	}
}

int main(void)
{
	String str1;
	str1.print();

	String str2 = "Hello,world";
	String str3("wangdao");

	str2.print();		
	str3.print();	

	String str4 = str3;
	str4.print();

	str4 = str2;
	str4.print();

	return 0;
}
