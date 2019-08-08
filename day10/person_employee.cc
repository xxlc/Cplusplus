#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

class Person{
public:
	Person(const char *name, int age)
	: _name(name)
	, _age(age){	cout << "Person(const char *, int)" << endl;	}
	
	void display(){
		cout << "name       : " << _name << endl;
		cout << "age        : " << _age << endl;
	}
private:
	string _name;
	int _age;
};

class Employee: public Person{
public:
	Employee(const char *name, int age, const char *department, int salary)
	: Person(name, age)
	, _department(department)
	, _salary(salary){	cout << "Employee(const char *, ...)" << endl;	}

	void display(){
		this->Person::display();
		cout << "department : " << _department << endl;
		cout << "salary     : " << _salary << endl;
	}
private:
	string _department;
	int _salary;
};

int main(){
	Employee emp1("熊大",21,"研发部",9999);
	Employee emp2("熊二",19,"销售部",8888);
	Employee emp3("熊三",34,"人事部",7777);
	emp1.display();
	cout << endl;
	emp2.display();
	cout << endl;
	emp3.display();
	return 0;
}
