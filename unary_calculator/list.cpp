#include "list.h"

List::List(const List& copy) : _size(copy._size),_capacity(copy._capacity)
{
	if (copy._list != nullptr)
	{
		_list = new char[_capacity];
		for (int i = 0; i < _size; i++)
			_list[i] = copy._list[i];
	}
	else
		_list = nullptr;
}

const List& List::operator =(const List& copy)
{
	_size = copy._size;
	_capacity = copy._capacity;
	if (_list != nullptr)
		delete [] _list;
	if (copy._list != nullptr)
	{
		_list = new char[_capacity];
		for (int i = 0; i < _size; i++)
			_list[i] = copy._list[i];
	}
	else
		_list = nullptr;
	return *this;
}

const List& List::operator =(List&& move)
{
	if (_list != nullptr)
		delete [] _list;
	_size = move._size;
	_capacity = move._capacity;
	_list = move._list;
	move._list = nullptr;
	return *this;
}

const List List::operator +(const List& right) const
{
	const int newSize = _size + right._size,newCapacity = _capacity + right._capacity;
	char *newList = new char[newCapacity];
	int i = 0;
	for (; i < _size; i++)
		newList[i] = _list[i];
	for (; i < right._size; i++)
		newList[i] = right._list[i];
	return List(newSize,newCapacity,newList);
}

void List::push_back(const char x)
{
	if (_capacity <= _size)
	{
		const char *tmp = _list;
		_capacity = _capacity * 2 + 1;
		_list = new char[_capacity];
		if (tmp != nullptr)
		{
			for (int i = 0; i < _size; i++)
				_list[i] = tmp[i];
			delete [] tmp;
		}
	}
	_list[_size] = x;
	_size++;
}

void List::pop_back(void)
{
	assert(_list != nullptr);
	_size--;
}
