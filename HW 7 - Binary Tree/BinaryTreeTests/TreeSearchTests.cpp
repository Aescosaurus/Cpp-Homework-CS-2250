#include "stdafx.h"
#include "CppUnitTest.h"
#include "BinaryTree.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace BinaryTreeTests
{
	TEST_CLASS(TreeSearchTests)
	{
	public:

		string actual;
		string expected;

		////////////////////////////////////////////////////////////////////////////////////////////////////////
		// Methods for cleaning up after tests complete
		////////////////////////////////////////////////////////////////////////////////////////////////////////
		TEST_METHOD_CLEANUP(ResetNodeCount)
		{
			BinaryTreeNode<string>::ResetNbrNodes();
		}

		////////////////////////////////////////////////////////////////////////////////////////////////////////
		// Test the Search method on binary trees
		////////////////////////////////////////////////////////////////////////////////////////////////////////
		TEST_METHOD(SearchRootOnlyTree)
		{
			BinaryTree<string> tree;
			tree.Insert("N");

			// Search for things in the tree
			Assert::AreEqual(true, tree.Search("N"), L"Search failed", LINE_INFO());

			// Search for things that aren't in the tree
			Assert::AreEqual(false, tree.Search("n"), L"Search failed", LINE_INFO());
			Assert::AreEqual(false, tree.Search("z"), L"Search failed", LINE_INFO());
			Assert::AreEqual(false, tree.Search("o"), L"Search failed", LINE_INFO());
			Assert::AreEqual(false, tree.Search("A"), L"Search failed", LINE_INFO());
			Assert::AreEqual(false, tree.Search("AB"), L"Search failed", LINE_INFO());
			Assert::AreEqual(false, tree.Search("NZ"), L"Search failed", LINE_INFO());

			// Search for a few numerical items not in the tree
			Assert::AreEqual(false, tree.Search("1"), L"Search failed", LINE_INFO());
			Assert::AreEqual(false, tree.Search("54"), L"Search failed", LINE_INFO());
			Assert::AreEqual(false, tree.Search("67"), L"Search failed", LINE_INFO());

			// Search for a few special character items not in the tree
			Assert::AreEqual(false, tree.Search("%$@&*"), L"Search failed", LINE_INFO());
			Assert::AreEqual(false, tree.Search("#"), L"Search failed", LINE_INFO());
			Assert::AreEqual(false, tree.Search("()"), L"Search failed", LINE_INFO());
		}

		TEST_METHOD(SearchSmallTree)
		{
			BinaryTree<string> tree;
			tree.Insert("N");
			tree.Insert("Z");
			tree.Insert("O");

			// Search for things in the tree
			Assert::AreEqual(true, tree.Search("O"), L"Search failed", LINE_INFO());
			Assert::AreEqual(true, tree.Search("Z"), L"Search failed", LINE_INFO());
			Assert::AreEqual(true, tree.Search("N"), L"Search failed", LINE_INFO());

			// Search for things that aren't in the tree
			Assert::AreEqual(false, tree.Search("n"), L"Search failed", LINE_INFO());
			Assert::AreEqual(false, tree.Search("z"), L"Search failed", LINE_INFO());
			Assert::AreEqual(false, tree.Search("o"), L"Search failed", LINE_INFO());
			Assert::AreEqual(false, tree.Search("A"), L"Search failed", LINE_INFO());
			Assert::AreEqual(false, tree.Search("AB"), L"Search failed", LINE_INFO());
			Assert::AreEqual(false, tree.Search("NZ"), L"Search failed", LINE_INFO());

			// Search for a few numerical items not in the tree
			Assert::AreEqual(false, tree.Search("1"), L"Search failed", LINE_INFO());
			Assert::AreEqual(false, tree.Search("54"), L"Search failed", LINE_INFO());
			Assert::AreEqual(false, tree.Search("67"), L"Search failed", LINE_INFO());

			// Search for a few special character items not in the tree
			Assert::AreEqual(false, tree.Search("%$@&*"), L"Search failed", LINE_INFO());
			Assert::AreEqual(false, tree.Search("#"), L"Search failed", LINE_INFO());
			Assert::AreEqual(false, tree.Search("()"), L"Search failed", LINE_INFO());
		}

		TEST_METHOD(SearchBigTree)
		{
			BinaryTree<string> tree;
			tree.Insert("N");
			tree.Insert("Z");
			tree.Insert("O");
			tree.Insert("A");
			tree.Insert("X");
			tree.Insert("B");
			tree.Insert("V");
			tree.Insert("Y");
			tree.Insert("E");
			tree.Insert("H");
			tree.Insert("W");
			tree.Insert("K");
			tree.Insert("R");
			tree.Insert("I");
			tree.Insert("Q");
			tree.Insert("C");
			tree.Insert("U");
			tree.Insert("J");
			tree.Insert("P");
			tree.Insert("S");
			tree.Insert("D");
			tree.Insert("T");
			tree.Insert("M");
			tree.Insert("F");
			tree.Insert("G");
			tree.Insert("L");

			// Search for each item in the tree
			Assert::AreEqual(true, tree.Search("A"), L"Search failed", LINE_INFO());
			Assert::AreEqual(true, tree.Search("B"), L"Search failed", LINE_INFO());
			Assert::AreEqual(true, tree.Search("C"), L"Search failed", LINE_INFO());
			Assert::AreEqual(true, tree.Search("D"), L"Search failed", LINE_INFO());
			Assert::AreEqual(true, tree.Search("E"), L"Search failed", LINE_INFO());
			Assert::AreEqual(true, tree.Search("F"), L"Search failed", LINE_INFO());
			Assert::AreEqual(true, tree.Search("G"), L"Search failed", LINE_INFO());
			Assert::AreEqual(true, tree.Search("H"), L"Search failed", LINE_INFO());
			Assert::AreEqual(true, tree.Search("I"), L"Search failed", LINE_INFO());
			Assert::AreEqual(true, tree.Search("J"), L"Search failed", LINE_INFO());
			Assert::AreEqual(true, tree.Search("K"), L"Search failed", LINE_INFO());
			Assert::AreEqual(true, tree.Search("L"), L"Search failed", LINE_INFO());
			Assert::AreEqual(true, tree.Search("M"), L"Search failed", LINE_INFO());
			Assert::AreEqual(true, tree.Search("N"), L"Search failed", LINE_INFO());
			Assert::AreEqual(true, tree.Search("O"), L"Search failed", LINE_INFO());
			Assert::AreEqual(true, tree.Search("P"), L"Search failed", LINE_INFO());
			Assert::AreEqual(true, tree.Search("Q"), L"Search failed", LINE_INFO());
			Assert::AreEqual(true, tree.Search("R"), L"Search failed", LINE_INFO());
			Assert::AreEqual(true, tree.Search("S"), L"Search failed", LINE_INFO());
			Assert::AreEqual(true, tree.Search("T"), L"Search failed", LINE_INFO());
			Assert::AreEqual(true, tree.Search("U"), L"Search failed", LINE_INFO());
			Assert::AreEqual(true, tree.Search("V"), L"Search failed", LINE_INFO());
			Assert::AreEqual(true, tree.Search("W"), L"Search failed", LINE_INFO());
			Assert::AreEqual(true, tree.Search("X"), L"Search failed", LINE_INFO());
			Assert::AreEqual(true, tree.Search("Y"), L"Search failed", LINE_INFO());
			Assert::AreEqual(true, tree.Search("Z"), L"Search failed", LINE_INFO());

			// Search for a few alphabetical items not in the tree
			Assert::AreEqual(false, tree.Search("a"), L"Search failed", LINE_INFO());
			Assert::AreEqual(false, tree.Search("b"), L"Search failed", LINE_INFO());
			Assert::AreEqual(false, tree.Search("c"), L"Search failed", LINE_INFO());
			Assert::AreEqual(false, tree.Search("d"), L"Search failed", LINE_INFO());
			Assert::AreEqual(false, tree.Search("e"), L"Search failed", LINE_INFO());
			Assert::AreEqual(false, tree.Search("AB"), L"Search failed", LINE_INFO());
			Assert::AreEqual(false, tree.Search("ABCDEF"), L"Search failed", LINE_INFO());

			// Search for a few numerical items not in the tree
			Assert::AreEqual(false, tree.Search("1"), L"Search failed", LINE_INFO());
			Assert::AreEqual(false, tree.Search("54"), L"Search failed", LINE_INFO());
			Assert::AreEqual(false, tree.Search("67"), L"Search failed", LINE_INFO());

			// Search for a few special character items not in the tree
			Assert::AreEqual(false, tree.Search("%$@&*"), L"Search failed", LINE_INFO());
			Assert::AreEqual(false, tree.Search("#"), L"Search failed", LINE_INFO());
			Assert::AreEqual(false, tree.Search("()"), L"Search failed", LINE_INFO());
		}
	};
}