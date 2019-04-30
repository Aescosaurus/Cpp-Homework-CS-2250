#ifndef BINARY_TREE_NODE_H
#define BINARY_TREE_NODE_H

#include <iostream>
#include <string>

using namespace std;

// TODO: Make this class a template
class BinaryTreeNode
{
public:
	BinaryTreeNode(const string& item);
	BinaryTreeNode(const BinaryTreeNode& node);
	~BinaryTreeNode();

	BinaryTreeNode* GetLeft() const;
	BinaryTreeNode* GetRight() const;
	string GetData() const;
	int GetHeight() const;

	// Mutators
	void SetLeft(BinaryTreeNode* left);
	void SetRight(BinaryTreeNode* right);
	void SetData(const string& data);
	void SetHeight(int height);

	friend ostream& operator<<(ostream& sout, const BinaryTreeNode& node);

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
	string data;
	int height;

	///////////////////////////////////////////////////////////////////////////
	// DO NOT USE THE BELOW IN YOUR CODE - THESE ARE FOR THE TESTING SUITE ONLY
	///////////////////////////////////////////////////////////////////////////
	static int nbrNodes;
	///////////////////////////////////////////////////////////////////////////
	// DO NOT USE THE ABOVE IN YOUR CODE - THESE ARE FOR THE TESTING SUITE ONLY
	///////////////////////////////////////////////////////////////////////////
};

#endif