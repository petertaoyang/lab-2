#ifndef MAP_H
#define MAP_H
#define MAP_H
#include<string>
#include<fstream>
#include <sstream>
#include <iostream>
#include <cmath>
#include "HashMapInterface.h"

using namespace std;

template<typename Z, typename Y>
class Map : public HashMapInterface<Z, Y>
{
private:
		struct Node
		{
		public:
			Node(Z referenceKey) { this->referenceKey = referenceKey; }
		   Z referenceKey;
		   Y mapValue;
		};

	size_t maxSize;
	Node** table;
	size_t currentSize;
	//size_t newSize;


public:
	Map()
	{
		maxSize = 31;
		table = new Node*[maxSize];
		for (int i = 0; i < maxSize; ++i)
		{
			table[i] = NULL;
		}
		currentSize = 0;
	}
	~Map() 
	{
		clear();
	}

	//I was trying to do the extra credit. However, after I add this code, my program doesn't 
	//even compile. 
	void resize()
	{
		int newSize = maxSize * 2;
		//maxSize = newSize;
		Node** tempTable;
		tempTable = new Node*[newSize];
		int index;
		for (int i = 0; i < newSize; ++i)
		{
			tempTable[i] = NULL;
		}

		for (int j = 0; j < maxSize; ++j)
		{
			if (table[j] != NULL)
			{
				index = hash(table[j]->referenceKey);
				int tem = 0;
				for (int i = 0; i < newSize; i++)
				{
					tem = index % newSize;
					tem = (tem + i * i) % newSize;
					if (tempTable[tem] == NULL)
					{
						tempTable[tem] = table[j];
						break;
					}

				}
			}

		}

		delete[] table;

		table = tempTable;
		maxSize = newSize;
	}

	//using formula to hash my referenceKey
	size_t hash(const Z& referenceKey)
	{
		string myString;
		stringstream ss;
		ss << referenceKey;
		myString = ss.str();

		int index = 0;
		for (int i = 0; i < myString.size(); ++i)
		{
			index += myString[i] * pow(3, myString.size() - (i+1));
			//index += myString[i];
		}

		return index;
	}

	Y& operator[](const Z& referenceKey)
	{ 
		int index;
		index = hash(referenceKey);
 
		if ((static_cast<double>(currentSize )/ static_cast<double>(maxSize)) >= 0.75)
		{

			cout << referenceKey << endl;
			resize();
		}
		index = index % maxSize;
		int tem = 0;
		
		for (int i = 0; i < maxSize; i++)
		{
			tem = index;
			tem = (tem + i * i) % maxSize;
			if (table[tem] == NULL)
			{
				table[tem] = new Node(referenceKey);
				currentSize++;
				return table[tem]->mapValue;
			}


			else if (referenceKey == table[tem]->referenceKey)
			{
				return table[tem]->mapValue;
			}
			
		}

		return table[tem]->mapValue;
	}

	size_t erase(const Z& referenceKey)
	{

		size_t count = 0;
		for (int i = 0; i < maxSize; ++i)
		{
			if (table[i]->referenceKey == referenceKey)
			{
				delete table[i];	
				table[i] = NULL;
				count++;
			}
		}
		currentSize--;
		return count;
	}

	//return: the number of elements that matchthe referenceKey in the Map.
	size_t count(const Z& referenceKey)
	{
		return currentSize;
	}

	//delete the whole map
	void clear()
	{
		for (int i = 0; i < maxSize; ++i)
		{
			if (table[i] != NULL)
			{
				delete table[i];
				table[i] = NULL;
			}
		}
		delete[] table;
		table = NULL;
		currentSize = 0;
		maxSize = 0;
	}

	//return the size of the map
	size_t size() const
	{
		return currentSize;
	}
	//return the mapValue of the max capacity of the map
	size_t max_size() const
	{
		return maxSize;
	}
	//print out the map elements
	string toString() const
	{
		stringstream ss;
		for (int i = 0; i < maxSize; ++i)
		{
			if (table[i] != NULL)
			{
				/*if (table[i]->referenceKey == "hypno")
				{
					continue;
				}*/
				//cout << table[i]->referenceKey << endl;
				ss << " [" << i << ":" << table[i]->referenceKey << "->" << table[i]->mapValue << "]"<< endl;
			}
		}

		return ss.str();
	}

};

#endif