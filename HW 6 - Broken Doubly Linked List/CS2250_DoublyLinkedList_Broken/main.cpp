#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

#include "DoublyLinkedList.h"

// Run the tests on the list using ints
void RunIntegerTests()
{
	// TESTING List Constructor
	DoublyLinkedList list;
	cout << list << endl;

	// TESTING List AddFront, Size and operator<<
	cout << "**************  TESTING AddFront, Size and operator<< ****************" << endl;
	for (int i = 1; i < 5; ++i)
	{
		list.AddFront(i);
		cout << "Size: " << list.Size() << endl;
		cout << "List: " << list << endl;
		list.PrintFullNodes();
	}

	// TESTING List Search
	cout << "\n**************  TESTING Search ****************" << endl;
	for (int i = 0; i <= 5; ++i)
	{
		cout << "Find " << i << ": " << (list.Search(i) ? "TRUE" : "FALSE") << endl;
	}

	// TESTING List RemoveFront, Size, operator<<
	cout << "\n**************  TESTING RemoveFront, Size, operator<< ****************" << endl;
	while (list.Size() > 0)
	{
		cout << "Removed: " << list.RemoveFront() << endl;
		cout << "Size: " << list.Size() << endl;
		cout << "List: " << list << endl;
		list.PrintFullNodes();
	}

	// TESTING List AddBack, Size and operator<<
	cout << "\n**************  TESTING AddBack, Size and operator<< ****************" << endl;
	for (int i = 1; i < 5; ++i)
	{
		list.AddBack(i);
		cout << "Size: " << list.Size() << endl;
		cout << "List: " << list << endl;
		list.PrintFullNodes();
	}

	// TESTING List RemoveBack, Size, operator<<
	cout << "\n**************  TESTING RemoveBack, Size, operator<< ****************" << endl;
	while (list.Size() > 0)
	{
		cout << "Removed: " << list.RemoveBack() << endl;
		cout << "Size: " << list.Size() << endl;
		cout << "List: " << list << endl << endl;
		list.PrintFullNodes();
	}

	// TESTING List AddBack, Size and operator<<
	cout << "\n**************  TESTING AddBack, AddFront, RemoveBack, RemoveFront << **" << endl;
	for (int i = 1; i < 5; ++i)
	{
		list.AddBack(i);
		list.AddFront(i);
		cout << "Size: " << list.Size() << endl;
		cout << "List: " << list << endl;
		list.PrintFullNodes();
	}

	while (list.Size() > 0)
	{
		cout << "Removed Back: " << list.RemoveBack() << endl;
		cout << "Size: " << list.Size() << endl;
		cout << "List: " << list << endl << endl;
		list.PrintFullNodes();
		cout << "Removed Front: " << list.RemoveFront() << endl;
		cout << "Size: " << list.Size() << endl;
		cout << "List: " << list << endl << endl;
		list.PrintFullNodes();
	}

	// TESTING List Search, RemoveItem, Size, operator<<
	cout << "\n**************  TESTING Search, RemoveItem, Size, operator<< ****************" << endl;
	cout << "NOTE:  Tests are performed to remove INNER items before OUTER items in list" << endl;

	// prepare a list
	for (int i = 1; i <= 5; ++i)
	{
		list.AddFront(i);
	}
	cout << "Size: " << list.Size() << endl;
	cout << "List: " << list << endl;
	list.PrintFullNodes();

	int i = 0;
	cout << "Find " << i << ": " << (list.Search(i) ? "TRUE" : "FALSE") << endl;
	cout << "Remove " << i << ": " << (list.RemoveItem(i) ? "TRUE" : "FALSE") << endl;
	cout << "Size: " << list.Size() << endl;
	cout << "List: " << list << endl << endl;
	list.PrintFullNodes();

	i = 3;
	cout << "Find " << i << ": " << (list.Search(i) ? "TRUE" : "FALSE") << endl;
	cout << "Remove " << i << ": " << (list.RemoveItem(i) ? "TRUE" : "FALSE") << endl;
	cout << "Size: " << list.Size() << endl;
	cout << "List: " << list << endl << endl;
	list.PrintFullNodes();

	i = 2;
	cout << "Find " << i << ": " << (list.Search(i) ? "TRUE" : "FALSE") << endl;
	cout << "Remove " << i << ": " << (list.RemoveItem(i) ? "TRUE" : "FALSE") << endl;
	cout << "Size: " << list.Size() << endl;
	cout << "List: " << list << endl << endl;
	list.PrintFullNodes();

	i = 4;
	cout << "Find " << i << ": " << (list.Search(i) ? "TRUE" : "FALSE") << endl;
	cout << "Remove " << i << ": " << (list.RemoveItem(i) ? "TRUE" : "FALSE") << endl;
	cout << "Size: " << list.Size() << endl;
	cout << "List: " << list << endl << endl;
	list.PrintFullNodes();

	i = 1;
	cout << "Find " << i << ": " << (list.Search(i) ? "TRUE" : "FALSE") << endl;
	cout << "Remove " << i << ": " << (list.RemoveItem(i) ? "TRUE" : "FALSE") << endl;
	cout << "Size: " << list.Size() << endl;
	cout << "List: " << list << endl << endl;
	list.PrintFullNodes();

	i = 5;
	cout << "Find " << i << ": " << (list.Search(i) ? "TRUE" : "FALSE") << endl;
	cout << "Remove " << i << ": " << (list.RemoveItem(i) ? "TRUE" : "FALSE") << endl;
	cout << "Size: " << list.Size() << endl;
	cout << "List: " << list << endl << endl;
	list.PrintFullNodes();

	// TESTING List Constructors, Destructors and operator=
	cout << "\n**************  TESTING Constructors, Destructors and operator= ****************" << endl;

	DoublyLinkedList* listPtr1 = new DoublyLinkedList();

	// prepare a list
	for (int i = 1; i <= 5; ++i)
	{
		listPtr1->AddFront(i);
	}
	cout << "Size: " << listPtr1->Size() << endl;
	cout << "List: " << *listPtr1 << endl;
	listPtr1->PrintFullNodes();

	// Test the copy constructor
	DoublyLinkedList* listPtr2 = new DoublyLinkedList(*listPtr1);
	cout << "Size Copy: " << listPtr2->Size() << endl;
	cout << "List Copy: " << *listPtr2 << endl;
	listPtr2->PrintFullNodes();
	delete listPtr2;

	// Test the assignment operator
	listPtr2 = new DoublyLinkedList();
	*listPtr2 = *listPtr1;
	cout << "Size operator=: " << listPtr2->Size() << endl;
	cout << "List operator=: " << *listPtr2 << endl;
	listPtr2->PrintFullNodes();
	delete listPtr2;

	// Test for self-assignment problems
	*listPtr1 = *listPtr1;
	cout << "Size self-assignment: " << listPtr1->Size() << endl;
	cout << "List self-assignment: " << *listPtr1 << endl;
	listPtr1->PrintFullNodes();

	// Delete the original list, if there is anything wrong with memory in copy or
	// assignment operator, this delete will cause a crash!
	delete listPtr1;
}

