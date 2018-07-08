#include <fstream>
#include "list.h"

class Unary
{
	public:
		Unary(const int number = 0) {initNumber(number);}
		Unary(const Unary& copy) {initNumber(copy.intNumber());}
		friend std::istream& operator >>(std::istream& input,Unary& unary);
		friend std::ostream& operator <<(std::ostrema& output,const Unary& unary) const;
		const Unary& operator =(const Unary& copy) {initNumber(copy.intNumber());}
		const Unary& operator +(const Unary& right) const {return Unary(_number.size() + right._number.size());}
		const Unary& operator -(const Unary& right) const {return Unary(_number.size() - right._number.size());}
		const Unary& operator *(const Unary& right) const {return Unary(_number.size() * right._number.size());}
		const Unary& operator /(const Unary& right) const {return Unary(_number.size() / right._number.size());}
		const Unary& pow(const int number,const int exponent) const
		const int intNumber(void) const {return _number.size();}
	private:
		void initNumber(const int number);
		List _number;
};
