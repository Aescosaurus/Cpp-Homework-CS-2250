#include <iostream>

using namespace std;

#ifndef DOUBLY_LINKED_LIST_NODE_H
#define DOUBLY_LINKED_LIST_NODE_H

#define NULL 0

template<typename T>
class DoublyLinkedListNode;

template<typename T>
ostream& operator<<( ostream& sout,const DoublyLinkedListNode<T>& list );

template<typename T>
class DoublyLinkedListNode
{
public:
	// Constructors
	DoublyLinkedListNode(void);       // Default
	DoublyLinkedListNode(const DoublyLinkedListNode& node);    // Copy
	DoublyLinkedListNode(const T& data);
	DoublyLinkedListNode(const T& data, DoublyLinkedListNode* prev, DoublyLinkedListNode* next);

	// Destructor
	~DoublyLinkedListNode(void);

	// Accessors/Inspectors
	const T& GetData() const;
	DoublyLinkedListNode* GetNext() const;
	DoublyLinkedListNode* GetPrev() const;

	// Mutators/Manipulators
	void SetData(const T& data);
	void SetNext(DoublyLinkedListNode* next);
	void SetPrev(DoublyLinkedListNode* prev);

	DoublyLinkedListNode& operator=(const DoublyLinkedListNode& list);
	friend ostream& operator<< <>(ostream& sout, const DoublyLinkedListNode& list);

	static int GetNbrOfNodes();

private:
	T m_data;             // node's item
	DoublyLinkedListNode* m_next; // next in list
	DoublyLinkedListNode* m_prev;

	// Static members for TESTING ONLY
	static int nbrOfNodes;
};

#include "DoublyLinkedListNode.cpp"

#endif