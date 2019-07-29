#pragma once
#include <string.h>
#include <iostream>

class String{
public:
	String() = default;
	String(const char* pstr)
	: _capacity(strlen(pstr))
	, _pstr(new char[_capacity+1]()){
		strcpy(_pstr, pstr);
		std::cout << "String()" << std::endl;
	}
	String(const String& str)
	: _capacity( strlen(str._pstr) )
	, _pstr( new char[_capacity+1]() ){
		strcpy(_pstr, str._pstr);
		std::cout << "String()" << std::endl;
	}
	~String(){
		if(_pstr != nullptr){
			delete [] _pstr;
			_capacity = 0;
		}
		std::cout << "~String()" << std::endl;
	}

	//运算符以成员函数形式重载
	String& operator=(const String &);
	String& operator=(const char *);
	String& operator+=(const String &);
	String& operator+=(const char *);
	char& operator[](std::size_t index);
	const char& operator[](std::size_t index) const;
	std::size_t size() const;
	const char* c_str() const;

	//运算符以友元函数形式重载
	friend bool operator==(const String &, const String &);
	friend bool operator!=(const String &, const String &);
	friend bool operator<(const String &, const String &);
	friend bool operator>(const String &, const String &);
	friend bool operator<=(const String &, const String &);
	friend bool operator>=(const String &, const String &);

	friend std::ostream& operator<<(std::ostream &, const String &);
	friend std::istream& operator>>(std::istream &, String &);
private:
	void push_back(char ch){
		char *tmp;
		if(strlen(_pstr) < _capacity){
			//此处将字符添加到_pstr后面
			strncat(_pstr, &ch, 1);
		}else{
			if(0 == _capacity){
				_capacity = 1;
			}
			_capacity += _capacity;
			tmp = new char[_capacity+1]();
			if(nullptr != _pstr){
		   		strcpy(tmp, _pstr);
				delete [] _pstr;
			}
			strncat(tmp, &ch, 1);
			_pstr = tmp;
		}
	}
private:
	int _capacity = 0;
	char *_pstr = nullptr;
};
