#include <iostream>
using std::cout;
using std::endl;

class Singleton{
	private:
		static Singleton *_pInstance;
	private:
		Singleton(){	cout << "Singleton()" << endl;	}
		~Singleton(){	cout << "~Singleton()" << endl;	}
	public:
		static Singleton* GetInstance(){
			if(nullptr == _pInstance){
				_pInstance = new Singleton();
			}
			return _pInstance;
		}
		static void DestroyInstance(){
			if(nullptr == _pInstance){
				delete _pInstance;
			}
		}
};
Singleton* Singleton::_pInstance = nullptr;

int main(){
	Singleton* p1 = Singleton::GetInstance();
	Singleton* p2 = Singleton::GetInstance();
	cout << "p1 = " << p1 << endl;
	cout << "p2 = " << p2 << endl;
	Singleton::DestroyInstance();
	return 0;
}
