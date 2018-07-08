#include "unary.h"

friend std::istream& Unary::operator >>(std::istream& input,Unary& unary)
{
	int number;
	input >> number;
	unary.initNumber(number);
	return input;
}

friend std::ostream& Unary::operator <<(std::ostrema& output,const Unary& unary)
{
	output << unary.intNumber();
	return output;
}

const Unary& Unary::pow(const int number,const int exponent) const
{
	int sum = 1;
	for (int i = 0; i < exponent; i++)
		sum += sum * number;
	return Unary(sum);
}

void Unary::initNumber(const int number)
{
	for (int i = 0; i < number; i++)
		_number.push_back('X');
}