// Run the tests on the list using strings
void RunStringTests()
{
	/*
	// TESTING List Constructor
	DoublyLinkedList<string> list;
	cout << list << endl;

	// TESTING List AddFront, Size and operator<<
	cout << "**************  TESTING AddFront, Size and operator<< ****************" << endl;
	for (int i = 1; i < 5; ++i)
	{
	list.AddFront(to_string(i));
	cout << "Size: " << list.Size() << endl;
	cout << "List: " << list << endl;
	list.PrintFullNodes();
	}

	// TESTING List Search
	cout << "\n**************  TESTING Search ****************" << endl;
	for (int i = 0; i <= 5; ++i)
	{
	cout << "Find " << i << ": " << (list.Search(to_string(i)) ? "TRUE" : "FALSE") << endl;
	}

	// TESTING List RemoveFront, Size, operator<<
	cout << "\n**************  TESTING RemoveFront, Size, operator<< ****************" << endl;
	while (list.Size() > 0)
	{
	cout << "Removed: " << list.RemoveFront() << endl;
	cout << "Size: " << list.Size() << endl;
	cout << "List: " << list << endl;
	list.PrintFullNodes();
	}

	// TESTING List AddBack, Size and operator<<
	cout << "\n**************  TESTING AddBack, Size and operator<< ****************" << endl;
	for (int i = 1; i < 5; ++i)
	{
	list.AddBack(to_string(i));
	cout << "Size: " << list.Size() << endl;
	cout << "List: " << list << endl;
	list.PrintFullNodes();
	}

	// TESTING List RemoveBack, Size, operator<<
	cout << "\n**************  TESTING RemoveBack, Size, operator<< ****************" << endl;
	while (list.Size() > 0)
	{
	cout << "Removed: " << list.RemoveBack() << endl;
	cout << "Size: " << list.Size() << endl;
	cout << "List: " << list << endl << endl;
	list.PrintFullNodes();
	}

	// TESTING List AddBack, Size and operator<<
	cout << "\n**************  TESTING AddBack, AddFront, RemoveBack, RemoveFront << **" << endl;
	for (int i = 1; i < 5; ++i)
	{
	list.AddBack(to_string(i));
	list.AddFront(to_string(i));
	cout << "Size: " << list.Size() << endl;
	cout << "List: " << list << endl;
	list.PrintFullNodes();
	}

	while (list.Size() > 0)
	{
	cout << "Removed Back: " << list.RemoveBack() << endl;
	cout << "Size: " << list.Size() << endl;
	cout << "List: " << list << endl << endl;
	list.PrintFullNodes();
	cout << "Removed Front: " << list.RemoveFront() << endl;
	cout << "Size: " << list.Size() << endl;
	cout << "List: " << list << endl << endl;
	list.PrintFullNodes();
	}

	// TESTING List Search, RemoveItem, Size, operator<<
	cout << "\n**************  TESTING Search, RemoveItem, Size, operator<< ****************" << endl;
	cout << "NOTE:  Tests are performed to remove INNER items before OUTER items in list" << endl;

	// prepare a list
	for (int i = 1; i <= 5; ++i)
	{
	list.AddFront(to_string(i));
	}
	cout << "Size: " << list.Size() << endl;
	cout << "List: " << list << endl;
	list.PrintFullNodes();

	int i = 0;
	cout << "Find " << i << ": " << (list.Search(to_string(i)) ? "TRUE" : "FALSE") << endl;
	cout << "Remove " << i << ": " << (list.RemoveItem(to_string(i)) ? "TRUE" : "FALSE") << endl;
	cout << "Size: " << list.Size() << endl;
	cout << "List: " << list << endl << endl;
	list.PrintFullNodes();

	i = 3;
	cout << "Find " << i << ": " << (list.Search(to_string(i)) ? "TRUE" : "FALSE") << endl;
	cout << "Remove " << i << ": " << (list.RemoveItem(to_string(i)) ? "TRUE" : "FALSE") << endl;
	cout << "Size: " << list.Size() << endl;
	cout << "List: " << list << endl << endl;
	list.PrintFullNodes();

	i = 2;
	cout << "Find " << i << ": " << (list.Search(to_string(i)) ? "TRUE" : "FALSE") << endl;
	cout << "Remove " << i << ": " << (list.RemoveItem(to_string(i)) ? "TRUE" : "FALSE") << endl;
	cout << "Size: " << list.Size() << endl;
	cout << "List: " << list << endl << endl;
	list.PrintFullNodes();

	i = 4;
	cout << "Find " << i << ": " << (list.Search(to_string(i)) ? "TRUE" : "FALSE") << endl;
	cout << "Remove " << i << ": " << (list.RemoveItem(to_string(i)) ? "TRUE" : "FALSE") << endl;
	cout << "Size: " << list.Size() << endl;
	cout << "List: " << list << endl << endl;
	list.PrintFullNodes();

	i = 1;
	cout << "Find " << i << ": " << (list.Search(to_string(i)) ? "TRUE" : "FALSE") << endl;
	cout << "Remove " << i << ": " << (list.RemoveItem(to_string(i)) ? "TRUE" : "FALSE") << endl;
	cout << "Size: " << list.Size() << endl;
	cout << "List: " << list << endl << endl;
	list.PrintFullNodes();

	i = 5;
	cout << "Find " << i << ": " << (list.Search(to_string(i)) ? "TRUE" : "FALSE") << endl;
	cout << "Remove " << i << ": " << (list.RemoveItem(to_string(i)) ? "TRUE" : "FALSE") << endl;
	cout << "Size: " << list.Size() << endl;
	cout << "List: " << list << endl << endl;
	list.PrintFullNodes();

	// TESTING List Constructors, Destructors and operator=
	cout << "\n**************  TESTING Constructors, Destructors and operator= ****************" << endl;

	DoublyLinkedList* listPtr1 = new DoublyLinkedList();

	// prepare a list
	for (int i = 1; i <= 5; ++i)
	{
	listPtr1->AddFront(to_string(i));
	}
	cout << "Size: " << listPtr1->Size() << endl;
	cout << "List: " << *listPtr1 << endl;
	listPtr1->PrintFullNodes();

	// Test the copy constructor
	DoublyLinkedList* listPtr2 = new DoublyLinkedList(*listPtr1);
	cout << "Size Copy: " << listPtr2->Size() << endl;
	cout << "List Copy: " << *listPtr2 << endl;
	listPtr2->PrintFullNodes();
	delete listPtr2;

	// Test the assignment operator
	listPtr2 = new DoublyLinkedList();
	*listPtr2 = *listPtr1;
	cout << "Size operator=: " << listPtr2->Size() << endl;
	cout << "List operator=: " << *listPtr2 << endl;
	listPtr2->PrintFullNodes();
	delete listPtr2;

	// Test for self-assignment problems
	*listPtr1 = *listPtr1;
	cout << "Size self-assignment: " << listPtr1->Size() << endl;
	cout << "List self-assignment: " << *listPtr1 << endl;
	listPtr1->PrintFullNodes();

	// Delete the original list, if there is anything wrong with memory in copy or
	// assignment operator, this delete will cause a crash!
	delete listPtr1;
	*/
}

int main()
{
	RunIntegerTests();
	RunStringTests();

	cout << "Hit ENTER to exit..." << endl;
	string a;
	getline(cin, a);

	return 0;
}

