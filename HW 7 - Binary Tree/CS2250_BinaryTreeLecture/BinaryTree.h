#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <string>

#include "BinaryTreeNode.h"

using namespace std;

// TODO: Make this class a template
class BinaryTree
{
public:
	BinaryTree(bool isAVL = false);
	~BinaryTree();

	void Insert(const string& item);
	bool Search(const string& item) const;
	bool Remove(const string& item);

	friend ostream& operator<<(ostream& sout, const BinaryTree& tree);

	void InOrderPrint(ostream& sout) const;
	void PreOrderPrint(ostream& sout) const;
	void PostOrderPrint(ostream& sout) const;

	bool IsAVL() const;

private:
	void InOrderPrint(ostream& sout, BinaryTreeNode* curr) const;
	void PreOrderPrint(ostream& sout, BinaryTreeNode* curr) const;
	void PostOrderPrint(ostream& sout, BinaryTreeNode* curr) const;

	void Insert(const string& item, BinaryTreeNode* curr);
	bool Search(const string& item, BinaryTreeNode* curr) const;
	bool Remove(const string& item, BinaryTreeNode* curr);
	BinaryTreeNode* RemoveNode(BinaryTreeNode* curr);

	bool NeedsRebalancing(BinaryTreeNode* curr);
	BinaryTreeNode* RebalanceNode(BinaryTreeNode* curr);
	void FixHeight(BinaryTreeNode* curr);
	
	void MakeEmpty(BinaryTreeNode* curr);

	BinaryTreeNode* root;
	bool isAVLTree;
};

#endif