#include <stdlib.h>
#include <pthread.h>
#include <iostream>
using std::cout;
using std::endl;

class Singleton{
public:
	static Singleton* getInstance(){
		// 多线程安全的
		pthread_once(&_once, init);
		return _pInstance;
	}
	static void init(){
		_pInstance = new Singleton();
		::atexit(destroy);
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
	static pthread_once_t _once;
};
Singleton* Singleton::_pInstance = nullptr;
pthread_once_t Singleton::_once = PTHREAD_ONCE_INIT;

int main(){
	Singleton *p1 = Singleton::getInstance();
	Singleton *p2 = Singleton::getInstance();
	Singleton *p3 = Singleton::getInstance();
	cout << "p1 = " << p1 << endl
		 << "p2 = " << p2 << endl
		 << "p3 = " << p3 << endl;
	return 0;
}
