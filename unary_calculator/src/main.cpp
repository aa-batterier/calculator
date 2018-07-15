#include <iostream>
#include "unary.h"

int main(void)
{
	for (;;)
	{
		std::string op;
		Unary number1,number2;
		std::cout << "Write in operator (to quit write quit): ";
		std::cin >> op;
		if (op == "quit")
			break;
		std::cout << "Write the first number: ";
		std::cin >> number1;
		std::cout << "Write the second number: ";
		std::cin >> number2;
		if (op == "+")
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
			std::cout << number1.pow(number2) << std::endl;
			continue;
		}
	}
	return 0;
}
