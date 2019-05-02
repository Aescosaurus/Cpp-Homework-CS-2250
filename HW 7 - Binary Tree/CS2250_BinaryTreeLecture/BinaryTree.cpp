#ifndef BINARY_TREE_CPP
#define BINARY_TREE_CPP

#include "BinaryTree.h"

// BinaryTree Constructor
// Initialize the tree to empty
template<typename T>
BinaryTree<T>::BinaryTree( bool isAVL )
{
	isAVLTree = isAVL;
	root = NULL;
}

// BinaryTree Destructor
// Deletes the root node.
// Relies on Node's delete method.
template<typename T>
BinaryTree<T>::~BinaryTree( void )
{
	MakeEmpty( root );
}

// MakeEmpty
// Recurses the entire tree, 
template<typename T>
void BinaryTree<T>::MakeEmpty( BinaryTreeNode<T>* curr )
{
	if( curr != nullptr )
	{
		MakeEmpty( curr->GetLeft() );
		MakeEmpty( curr->GetRight() );

		delete curr;
	}
}

/////////////////////////////////////////////////////////////////
// Insert Methods
/////////////////////////////////////////////////////////////////

// BinaryTree Insert
// Public Insert adds the item into the tree.
// If the tree is empty, adds the item as the root.
// Otherwise, uses the private insert to recursively insert.
template<typename T>
void BinaryTree<T>::Insert( const T& item )
{
	if( root == nullptr )
	{
		root = new BinaryTreeNode<T>( item );
	}
	else Insert( item,root );
}

// Insert
// Insert the item starting at the current node.  If the
// item is less than the current node, the item is added
// to the left subtree.  If the item is greater, it is
// added to the right subtree.  If there is no subtree,
// the node is added as a child of this node.
template<typename T>
void BinaryTree<T>::Insert( const T& item,BinaryTreeNode<T>* curr )
{
	if( item > curr->GetData() )
	{
		if( curr->GetRight() == nullptr )
		{
			curr->SetRight( new BinaryTreeNode<T>( item ) );
		}
		else Insert( item,curr->GetRight() );
	}
	else if( item < curr->GetData() )
	{
		if( curr->GetLeft() == nullptr )
		{
			curr->SetLeft( new BinaryTreeNode<T>( item ) );
		}
		else Insert( item,curr->GetLeft() );
	}
}

/////////////////////////////////////////////////////////////////
// Search Methods
/////////////////////////////////////////////////////////////////

// Search
// Public Search method that uses the private version to search
// from the root.  Returns TRUE if the item is found.  Returns 
// FALSE if the tree is empty or if the item is not found.
template<typename T>
bool BinaryTree<T>::Search( const T& item ) const
{
	return( Search( item,root ) );
}

// Search
// Private Search method that examines the current node and
// recursively its children until it finds the item.  If
// the current node has no children and does not match
// the item, then the search is exhausted and the item
// was not found.
// Returns TRUE if the item is found, FALSE if not. 
template<typename T>
bool BinaryTree<T>::Search( const T& item,BinaryTreeNode<T>* curr ) const
{
	if( curr == nullptr )
	{
		return( false );
	}
	else if( curr->GetData() == item )
	{
		return( true );
	}
	else
	{
		if( item > curr->GetData() ) return( Search( item,curr->GetRight() ) );
		else return( Search( item,curr->GetLeft() ) );
	}
}

/////////////////////////////////////////////////////////////////
// Remove Methods
/////////////////////////////////////////////////////////////////

// Remove
// The public versrion of Remove that initiates the recursive
// search for the item to remove.
// Returns true if the remove was successful, false otherwise.
template<typename T>
bool BinaryTree<T>::Remove( const T& item )
{
	if( root == nullptr )
	{
		return( false );
	}
	if( root->GetData() == item )
	{
		root = RemoveNode( root );
		// root = nullptr;
		return( true );
	}
	else
	{
		return( Remove( item,root ) );
	}
}

