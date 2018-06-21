#include <iostream>
#include <stdexcept>
#include <vector>
using std::runtime_error;

/*
int sub(int a, int b) {
	if (a < 0 || b < 0) {
		throw std::invalid_argument("received negative value");
	}
	
	int c = a + b;
	std::cout << c << std::endl;
	return c;
}

int main() {
	try {
		sub(3, -1);
	}
	catch (const std::invalid_argument& ia) {
		std::cerr << "Invalid argument: " << ia.what() << '\n';
	}
	getchar();
	return 0;
}
*/

/*
int main() {
	std::vector<int> v(5);
	try {
		v.at(20) = 100;
	}
	catch (const std::out_of_range& oor){
		std::cerr << "Out of Range error: " << oor.what() << '\n';
	}
	getchar();
	return 0;
}
*/

/*
double division(int a, int b) {
	if (b == 0) {
		throw "Division by zero condition!";
	}
	return (a / b);
}
int main() {
	int x = 50;
	int y = 0;
	double z = 0;

	try {
		z = division(x, y);
		std::cout << z << std::endl;
	}
	catch (const char* msg) {
		std::cerr << msg << std::endl;
	}
	getchar();
	return 0;
}*/

class DivideByZero : public runtime_error {
public: 
	DivideByZero::DivideByZero()
		:runtime_error("divided by zero"){}
};

double sub(int a, int b) {
	if (b == 0) {
		throw DivideByZero();
	}
	return static_cast<double>(a / b);
}

int main() {
	int num1;
	int num2; 
	double result; 

	while (std::cin >> num1 >> num2) {
		try {
			result = sub(num1, num2);
			std::cout << "The result of dividing is: " << result << std::endl;
		}
		catch(DivideByZero &DivideByZero){
			std::cout << "Exception occurred: " << DivideByZero.what() << std::endl;
		}
	}
	getchar();
	return 0;
}