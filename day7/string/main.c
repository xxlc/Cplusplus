#include "string.h"
#include <iostream>
using std::cout;
using std::endl;
using std::cin;

int main(){
	String str1;
	str1 = "hello world";
	cout << "str1 = " << str1 << endl;
	String str2(str1);
	cout << "str2 = " << str2 << endl;
	cin >> str2;
	cout << "str2 = " << str2 << endl;
	str1 += str2;
	cout << "str1 += str2 -----> " << str1 << endl;
	
	
	return 0;
}
