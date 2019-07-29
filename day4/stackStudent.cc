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
	~Student(){
		cout << "~Student()" << endl;
		if(_name){
			delete [] _name;
			_name = nullptr;
		}
	}
	void print() const{
		cout << "id: " << _id << endl;
		cout << "name: " << _name << endl;
	}
private:
	void* operator new(size_t size);
	void operator delete(void *p);
private:
	int _id;
	char *_name;
};

int main(){
	//Student *pstu = new Student(100, "Jackie");
	//上式将报错：operator new 是一个私有函数
	Student s1(11,"Rose");
	s1.print();
	//栈对象不用自行销毁，等待跳出作用域后自行销毁
	return 0;
}
