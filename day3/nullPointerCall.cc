#include <iostream>
using std::cout;
using std::endl;

class NullPointerCall{
	public:
		void test1(){
			cout << "test1()" << endl;
		}
		void test2(int data){
			cout << "test2() data = " << data << endl;
		}
		static void test3(){
			cout << "test3() _data2 = " << _data2 << endl;
		}
		void test4(){
			cout << "test4() _data = " << this->_data << endl;
		}
	private:
		int _data;
		static int _data2;
};
int NullPointerCall::_data2 = 0;

int main(){
	//对象空指针可访问public函数，但不能访问到private中数据成员
	//一旦访问则会导致程序崩溃
	NullPointerCall *p = nullptr;
	p->test1();
	p->test2(10);
	p->test3();
	p->test4();
	return 0;
}
