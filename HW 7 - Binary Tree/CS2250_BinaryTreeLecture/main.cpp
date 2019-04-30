#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>

#include "BinaryTree.h"
#include "Trophy.h"

using namespace std;

string smallRootOnlyTree[] = { "A" };
string smallRootOnlyTreeOutput[] = { "A ", "A ", "A " };

string smallSimpleTree[] = { "D", "B", "F" };
string smallSimpleTreeOutput[] = { "D B F ", "B D F ", "B F D " };

string leftLeftTree[] = { "C", "B", "A" };
string leftLeftTreeOutput[] = { "C B A ", "A B C ", "A B C " };
string leftLeftTreeOutputAVL[] = { "B A C ", "A B C ", "A C B " };

string rightRightTree[] = { "A", "B", "C" };
string rightRightTreeOutput[] = { "A B C ", "A B C ", "C B A " };
string rightRightTreeOutputAVL[] = { "B A C ", "A B C ", "A C B " };

string leftRightTree[] = { "C", "A", "B" };
string leftRightTreeOutput[] = { "C A B ", "A B C ", "B A C " };
string leftRightTreeOutputAVL[] = { "B A C ", "A B C ", "A C B " };

string rightLeftTree[] = { "A", "C", "B" };
string rightLeftTreeOutput[] = { "A C B ", "A B C ", "B C A " };
string rightLeftTreeOutputAVL[] = { "B A C ", "A B C ", "A C B " };

string smallFullTree[] = { "D", "B", "F", "C", "A", "E", "G" };
string smallFullTreeOutput[] = { "D B A C F E G ", "A B C D E F G ", "A C B E G F D " };

string largeTree[] = { "M", "J", "C", "B", "S", "I", "P", "D", "U", "F", "W", "H", "K", "N", "X", "O", "V", "A", "L", "Q", "R", "G", "T", "E", "Y" };
string largeTreeOutput[] = { "M J C B A I D F E H G K L S P N O Q R U T W V X Y ",
							 "A B C D E F G H I J K L M N O P Q R S T U V W X Y ",
							 "A B E G H F D I C L K J O N R Q P T V Y X W U S M " };
string largeTreeOutputAVL[] = { "J F C B A D E H G I P M K L N O U R Q S T W V X Y ",
								"A B C D E F G H I J K L M N O P Q R S T U V W X Y ",
								"A B E D C G I H F L K O N M Q T S R V Y X W U P J " };

const int testNameSize = 65;
int nbrFailed = 0;

void TestTree(string test, string nodes[], int nbrNodes, string output[], bool isAVL = false)
{
	// TODO: change this into a templated tree based on strings
	BinaryTree* tree = new BinaryTree(isAVL);
	string testName = "";

	cout << "************************************************************************" << endl;
	cout << "TESTING " << test << endl;
	cout << "************************************************************************" << endl;

	// TODO: change the BinaryTreeNode references below to use templates based on strings
	// Test node insertion
	for (int i = 0; i < nbrNodes; ++i)
	{
		tree->Insert(nodes[i]);
		testName = "Inserting " + nodes[i] + " NumberOfNodes = " + to_string(BinaryTreeNode::GetNbrNodes());
		string result = ((BinaryTreeNode::GetNbrNodes() == (i + 1)) ? "PASSED" : "FAILED");
		if (result == "FAILED") ++nbrFailed;
		cout << left << setw(testNameSize) << testName << result << endl;
		cout << *tree << endl;
	}

	// Test search
	for (int i = 0; i < nbrNodes; ++i)
	{
		testName = "Searching for " + nodes[i];
		string result = (tree->Search(nodes[i]) ? "PASSED" : "FAILED");
		if (result == "FAILED") ++nbrFailed;
		cout << left << setw(testNameSize) << testName << result << endl;
	}
	testName = "Searching for Z ";
	string result = (!tree->Search("Z") ? "PASSED" : "FAILED");
	if (result == "FAILED") ++nbrFailed;
	cout << left << setw(testNameSize) << testName << result << endl;

	// Test Output
	ostringstream stream;
	stream << *tree;
	string actualResult = stream.str();
	string expectedResult = "PreOrderPrint:   " + output[0] + "\n"
		+ "InOrderPrint:    " + output[1] + "\n"
		+ "PostOrderPrint:  " + output[2] + "\n";

	cout << "Actual Result: " << endl << actualResult << endl;
	cout << "Expected Result: " << endl << expectedResult << endl;
	result = ((actualResult == expectedResult) ? "PASSED" : "FAILED");
	if (result == "FAILED") ++nbrFailed;
	cout << left << setw(testNameSize) << "Output of Tree (above) " << result << endl;

	// Test Removal
	testName = "Removing Z ";
	result = (!tree->Remove("Z") ? "PASSED" : "FAILED");
	if (result == "FAILED") ++nbrFailed;
	cout << left << setw(testNameSize) << testName << result << endl;

	// TODO: change the BinaryTreeNode references below to use templates based on strings
	for (int i = 0; i < nbrNodes; ++i)
	{
		testName = "Removing " + nodes[i];
		result = (tree->Remove(nodes[i]) ? "PASSED" : "FAILED");
		if (result == "FAILED") ++nbrFailed;
		cout << left << setw(testNameSize) << testName << result << endl;
		testName = "Number of Nodes = " + to_string(BinaryTreeNode::GetNbrNodes());
		result = ((BinaryTreeNode::GetNbrNodes() == (nbrNodes - i - 1)) ? "PASSED" : "FAILED");
		if (result == "FAILED") ++nbrFailed;
		cout << left << setw(testNameSize) << testName << result << endl;
	}

	delete tree;
	cout << endl;
}

