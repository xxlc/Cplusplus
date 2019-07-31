#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

class CowString{
	class PROXY{
	public:
		PROXY(CowString &cowStr, int idx)
		: _cowStr(cowStr)
		, _idx(idx){
			cout << "PROXY()" << endl;
		}
		char& operator=(const char &ch){
			cout << "PROXY operator=(const char &)" << endl;
			if( _idx>=0 && _idx<_cowStr.size() ){
				if( _cowStr.returnRefCount() > 1 ){
					_cowStr.decreRefCount();
					char *tmp = new char[strlen(_cowStr._pstr)+5]() + 4;
					strcpy(tmp, _cowStr._pstr);
					_cowStr._pstr = tmp;
					_cowStr.initRefCount();
				}
				_cowStr._pstr[_idx] = ch;
				return _cowStr._pstr[_idx];
			}else{
				static char nullchar = '\0';
				return nullchar;
			}
		}
		operator char(){
			cout << "PROXY operator char()" << endl;
			return _cowStr._pstr[_idx];
		}
	private:
		CowString &_cowStr;
		int _idx;
	};

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
	PROXY operator[](int index){
		return PROXY(*this, index);	
	}
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
	cout << "执行写操作之后" << endl;
	cout << s1;
	printf("\ts1.c_str() = %p\n", s1.c_str());
	cout << s2;
	printf("\ts2.c_str() = %p\n", s2.c_str());
	cout << s3;
	printf("\ts3.c_str() = %p\n", s3.c_str());
	cout << "s1的引用计数 = " << s1.returnRefCount() << endl << endl;
	
	cout << s2[0] << endl;
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
