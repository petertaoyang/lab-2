#ifndef BST_H
#define BST_H

#include "BSTInterface.h"
#include <string>
#include <fstream>
#include <sstream>

using namespace std;


template<typename T>
class BST :public BSTInterface<T> {
private:
	int theSize;
	struct Node
	{
		T data_;
		Node* left_;
		Node* right_;
		Node(T d) : data_(d), left_(NULL), right_(NULL) { }
	};
	Node* root_;
public:
	BST() { 
		theSize = 0;
		this->root_ = NULL;
	}
	~BST() { clearTree(); }
	

	bool insert(Node*& node, const T& data) {
		if (node == NULL) {
			node = new Node(data);
			theSize++;
			return true;
		}
		else if (data == node->data_) {
			return false;
		}
		else if (data < node->data_) {
			return (insert(node->left_, data));
		}
		else if (data > node->data_) {
			return (insert(node->right_, data));
		}
	}

	// deletes, swaps, rotates nodes 
	bool predecessor(Node* &n1, Node* &n2) {
		// As soon as right == NULL, the predecessor has been found.
		if (n2->right_ == NULL) {
			n1->data_ = n2->data_;
			Node* temp = n2;
			n2 = n2->left_;
			delete temp;
			temp = NULL;
			theSize--;
			return true;
		}
		else {
			predecessor(n1, n2->right_);
		}
		return false;
	}


	bool remove(Node*& node, const T& data) {
		if (node == NULL) {
			return false;
			}
		// Once you've arrived to the correct node, delete the node
			if (data == node->data_) {
				// Current node has no children
				if (node->right_ == NULL && node->left_ == NULL) {
					delete node;
					node = NULL;
					theSize--;
					return true;
				}
				// Current node has one child
				else if ((node->right_ == NULL && node->left_ != NULL) || // One left child
					(node->left_ == NULL && node->right_ != NULL)) { // One right child
					Node * temp = node;
					// Move the existing child node up
					if (node->left_ == NULL)
						node = node->right_;
					else
						if (node->right_ == NULL)
							node = node->left_;

					delete temp;
					temp = NULL;
					theSize--;
					return true;
				}
				// Two children
				else if (node->right_ != NULL && node->left_ != NULL) {
					// Find the inorder predecessor and put it where the deleted node is.
					return predecessor(node, node->left_);
				}
			}
			else {
				// If you aren't at the correct node or at the bottom of the tree, keep moving through.
				if (data > node->data_)
					return remove(node->right_, data);
				else
					if (data < node->data_)
						return remove(node->left_, data);
			}
			return false;
	}

	bool deleteTree(Node*& root_) {

		if (root_ == NULL) {
			return true;
		}
		// Move left if you can
		if (root_->left_ != NULL) {
			deleteTree(root_->left_);
			
		}
		// Move right if you can
		if (root_->right_ != NULL) {
			deleteTree(root_->right_);
			
		}
		// Once all the children of the node are deleted from above calls, delete the node
		delete root_;
		root_ = NULL;
		theSize--;
		return true;
	}

	bool find(T num) {
		return findHelp(root_, num);
	}

	bool findHelp(Node* node, T num) {
		if (node == NULL) {
			return false;
		}
		if (node->data_ == num) {
			return true;
		}
		else if (node->data_ > num) {
			return findHelp(node->left_, num);
		}
		else if (node->data_ < num) {
			return findHelp(node->right_, num);
		}
		//return false;
	}

	int size() {
		return theSize;
	}


	/** Return true if node added to BST, else false */
	virtual bool addNode(const T& data) { return insert(this->root_, data); }

	/** Return true if node removed from BST, else false */
	virtual bool removeNode(const T& data) { return remove(this->root_, data); }

	/** Return true if BST cleared of all nodes, else false */
	virtual bool clearTree() { return deleteTree(root_); }

	/** Return a level order traversal of a BST as a string */
	virtual string toString() const {
		stringstream out;
		if (root_ == NULL) { out << " empty"; }
		else
		{
			int level = -1;
			do
			{
				out << endl << "  " << ((++level) + 1) << ":";
			} while (outLevel(root_, level, out));
		}
		return out.str();
	}

	/** Override insertion operator to insert BST string */
	friend std::ostream& operator<< (ostream& os, const BST& bst) {
		os << bst.toString();
		return os;
	}

	/** Output nodes at a given level */
	bool outLevel(Node* root, int level, stringstream& out) const
	{
		if (root == NULL) return false;
		if (level == 0)
		{
			out << " " << root->data_;
			if ((root->left_ != NULL) || (root->right_ != NULL)) return true;
			return false;
		}
		if ((level == 1) && !root->left_ && root->right_) out << " _";
		bool left = outLevel(root->left_, level - 1, out);
		bool right = outLevel(root->right_, level - 1, out);
		if ((level == 1) && root->left_ && !root->right_) out << " _";
		return left || right;
	} // end outLevel()


};


#endif
