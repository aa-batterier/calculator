#include <iostream>
#include <stdlib>

class Unary
{
	public:
		Unary(const int number = 0) {initNumber(number);}
		const int intNumber(void) const {return _number.size();}
		const Unary& operator +(const Unary& right) const;
	private:
		void initNumber(const int number);
		std::vector<char> _number;
};
