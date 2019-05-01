#include "unary.h"

std::istream& operator >>(std::istream& input,Unary& unary)
{
	int number;
	input >> number;
	unary.initNumber(number);
	return input;
}

std::ostream& operator <<(std::ostream& output,const Unary& unary)
{
	output << unary.intNumber();
	return output;
}

const Unary Unary::pow(const Unary& exponent) const
{
	int sum = 1;
	for (int i = 0; i < exponent._number.size(); i++)
		sum += sum * _number.size();
	return Unary(sum);
}

const Unary Unary::pow(const int exponent) const
{
	int sum = 1;
	for (int i = 0; i < exponent; i++)
		sum += sum * _number.size();
	return Unary(sum);
}

void Unary::initNumber(const int number)
{
	for (int i = 0; i < number; i++)
		_number.push_back('X');
}
