#include <iostream>
using std::cout;
using std::endl;
//要求：定义一个类，只能由该类创建唯一的一个对象
//1. 该对象不能是栈/全局对象
//2. 只能将该对象放在堆上

//应用场景：
//1. 可以用单例模式替换掉全局变量
//2. 配置文件中的存储都是程序的输入信息
//3。 词典库，网页库
class Singleton{
public:
	static Singleton *getInstance(){
		if(nullptr == _pInstance){
			_pInstance = new Singleton();
		}
		return _pInstance;
	}
	static void destroy(){
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
Singleton *Singleton::_pInstance = nullptr;

int main(){
	//Singleton s1;非法
	//Singleton *p0 = new Singleton;非法
	Singleton *p1 = Singleton::getInstance();
	Singleton *p2 = Singleton::getInstance();
	Singleton *p3 = Singleton::getInstance();
	cout << "p1 = " << p1 << endl
		 << "p2 = " << p2 << endl
		 << "p3 = " << p3 << endl;
	//delete p1;非法
	Singleton::destroy();
	return 0;
}