// TODO: Once you've added templates, uncomment this code
/*
////////////////////////////////////////////////////////////////////////////////
// Template Tests
// Uncomment this portion of the file to test your templated BinaryTree on ints
////////////////////////////////////////////////////////////////////////////////

void TestTemplatedTree(string test, int size, bool isAVL = false)
{
	BinaryTree<int>* tree = new BinaryTree<int>(isAVL);
	string testName = "";

	cout << "************************************************************************" << endl;
	cout << "TESTING TEMPLATE TREE " << test << endl;
	cout << "************************************************************************" << endl;

	vector<int> numbers;
	// Create list of numbers to insert
	for (int i = 0; i < size; ++i)
	{
		numbers.push_back(i);
	}

	// Insert numbers in a random order
	while (numbers.size() > 0)
	{
		int randomIndex = static_cast<int>(rand() % numbers.size());
		tree->Insert(numbers[randomIndex]);
		testName = "Inserting " + to_string(numbers[randomIndex]) + " NumberOfNodes = " + to_string(BinaryTreeNode<int>::GetNbrNodes());
		numbers.erase(numbers.begin() + randomIndex);

		string result = ((BinaryTreeNode<int>::GetNbrNodes() == (size - numbers.size())) ? "PASSED" : "FAILED");
		if (result == "FAILED") ++nbrFailed;
		cout << left << setw(testNameSize) << testName << result << endl;
		cout << *tree << endl;
	}

	// Test search
	for (int i = 0; i < size; ++i)
	{
		testName = "Searching for " + to_string(i);
		string result = (tree->Search(i) ? "PASSED" : "FAILED");
		if (result == "FAILED") ++nbrFailed;
		cout << left << setw(testNameSize) << testName << result << endl;
	}
	testName = "Searching for -1 ";
	string result = (!tree->Search(-1) ? "PASSED" : "FAILED");
	if (result == "FAILED") ++nbrFailed;
	cout << left << setw(testNameSize) << testName << result << endl;

	// Test Removal
	testName = "Removing -1 ";
	result = (!tree->Remove(-1) ? "PASSED" : "FAILED");
	if (result == "FAILED") ++nbrFailed;
	cout << left << setw(testNameSize) << testName << result << endl;

	numbers;
	// Create list of numbers to insert
	for (int i = 0; i < size; ++i)
	{
		numbers.push_back(i);
	}

	// Remove numbers in a random order
	while (numbers.size() > 0)
	{
		int randomIndex = static_cast<int>(rand() % numbers.size());
		result = (tree->Remove(numbers[randomIndex]) ? "PASSED" : "FAILED");
		if (result == "FAILED") ++nbrFailed;
		testName = "Removing " + to_string(numbers[randomIndex]) + " NumberOfNodes = " + to_string(BinaryTreeNode<int>::GetNbrNodes());
		cout << left << setw(testNameSize) << testName << result << endl;
		numbers.erase(numbers.begin() + randomIndex);

		testName = "Number of Nodes = " + to_string(BinaryTreeNode<int>::GetNbrNodes());
		result = ((BinaryTreeNode<int>::GetNbrNodes() == (numbers.size())) ? "PASSED" : "FAILED");
		if (result == "FAILED") ++nbrFailed;
		cout << left << setw(testNameSize) << testName << result << endl;
	}

	delete tree;
	cout << endl;
}
*/

void RunTests()
{
	// Test normal trees
	TestTree("smallRootOnlyTree", smallRootOnlyTree, 1, smallRootOnlyTreeOutput);
	TestTree("smallSimpleTree", smallSimpleTree, 3, smallSimpleTreeOutput);
	TestTree("smallFullTree", smallFullTree, 7, smallFullTreeOutput);

	TestTree("rightLeftTree", rightLeftTree, 3, rightLeftTreeOutput);
	TestTree("leftRightTree", leftRightTree, 3, leftRightTreeOutput);
	TestTree("rightRightTree", rightRightTree, 3, rightRightTreeOutput);
	TestTree("leftLeftTree", leftLeftTree, 3, leftLeftTreeOutput);
	TestTree("largeTree", largeTree, 25, largeTreeOutput);

	// Test the AVL tree
	TestTree("rightLeftTreeAVL", rightLeftTree, 3, rightLeftTreeOutputAVL, true);
	TestTree("leftRightTreeAVL", leftRightTree, 3, leftRightTreeOutputAVL, true);
	TestTree("rightRightTreeAVL", rightRightTree, 3, rightRightTreeOutputAVL, true);
	TestTree("leftLeftTreeAVL", leftLeftTree, 3, leftLeftTreeOutputAVL, true);
	TestTree("largeTreeAVL", largeTree, 25, largeTreeOutputAVL, true);
	TestTree("largeTreeAVL", largeTree, 25, largeTreeOutputAVL, true);

	// TODO: Once you've added templates, uncomment this code
	/*
	////////////////////////////////////////////////////////////////////////////////
	// Template Tests
	// Uncomment this portion of the file to test your templated BinaryTree on ints
	////////////////////////////////////////////////////////////////////////////////

	// Test the Templated Tree
	TestTemplatedTree("FiveIntegerTemplateTree", 5);
	TestTemplatedTree("FifteenIntegerTemplateTree", 15);
	TestTemplatedTree("TwentyFiveIntegerTemplateTree", 25);
	TestTemplatedTree("FiftyIntegerTemplateTree", 50);
	*/
}

int main()
{
	RunTests();

	cout << "======================================================================" << endl;
	cout << "Number of FAILED Tests: " << nbrFailed << endl;

	char c;
	cin.get(c);
	return 0;
}