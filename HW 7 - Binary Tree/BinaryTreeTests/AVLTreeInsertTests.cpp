#include "stdafx.h"
#include "CppUnitTest.h"
#include "BinaryTree.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace AVLTreeTests
{
	TEST_CLASS(AVLTreeInsertTests)
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
		// Empty and Deleted Tests
		////////////////////////////////////////////////////////////////////////////////////////////////////////
		TEST_METHOD(InsertFromEmpty)
		{
			BinaryTree<string> tree(true);
			Assert::AreEqual(false, tree.Search("A"), L"Search from empty failed", LINE_INFO());
			Assert::AreEqual(0, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Insert failed", LINE_INFO());
		}

		TEST_METHOD(InsertDeleted)
		{
			BinaryTree<string> tree(true);
			tree.Insert("A");
			tree.Insert("B");
			tree.Insert("C");
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

			Assert::AreEqual(5, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Insert failed", LINE_INFO());
		}

		////////////////////////////////////////////////////////////////////////////////////////////////////////
		// Root Tests
		////////////////////////////////////////////////////////////////////////////////////////////////////////
		TEST_METHOD(InsertRootNoChildren)
		{
			BinaryTree<string> tree(true);
			tree.Insert("A");

			{
				ostringstream stream;
				tree.PreOrderPrint(stream);
				actual = stream.str();
				expected = "A ";
				Assert::AreEqual(expected, actual, L"Preorder failed", LINE_INFO());
			}
			{
				ostringstream stream;
				tree.InOrderPrint(stream);
				actual = stream.str();
				expected = "A ";
				Assert::AreEqual(expected, actual, L"Inorder failed", LINE_INFO());
			}
			{
				ostringstream stream;
				tree.PostOrderPrint(stream);
				actual = stream.str();
				expected = "A ";
				Assert::AreEqual(expected, actual, L"Postorder failed", LINE_INFO());
			}

			Assert::AreEqual(1, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Insert failed", LINE_INFO());
		}

		TEST_METHOD(InsertRootLeftChild)
		{
			BinaryTree<string> tree(true);
			tree.Insert("B");
			tree.Insert("A");

			{
				ostringstream stream;
				tree.PreOrderPrint(stream);
				actual = stream.str();
				expected = "B A ";
				Assert::AreEqual(expected, actual, L"Preorder failed", LINE_INFO());
			}
			{
				ostringstream stream;
				tree.InOrderPrint(stream);
				actual = stream.str();
				expected = "A B ";
				Assert::AreEqual(expected, actual, L"Inorder failed", LINE_INFO());
			}
			{
				ostringstream stream;
				tree.PostOrderPrint(stream);
				actual = stream.str();
				expected = "A B ";
				Assert::AreEqual(expected, actual, L"Postorder failed", LINE_INFO());
			}

			Assert::AreEqual(2, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Insert failed", LINE_INFO());
		}

		TEST_METHOD(InsertRootRightChild)
		{
			BinaryTree<string> tree(true);
			tree.Insert("A");
			tree.Insert("B");

			{
				ostringstream stream;
				tree.PreOrderPrint(stream);
				actual = stream.str();
				expected = "A B ";
				Assert::AreEqual(expected, actual, L"Preorder failed", LINE_INFO());
			}
			{
				ostringstream stream;
				tree.InOrderPrint(stream);
				actual = stream.str();
				expected = "A B ";
				Assert::AreEqual(expected, actual, L"Inorder failed", LINE_INFO());
			}
			{
				ostringstream stream;
				tree.PostOrderPrint(stream);
				actual = stream.str();
				expected = "B A ";
				Assert::AreEqual(expected, actual, L"Postorder failed", LINE_INFO());
			}

			Assert::AreEqual(2, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Insert failed", LINE_INFO());
		}

		////////////////////////////////////////////////////////////////////////////////////////////////////////
		// Child Tests
		////////////////////////////////////////////////////////////////////////////////////////////////////////
		TEST_METHOD(InsertLeftLeftChild)
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

			Assert::AreEqual(3, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Insert failed", LINE_INFO());
		}

		TEST_METHOD(InsertLeftRightChild)
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

			Assert::AreEqual(3, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Insert failed", LINE_INFO());
		}

		TEST_METHOD(InsertRightLeftChild)
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

			Assert::AreEqual(3, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Insert failed", LINE_INFO());
		}

		TEST_METHOD(InsertRightRightChild)
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

			Assert::AreEqual(3, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Insert failed", LINE_INFO());
		}

		////////////////////////////////////////////////////////////////////////////////////////////////////////
		// Two Child Tests
		////////////////////////////////////////////////////////////////////////////////////////////////////////
		TEST_METHOD(InsertRootWithTwoChildren)
		{
			BinaryTree<string> tree(true);
			tree.Insert("B");
			tree.Insert("A");
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

			Assert::AreEqual(3, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Insert failed", LINE_INFO());
		}

		TEST_METHOD(InsertLeftChildWithTwoChildren)
		{
			BinaryTree<string> tree(true);
			tree.Insert("D");
			tree.Insert("B");
			tree.Insert("A");
			tree.Insert("C");

			{
				ostringstream stream;
				tree.PreOrderPrint(stream);
				actual = stream.str();
				expected = "B A D C ";
				Assert::AreEqual(expected, actual, L"Preorder failed", LINE_INFO());
			}
			{
				ostringstream stream;
				tree.InOrderPrint(stream);
				actual = stream.str();
				expected = "A B C D ";
				Assert::AreEqual(expected, actual, L"Inorder failed", LINE_INFO());
			}
			{
				ostringstream stream;
				tree.PostOrderPrint(stream);
				actual = stream.str();
				expected = "A C D B ";
				Assert::AreEqual(expected, actual, L"Postorder failed", LINE_INFO());
			}

			Assert::AreEqual(4, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Insert failed", LINE_INFO());
		}

		TEST_METHOD(InsertRightChildWithTwoChildren)
		{
			BinaryTree<string> tree(true);
			tree.Insert("A");
			tree.Insert("C");
			tree.Insert("B");
			tree.Insert("D");

			{
				ostringstream stream;
				tree.PreOrderPrint(stream);
				actual = stream.str();
				expected = "B A C D ";
				Assert::AreEqual(expected, actual, L"Preorder failed", LINE_INFO());
			}
			{
				ostringstream stream;
				tree.InOrderPrint(stream);
				actual = stream.str();
				expected = "A B C D ";
				Assert::AreEqual(expected, actual, L"Inorder failed", LINE_INFO());
			}
			{
				ostringstream stream;
				tree.PostOrderPrint(stream);
				actual = stream.str();
				expected = "A D C B ";
				Assert::AreEqual(expected, actual, L"Postorder failed", LINE_INFO());
			}

			Assert::AreEqual(4, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Insert failed", LINE_INFO());
		}

		////////////////////////////////////////////////////////////////////////////////////////////////////////
		// Root Grand Child Tests
		////////////////////////////////////////////////////////////////////////////////////////////////////////
		TEST_METHOD(InsertRootWithRightInnerGrandChild)
		{
			BinaryTree<string> tree(true);
			tree.Insert("B");
			tree.Insert("A");
			tree.Insert("D");
			tree.Insert("C");

			{
				ostringstream stream;
				tree.PreOrderPrint(stream);
				actual = stream.str();
				expected = "B A D C ";
				Assert::AreEqual(expected, actual, L"Preorder failed", LINE_INFO());
			}
			{
				ostringstream stream;
				tree.InOrderPrint(stream);
				actual = stream.str();
				expected = "A B C D ";
				Assert::AreEqual(expected, actual, L"Inorder failed", LINE_INFO());
			}
			{
				ostringstream stream;
				tree.PostOrderPrint(stream);
				actual = stream.str();
				expected = "A C D B ";
				Assert::AreEqual(expected, actual, L"Postorder failed", LINE_INFO());
			}

			Assert::AreEqual(4, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Insert failed", LINE_INFO());
		}

		TEST_METHOD(InsertRootWithLeftInnerGrandChild)
		{
			BinaryTree<string> tree(true);
			tree.Insert("C");
			tree.Insert("A");
			tree.Insert("D");
			tree.Insert("B");

			{
				ostringstream stream;
				tree.PreOrderPrint(stream);
				actual = stream.str();
				expected = "C A B D ";
				Assert::AreEqual(expected, actual, L"Preorder failed", LINE_INFO());
			}
			{
				ostringstream stream;
				tree.InOrderPrint(stream);
				actual = stream.str();
				expected = "A B C D ";
				Assert::AreEqual(expected, actual, L"Inorder failed", LINE_INFO());
			}
			{
				ostringstream stream;
				tree.PostOrderPrint(stream);
				actual = stream.str();
				expected = "B A D C ";
				Assert::AreEqual(expected, actual, L"Postorder failed", LINE_INFO());
			}

			Assert::AreEqual(4, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Insert failed", LINE_INFO());
		}

		TEST_METHOD(InsertRootWithRightOuterGrandChild)
		{
			BinaryTree<string> tree(true);
			tree.Insert("B");
			tree.Insert("A");
			tree.Insert("C");
			tree.Insert("D");

			{
				ostringstream stream;
				tree.PreOrderPrint(stream);
				actual = stream.str();
				expected = "B A C D ";
				Assert::AreEqual(expected, actual, L"Preorder failed", LINE_INFO());
			}
			{
				ostringstream stream;
				tree.InOrderPrint(stream);
				actual = stream.str();
				expected = "A B C D ";
				Assert::AreEqual(expected, actual, L"Inorder failed", LINE_INFO());
			}
			{
				ostringstream stream;
				tree.PostOrderPrint(stream);
				actual = stream.str();
				expected = "A D C B ";
				Assert::AreEqual(expected, actual, L"Postorder failed", LINE_INFO());
			}

			Assert::AreEqual(4, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Insert failed", LINE_INFO());
		}

		TEST_METHOD(InsertRootWithLeftOuterGrandChild)
		{
			BinaryTree<string> tree(true);
			tree.Insert("C");
			tree.Insert("B");
			tree.Insert("D");
			tree.Insert("A");

			{
				ostringstream stream;
				tree.PreOrderPrint(stream);
				actual = stream.str();
				expected = "C B A D ";
				Assert::AreEqual(expected, actual, L"Preorder failed", LINE_INFO());
			}
			{
				ostringstream stream;
				tree.InOrderPrint(stream);
				actual = stream.str();
				expected = "A B C D ";
				Assert::AreEqual(expected, actual, L"Inorder failed", LINE_INFO());
			}
			{
				ostringstream stream;
				tree.PostOrderPrint(stream);
				actual = stream.str();
				expected = "A B D C ";
				Assert::AreEqual(expected, actual, L"Postorder failed", LINE_INFO());
			}

			Assert::AreEqual(4, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Insert failed", LINE_INFO());
		}

		////////////////////////////////////////////////////////////////////////////////////////////////////////
		// Nonroot Grand Child Tests
		////////////////////////////////////////////////////////////////////////////////////////////////////////
		TEST_METHOD(InsertLeftChildWithInnerChild)
		{
			BinaryTree<string> tree(true);
			tree.Insert("E");
			tree.Insert("B");
			tree.Insert("A");
			tree.Insert("D");
			tree.Insert("C");

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

			Assert::AreEqual(5, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Insert failed", LINE_INFO());
		}

		TEST_METHOD(InsertRightChildWithInnerChild)
		{
			BinaryTree<string> tree(true);
			tree.Insert("A");
			tree.Insert("C");
			tree.Insert("B");
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

			Assert::AreEqual(5, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Insert failed", LINE_INFO());
		}

		TEST_METHOD(InsertLeftChildWithOuterChild)
		{
			BinaryTree<string> tree(true);
			tree.Insert("E");
			tree.Insert("B");
			tree.Insert("A");
			tree.Insert("C");
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

			Assert::AreEqual(5, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Insert failed", LINE_INFO());
		}

		TEST_METHOD(InsertRightChildWithOuterChild)
		{
			BinaryTree<string> tree(true);
			tree.Insert("A");
			tree.Insert("C");
			tree.Insert("B");
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
			
			Assert::AreEqual(5, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Insert failed", LINE_INFO());
		}

		////////////////////////////////////////////////////////////////////////////////////////////////////////
		// Root Great Grand Child Tests
		////////////////////////////////////////////////////////////////////////////////////////////////////////
		TEST_METHOD(InsertRootWithRightLeftLeftChild)
		{
			BinaryTree<string> tree(true);
			tree.Insert("B");
			tree.Insert("A");
			tree.Insert("E");
			tree.Insert("D");
			tree.Insert("C");

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
			
			Assert::AreEqual(5, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Insert failed", LINE_INFO());
		}

		TEST_METHOD(InsertRootWithRightLeftRightChild)
		{
			BinaryTree<string> tree(true);
			tree.Insert("B");
			tree.Insert("A");
			tree.Insert("E");
			tree.Insert("C");
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
			
			Assert::AreEqual(5, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Insert failed", LINE_INFO());
		}

		////////////////////////////////////////////////////////////////////////////////////////////////////////
		// Nonroot Great Grand Child Tests
		////////////////////////////////////////////////////////////////////////////////////////////////////////
		TEST_METHOD(InsertRootLeftWithRightLeftLeftChild)
		{
			BinaryTree<string> tree(true);
			tree.Insert("F");
			tree.Insert("B");
			tree.Insert("A");
			tree.Insert("E");
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
			
			Assert::AreEqual(6, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Insert failed", LINE_INFO());
		}

		TEST_METHOD(InsertRootRightWithRightLeftLeftChild)
		{
			BinaryTree<string> tree(true);
			tree.Insert("A");
			tree.Insert("C");
			tree.Insert("B");
			tree.Insert("F");
			tree.Insert("E");
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
			
			Assert::AreEqual(6, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Insert failed", LINE_INFO());
		}

		TEST_METHOD(InsertRootLeftWithRightLeftRightChild)
		{
			BinaryTree<string> tree(true);
			tree.Insert("F");
			tree.Insert("B");
			tree.Insert("A");
			tree.Insert("E");
			tree.Insert("C");
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
			
			Assert::AreEqual(6, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Insert failed", LINE_INFO());
		}

		TEST_METHOD(InsertRootRightWithRightLeftRightChild)
		{
			BinaryTree<string> tree(true);
			tree.Insert("A");
			tree.Insert("C");
			tree.Insert("B");
			tree.Insert("F");
			tree.Insert("D");
			tree.Insert("E");

			{
				ostringstream stream;
				tree.PreOrderPrint(stream);
				actual = stream.str();
				expected = "D B A C F E ";

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
				expected = "A C B E F D ";
				Assert::AreEqual(expected, actual, L"Postorder failed", LINE_INFO());
			}
			
			Assert::AreEqual(6, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Insert failed", LINE_INFO());
		}

		////////////////////////////////////////////////////////////////////////////////////////////////////////
		// Insert Min Chain
		////////////////////////////////////////////////////////////////////////////////////////////////////////
		TEST_METHOD(InsertRootMinChain)
		{
			BinaryTree<string> tree(true);
			tree.Insert("A");
			tree.Insert("H");
			tree.Insert("G");
			tree.Insert("F");
			tree.Insert("E");
			tree.Insert("D");
			tree.Insert("C");
			tree.Insert("B");

			{
				ostringstream stream;
				tree.PreOrderPrint(stream);
				actual = stream.str();
				expected = "E C A B D G F H ";

				Assert::AreEqual(expected, actual, L"Preorder failed", LINE_INFO());
			}
			{
				ostringstream stream;
				tree.InOrderPrint(stream);
				actual = stream.str();
				expected = "A B C D E F G H ";
				Assert::AreEqual(expected, actual, L"Inorder failed", LINE_INFO());
			}
			{
				ostringstream stream;
				tree.PostOrderPrint(stream);
				actual = stream.str();
				expected = "B A D C F H G E ";
				Assert::AreEqual(expected, actual, L"Postorder failed", LINE_INFO());
			}
			
			Assert::AreEqual(8, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Insert failed", LINE_INFO());
		}

		////////////////////////////////////////////////////////////////////////////////////////////////////////
		// Insert Big Tree
		////////////////////////////////////////////////////////////////////////////////////////////////////////
		TEST_METHOD(InsertBigTree)
		{
			BinaryTree<string> tree(true);
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

			{
				ostringstream stream;
				tree.PreOrderPrint(stream);
				actual = stream.str();
				expected = "O H D B A C F E G K I J M L N V R Q P T S U X W Z Y ";

				Assert::AreEqual(expected, actual, L"Preorder failed", LINE_INFO());
			}
			{
				ostringstream stream;
				tree.InOrderPrint(stream);
				actual = stream.str();
				expected = "A B C D E F G H I J K L M N O P Q R S T U V W X Y Z ";
				Assert::AreEqual(expected, actual, L"Inorder failed", LINE_INFO());
			}
			{
				ostringstream stream;
				tree.PostOrderPrint(stream);
				actual = stream.str();
				expected = "A C B E G F D J I L N M K H P Q S U T R W Y Z X V O ";
				Assert::AreEqual(expected, actual, L"Postorder failed", LINE_INFO());
			}
			
			Assert::AreEqual(26, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Insert failed", LINE_INFO());
		}

		////////////////////////////////////////////////////////////////////////////////////////////////////////
		// AVL Testing Root Rebalancing
		////////////////////////////////////////////////////////////////////////////////////////////////////////
		TEST_METHOD(RootLeftLeft)
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

			Assert::AreEqual(3, BinaryTreeNode<string>::GetNbrNodes(), L"RootLeftLeft Insert failed", LINE_INFO());
		}
		TEST_METHOD(RootRightRight)
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

			Assert::AreEqual(3, BinaryTreeNode<string>::GetNbrNodes(), L"RootRightRight Insert failed", LINE_INFO());
		}

		TEST_METHOD(RootRightLeft)
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

			Assert::AreEqual(3, BinaryTreeNode<string>::GetNbrNodes(), L"RootRightLeft Insert failed", LINE_INFO());
		}

		TEST_METHOD(RootLeftRight)
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

			Assert::AreEqual(3, BinaryTreeNode<string>::GetNbrNodes(), L"RootLeftRight Insert failed", LINE_INFO());
		}
		TEST_METHOD(NonrootRightRight)
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

			Assert::AreEqual(5, BinaryTreeNode<string>::GetNbrNodes(), L"NonrootRightRight Insert failed", LINE_INFO());
		}
		TEST_METHOD(NonrootLeftLeft)
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

			Assert::AreEqual(5, BinaryTreeNode<string>::GetNbrNodes(), L"NonrootLeftLeft Insert failed", LINE_INFO());
		}

		TEST_METHOD(NonrootRightleft)
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

			Assert::AreEqual(5, BinaryTreeNode<string>::GetNbrNodes(), L"NonrootRightleft Insert failed", LINE_INFO());
		}
		TEST_METHOD(NonrootLeftRight)
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

			Assert::AreEqual(5, BinaryTreeNode<string>::GetNbrNodes(), L"NonrootLeftRight Insert failed", LINE_INFO());
		}
		////////////////////////////////////////////////////////////////////////////////////////////////////////
		// AVL Testing Root Rebalancing from Descendent
		////////////////////////////////////////////////////////////////////////////////////////////////////////
		TEST_METHOD(RootRightRightDescendent)
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

			Assert::AreEqual(6, BinaryTreeNode<string>::GetNbrNodes(), L"RootRightRightDescendent Insert failed", LINE_INFO());
		}
		TEST_METHOD(RootLeftLeftDescendent)
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

			Assert::AreEqual(6, BinaryTreeNode<string>::GetNbrNodes(), L"RootLeftLeftDescendent Insert failed", LINE_INFO());
		}
		TEST_METHOD(RootLeftRightDescendent)
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

			Assert::AreEqual(6, BinaryTreeNode<string>::GetNbrNodes(), L"RootLeftLeftDescendent Insert failed", LINE_INFO());
		}

		TEST_METHOD(RootRightLeftDescendent)
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

			Assert::AreEqual(6, BinaryTreeNode<string>::GetNbrNodes(), L"RootLeftLeftDescendent Insert failed", LINE_INFO());
		}
	};
}