// Remove
// The private version of Remove, recursively searches for the item
// to remove. Returns true if the removal was successful, false otherwise.
// Uses RemoveNode to actually remove the node of the item once found and 
// fixes the parent's pointer to the removed node.
template<typename T>
bool BinaryTree<T>::Remove( const T& item,BinaryTreeNode<T>* curr )
{
	if( curr == nullptr )
	{
		return( false );
	}
	else if( curr->GetLeft() != nullptr &&
		curr->GetLeft()->GetData() == item )
	{
		curr->SetLeft( RemoveNode( curr->GetLeft() ) );
	}
	else if( curr->GetRight() != nullptr &&
		curr->GetRight()->GetData() == item )
	{
		curr->SetRight( RemoveNode( curr->GetRight() ) );
	}
	else
	{
		if( item > curr->GetData() ) return( Remove( item,curr->GetRight() ) );
		else return( Remove( item,curr->GetLeft() ) );
	}
}

// RemoveNode
// Removes the curr node by determining which node should take its
// place in the revised tree.  Returns the node that should take
// curr's place in the tree with restructured children as appropriate.
// If curr had no children, null is returned.
template<typename T>
BinaryTreeNode<T>* BinaryTree<T>::RemoveNode( BinaryTreeNode<T>* curr )
{
	if( curr->GetLeft() == nullptr &&
		curr->GetRight() == nullptr )
	{
		delete curr;
		return( nullptr );
	}
	else if( curr->GetLeft() == nullptr )
	{
		auto* temp = curr->GetRight();
		delete curr;
		return( temp );
	}
	else if( curr->GetRight() == nullptr )
	{
		auto* temp = curr->GetLeft();
		delete curr;
		return( temp );
	}
	else
	{
		auto* min = curr;
		auto* parent = curr;
		min = min->GetRight();
		while( min->GetLeft() != nullptr )
		{
			parent = min;
			min = min->GetLeft();
		}
		curr->SetData( min->GetData() );
		if( parent->GetLeft() == min )
		{
			parent->SetLeft( min->GetRight() );
			// parent->SetRight( nullptr );
		}
		else if( parent->GetRight() == min )
		{
			parent->SetRight( min->GetRight() );
		}
		delete min;
		min = nullptr;
		// delete curr;
		return( curr );
	}
}

/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
// AVL METHODS - ADD THESE IN WEEK 2
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////
// AVL Methods
/////////////////////////////////////////////////////////////////

// NeedsBalancing
// Determines if the curr node needs to be rebalanced by looking
// at its children and grandchildren.  If there is a difference in
// height between the left and right child that is greater than 1,
// the node needs to be rebalanced.  False otherwise.
template<typename T>
bool BinaryTree<T>::NeedsRebalancing( BinaryTreeNode<T>* curr )
{
	// TODO: Add your code here for week 2

	return false;
}

// RebalanceNode the current node
// Rebalances the curr node by moving around its children and
// grandchildren as required based on which type of rotation
// is necessary (left-left, right-right, right-left or left-right).
// Returns the new node that should replace curr in the tree.
template<typename T>
BinaryTreeNode<T>* BinaryTree<T>::RebalanceNode( BinaryTreeNode<T>* curr )
{
	// TODO: Add your code here for week 2

	return NULL;
}

// FixHeight
// Fixes the height of curr by looking at the height of its
// chilren and taking the larger height and adding one.
template<typename T>
void BinaryTree<T>::FixHeight( BinaryTreeNode<T>* curr )
{
	// TODO: Add your code here for week 2

}

/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
// DO NOT CHANGE ANYTHING BELOW THIS LINE
// ALL METHODS BELOW THIS LINE ARE FINE AND SHOULD WORK WITH
// YOUR CODE.  YOU DO NOT NEED TO CHANGE ANYTHING FROM HERE TO
// THE BOTTOM OF THE FILE.
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////

