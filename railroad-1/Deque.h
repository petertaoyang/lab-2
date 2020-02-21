#ifndef DEQUE_H
#define DEQUE_H

#include <sstream>

#include "DequeInterface.h"

template<typename T>
class Deque : public DequeInterface<T>
{
public:
	Deque() : 
		capacity(DEFAULT_CAPACITY),
		numItems(0),
		frontIndex(0),
		rearIndex(DEFAULT_CAPACITY - 1),
		data(new T[DEFAULT_CAPACITY]) {}
	~Deque()
	{
		delete[] data;
	}

	/** Insert item at front of deque */
	virtual void push_front(const T& value)
	{
		if (numItems == capacity)
		{
			reallocate();
		}
		numItems++;
		frontIndex = (frontIndex - 1) % capacity;
		data[frontIndex] = value;
	}

	/** Insert item at rear of deque */
	virtual void push_back(const T& value)
	{
		if (numItems == capacity)
		{
			reallocate();
		}
		numItems++;
		rearIndex = (rearIndex + 1) % capacity;
		data[rearIndex] = value;
	}

	/** Remove the front item of the deque */
	virtual void pop_front(void)
	{
		numItems--;
		frontIndex = (frontIndex + 1) % capacity;
	}

	/** Remove the rear item of the deque */
	virtual void pop_back(void)
	{
		numItems--;
		rearIndex = (rearIndex - 1) % capacity;
	}

	/** Return the front item of the deque (Do not remove) */
	virtual T& front(void)
	{
		return data[frontIndex];
	}

	/** Return the rear item of the deque (Do not remove) */
	virtual T& back(void)
	{
		return data[rearIndex];
	}

	/** Return the number of items in the deque */
	virtual size_t size(void) const
	{
		return numItems;
	}

	/** Return true if deque is empty */
	virtual bool empty(void) const
	{
		if (numItems == 0)
		{
			return true;
		}
		return false;
	}

	/** Return item in deque at index (0 based) */
	virtual T& at(size_t index)
	{
		int newIndex;
		newIndex = (frontIndex + index) % capacity;
		return data[newIndex];
	}

	/** Return the deque items */
	virtual std::string toString(void) const
	{
		std::ostringstream outSS;

		int index = frontIndex;
		for (unsigned i = 0; i < numItems; i++)
		{
			outSS << " " << data[index];
			index = (index + 1) % capacity;
		}
		
		return outSS.str();
	}

	/** Find the position of value in the deque returning -1 means not found. */
	int find(T value)
	{
		int index = frontIndex;
		for (unsigned i = 0; i < numItems; i++)
		{
			if (value == data[index]) { return i; }
			index = (index + 1) % capacity;
		}
		return -1;
	}

private:
	size_t capacity;
	size_t numItems;
	size_t frontIndex;
	size_t rearIndex;
	T *data;

	void reallocate(void)
	{
		size_t newCapacity = 2 * capacity;
		T *newData = new T[newCapacity];
		size_t j = frontIndex;

		for (unsigned i = 0; i < numItems; ++i)
		{
			newData[i] = data[j];
			j = (j + 1) % capacity;
		}

		frontIndex = 0;
		rearIndex = numItems - 1;
		capacity = newCapacity;
		std::swap(data, newData);

		delete[] newData;
	}

};

//FIXME move 10+

#endif // !DEQUE_H
