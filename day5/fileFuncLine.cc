#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;

int main(){
	cout << __FILE__ << endl
		 << __LINE__ << endl
		 << __FUNCTION__ << endl;

	cout << string("[").append(__FILE__).append(":")
			.append(__FUNCTION__).append(":")
			.append(std::to_string(__LINE__)).append("]") << endl;
	return 0;
}
