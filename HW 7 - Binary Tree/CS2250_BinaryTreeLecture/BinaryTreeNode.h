#ifndef BINARY_TREE_NODE_H
#define BINARY_TREE_NODE_H

#include <iostream>
#include <string>

using namespace std;

template<typename T>
class BinaryTreeNode;

template<typename T>
ostream& operator<<( ostream& sout,const BinaryTreeNode<T>& node );

// TODO: Make this class a template
template<typename T>
class BinaryTreeNode
{
public:
	BinaryTreeNode(const T& item);
	BinaryTreeNode(const BinaryTreeNode& node);
	~BinaryTreeNode();

	BinaryTreeNode* GetLeft() const;
	BinaryTreeNode* GetRight() const;
	T GetData() const;
	int GetHeight() const;

	// Mutators
	void SetLeft(BinaryTreeNode* left);
	void SetRight(BinaryTreeNode* right);
	void SetData(const T& data);
	void SetHeight(int height);

	friend ostream& operator<< <>(ostream& sout, const BinaryTreeNode& node);

	///////////////////////////////////////////////////////////////////////////
	// DO NOT USE THE BELOW IN YOUR CODE - THESE ARE FOR THE TESTING SUITE ONLY
	///////////////////////////////////////////////////////////////////////////
	static int GetNbrNodes();
	static void ResetNbrNodes();
	///////////////////////////////////////////////////////////////////////////
	// DO NOT USE THE ABOVE IN YOUR CODE - THESE ARE FOR THE TESTING SUITE ONLY
	///////////////////////////////////////////////////////////////////////////
private:

	BinaryTreeNode* left;
	BinaryTreeNode* right;
	T data;
	int height;

	///////////////////////////////////////////////////////////////////////////
	// DO NOT USE THE BELOW IN YOUR CODE - THESE ARE FOR THE TESTING SUITE ONLY
	///////////////////////////////////////////////////////////////////////////
	static int nbrNodes;
	///////////////////////////////////////////////////////////////////////////
	// DO NOT USE THE ABOVE IN YOUR CODE - THESE ARE FOR THE TESTING SUITE ONLY
	///////////////////////////////////////////////////////////////////////////
};

#include "BinaryTreeNode.cpp"

#endif