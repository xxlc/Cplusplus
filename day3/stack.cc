#include <iostream>
using std::cout;
using std::endl;

class Stack{
private:
	int _stack[10] = {0};
	int _idx = 0;
public:
	Stack() = default;
	~Stack(){}

	void push(int);	//元素入栈
	void pop();		//元素出栈
	int top();		//读栈顶元素
	bool empty();	//判断栈空
	bool full();	//判断栈满
};
void Stack::push(int data){
	if(true == full()){
		cout << "stack full" << endl;
		return;
	}
	_stack[_idx] = data;
	_idx++;
}
void Stack::pop(){
	if(true == empty()){
		cout << "stack empty" << endl;
		return;
	}
	_idx--;
}
int Stack::top(){
	if(true == empty()){
		cout << "stack empty" << endl;
		return -1;
	}
	return _stack[_idx-1];
}
bool Stack::empty(){
	if(0 == _idx){
		return true;
	}else{
		return false;
	}
}
bool Stack::full(){
	if(sizeof(_stack) == _idx){
		return true;
	}else{
		return false;
	}
}


int main(){
	Stack s1;
	s1.push(10);
	s1.push(12);
	s1.push(14);
	cout << "Stack top = " << s1.top() << endl;
	s1.pop();
	cout << "Stack top = " << s1.top() << endl;
	return 0;
}
