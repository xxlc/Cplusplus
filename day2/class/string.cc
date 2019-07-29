#include <string>
#include <iostream>

using std::string;
using std::cin;
using std::cout;
using std::endl;

int main(){
	//C++字符串操作
	string s1 = "hello";
	string s2 = "world";
	//字符串连接
	string s3 = s1 + 'x' + "wangdao" + s2;
	cout << "s3 = " << s3 << endl;
	//字符串追加
	s1.append(s2);
	cout << "s1 = " << s1 << endl;
	cout << "s1.size() = " << s1.size() << endl;
	cout << "s1.length() = " << s1.length() << endl;
	//对C++的字符串进行遍历
	for(size_t idx=0; idx!=s1.size(); ++idx){
		cout << s1[idx] << endl;
	}
	//查找子串
	size_t pos = s3.find("world");
	string s4 = s3.substr(pos, 4);
	cout << "s4 = " << s4 << endl;
	//将C++风格字符串转换为C风格字符串
	const char *pstr1 = s4.c_str();
	const char *pstr2 = s4.data();
	printf("pstr1 = %p\n",pstr1);
	printf("pstr2 = %p\n",pstr2);
	cout << "pstr1 = " << pstr1 << endl;
	cout << "pstr2 = " << pstr2 << endl;
	return 0;
}
