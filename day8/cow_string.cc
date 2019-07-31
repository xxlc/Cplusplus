#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

class CowString{
public:
	CowString()
		: _pstr(new char[5]()+4){
			// new char[5] 中前四个字节代表一个int变量
			initRefCount();
			cout << "CowString()" << endl;
		}
	CowString(const char *pstr)
		: _pstr(new char[strlen(pstr)+5]()+4){
			initRefCount();
			strcpy(_pstr, pstr);
			cout << "CowString(const char *)" << endl;
		}
	CowString(const CowString &rhs)
		: _pstr(rhs._pstr){
			increRefCount();
			cout << "CowString(const CowString &)" << endl;
		}
	~CowString(){
		if( returnRefCount() > 1 ){
			decreRefCount();
		}else{
			release();
		}
		cout << "~CowString()" << endl;
	}
	//function~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	CowString& operator=(const CowString &rhs){
		cout << "CowString& operator=(const CowString &)" << endl;
		if(this != &rhs){
			release();
			_pstr = rhs._pstr;
			increRefCount();
		}
		return *this;
	}
	int returnRefCount(){
		return *(int*)(_pstr - 4);
	}
	const char* c_str() const{
		return _pstr;
	}
	int size() const{
		return strlen(_pstr);
	}
	char& operator[](int index);
	//friend~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	friend std::ostream& operator<<(std::ostream &os,const CowString &rhs);
private:
	void initRefCount()	{	*(int*)(_pstr - 4) = 1;	}
	void increRefCount(){	*(int*)(_pstr - 4) += 1;}
	void decreRefCount(){	*(int*)(_pstr - 4) -= 1;}
	void release()		{		delete [] (_pstr-4);}
private:
	char *_pstr;
};

char& CowString::operator[](int index){
	if( index>=0 && index<size() ){
		if( returnRefCount() > 1 ){
			char *tmp = new char[size()+5]() + 4;
			strcpy(tmp, _pstr);
			decreRefCount();
			_pstr = tmp;
			initRefCount();
		}
		return _pstr[index];
	}else{
		static char nullchar = '\0';
		return nullchar;
	}
}
std::ostream& operator<<(std::ostream &os,const CowString &rhs){
	os << "_pstr = " << rhs._pstr;
	return os;
}

int main(){
	CowString s1 = "hello world";
	CowString s2 = s1;
	CowString s3;
	s3 = s1;
	cout << "执行赋值操作之后" << endl;
	cout << s1;
	printf("\ts1.c_str() = %p\n", s1.c_str());
	cout << s2;
	printf("\ts2.c_str() = %p\n", s2.c_str());
	cout << s3;
	printf("\ts3.c_str() = %p\n", s3.c_str());
	cout << "s1的引用计数 = " << s1.returnRefCount() << endl << endl;

	s3[0] = 'X';
	cout << "s3[0] = 'X';" << endl;
	cout << "执行写操作之后" << endl;
	cout << s1;
	printf("\ts1.c_str() = %p\n", s1.c_str());
	cout << s2;
	printf("\ts2.c_str() = %p\n", s2.c_str());
	cout << s3;
	printf("\ts3.c_str() = %p\n", s3.c_str());
	cout << "s1的引用计数 = " << s1.returnRefCount() << endl << endl;
	
	cout << "s2[0] = " << s2[0] << endl;
	cout << "执行读操作之后" << endl;
	cout << s1;
	printf("\ts1.c_str() = %p\n", s1.c_str());
	cout << s2;
	printf("\ts2.c_str() = %p\n", s2.c_str());
	cout << s3;
	printf("\ts3.c_str() = %p\n", s3.c_str());
	cout << "s1的引用计数 = " << s1.returnRefCount() << endl << endl;


	return 0;
}
