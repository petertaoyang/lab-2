#ifndef STATION_H
#define STATION_H

#include "Vector.h"
#include "Queue.h"
#include "Stack.h"

template<typename T>
class Station
{
public:
	Station() : empty(true) {}
	~Station() {}

	/** Add an incoming car to the turntable, else report occupied. */
	std::string addCar(const T& inCar)
	{
		if (empty)
		{
			turnTableCar = inCar;
			empty = false;
			return "OK";
		}
		else { return "Turntable occupied!"; }
	}

	/** Remove a car from the turntable and push into train vector, else report empty. */
	std::string removeCar() 
	{
		if (empty) { return "Turntable empty!"; }
		else
		{
			empty = true;
			train.pushBack(turnTableCar);
			return "OK";
		}
	}

	/** Return the train car on station turntable. */
	std::string topCar() { return std::to_string(turnTableCar); }

	/** Move a train from the turntable to the stack, else report empty. */
	std::string addStack()
	{
		if (empty) { return "Turntable empty!"; }
		else
		{
			stack.push(turnTableCar);
			empty = true;
			return "OK";
		}
	}

	/** Move a car from the front of the stack and put it on the turntable, else report empty or occupied. */
	std::string removeStack()
	{
		if (stack.size() == 0) { return "Stack empty!"; }
		if (empty)
		{
			turnTableCar = stack.top();
			empty = false;
			stack.pop();
			return "OK";
		}
		else { return "Turntable occupied!"; }
	}

	/** Return the top of the stack container. */
	std::string topStack() { return std::to_string(stack.top()); }

	/** Return the current size of stack container. */
	std::string sizeStack() { return std::to_string(stack.size()); }

	/** Move a train from the turntable to the queue, else report empty. */
	std::string addQueue()
	{
		if (empty) { return "Turntable empty!"; }
		else
		{
			queue.push(turnTableCar);
			empty = true;
			return "OK";
		}
	}

	/** Move a car from the front of the queue and put it on the turntable, else report empty or occupied. */
	std::string removeQueue()
	{
		if (queue.size() == 0) { return "Queue empty!"; }
		if (empty)
		{
			turnTableCar = queue.top();
			empty = false;
			queue.pop();
			return "OK";
		}
		else { return "Turntable occupied!"; }
	}

	/** Return the top of the queue container. */
	std::string topQueue() { return std::to_string(queue.top()); }

	/** Return the current size of the queue container. */
	std::string sizeQueue() { return std::to_string(queue.size()); }

	/** Return the current location and position of a car. */
	std::string find(T value)
	{
		if (value == turnTableCar) { return "Turntable"; }
		else if (train.find(value) != -1)
		{
			std::ostringstream outSS;
			outSS << "Train[" << train.find(value) << "]";

			return outSS.str();
		}
		else if (queue.find(value) != -1)
		{
			std::ostringstream outSS;
			outSS << "Queue[" << queue.find(value) << "]";

			return outSS.str();
		}
		else if (stack.find(value) != -1)
		{
			std::ostringstream outSS;
			outSS << "Stack[" << stack.find(value) << "]";

			return outSS.str();
		}
		else
		{
			return "Not Found!";
		}
	}

	/** Output the contents of the train vector. */
	std::string toString() const { return train.toString(); }

private:
	Vector<T> train;
	Stack<T> stack;
	Queue<T> queue;
	T turnTableCar;
	bool empty;

};
#endif // !STATION_H

