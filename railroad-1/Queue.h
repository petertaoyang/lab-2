#ifndef QUEUE_H
#define QUEUE_H

#include "Deque.h"

template<typename T>
class Queue
{
public:
	Queue() {}
	~Queue() {}

	/**Delegate to qDeque push_front()*/
	void push(const T& value) { qDeque.push_front(value); }

	/**Delegate to qDeque pop_back()*/
	void pop(void) { qDeque.pop_back(); }

	/**Delegate to qDeque back()*/
	T& top(void) { return qDeque.back(); }

	/**Delegate to qDeque size()*/
	size_t size(void) { return qDeque.size(); }

	/**Delegate to qDeque at()*/
	T& at(size_t index) { return qDeque.at(index); }

	/**Delegate to qDeque toString()*/
	std::string toString(void) const { return qDeque.toString(); }

	/**Finds the index of value in vDeque, else return -1. */
	int find(T value)
	{
		if (qDeque.find(value) != -1) { return (qDeque.size() - 1 - qDeque.find(value)); }
		else { return -1; }
	}
private:
	Deque<T> qDeque;

};
#endif // !QUEUE_H

