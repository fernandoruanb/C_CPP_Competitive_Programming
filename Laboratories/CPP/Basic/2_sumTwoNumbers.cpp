#include <iostream>

int main(void) {

	int num1, num2;

	std::cout << "Type two numbers: ";
	std::cin >> num1 >> num2;

	/*std::cout << "Type the second number: ";
	std::cin >> num2;*/

	std::cout << num1 << " + " <<  num2 << " = " << num1 + num2 << std::endl;
	return (0);
}
