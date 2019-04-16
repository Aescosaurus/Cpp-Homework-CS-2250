#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include "DoublyLinkedListNode.h"

template<typename T>
class DoublyLinkedList;

template<typename T>
ostream& operator<<( ostream& sout,const DoublyLinkedList<T>& list );

template<typename T>
class DoublyLinkedList
{
public:
	// Constructors & Destructor
	DoublyLinkedList();
	DoublyLinkedList( const DoublyLinkedList& list );
	~DoublyLinkedList();

	// Add methods
	void AddFront( const T& item );
	void AddBack( const T& item );

	// Remove methods
	T  RemoveFront();
	T  RemoveBack();
	bool RemoveItem( const T& item );

	// Facilitator methods
	bool Search( const T& item ) const;
	int  Size() const;
	void PrintFullNodes() const;

	// Operators
	DoublyLinkedList& operator=( const DoublyLinkedList& rhsList );
	friend ostream& operator<< <>( ostream& sout,const DoublyLinkedList& list );

	// Accessors for TESTING ONLY
	const DoublyLinkedListNode<T>* const GetHead() const;
	const DoublyLinkedListNode<T>* const GetTail() const;
	int GetCount() const;

private:
	DoublyLinkedListNode<T>* SearchNodes( const T& item ) const;

	DoublyLinkedListNode<T>* m_head;   // first node in list
	DoublyLinkedListNode<T>* m_tail;   // last node in list
	int m_count;                    // number of nodes in list
};

#include "DoublyLinkedList.cpp"

#endif
