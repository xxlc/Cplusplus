#include <stdlib.h>
#include <iostream>
using std::cout;
using std::endl;

class Singleton{
public:
	static Singleton* getInstance(){
		if(nullptr == _pInstance){
			::atexit(destroy);
			_pInstance = new Singleton();
		}
		return _pInstance;
	}
	static void destroy(void){
		if(_pInstance){
			delete _pInstance;
		}
	}

private:
	Singleton(){	cout << "Singleton()" << endl;	}
	~Singleton(){	cout << "~Singleton()" << endl;	}
private:
	static Singleton *_pInstance;
};
Singleton* Singleton::_pInstance = nullptr;

int main(){
	Singleton *p1 = Singleton::getInstance();
	Singleton *p2 = Singleton::getInstance();
	Singleton *p3 = Singleton::getInstance();
	cout << "p1 = " << p1 << endl
		 << "p2 = " << p2 << endl
		 << "p3 = " << p3 << endl;
	return 0;
}
