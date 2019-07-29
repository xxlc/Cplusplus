#include <stdlib.h>
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

void* operator new(size_t size){
	cout << "void* operator new(size_t)" << endl;
	void* ret = malloc(size);
	return ret;
}
void operator delete(void* p){
	cout << "void operator delete(void*)" << endl;
	free(p);
}

class Student{
public:
	Student(int id,const char *name)
	:_id(id)
	,_name(new char[strlen(name)+1]()){
		//上面的new表达式调用的是类外的new函数
		cout << "Student(int, const char*)" << endl;
		strcpy(_name, name);
	}
	~Student(){
		cout << "~Student()" << endl;
		if(_name){
			//此处的delete表达式调用类外的delete
			delete [] _name;
			_name = nullptr;
		}
	}
	void print() const{
		cout << "id: " << _id << endl;
		cout << "name: " << _name << endl;
	}
	void* operator new(size_t size){
		cout << "class void* operator new(size_t)" << endl;
		void* ret = malloc(size);
		cout << "class malloc" << endl;
		return ret;
	}
	void operator delete(void* p){
		cout << "class void operator delete(void*)" << endl;
		free(p);
	}
private:
	int _id;
	char *_name;
};

int main(){
	//此处是new表达式，并非new函数
	Student *pstu = new Student(100, "Jackie");
	pstu->print();
	//此处是delete表达式，并非delete函数
	delete pstu;
	return 0;
}
