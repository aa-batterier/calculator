#include <iostream>
#include "unary.h"

int main(void)
{
	std::string op;
	Unary number1,number2;
	for (;;)
	{
		std::cout << "Write the first number: ";
		std::cin >> number1;
		std::cout << "Write in operator (to quit write quit): ";
		std::cin >> op;
		std::cout << "Write the second number: ";
		std::cin >> number2;
		if (op == "quit")
			break;
		else if (op == "+")
		{
			std::cout << number1 + number2 << std::endl;
			continue;
		}
		else if (op == "-")
		{
			std::cout << number1 - number2 << std::endl;
			continue;
		}
		else if (op == "*")
		{
			std::cout << number1 * number2 << std::endl;
			continue;
		}
		else if (op == "/")
		{
			std::cout << number1 / number2 << std::endl;
			continue;
		}
		else if (op == "e")
		{
			std::cout << pow(number1,number2) << std::endl;
			continue;
		}
	}
	return 0;
}
