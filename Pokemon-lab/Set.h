#ifndef SET_H
#define SET_H
#include "SetInterface.h"
#include "BST.h"

//my set is inherint from the binary search tree
using namespace std;
template<typename T>
class Set : public SetInterface<T>
{

private:
	BST<T>treeSet;

public:

	Set()
	{
	}
	~Set() {}

	//insert a new item and return true if success. Otherwise, return false;
	bool insert(const T& item)
	{
		return treeSet.addNode(item);
	}

	//earse a item from the set
	size_t erase(const T& item)
	{
		if (treeSet.removeNode(item) == true)
		{
			return 1;
		}

		else
		{
			return 0;
		}
	}

	//delete the whole set
	void clear()
	{
		treeSet.clearTree();
	}

	//return the size of the set
	size_t size() const
	{
		return treeSet.count();
	}
	//return 1 if the item is in the set. Otherwise return 0.
	size_t count(const T& item)
	{
		if (treeSet.find(item) == true)
		{
			return 1;
		}

		else
		{
			return 0;
		}

	}

	//ptint out all the elements in the set in level order.
	string toString() const
	{
		return treeSet.tree();
	}

	friend std::ostream& operator<< (ostream& os, const Set& myclass)
	{
		os << myclass.toString();
		return os;
	}
};

#endif