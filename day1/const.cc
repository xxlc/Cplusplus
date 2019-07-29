#include <iostream>

int main(){
	int number1 = 1;
	int number2 = 2;
	const int* p1 = &number1;
	*p1 = 10;
	p1 = &number2;

	int const *p2 = &number1;
	*p2 = 10;
	p2 = &number2;

	int* const p3 = &number1;
	*p3 = 10;
	p3 = &number2;
	return 0;
}
