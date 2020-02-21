#ifndef STACK_H
#define STACK_H

#include "Deque.h"

template<typename T>
class Stack
{
public:
	Stack() {}
	~Stack() {}
	
	/**Delegate to sDeque push_front()*/
	void push(const T& value) { sDeque.push_front(value); }

	/**Delegate to sDeque pop_front()*/
	void pop(void) { sDeque.pop_front(); }

	/**Delegate to sDeque front()*/
	T& top(void) { return sDeque.front(); }

	/**Delegate to sDeque size()*/
	size_t size(void) { return sDeque.size(); }

	/**Delegate to sDeque at()*/
	T& at(size_t index) { return sDeque.at(index); }

	/**Delegate to sDeque toString() (sorted Last in to First in)*/
	std::string toString(void) const { return sDeque.toString(); }

	/**Finds the index of value in vDeque, else return -1. */
	int find(T value)
	{
		if (sDeque.find(value) != -1) { return (sDeque.size() - 1 - sDeque.find(value)); }
		else { return -1; }
	}
private:
	Deque<T> sDeque;

};
#endif // !STACK_H

