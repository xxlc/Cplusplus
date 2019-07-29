#include <iostream>
using std::cout;
using std::endl;
//循环队列类
class Queue{
	private:
		//只能存9个元素
		int _capacity;
		int *_queue;
		int _head;
		int _tail;
		Queue() = default;
	public:
		Queue(int capacity)
			:_capacity(capacity)
			,_queue(new int[capacity+1]())
			,_head(0),_tail(0){}
		~Queue(){
			if(_queue){
				delete [] _queue;
			}
		}

		void push(int);	//元素入队
		void pop();		//元素出队
		int front();	//读取队头元素
		int back();		//读取队尾元素
		bool empty();	//判断队列是否为空
		bool full();	//判断队列是否已满
};
void Queue::push(int data){
	if(true == full()){
		return;
	}
	_queue[_tail] = data;
	_tail = (_tail+1) % _capacity;
}
void Queue::pop(){
	if(true == empty()){
		return;
	}
	_head = (_head+1) % _capacity;
}
int Queue::front(){
	if(true == empty()){
		return -1;	
	}
	return _queue[_head];
}
int Queue::back(){
	if(true == empty()){
		return -1;
	}
	int t = _tail;
	if(t == 0){
		t = _capacity;
	}
	return _queue[t-1];
}
bool Queue::empty(){
	if(_head == _tail){
		cout << "Queue empty" << endl;
		return true;
	}else{
		return false;
	}
}
bool Queue::full(){
	if( (_tail+1)%_capacity == _head ){
		cout << "Queue full" << endl;
		return true;
	}else{
		return false;
	}
}

int main(){
	Queue q(10);
	for(int i=0; i<11; i++){
		cout << i << " enQueue" << endl;
		q.push(i);
	}
	for(int i=0; i<11; i++){
		cout << "deQueue " << q.front() << endl;
		q.pop();
	}
	return 0;
}
