#include "DoublyLinkedList.h"
#include <cassert>

// Default Constructor
// Initializes first and last pointers to NULL (empty list)
// Sets number of nodes to zero
DoublyLinkedList::DoublyLinkedList()
{
	m_count = 0;
	m_head = NULL;
	m_tail = NULL;
}

// Copy Constructor
// Iterates through the parameter list, adding each node to
// the "this" list, in order
DoublyLinkedList::DoublyLinkedList( const DoublyLinkedList& list )
{
	m_head = new DoublyLinkedListNode( *list.m_head );
	m_head->SetPrev( nullptr );
	auto cur = m_head;
	auto otherCur = list.m_head;

	while( m_count < list.m_count )
	{
		auto temp = cur;

		cur = new DoublyLinkedListNode( *otherCur->GetNext() );
		cur->SetPrev( temp );

		++m_count;
	}

	m_tail = new DoublyLinkedListNode( *list.m_tail );
}

// Destructor
// Destroys any remaining nodes in the list
DoublyLinkedList::~DoublyLinkedList()
{
	for( int i = 0; i < m_count - 1; ++i )
	{
		DoublyLinkedListNode* curr = m_head->GetNext();

		// Delete the first node
		delete m_head;

		// Adjust the head pointer to next node
		m_head = curr;

		// Advance to next node
		curr = curr->GetNext();
	}
}

// AddFront - adds the item to the front of the list
void DoublyLinkedList::AddFront( int item )
{
	// Create a new node
	DoublyLinkedListNode* newNode = new DoublyLinkedListNode( item );

	if( m_head != nullptr )
	{
		// Connect the new node to the front of the list
		newNode->SetNext( m_head );
		m_head->SetPrev( newNode );

		// Set the head to point to new node
		m_head = newNode;
		// m_tail = m_head;
	}
	else if( m_head == m_tail &&
		m_head != nullptr )
	{
		m_head = newNode;
		m_head->SetNext( m_tail );
		m_tail->SetPrev( m_head );
	}
	else
	{
		m_head = newNode;
		m_tail = newNode;
	}

	++m_count;
}

// AddBack - adds the item to the back of the list
void DoublyLinkedList::AddBack( int item )
{
	// Create a new node
	DoublyLinkedListNode* newNode = new DoublyLinkedListNode( item );

	if( m_head != nullptr )
	{
		// Connect the new node to the back of the list
		newNode->SetPrev( m_tail );
		m_tail->SetNext( newNode );

		m_tail = newNode;
	}
	else if( m_head == m_tail &&
		m_head != nullptr )
	{
		m_tail = newNode;
		m_head->SetNext( m_tail );
		m_tail->SetPrev( m_head );
	}
	else
	{
		m_head = newNode;
		m_tail = newNode;
	}

	++m_count;
}

// RemoveFront - removes the first item in the list
// Returns the value stored in the first item in the list
// Displays an error and returns 0 if the list is empty
int DoublyLinkedList::RemoveFront()
{
	// If there are no items in the list
	if( m_head == nullptr )
	{
		throw string( "ERROR:  Cannot remove from an empty list" );
		return( 0 );
	}
	else if( m_head == m_tail )
	{
		assert( m_count == 1 );

		int data = m_head->GetData();

		m_head = nullptr;
		m_tail = nullptr;

		--m_count;

		return( data );
	}
	// If there at least one item
	else
	{
		// Store data to be removed
		int data = m_head->GetData();

		// Create a temp pointer to node to remove
		DoublyLinkedListNode* temp = m_head;

		// Set head to point to 2nd node
		m_head = m_head->GetNext();

		// Fix new "head" node's pointer
		m_head->SetPrev( NULL );

		// Delete old head node
		delete temp;

		--m_count;
		return data;
	}
}

// RemoveBack - removes the last item in the list
// Returns the value stored in the last item in the list
// Displays an error and returns 0 if the list is empty
int DoublyLinkedList::RemoveBack()
{
	// If there are no items in the list
	if( m_head == nullptr )
	{
		throw string( "ERROR:  Cannot remove from an empty list" );
		return( 0 );
	}
	else if( m_head == m_tail )
	{
		int data = m_head->GetData();
		
		m_head = nullptr;
		m_tail = nullptr;

		--m_count;
		assert( m_count == 0 );

		return( data );
	}
	else
	{
		// Store data to be removed
		int data = m_tail->GetData();

		// Create a temp pointer to node to remove
		DoublyLinkedListNode* temp = m_tail;

		// Set tail to point to new node
		m_tail = m_tail->GetPrev();

		// Fix new "tail" node's pointer
		m_tail->SetNext( nullptr );

		// Delete old head node
		delete temp;

		--m_count;

		return data;
	}
}

