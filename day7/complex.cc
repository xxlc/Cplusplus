#include <iostream>
#include <limits>
using std::cout;
using std::endl;

class Complex{
public:
	Complex(double dreal, double dimag)
	: _dreal(dreal)
	, _dimag(dimag){
		cout << "Complex(double, double)" << endl;
	}
	void display() const{
		cout << _dreal << " + " << _dimag << "i" << endl;
	}
	//前置形式
	Complex& operator++(){
		++_dreal;
		++_dimag;
		return *this;
	}
	//后置形式
	Complex operator++(int){
		Complex tmp(*this);
		++_dreal;
		++_dimag;
		return tmp;
	}
	//复合赋值运算符都推荐以成员函数形式重载
	Complex& operator+=(const Complex &rhs){
		_dreal += rhs._dreal;
		_dimag += rhs._dimag;
		return *this;
	}
	//友元
	friend Complex operator+(const Complex &lhs, const Complex &rhs);
	friend bool operator==(const Complex &lhs, const Complex &rhs);

	friend std::ostream & operator<<(std::ostream &os, const Complex &rhs);
	friend std::istream & operator>>(std::istream &is, Complex &rhs);
private:
	  double _dreal;
	  double _dimag;
};

std::ostream & operator<<(std::ostream &os, const Complex &rhs){
	if(rhs._dimag == 0){
		os << rhs._dreal;
	}else{
		if(rhs._dreal == 0){
			if(rhs._dimag == 1){
				os << "i";
			}else if(rhs._dimag == -1){
				os << "-i";
			}else{
				os << rhs._dimag << "i";
			}
		}else{
			os << rhs._dreal;
			if(rhs._dimag > 0){
				os << " + " << rhs._dimag << "i";
			}else{
				os << " - " << rhs._dimag*(-1) << "i";
			}
		
		}
	}
	return os;
}
void readDoubleValue(std::istream &is, double &number){
	cout << ">> pls input a valid double value:" << endl;
	while(is >> number, !is.eof()){
		if(is.bad()){
			cout << "istream has corrupted!" << endl;
			return;
		}else if(is.fail()){
			is.clear();
			is.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
			cout << ">> pls input a valid double value:" << endl;
			continue;
		}
		break;
	}
}
std::istream & operator>>(std::istream &is, Complex &rhs){
	readDoubleValue(is, rhs._dreal);
	readDoubleValue(is, rhs._dimag);
	return is;	
}
Complex operator+(const Complex &lhs, const Complex &rhs){
	return Complex(lhs._dreal+rhs._dreal, lhs._dimag+rhs._dimag); 
}
bool operator==(const Complex &lhs, const Complex &rhs){
	return (lhs._dreal == lhs._dreal)&&(rhs._dimag == rhs._dimag);
}
bool operator!=(const Complex &lhs, const Complex &rhs){
	return !(lhs == rhs);
}

int main(void){
	Complex c1(1,2), c2(3,4);
	cout << "(++c1) = " << (++c1) << endl;
	//(++c1).display();
	cout << "c1 = " << c1 << endl;
	//c1.display();
	cout << "(c1++) = " << (c1++) << endl;
	//(c1++).display();
	cout << "c1 = " << c1 << endl;
	//c1.display();

	c1 += c2;
	cout << "c1 += c2; --> " << c1 << endl;
	//c1.display();


	Complex c3 = c1 + c2;
	cout << "c3 = " << c3 << endl;
	//c3.display();

	return 0;
}
