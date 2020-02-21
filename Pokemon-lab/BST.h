#ifndef BSTINTERFACE_H
#define BSTINTERFACE_H
#include <string>
#include <sstream>
#include <iostream>
#include<list>
using namespace std;

template<typename T>
class BST
{
private:
	struct Node
	{
		T data;
		Node* left;
		Node* right;

		Node(T data)
		{
			this->data = data;
			left = NULL;
			right = NULL;
		}

	};

	int size = 0;
	Node* root;
public:
	BST() { this->root = NULL; }
	~BST() { clearTree(); }
	bool recuAdd(Node*& root, const T& value)
	{
		if (root == NULL)
		{
			root = new Node(value);
			return true;
		}

		if (value == root->data)
		{
			return false;
		}

		if (value < root->data)
		{
			return recuAdd(root->left, value);
		}

		if (value > root->data)
		{
			return recuAdd(root->right, value);
		}

		return true;
	};

	bool addNode(const T& value)
	{
		if (recuAdd(root, value) == true)
		{
			size++;
			return true;
		}

		return recuAdd(root, value);
	};

	void swap(Node*& old, Node*& IOP)
	{
		if (IOP->right == NULL)
		{
			old->data = IOP->data;
			recuRemove(IOP, old->data);
		}

		else
		{
			swap(old, IOP->right);
		}
	};

	bool recuRemove(Node*& originalRoot, const T& value)
	{
		if (originalRoot == NULL)
		{
			return false;
		}

		if (value < originalRoot->data)
		{
			return recuRemove(originalRoot->left, value);
		}

		if (value > originalRoot->data)
		{
			return recuRemove(originalRoot->right, value);
		}

		if (value == originalRoot->data)
		{
			Node* temp = originalRoot;
			if (originalRoot->left == NULL && originalRoot->right == NULL)
			{
				originalRoot = NULL;
				delete temp;
				temp = NULL;
				return true;
			}

			if (originalRoot->left == NULL && originalRoot->right != NULL)
			{
				originalRoot = originalRoot->right;
				delete temp;
				temp = NULL;
				return true;
			}

			if (originalRoot->left != NULL && originalRoot->right == NULL)
			{
				originalRoot = originalRoot->left;
				delete temp;
				temp = NULL;
				return true;
			}

			if (originalRoot->left != NULL && originalRoot->right != NULL)
			{
				swap(originalRoot, originalRoot->left);
				//delete temp;
				temp = NULL;
				return true;
			}
		}
	};

	bool removeNode(const T& value)
	{
		if (recuRemove(root, value) == true)
		{
			size--;
			return true;
		}
		return recuRemove(root, value);
	};

	int count() const
	{
		return size;
	};


	bool clearTree()
	{
		while (root != NULL)
		{
			removeNode(root->data);
		}
		return true;
	};

	bool find(const T& value)
	{
		return recuSearch(root, value);
	};

	bool recuSearch(Node*& originalRoot, const T& value)
	{
		if (originalRoot == NULL)
		{
			return false;
		}

		if (originalRoot->data == value)
		{
			return true;
		}

		if (value < originalRoot->data)
		{
			return recuSearch(originalRoot->left, value);
		}

		if (value > originalRoot->data)
		{
			return recuSearch(originalRoot->right, value);
		}

		return false;
	}

	void recuInOrder(Node*& originalRoot)
	{
		string output = "";
		stringstream ss;
		T value;
		if (originalRoot == NULL)
		{
			return;
		}

		recuInOrder(originalRoot->left);
		value = originalRoot->data;
		recuInOrder(originalRoot->right);
	}


	string tree() const
	{
		list<Node*> s;
		Node *curr = root;
		stringstream ss;

		if (size == 0)
		{
			return "Empty";
		}

		while (curr != NULL || s.empty() == false)
		{
			while (curr != NULL)
			{
				s.push_back(curr);
				curr = curr->left;
			}

			curr = s.back();
			s.pop_back();

			ss << curr->data << ",";
			curr = curr->right;

		}
		string myString = ss.str();
		myString.pop_back();
		return myString;
	}

	bool outLevel(Node* root, int level, stringstream& out) const
	{
		if (root == NULL)
		{
			return false;
		}

		if (level == 1)
		{
			out << " " << root->data;
			if ((root->left != NULL) || (root->right != NULL))
			{
				return true;
			}
			return false;
		}

		if ((level == 2) && !root->left && root->right)
		{
			out << " _";
		}
		bool left = outLevel(root->left, level - 1, out);
		bool right = outLevel(root->right, level - 1, out);
		if ((level == 2) && root->left && !root->right)
		{
			out << " _";
		}

		return left || right;
	};  // end outLevel()

	string toString() const
	{
		stringstream out;
		if (root == NULL)
		{
			out << " Empty";
		}
		else
		{
			int level = 0;

			do
			{
				out << endl << "  " << ++level << ":";
			}

			while (outLevel(root, level, out));
		}

		return out.str();
	}; // end toString()

};

#endif
