#include <iostream>
using std::cout;
using std::endl;

class Singleton{
	class AutoRelease{
	public:
		AutoRelease(){	cout << "AutoRelease()" << endl;	}
		~AutoRelease(){
			if(_pInstance){
				delete _pInstance;
				cout << "~AutoRelease()" << endl;
			}
		}
	};
public:
	static Singleton* getInstance(){
		if(nullptr == _pInstance){
			_pInstance = new Singleton();
		}
		return _pInstance;
	}

private:
	Singleton(){	cout << "Singleton()" << endl;	}
	~Singleton(){	cout << "~Singleton()" << endl;	}
private:
	static Singleton *_pInstance;
	static AutoRelease _auto;
};

Singleton* Singleton::_pInstance = nullptr;
Singleton::AutoRelease Singleton::_auto;

int main(){
	Singleton *p1 = Singleton::getInstance();
	Singleton *p2 = Singleton::getInstance();
	Singleton *p3 = Singleton::getInstance();
	cout << "p1 = " << p1 << endl
		 << "p2 = " << p2 << endl
		 << "p3 = " << p3 << endl;
	return 0;
}
