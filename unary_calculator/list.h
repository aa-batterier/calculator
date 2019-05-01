#include <cassert>

class List
{
	public:
		List(const int size = 0,const int capacity = 0,char *list = nullptr) : _size(size),_capacity(capacity),_list(list) {}
		List(const List& copy);
		List(List&& move) : _size(move._size),_capacity(move._capacity),_list(move._list) {move._list = nullptr;}
		~List(void) {if (_list != nullptr) delete [] _list;}
		const List& operator =(const List& copy);
		const List& operator =(List&& move);
		const List operator +(const List& right) const;
		void push_back(const char x);
		void pop_back(void);
		const char back(void) const {return _list[_size-1];}
		const int size(void) const {return _size;}
	private:
		int _size,_capacity;
		char *_list;
};
