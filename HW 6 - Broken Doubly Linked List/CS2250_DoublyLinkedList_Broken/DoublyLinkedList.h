#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include "DoublyLinkedListNode.h"

class DoublyLinkedList
{
public:
	// Constructors & Destructor
	DoublyLinkedList();
	DoublyLinkedList(const DoublyLinkedList& list);
	~DoublyLinkedList();

	// Add methods
	void AddFront(int item);
	void AddBack(int item);

	// Remove methods
	int  RemoveFront();
	int  RemoveBack();
	bool RemoveItem(int item);

	// Facilitator methods
	bool Search(int item) const;
	int  Size() const;
	void PrintFullNodes() const;

	// Operators
	DoublyLinkedList& operator=(const DoublyLinkedList& rhsList);
	friend ostream& operator<<(ostream& sout, const DoublyLinkedList& list);

	// Accessors for TESTING ONLY
	const DoublyLinkedListNode* const GetHead() const;
	const DoublyLinkedListNode* const GetTail() const;
	int GetCount() const;

private:
	DoublyLinkedListNode* SearchNodes(int item) const;

	DoublyLinkedListNode* m_head;   // first node in list
	DoublyLinkedListNode* m_tail;   // last node in list
	int m_count;                    // number of nodes in list
};

#endif
