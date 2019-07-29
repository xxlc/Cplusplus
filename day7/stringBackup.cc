#include <string.h>

#include <iostream>
using std::cout;
using std::endl;

class String{
public:
	String() = default;
	String(const char* pstr)
	: _capacity(strlen(pstr))
	, _pstr(new char[_capacity+1]()){
		strcpy(_pstr, pstr);
		cout << "String()" << endl;
	}
	String(const String& str)
	: _capacity( strlen(str._pstr) )
	, _pstr( new char[_capacity+1]() ){
		strcpy(_pstr, str._pstr);
		cout << "String()" << endl;
	}
	~String(){
		if(_pstr != nullptr){
			delete [] _pstr;
			_capacity = 0;
		}
		cout << "~String()" << endl;
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
		}
	}
private:
	int _capacity = 0;
	char *_pstr = nullptr;
};


//运算符以成员函数形式重载
String& String::operator=(const String &str){
	if(this != &str){
		if(_pstr != nullptr){
			delete [] _pstr;
		}
		_capacity =	str._capacity; 
		_pstr = new char[_capacity+1]();
		strcpy(_pstr, str._pstr);
	}
	return *this;
}
String& String::operator=(const char *pstr){
	if(_pstr != pstr){
		if(_pstr != nullptr){
			delete [] _pstr;
		}
		_capacity = strlen(pstr);
		_pstr = new char[_capacity+1]();
		strcpy(_pstr, pstr);
	}
	return *this;
}
String& String::operator+=(const String &str){
	if(str._pstr != nullptr){
		if(_pstr != nullptr){
			_capacity += str._capacity;
			char *tmp = new char[_capacity+1]();
			strcat(tmp, _pstr);
			strcat(tmp, str._pstr);
			delete [] _pstr;
			_pstr = tmp;
		}else{
			*this = str;
		}
	}
	return *this;	
}
String& String::operator+=(const char *pstr){
	if(pstr != nullptr){
		if(_pstr != nullptr){
			_capacity += strlen(pstr);
			char *tmp = new char[_capacity+1]();
			strcat(tmp, _pstr);
			strcat(tmp, pstr);
			delete [] _pstr;
			_pstr = tmp;
		}else{
			*this = pstr;
		}
	}
	return *this;
}
char& String::operator[](std::size_t index){
	if( index < strlen(_pstr) ){
		return _pstr[index];
	}else{
		cout << "the index of string access to cross-border" << endl;
		exit(0);
	}
}
const char& String::operator[](std::size_t index) const{
	if( index < strlen(_pstr) ){
		return _pstr[index];
	}else{
		cout << "the index of string access to cross-border" << endl;
		exit(0);
	}
}
std::size_t String::size() const{
	return strlen(_pstr);
}
const char* String::c_str() const{
	return _pstr;
}

//运算符以友元函数形式重载
bool operator==(const String &lhs, const String &rhs){
	if( !strcmp(lhs._pstr, rhs._pstr) ){
		return true;
	}else{
		return false;
	}
}
bool operator!=(const String &lhs, const String &rhs){
	if( lhs == rhs ){
		return false;
	}else{
		return true;
	}
}
bool operator<(const String &lhs, const String &rhs){
	if( strcmp(lhs._pstr, rhs._pstr)<0 ){
		return true;
	}else{
		return false;
	}
}
bool operator>(const String &lhs, const String &rhs){
	if( strcmp(lhs._pstr, rhs._pstr)>0 ){
		return true;
	}else{
		return false;
	}
}
bool operator<=(const String &lhs, const String &rhs){
	if( lhs > rhs ){
		return false;
	}else{
		return true;
	}
}
bool operator>=(const String &lhs, const String &rhs){
	if( lhs < rhs ){
		return false;
	}else{
		return true;
	}
}

std::ostream& operator<<(std::ostream &os, const String &str){
	os << str._pstr;
	return os;
}
std::istream& operator>>(std::istream &is, String &str){
	str.~String();
	str._capacity = 5;
	str._pstr = new char[str._capacity+1]();
	char ch;
	int flag = 0;
	while(is>>ch, !is.eof()){
		if(ch!='\n'&&ch!=' '){
			flag = 1;
			str.push_back(ch);
		}else{
			if(1 == flag)
				break;
		}
	}
	return is;
}
