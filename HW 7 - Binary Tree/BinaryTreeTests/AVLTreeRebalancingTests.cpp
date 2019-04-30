#include "stdafx.h"
#include "CppUnitTest.h"
#include "BinaryTree.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace AVLTreeTests
{
	TEST_CLASS(AVLTreeRebalancingTests)
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
		// AVL Testing Root Rebalancing
		////////////////////////////////////////////////////////////////////////////////////////////////////////
		TEST_METHOD(AVL_RootLeftLeft)
		{
			BinaryTree<string> tree(true);
			tree.Insert("C");
			tree.Insert("B");
			tree.Insert("A");

			{
				ostringstream stream;
				tree.PreOrderPrint(stream);
				actual = stream.str();
				expected = "B A C ";
				Assert::AreEqual(expected, actual, L"Preorder failed", LINE_INFO());
			}
			{
				ostringstream stream;
				tree.InOrderPrint(stream);
				actual = stream.str();
				expected = "A B C ";
				Assert::AreEqual(expected, actual, L"Inorder failed", LINE_INFO());
			}
			{
				ostringstream stream;
				tree.PostOrderPrint(stream);
				actual = stream.str();
				expected = "A C B ";
				Assert::AreEqual(expected, actual, L"Postorder failed", LINE_INFO());
			}

			Assert::AreEqual(3, BinaryTreeNode<string>::GetNbrNodes(), L"AVL_RootLeftLeft Insert failed", LINE_INFO());
		}
		TEST_METHOD(AVL_RootRightRight)
		{
			BinaryTree<string> tree(true);
			tree.Insert("A");
			tree.Insert("B");
			tree.Insert("C");

			{
				ostringstream stream;
				tree.PreOrderPrint(stream);
				actual = stream.str();
				expected = "B A C ";
				Assert::AreEqual(expected, actual, L"Preorder failed", LINE_INFO());
			}
			{
				ostringstream stream;
				tree.InOrderPrint(stream);
				actual = stream.str();
				expected = "A B C ";
				Assert::AreEqual(expected, actual, L"Inorder failed", LINE_INFO());
			}
			{
				ostringstream stream;
				tree.PostOrderPrint(stream);
				actual = stream.str();
				expected = "A C B ";
				Assert::AreEqual(expected, actual, L"Postorder failed", LINE_INFO());
			}

			Assert::AreEqual(3, BinaryTreeNode<string>::GetNbrNodes(), L"AVL_RootRightRight Insert failed", LINE_INFO());
		}

		TEST_METHOD(AVL_RootRightLeft)
		{
			BinaryTree<string> tree(true);
			tree.Insert("A");
			tree.Insert("C");
			tree.Insert("B");

			{
				ostringstream stream;
				tree.PreOrderPrint(stream);
				actual = stream.str();
				expected = "B A C ";
				Assert::AreEqual(expected, actual, L"Preorder failed", LINE_INFO());
			}
			{
				ostringstream stream;
				tree.InOrderPrint(stream);
				actual = stream.str();
				expected = "A B C ";
				Assert::AreEqual(expected, actual, L"Inorder failed", LINE_INFO());
			}
			{
				ostringstream stream;
				tree.PostOrderPrint(stream);
				actual = stream.str();
				expected = "A C B ";
				Assert::AreEqual(expected, actual, L"Postorder failed", LINE_INFO());
			}

			Assert::AreEqual(3, BinaryTreeNode<string>::GetNbrNodes(), L"AVL_RootRightLeft Insert failed", LINE_INFO());
		}

		TEST_METHOD(AVL_RootLeftRight)
		{
			BinaryTree<string> tree(true);
			tree.Insert("C");
			tree.Insert("A");
			tree.Insert("B");

			{
				ostringstream stream;
				tree.PreOrderPrint(stream);
				actual = stream.str();
				expected = "B A C ";
				Assert::AreEqual(expected, actual, L"Preorder failed", LINE_INFO());
			}
			{
				ostringstream stream;
				tree.InOrderPrint(stream);
				actual = stream.str();
				expected = "A B C ";
				Assert::AreEqual(expected, actual, L"Inorder failed", LINE_INFO());
			}
			{
				ostringstream stream;
				tree.PostOrderPrint(stream);
				actual = stream.str();
				expected = "A C B ";
				Assert::AreEqual(expected, actual, L"Postorder failed", LINE_INFO());
			}

			Assert::AreEqual(3, BinaryTreeNode<string>::GetNbrNodes(), L"AVL_RootLeftRight Insert failed", LINE_INFO());
		}
		////////////////////////////////////////////////////////////////////////////////////////////////////////
		// AVL Testing Non-Root Rebalancing
		////////////////////////////////////////////////////////////////////////////////////////////////////////
		TEST_METHOD(AVL_NonrootRightRight)
		{
			BinaryTree<string> tree(true);
			tree.Insert("B");
			tree.Insert("C");
			tree.Insert("A");
			tree.Insert("D");
			tree.Insert("E");

			{
				ostringstream stream;
				tree.PreOrderPrint(stream);
				actual = stream.str();
				expected = "B A D C E ";
				Assert::AreEqual(expected, actual, L"Preorder failed", LINE_INFO());
			}
			{
				ostringstream stream;
				tree.InOrderPrint(stream);
				actual = stream.str();
				expected = "A B C D E ";
				Assert::AreEqual(expected, actual, L"Inorder failed", LINE_INFO());
			}
			{
				ostringstream stream;
				tree.PostOrderPrint(stream);
				actual = stream.str();
				expected = "A C E D B ";
				Assert::AreEqual(expected, actual, L"Postorder failed", LINE_INFO());
			}

			Assert::AreEqual(5, BinaryTreeNode<string>::GetNbrNodes(), L"AVL_NonrootRightRight Insert failed", LINE_INFO());
		}
		TEST_METHOD(AVL_NonrootLeftLeft)
		{
			BinaryTree<string> tree(true);
			tree.Insert("D");
			tree.Insert("C");
			tree.Insert("E");
			tree.Insert("B");
			tree.Insert("A");

			{
				ostringstream stream;
				tree.PreOrderPrint(stream);
				actual = stream.str();
				expected = "D B A C E ";
				Assert::AreEqual(expected, actual, L"Preorder failed", LINE_INFO());
			}
			{
				ostringstream stream;
				tree.InOrderPrint(stream);
				actual = stream.str();
				expected = "A B C D E ";
				Assert::AreEqual(expected, actual, L"Inorder failed", LINE_INFO());
			}
			{
				ostringstream stream;
				tree.PostOrderPrint(stream);
				actual = stream.str();
				expected = "A C B E D ";
				Assert::AreEqual(expected, actual, L"Postorder failed", LINE_INFO());
			}

			Assert::AreEqual(5, BinaryTreeNode<string>::GetNbrNodes(), L"AVL_NonrootLeftLeft Insert failed", LINE_INFO());
		}

		TEST_METHOD(AVL_NonrootRightleft)
		{
			BinaryTree<string> tree(true);
			tree.Insert("D");
			tree.Insert("C");
			tree.Insert("E");
			tree.Insert("A");
			tree.Insert("B");

			{
				ostringstream stream;
				tree.PreOrderPrint(stream);
				actual = stream.str();
				expected = "D B A C E ";
				Assert::AreEqual(expected, actual, L"Preorder failed", LINE_INFO());
			}
			{
				ostringstream stream;
				tree.InOrderPrint(stream);
				actual = stream.str();
				expected = "A B C D E ";
				Assert::AreEqual(expected, actual, L"Inorder failed", LINE_INFO());
			}
			{
				ostringstream stream;
				tree.PostOrderPrint(stream);
				actual = stream.str();
				expected = "A C B E D ";
				Assert::AreEqual(expected, actual, L"Postorder failed", LINE_INFO());
			}

			Assert::AreEqual(5, BinaryTreeNode<string>::GetNbrNodes(), L"AVL_NonrootRightleft Insert failed", LINE_INFO());
		}
		TEST_METHOD(AVL_NonrootLeftRight)
		{
			BinaryTree<string> tree(true);
			tree.Insert("B");
			tree.Insert("C");
			tree.Insert("A");
			tree.Insert("E");
			tree.Insert("D");

			{
				ostringstream stream;
				tree.PreOrderPrint(stream);
				actual = stream.str();
				expected = "B A D C E ";
				Assert::AreEqual(expected, actual, L"Preorder failed", LINE_INFO());
			}
			{
				ostringstream stream;
				tree.InOrderPrint(stream);
				actual = stream.str();
				expected = "A B C D E ";
				Assert::AreEqual(expected, actual, L"Inorder failed", LINE_INFO());
			}
			{
				ostringstream stream;
				tree.PostOrderPrint(stream);
				actual = stream.str();
				expected = "A C E D B ";
				Assert::AreEqual(expected, actual, L"Postorder failed", LINE_INFO());
			}

			Assert::AreEqual(5, BinaryTreeNode<string>::GetNbrNodes(), L"AVL_NonrootLeftRight Insert failed", LINE_INFO());
		}
		////////////////////////////////////////////////////////////////////////////////////////////////////////
		// AVL Testing Root Rebalancing from Descendent
		////////////////////////////////////////////////////////////////////////////////////////////////////////
		TEST_METHOD(AVL_RootRightRightDescendent)
		{
			BinaryTree<string> tree(true);
			tree.Insert("B");
			tree.Insert("A");
			tree.Insert("D");
			tree.Insert("C");
			tree.Insert("E");
			tree.Insert("F");

			{
				ostringstream stream;
				tree.PreOrderPrint(stream);
				actual = stream.str();
				expected = "D B A C E F ";
				Assert::AreEqual(expected, actual, L"Preorder failed", LINE_INFO());
			}
			{
				ostringstream stream;
				tree.InOrderPrint(stream);
				actual = stream.str();
				expected = "A B C D E F ";
				Assert::AreEqual(expected, actual, L"Inorder failed", LINE_INFO());
			}
			{
				ostringstream stream;
				tree.PostOrderPrint(stream);
				actual = stream.str();
				expected = "A C B F E D ";
				Assert::AreEqual(expected, actual, L"Postorder failed", LINE_INFO());
			}

			Assert::AreEqual(6, BinaryTreeNode<string>::GetNbrNodes(), L"AVL_RootRightRightDescendent Insert failed", LINE_INFO());
		}
		TEST_METHOD(AVL_RootLeftLeftDescendent)
		{
			BinaryTree<string> tree(true);
			tree.Insert("E");
			tree.Insert("C");
			tree.Insert("F");
			tree.Insert("B");
			tree.Insert("D");
			tree.Insert("A");

			{
				ostringstream stream;
				tree.PreOrderPrint(stream);
				actual = stream.str();
				expected = "C B A E D F ";
				Assert::AreEqual(expected, actual, L"Preorder failed", LINE_INFO());
			}
			{
				ostringstream stream;
				tree.InOrderPrint(stream);
				actual = stream.str();
				expected = "A B C D E F ";
				Assert::AreEqual(expected, actual, L"Inorder failed", LINE_INFO());
			}
			{
				ostringstream stream;
				tree.PostOrderPrint(stream);
				actual = stream.str();
				expected = "A B D F E C ";
				Assert::AreEqual(expected, actual, L"Postorder failed", LINE_INFO());
			}

			Assert::AreEqual(6, BinaryTreeNode<string>::GetNbrNodes(), L"AVL_RootLeftLeftDescendent Insert failed", LINE_INFO());
		}
		TEST_METHOD(AVL_RootLeftRightDescendent)
		{
			BinaryTree<string> tree(true);
			tree.Insert("E");
			tree.Insert("B");
			tree.Insert("F");
			tree.Insert("A");
			tree.Insert("D");
			tree.Insert("C");

			{
				ostringstream stream;
				tree.PreOrderPrint(stream);
				actual = stream.str();
				expected = "D B A C E F ";
				Assert::AreEqual(expected, actual, L"Preorder failed", LINE_INFO());
			}
			{
				ostringstream stream;
				tree.InOrderPrint(stream);
				actual = stream.str();
				expected = "A B C D E F ";
				Assert::AreEqual(expected, actual, L"Inorder failed", LINE_INFO());
			}
			{
				ostringstream stream;
				tree.PostOrderPrint(stream);
				actual = stream.str();
				expected = "A C B F E D ";
				Assert::AreEqual(expected, actual, L"Postorder failed", LINE_INFO());
			}

			Assert::AreEqual(6, BinaryTreeNode<string>::GetNbrNodes(), L"AVL_RootLeftLeftDescendent Insert failed", LINE_INFO());
		}

		TEST_METHOD(AVL_RootRightLeftDescendent)
		{
			BinaryTree<string> tree(true);
			tree.Insert("B");
			tree.Insert("A");
			tree.Insert("E");
			tree.Insert("C");
			tree.Insert("F");
			tree.Insert("D");

			{
				ostringstream stream;
				tree.PreOrderPrint(stream);
				actual = stream.str();
				expected = "C B A E D F ";
				Assert::AreEqual(expected, actual, L"Preorder failed", LINE_INFO());
			}
			{
				ostringstream stream;
				tree.InOrderPrint(stream);
				actual = stream.str();
				expected = "A B C D E F ";
				Assert::AreEqual(expected, actual, L"Inorder failed", LINE_INFO());
			}
			{
				ostringstream stream;
				tree.PostOrderPrint(stream);
				actual = stream.str();
				expected = "A B D F E C ";
				Assert::AreEqual(expected, actual, L"Postorder failed", LINE_INFO());
			}

			Assert::AreEqual(6, BinaryTreeNode<string>::GetNbrNodes(), L"AVL_RootLeftLeftDescendent Insert failed", LINE_INFO());
		}
	};
}