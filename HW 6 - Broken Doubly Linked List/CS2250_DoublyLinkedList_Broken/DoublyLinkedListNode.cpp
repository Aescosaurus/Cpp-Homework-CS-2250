#include "DoublyLinkedList.h"

// Static member for TESTING ONLY
int DoublyLinkedListNode::nbrOfNodes = 0;

int DoublyLinkedListNode::GetNbrOfNodes()
{
	return nbrOfNodes;
}

// Constructors
// Default constructor
// Initializes next and previous pointers to NULL
// Initializes data to a "safe" value of 0
DoublyLinkedListNode::DoublyLinkedListNode(void)
{
	m_data = 0;
	m_next = NULL;
	m_prev = NULL;

	++nbrOfNodes;
}

// Copy Constructor
// Copies an existing node exactly by copying each data member
DoublyLinkedListNode::DoublyLinkedListNode(const DoublyLinkedListNode& node)
{
	m_data = node.m_data;
	m_next = node.m_next;
	m_prev = node.m_prev;

	++nbrOfNodes;
}

// Constructor
// Accepts the data to store in the node as the parameter
// Initializes previous and next pointers to NULL
DoublyLinkedListNode::DoublyLinkedListNode(int data)
{
	m_data = data;
	m_next = NULL;
	m_prev = NULL;

	++nbrOfNodes;
}

// Constructor
// Accepts data, prev, and next pointers as parameters
DoublyLinkedListNode::DoublyLinkedListNode(int data, DoublyLinkedListNode* prev, DoublyLinkedListNode* next)
{
	m_data = data;
	m_next = next;
	m_prev = prev;

	++nbrOfNodes;
}

// Destructor
DoublyLinkedListNode::~DoublyLinkedListNode(void)
{
	m_next = NULL;
	m_prev = NULL;

	--nbrOfNodes;
}

// Accessors
// GetData - returns the data stored in the node
int DoublyLinkedListNode::GetData() const
{
	return m_data;
}

// GetNext - returns the pointer to the next node
DoublyLinkedListNode* DoublyLinkedListNode::GetNext() const
{
	return m_next;
}

// GetPrev - returns the pointer to the prevous node
DoublyLinkedListNode* DoublyLinkedListNode::GetPrev() const
{
	return m_prev;
}

// Mutators
// SetData - sets the data to store in the node
void DoublyLinkedListNode::SetData(int data)
{
	m_data = data;
}

// SetNext - sets the pointer to the next node
void DoublyLinkedListNode::SetNext(DoublyLinkedListNode* next)
{
	m_next = next;
}

// SetPrev - sets the pointer to the previous node
void DoublyLinkedListNode::SetPrev(DoublyLinkedListNode* prev)
{
	m_prev = prev;
}

// operator<< - displays the node
ostream& operator<<(ostream& sout, const DoublyLinkedListNode& curr)
{
	sout << "[ (data) " << curr.m_data << " : (prev) " << curr.m_prev << " : (next) " << curr.m_next << " ]";
	return sout;
}

DoublyLinkedListNode& DoublyLinkedListNode::operator=(const DoublyLinkedListNode& rhsNode)
{
	m_data = rhsNode.m_data;
	m_next = rhsNode.m_next;
	m_prev = rhsNode.m_prev;

	return *this;
}