// IsAVL
// Returns true if the tree is an AVL tree and false otherwise
template<typename T>
bool BinaryTree<T>::IsAVL() const
{
	return isAVLTree;
}

/////////////////////////////////////////////////////////////////
// Print Methods
/////////////////////////////////////////////////////////////////

// InOrderPrint
// Public version of InOrderPrint, intializes the recursion
template<typename T>
void BinaryTree<T>::InOrderPrint( ostream& sout ) const
{
	InOrderPrint( sout,root );
}

// PreOrderPrint
// Public version of PreOrderPrint, intializes the recursion
template<typename T>
void BinaryTree<T>::PreOrderPrint( ostream& sout ) const
{
	PreOrderPrint( sout,root );
}

// PostOrderPrint
// Public version of PostOrderPrint, intializes the recursion
template<typename T>
void BinaryTree<T>::PostOrderPrint( ostream& sout ) const
{
	PostOrderPrint( sout,root );
}

// InOrderPrint
// Prints the tree in order (left child, current
// node, right child).
template<typename T>
void BinaryTree<T>::InOrderPrint( ostream& sout,BinaryTreeNode<T>* curr ) const
{
	// If the current Node exists
	if( curr == NULL )
	{
		return;
	}
	// If the node has a left subtree, print that first
	if( curr->GetLeft() != NULL )
	{
		// Print the left subtree
		InOrderPrint( sout,curr->GetLeft() );
	}

	// Print the current node
	//sout << curr->GetData() << endl;
	sout << *curr << " ";

	// If the node has a right subtree, print it last
	if( curr->GetRight() != NULL )
	{
		// Print the right subtree
		InOrderPrint( sout,curr->GetRight() );
	}
}

// PreOrderPrint
// Prints the tree in pre-order (current node, left child,
// right child).
template<typename T>
void BinaryTree<T>::PreOrderPrint( ostream& sout,BinaryTreeNode<T>* curr ) const
{
	// If the current Node exists
	if( curr == NULL )
	{
		return;
	}

	// Print the current node
	//sout << curr->GetData() << endl;
	sout << *curr << " ";

	// If the node has a left subtree, print that first
	if( curr->GetLeft() != NULL )
	{
		// Print the left subtree
		PreOrderPrint( sout,curr->GetLeft() );
	}

	// If the node has a right subtree, print it last
	if( curr->GetRight() != NULL )
	{
		// Print the right subtree
		PreOrderPrint( sout,curr->GetRight() );
	}
}

// PostOrderPrint
// Prints the tree "post-order".  Prints
// the left subtree, prints the right subree, then the current node.
template<typename T>
void BinaryTree<T>::PostOrderPrint( ostream& sout,BinaryTreeNode<T>* curr ) const
{
	// If the current Node exists
	if( curr == NULL )
	{
		return;
	}

	// If the node has a left subtree, print that first
	if( curr->GetLeft() != NULL )
	{
		// Print the left subtree
		PostOrderPrint( sout,curr->GetLeft() );
	}

	// If the node has a right subtree, print it last
	if( curr->GetRight() != NULL )
	{
		// Print the right subtree
		PostOrderPrint( sout,curr->GetRight() );
	}

	// Print the current node
	//sout << curr->GetData() << endl;
	sout << *curr << " ";
}

/////////////////////////////////////////////////////////////////
// Operators
/////////////////////////////////////////////////////////////////

// Insertion Operator
// Display the tree using an in-order print
template<typename T>
ostream& operator<< <>( ostream& sout,const BinaryTree<T>& tree )
{
	sout << "PreOrderPrint:   ";
	tree.PreOrderPrint( sout,tree.root );
	sout << "\n";

	sout << "InOrderPrint:    ";
	tree.InOrderPrint( sout,tree.root );
	sout << "\n";

	sout << "PostOrderPrint:  ";
	tree.PostOrderPrint( sout,tree.root );
	sout << "\n";
	return sout;
}

#endif
