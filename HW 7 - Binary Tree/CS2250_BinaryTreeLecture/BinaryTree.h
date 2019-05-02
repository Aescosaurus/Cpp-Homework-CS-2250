#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <string>

#include "BinaryTreeNode.h"

using namespace std;

template<typename T>
class BinaryTree;

template<typename T>
ostream& operator<<( ostream& sout,const BinaryTree<T>& tree );

// TODO: Make this class a template
template<typename T>
class BinaryTree
{
public:
	BinaryTree(bool isAVL = false);
	~BinaryTree();

	void Insert(const T& item);
	bool Search(const T& item) const;
	bool Remove(const T& item);

	friend ostream& operator<< <>(ostream& sout, const BinaryTree& tree);

	void InOrderPrint(ostream& sout) const;
	void PreOrderPrint(ostream& sout) const;
	void PostOrderPrint(ostream& sout) const;

	bool IsAVL() const;

private:
	void InOrderPrint(ostream& sout, BinaryTreeNode<T>* curr) const;
	void PreOrderPrint(ostream& sout, BinaryTreeNode<T>* curr) const;
	void PostOrderPrint(ostream& sout, BinaryTreeNode<T>* curr) const;

	void Insert(const T& item, BinaryTreeNode<T>* curr);
	bool Search(const T& item, BinaryTreeNode<T>* curr) const;
	bool Remove(const T& item, BinaryTreeNode<T>* curr);
	BinaryTreeNode<T>* RemoveNode(BinaryTreeNode<T>* curr);

	bool NeedsRebalancing(BinaryTreeNode<T>* curr);
	BinaryTreeNode<T>* RebalanceNode(BinaryTreeNode<T>* curr);
	void FixHeight(BinaryTreeNode<T>* curr);
	
	void MakeEmpty(BinaryTreeNode<T>* curr);

	BinaryTreeNode<T>* root;
	bool isAVLTree;
};

#include "BinaryTree.cpp"

#endif