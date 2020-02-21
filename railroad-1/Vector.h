#ifndef VECTOR_H
#define VECTOR_H

#include "Deque.h"

template<typename T>
class Vector
{
public:
	Vector() {}
	~Vector() {}

	/**Delegate to vDeque push_back()*/
	void pushBack(const T& value) { vDeque.push_back(value); }

	/**Delegate to vDeque pop_back()*/
	void popBack(void) { vDeque.pop_back(); }

	/**Delegate to vDeque back()*/
	T& back(void) { return vDeque.back(); }

	/**Delegate to vDeque size()*/
	size_t size(void) { return vDeque.size(); }

	/**Delegate to vDeque at()*/
	T& at(size_t index) { return vDeque.at(index); }

	/**Delegate to vDeque toString()*/
	std::string toString(void) const { return vDeque.toString(); }

	/**Finds the index of value in vDeque, else return -1. */
	int find(T value)
	{
		if (vDeque.find(value) != -1) { return vDeque.find(value); }
		else { return -1; }
	}

private:
	Deque<T> vDeque;

};
#endif // !VECTOR_H

