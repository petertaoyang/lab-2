#ifndef LINKED_LIST_H    

#include "LinkedListInterface.h"
#include <string>
#include <iostream>
template <typename T>
class LinkedList :
	public LinkedListInterface <T>
{
private: 
	struct Node
	{
		T data;
		Node* next;
		Node(const T& d)
		{
			data = d;
			next = nullptr;
		}
		Node(const T& d, Node* n)
		{
			data = d;
			next = n;
		}
	};
	Node* head = nullptr;

public:
	LinkedList()
	{
		this->head = NULL;
	}
	~LinkedList()
	{
		clear();
	}

	virtual bool checkMatch(T value)
	{
		Node* matchNode = head;
	
		while (matchNode != nullptr)
		{
			
			if (value == matchNode->data)
			{
				return true;
			}
			matchNode = matchNode->next;
		}
		return false;
	}

	virtual bool insertHead(T value)
	{
		head = new Node(value,head);
		return true;		
	}
	virtual bool insertTail(T value)
	{	
		Node* nodePtr = head;
		if (nodePtr == nullptr)
		{
			insertHead(value);
			return true;
		}

		Node* tempNode = new Node(value);
		while (nodePtr != nullptr)
		{		
			if (nodePtr->next != nullptr) {
				nodePtr = nodePtr->next;
			}
			else
			{
				nodePtr->next = tempNode;
				return true;
			}
		}
		
	}

	virtual bool insertAfter(T matchNode, T node)
	{	
		Node* nodePtrA = head;
		//matchNodeA = matchNodeA->next;
		while (nodePtrA != nullptr)
		{
			if (nodePtrA->next != nullptr) 
			{
				if (matchNode == nodePtrA->data)
				{
					nodePtrA->next = new Node(node, nodePtrA->next);
					return true;
				}
				nodePtrA = nodePtrA->next;
			}
			else if (nodePtrA->data == matchNode)
			{
				nodePtrA->next = new Node(node, nodePtrA->next);
				return true;
			}
			else
			{
				return false;
			}	
		}
	}
	virtual bool remove(T value)
	{
		Node* nodePre = head;
		if (head->data == value)
		{
			head = head->next;
			delete nodePre;
			return true;
		}
		if (head != nullptr)
		{
			Node* nodeCur = head->next;
			for (nodeCur; nodeCur != nullptr; nodeCur = nodeCur->next)
			{	
				if (nodeCur->data == value)
				{
					nodePre->next = nodeCur->next;
					delete nodeCur;
					break;
				}
				if (nodePre != nullptr) {
					nodePre = nodePre->next;
				}
			}
			return true;
		}
		if (head == nullptr)
		{
			return false;
		}
	}
	virtual bool clear()
	{
		
		for (Node* pointer = head; pointer != nullptr;)
		{
			head = pointer->next;
			delete pointer;
			if (head == nullptr)
			{
				break;
			}	
			pointer = head;
		}
	return true;
	}

	virtual size_t size() const
	{
		int nCount = 0;
		Node* curNode = head;
		while (curNode != nullptr)
		{
			if (curNode == nullptr)
			{
				return nCount;
			}
			curNode = curNode->next;
				nCount += 1;
		}
		return nCount;
	}
	
	virtual bool at(size_t index, std::string& value)
	{
		size_t nCount = 0;
		for (Node* pointer = head; pointer != nullptr; pointer = pointer->next)
		{
			if (index == nCount)
			{
				std::stringstream outSS;
				outSS << pointer->data;
				value = outSS.str();	
				return true;
			}
			nCount += 1;
		}
	}

	virtual std::string toString() const
	{
		std::stringstream outSS;
		Node* printNode = head;
		if (printNode == nullptr)
		{
			outSS << "Empty";
			return outSS.str();
		}
		else {
			while (printNode != nullptr)
			{

				outSS << printNode->data << " ";
				printNode = printNode->next;
			}
			return outSS.str();
		}
	}
	class Iterator
	{
	private:
		Node* myList;
	public:
		Iterator(Node* a)
		{
			 myList = a;
		}		
		Iterator& operator++()
		{
			myList = myList->next;
			return *this;
		}
		T& operator*() const
		{
			return myList->data;
		}		
		bool operator !=(const Iterator& other) const
		{
			return myList != other.myList;		
		}	
	};
	Iterator begin()
	{
		return Iterator(head);
	}
	Iterator end()
	{
		return Iterator(nullptr);
	}
};
#endif LINKED_LIST_H

