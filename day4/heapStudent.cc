#include <stdlib.h>
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

class Student{
public:
	Student(int id,const char *name)
	:_id(id)
	,_name(new char[strlen(name)+1]()){
		cout << "Student(int, const char*)" << endl;
		strcpy(_name, name);
	}
	void print() const{
		cout << "id: " << _id << endl;
		cout << "name: " << _name << endl;
	}
	void destroy(){
		cout << "delete this before:" << endl;
		//自行销毁堆对象
		//delete表达式时先调用析构函数，再执行operator delete(this)
		delete this;
		cout << "delete this after:" << endl;
	}
private:
	~Student(){
		cout << "~Student()" << endl;
		if(_name){
			delete [] _name;
			_name = nullptr;
		}
	}
	int _id;
	char *_name;
};

int main(){
	//Student s1(1,"sd");报错
	Student *pstu = new Student(100, "Jackie");
	pstu->print();
	pstu->destroy();
	return 0;
}
