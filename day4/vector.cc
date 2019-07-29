#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;
//vector 称为动态数组，可以动态扩容
//策略：当size() == capacity()时，
//		先申请 2×size() 的空间，
//		再将原来的元素全部复制到新空间，
//		然后再回收原来的空间，最后再添加新元素
//缺点：动态扩容的开销比较大
void display(vector<int> &vec){
	cout << "vec's size = " << vec.size() << endl;
	cout << "vec's capacity = " << vec.capacity() << endl;
}
int main(){
	vector<int> vec;
	//直接开100个int类型的空间，如果不开空间则初始 capacity=0
	vec.reserve(1000);
	//sizeof(vec)=24，因为 vec 对象中含有三个指针
	cout << "sizeof(vec) = " << sizeof(vec) << endl;

	vec.push_back(1);
	display(vec);
	vec.push_back(2);
	display(vec);
	vec.push_back(3);
	display(vec);
	cout << "vec.pop_back()" << endl;
	vec.pop_back();
	display(vec);
	return 0;
}
