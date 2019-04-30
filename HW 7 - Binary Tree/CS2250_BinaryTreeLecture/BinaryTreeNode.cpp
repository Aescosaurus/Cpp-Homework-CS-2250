#ifndef BINARY_TREE_NODE_CPP
#define BINARY_TREE_NODE_CPP

#include "BinaryTreeNode.h"

////////////////////////////////////////////////////////////////////////////
// DO NOT USE THE BELOW IN YOUR CODE - THESE ARE FOR THE TESTING SUITE ONLY
////////////////////////////////////////////////////////////////////////////
int BinaryTreeNode::nbrNodes = 0;

// GetNbrNodes
// Returns the number of nodes created since the application started
// DO NOT CALL THIS FUNCTION IN YOUR CODE - USED ONLY BY THE TESTING CODE

int BinaryTreeNode::GetNbrNodes()
{
	return nbrNodes;
}

// ResetNbrNodes
// Resets the number of nodes to zero
// DO NOT CALL THIS FUNCTION IN YOUR CODE - USED ONLY BY THE TESTING CODE
void BinaryTreeNode::ResetNbrNodes()
{
	nbrNodes = 0;
}
////////////////////////////////////////////////////////////////////////////
// DO NOT USE THE ABOVE IN YOUR CODE - THESE ARE FOR THE TESTING SUITE ONLY
////////////////////////////////////////////////////////////////////////////

// BinaryTreeNode Constructor
// Store the item in the node
// Set it to have no children
BinaryTreeNode::BinaryTreeNode(const string& item)
{
	data = item;
	right = NULL;
	left = NULL;
	height = 0;

	++nbrNodes;
}

// Copy constructor
BinaryTreeNode::BinaryTreeNode(const BinaryTreeNode& node)
{
	data = node.data;
	right = node.right;
	left = node.left;
	height = node.height;

	++nbrNodes;
}

// BinaryTreeNode Destructor
// Delete each child.  This recursively
// calls the destructor "down" the tree
BinaryTreeNode::~BinaryTreeNode()
{
	--nbrNodes;
}

// GetLeft
// Returns a pointer to the left child
BinaryTreeNode* BinaryTreeNode::GetLeft() const
{
	return left;
}

// GetRight
// REturns a pointer to the right child
BinaryTreeNode* BinaryTreeNode::GetRight() const
{
	return right;
}

// GetData
// Returns the data associated with the node
string BinaryTreeNode::GetData() const
{
	return data;
}

// GetHeight
// Returns the height of the node
int BinaryTreeNode::GetHeight() const
{
	return height;
}

// SetLeft
// Sets the left child
void BinaryTreeNode::SetLeft(BinaryTreeNode* left)
{
	this->left = left;
}

// SetRight
// Sets the right child
void BinaryTreeNode::SetRight(BinaryTreeNode* right)
{
	this->right = right;
}

// SetData
// Sets the data of the node
void BinaryTreeNode::SetData(const string& data)
{
	this->data = data;
}

// SetHeight
// Sets the height of the node
void BinaryTreeNode::SetHeight(int height)
{
	this->height = height;
}

// Insertion Operator
// displays the node's data
ostream& operator<<(ostream& sout, const BinaryTreeNode& node)
{
	sout << node.GetData();
	return sout;
}

#endif