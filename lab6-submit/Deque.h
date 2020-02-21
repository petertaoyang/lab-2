#ifndef DEQUE_H
#define DEQUE_H
#include "DequeInterface.h"
using namespace std;

template<typename T>
class Deque : public DequeInterface <T>
{
    private:
    size_t capacity;
    size_t num_items;
    size_t front_index;
    size_t rear_index;
    T* the_data;

    public:
    Deque()
    {
		capacity =	DEFAULT_CAPACITY;
		num_items = 0;
		front_index = 0;
		rear_index = DEFAULT_CAPACITY -1;
		the_data = new T[DEFAULT_CAPACITY];
	};
    ~Deque()
    {

    };
	//push to the front of the structure
    void push_front(const T& itemToPush)
    {
		if ((num_items + front_index) == capacity)
		{
	   		reallocate();
		}
		front_index = (front_index - 1) % capacity;
		the_data[front_index] = itemToPush;
		num_items++;
    }

	/** Insert item at rear of deque */
	void push_back(const T& itemToPush)
	{
		if ((num_items + front_index) == capacity)
		{
	   		reallocate();
		}
		rear_index = (rear_index + 1) % capacity;
		the_data[rear_index] = itemToPush;
		num_items++;
	}

	/** Remove the front item of the deque */
	void pop_front(void)
	{
		if ((num_items + front_index) == capacity)
		{
	   		reallocate();
		}
		front_index = front_index + 1;
		num_items--;
		return;
	}

	/** Remove the rear item of the deque */
	void pop_back(void)
	{
		if ((num_items + front_index) == capacity)
		{
	   		reallocate();
		}
		rear_index = rear_index - 1;
		num_items--;
		return;
	}

	/** Return the front item of the deque (Do not remove) */
	T& front(void)
	{
		return the_data[front_index];
	}

	/** Return the rear item of the deque (Do not remove) */
	T& back(void)
	{
		return the_data[rear_index];
	}

	/** Return the number of tems in the deque */
	size_t size(void) const
	{
		return num_items;
	}

	/** Return true if deque is empty */
	bool empty(void) const
	{
		if(num_items == 0)
		{
	 		return true;
		}
		else{
	 		return false;
		}
	}
	
	/** Return item in deque at index (0 based) */
	T& at(size_t index)
	{
		return the_data[index];
	}

	/** Return the deque items */
	std::string toString(void) const
	{
		//empty
	}
	
	T& operator[](size_t i)
	{
		if (i >= num_items)
	    throw std::out_of_range("Invalid index deque::operator[]");
		size_t block_index = (front_index + i) / capacity;
		size_t data_index = (front_index + i) % capacity;
		return the_data[block_index][data_index];
	}
	
	void reallocate(void){
		size_t new_capacity = 2 * capacity;
		T* new_data = new T[new_capacity];
		size_t j = front_index;
		for (size_t i = 0; i < num_items; i++)
		{
		   new_data[i] = the_data[j];
		   j = (j + 1) % capacity;
		}
		front_index = 0;
		capacity = new_capacity;
		std::swap(the_data, new_data);
		delete[] new_data;
	}
};
#endif  