// RemoveItem - removes first match to the parameter
// Returns true if the item was found and removed, false otherwise
bool DoublyLinkedList::RemoveItem( int item )
{
	DoublyLinkedListNode* curr = SearchNodes( item );

	// If item was not found or list is empty
	if( curr == nullptr )
	{
		return false;
	}
	else if( curr == m_head )
	{
		RemoveFront();
		return( true );
	}
	else if( curr == m_tail )
	{
		RemoveBack();
		return( true );
	}
	else if( curr->GetNext() == nullptr ||
		curr->GetPrev() == nullptr )
	{
		return( false );
	}
	else
	{
		// Re-link the list.
		curr->GetNext()->SetPrev( curr->GetPrev() );
		curr->GetPrev()->SetNext( curr->GetNext() );

		// Remove item
		delete curr;
		--m_count;

		return true;
	}
}

// Search - searches for the parameter
// Returns true if the item is found, false otherwise
bool DoublyLinkedList::Search( int item ) const
{
	DoublyLinkedListNode* curr = SearchNodes( item );
	return( curr != nullptr );
}

// SearchNodes - searches for the parameter and returns its node
// Returns NULL if the item was not found
DoublyLinkedListNode* DoublyLinkedList::SearchNodes( int item ) const
{
	DoublyLinkedListNode* curr = m_head;

	// Iterate through the list of nodes
	while( curr != NULL )
	{
		// If this node's data matches the parameter
		// return it
		if( curr->GetData() == item ) return curr;
		else curr = curr->GetNext();
	}

	// Item was not found, return NULL
	return nullptr;
}

// Size - returns the number of items in the list
int DoublyLinkedList::Size() const
{
	return m_count;
}

////////////////////////////////////////////////////////////////////////////////////
// THERE ARE NO INTENTIONAL ERRORS TO ANY METHODS BELOW THIS LINE
// USE THESE TO HELP YOU DEBUG
// ASSUMING YOUR LIST IS SET UP CORRECTLY, THESE WILL WORK
////////////////////////////////////////////////////////////////////////////////////

// Method for debugging the list, prints as many nodes
// as it can find up to the count (prevents infinite
// looping from pointer errors!).  Displays memory
// location and node values
void DoublyLinkedList::PrintFullNodes() const
{
	cout << "Head: " << m_head << endl;

	int cnt = 0;
	DoublyLinkedListNode* curr = m_head;
	while( curr != NULL && cnt++ <= m_count )
	{
		cout << "Node: " << curr << " " << *curr << endl;
		curr = curr->GetNext();
	}
	cout << "Tail: " << m_tail << endl;
}

// GetHead - returns the head as a constant pointer to constant data, 
// allowing the calling function to verify that the elements of the list
// are correct without altering the list in any way
const DoublyLinkedListNode* const DoublyLinkedList::GetHead() const
{
	return m_head;
}

// GetTail - returns the tail as a constant pointer to constant data, 
// allowing the calling function to verify that the elements of the list
// are correct without altering the list in any way
const DoublyLinkedListNode* const DoublyLinkedList::GetTail() const
{
	return m_tail;
}

// GetCount - returns the count as an int to verify its value
int DoublyLinkedList::GetCount() const
{
	return m_count;
}

// operator<< displays the list in a reasonable format
// Displays the nodes forward and backward (to check both
// directions of pointers)
ostream& operator<<( ostream& sout,const DoublyLinkedList& list )
{
	DoublyLinkedListNode* curr = list.m_head;

	// If the list is empty, display an appropriate message
	if( curr == NULL )
	{
		sout << "EMPTY LIST";
		return sout;
	}

	// Display the first node
	sout << curr->GetData();
	curr = curr->GetNext();

	// While there are more nodes
	while( curr != NULL )
	{
		// Display an arrow (pointer!) and the next node
		sout << "->" << curr->GetData();
		curr = curr->GetNext();
	}

	// Do it backwards!
	curr = list.m_tail;
	sout << "....";

	// If there are no nodes, display an appropriate message
	if( curr == NULL )
	{
		sout << "EMPTY LIST";
		return sout;
	}

	// Display the last node
	sout << curr->GetData();
	curr = curr->GetPrev();

	// While there are more nodes, display them
	while( curr != NULL )
	{
		// Display an arrow (pointer!) and the next node
		sout << "->" << curr->GetData();
		curr = curr->GetPrev();
	}

	// Return the stream
	return sout;
}

DoublyLinkedList& DoublyLinkedList::operator=( const DoublyLinkedList& rhsList )
{
	// If this is NOT the same object as rs
	if( this != &rhsList )
	{
		while( m_count > 0 )
		{
			RemoveFront();
		}

		// Iterator for parameter list, start at first node
		DoublyLinkedListNode* curr = rhsList.m_head;

		// While there are still nodes left
		while( curr != NULL )
		{
			// Add the current node
			AddBack( curr->GetData() );

			// Go to the next node
			curr = curr->GetNext();
		}
	}

	return *this;
}