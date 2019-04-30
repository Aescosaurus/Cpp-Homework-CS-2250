#include "stdafx.h"
#include "CppUnitTest.h"
#include "BinaryTree.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace BinaryTreeTests
{
	TEST_CLASS(TreeRemovalTests)
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
		TEST_METHOD(RemoveFromEmpty)
		{
			BinaryTree<string> tree;
			Assert::AreEqual(false, tree.Remove("A"), L"tree.Remove from empty failed", LINE_INFO());
			Assert::AreEqual(0, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
		}

		TEST_METHOD(RemoveDeleted)
		{
			BinaryTree<string> tree;
			tree.Insert("A");
			tree.Insert("B");
			tree.Insert("C");
			tree.Insert("D");
			tree.Insert("E");

			{
				ostringstream stream;
				tree.PreOrderPrint(stream);
				actual = stream.str();
				expected = "A B C D E ";
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
				expected = "E D C B A ";
				Assert::AreEqual(expected, actual, L"Postorder failed", LINE_INFO());
			}

			Assert::AreEqual(5, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Insert failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("A"), L"tree.Remove root failed", LINE_INFO());
			Assert::AreEqual(false, tree.Remove("A"), L"tree.Remove already deleted failed", LINE_INFO());
			Assert::AreEqual(4, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("B"), L"tree.Remove root failed", LINE_INFO());
			Assert::AreEqual(false, tree.Remove("B"), L"tree.Remove already deleted failed", LINE_INFO());
			Assert::AreEqual(3, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("C"), L"tree.Remove root failed", LINE_INFO());
			Assert::AreEqual(false, tree.Remove("C"), L"tree.Remove already deleted failed", LINE_INFO());
			Assert::AreEqual(2, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("D"), L"tree.Remove root failed", LINE_INFO());
			Assert::AreEqual(false, tree.Remove("D"), L"tree.Remove already deleted failed", LINE_INFO());
			Assert::AreEqual(1, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("E"), L"tree.Remove root failed", LINE_INFO());
			Assert::AreEqual(false, tree.Remove("E"), L"tree.Remove already deleted failed", LINE_INFO());
			Assert::AreEqual(0, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
		}

		////////////////////////////////////////////////////////////////////////////////////////////////////////
		// Root Tests
		////////////////////////////////////////////////////////////////////////////////////////////////////////
		TEST_METHOD(RemoveRootNoChildren)
		{
			BinaryTree<string> tree;
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
			Assert::AreEqual(true, tree.Remove("A"), L"tree.Remove root failed", LINE_INFO());
			Assert::AreEqual(0, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
		}

		TEST_METHOD(RemoveRootLeftChild)
		{
			BinaryTree<string> tree;
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
			Assert::AreEqual(true, tree.Remove("A"), L"tree.Remove root's left child failed", LINE_INFO());
			Assert::AreEqual(1, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("B"), L"tree.Remove root failed", LINE_INFO());
			Assert::AreEqual(0, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
		}

		TEST_METHOD(RemoveRootRightChild)
		{
			BinaryTree<string> tree;
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
			Assert::AreEqual(true, tree.Remove("B"), L"tree.Remove root's right child failed", LINE_INFO());
			Assert::AreEqual(1, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("A"), L"tree.Remove root failed", LINE_INFO());
			Assert::AreEqual(0, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
		}

		////////////////////////////////////////////////////////////////////////////////////////////////////////
		// Child Tests
		////////////////////////////////////////////////////////////////////////////////////////////////////////
		TEST_METHOD(RemoveLeftLeftChild)
		{
			BinaryTree<string> tree;
			tree.Insert("C");
			tree.Insert("B");
			tree.Insert("A");

			{
				ostringstream stream;
				tree.PreOrderPrint(stream);
				actual = stream.str();
				expected = "C B A ";
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
				expected = "A B C ";
				Assert::AreEqual(expected, actual, L"Postorder failed", LINE_INFO());
			}

			Assert::AreEqual(3, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Insert failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("C"), L"tree.Remove left left child failed", LINE_INFO());
			Assert::AreEqual(2, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("B"), L"tree.Remove left child failed", LINE_INFO());
			Assert::AreEqual(1, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("A"), L"tree.Remove root failed", LINE_INFO());
			Assert::AreEqual(0, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
		}

		TEST_METHOD(RemoveLeftRightChild)
		{
			BinaryTree<string> tree;
			tree.Insert("C");
			tree.Insert("A");
			tree.Insert("B");

			{
				ostringstream stream;
				tree.PreOrderPrint(stream);
				actual = stream.str();
				expected = "C A B ";
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
				expected = "B A C ";
				Assert::AreEqual(expected, actual, L"Postorder failed", LINE_INFO());
			}

			Assert::AreEqual(3, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Insert failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("B"), L"tree.Remove left right child failed", LINE_INFO());
			Assert::AreEqual(2, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("A"), L"tree.Remove left child failed", LINE_INFO());
			Assert::AreEqual(1, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("C"), L"tree.Remove root failed", LINE_INFO());
			Assert::AreEqual(0, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
		}

		TEST_METHOD(RemoveRightLeftChild)
		{
			BinaryTree<string> tree;
			tree.Insert("A");
			tree.Insert("C");
			tree.Insert("B");

			{
				ostringstream stream;
				tree.PreOrderPrint(stream);
				actual = stream.str();
				expected = "A C B ";
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
				expected = "B C A ";
				Assert::AreEqual(expected, actual, L"Postorder failed", LINE_INFO());
			}

			Assert::AreEqual(3, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Insert failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("B"), L"tree.Remove right left child failed", LINE_INFO());
			Assert::AreEqual(2, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("C"), L"tree.Remove left child failed", LINE_INFO());
			Assert::AreEqual(1, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("A"), L"tree.Remove root failed", LINE_INFO());
			Assert::AreEqual(0, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
		}

		TEST_METHOD(RemoveRightRightChild)
		{
			BinaryTree<string> tree;
			tree.Insert("A");
			tree.Insert("B");
			tree.Insert("C");

			{
				ostringstream stream;
				tree.PreOrderPrint(stream);
				actual = stream.str();
				expected = "A B C ";
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
				expected = "C B A ";
				Assert::AreEqual(expected, actual, L"Postorder failed", LINE_INFO());
			}

			Assert::AreEqual(3, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Insert failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("C"), L"tree.Remove right left child failed", LINE_INFO());
			Assert::AreEqual(2, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("B"), L"tree.Remove left child failed", LINE_INFO());
			Assert::AreEqual(1, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("A"), L"tree.Remove root failed", LINE_INFO());
			Assert::AreEqual(0, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
		}

		////////////////////////////////////////////////////////////////////////////////////////////////////////
		// Two Child Tests
		////////////////////////////////////////////////////////////////////////////////////////////////////////
		TEST_METHOD(RemoveRootWithTwoChildren)
		{
			BinaryTree<string> tree;
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
			Assert::AreEqual(true, tree.Remove("B"), L"tree.Remove root with 2 children failed", LINE_INFO());
			Assert::AreEqual(2, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("C"), L"tree.Remove root failed", LINE_INFO());
			Assert::AreEqual(1, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("A"), L"tree.Remove root failed", LINE_INFO());
			Assert::AreEqual(0, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
		}

		TEST_METHOD(RemoveLeftChildWithTwoChildren)
		{
			BinaryTree<string> tree;
			tree.Insert("D");
			tree.Insert("B");
			tree.Insert("A");
			tree.Insert("C");

			{
				ostringstream stream;
				tree.PreOrderPrint(stream);
				actual = stream.str();
				expected = "D B A C ";
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
				expected = "A C B D ";
				Assert::AreEqual(expected, actual, L"Postorder failed", LINE_INFO());
			}

			Assert::AreEqual(4, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Insert failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("B"), L"tree.Remove left child with 2 children failed", LINE_INFO());
			Assert::AreEqual(3, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("C"), L"tree.Remove left child failed", LINE_INFO());
			Assert::AreEqual(2, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("A"), L"tree.Remove left child failed", LINE_INFO());
			Assert::AreEqual(1, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("D"), L"tree.Remove root failed", LINE_INFO());
			Assert::AreEqual(0, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
		}

		TEST_METHOD(RemoveRightChildWithTwoChildren)
		{
			BinaryTree<string> tree;
			tree.Insert("A");
			tree.Insert("C");
			tree.Insert("B");
			tree.Insert("D");

			{
				ostringstream stream;
				tree.PreOrderPrint(stream);
				actual = stream.str();
				expected = "A C B D ";
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
				expected = "B D C A ";
				Assert::AreEqual(expected, actual, L"Postorder failed", LINE_INFO());
			}

			Assert::AreEqual(4, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Insert failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("C"), L"tree.Remove right child with 2 children failed", LINE_INFO());
			Assert::AreEqual(3, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("D"), L"tree.Remove right child failed", LINE_INFO());
			Assert::AreEqual(2, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("B"), L"tree.Remove right child failed", LINE_INFO());
			Assert::AreEqual(1, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("A"), L"tree.Remove root failed", LINE_INFO());
			Assert::AreEqual(0, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
		}

		////////////////////////////////////////////////////////////////////////////////////////////////////////
		// Root Grand Child Tests
		////////////////////////////////////////////////////////////////////////////////////////////////////////
		TEST_METHOD(RemoveRootWithRightInnerGrandChild)
		{
			BinaryTree<string> tree;
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
			Assert::AreEqual(true, tree.Remove("B"), L"tree.Remove root with right inner child failed", LINE_INFO());
			Assert::AreEqual(3, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("C"), L"tree.Remove root with two children failed", LINE_INFO());
			Assert::AreEqual(2, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("D"), L"tree.Remove root with left child failed", LINE_INFO());
			Assert::AreEqual(1, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("A"), L"tree.Remove root failed", LINE_INFO());
			Assert::AreEqual(0, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
		}

		TEST_METHOD(RemoveRootWithLeftInnerGrandChild)
		{
			BinaryTree<string> tree;
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
			Assert::AreEqual(true, tree.Remove("C"), L"tree.Remove root with right inner child failed", LINE_INFO());
			Assert::AreEqual(3, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("D"), L"tree.Remove root with left inner child", LINE_INFO());
			Assert::AreEqual(2, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("A"), L"tree.Remove root with right child failed", LINE_INFO());
			Assert::AreEqual(1, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("B"), L"tree.Remove root failed", LINE_INFO());
			Assert::AreEqual(0, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
		}

		TEST_METHOD(RemoveRootWithRightOuterGrandChild)
		{
			BinaryTree<string> tree;
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
			Assert::AreEqual(true, tree.Remove("B"), L"tree.Remove root with right outer child failed", LINE_INFO());
			Assert::AreEqual(3, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("C"), L"tree.Remove root with two children", LINE_INFO());
			Assert::AreEqual(2, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("D"), L"tree.Remove root with left child failed", LINE_INFO());
			Assert::AreEqual(1, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("A"), L"tree.Remove root failed", LINE_INFO());
			Assert::AreEqual(0, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
		}

		TEST_METHOD(RemoveRootWithLeftOuterGrandChild)
		{
			BinaryTree<string> tree;
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
			Assert::AreEqual(true, tree.Remove("C"), L"tree.Remove root with left outer child failed", LINE_INFO());
			Assert::AreEqual(3, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("D"), L"tree.Remove root with left left child", LINE_INFO());
			Assert::AreEqual(2, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("B"), L"tree.Remove root with left child failed", LINE_INFO());
			Assert::AreEqual(1, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("A"), L"tree.Remove root failed", LINE_INFO());
			Assert::AreEqual(0, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
		}

		////////////////////////////////////////////////////////////////////////////////////////////////////////
		// Nonroot Grand Child Tests
		////////////////////////////////////////////////////////////////////////////////////////////////////////
		TEST_METHOD(RemoveLeftChildWithInnerChild)
		{
			BinaryTree<string> tree;
			tree.Insert("E");
			tree.Insert("B");
			tree.Insert("A");
			tree.Insert("D");
			tree.Insert("C");

			{
				ostringstream stream;
				tree.PreOrderPrint(stream);
				actual = stream.str();
				expected = "E B A D C ";

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
				expected = "A C D B E ";
				Assert::AreEqual(expected, actual, L"Postorder failed", LINE_INFO());
			}

			Assert::AreEqual(5, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Insert failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("B"), L"tree.Remove left child with inner child failed", LINE_INFO());
			Assert::AreEqual(4, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("C"), L"tree.Remove left child with two children failed", LINE_INFO());
			Assert::AreEqual(3, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("D"), L"tree.Remove left child with left child failed", LINE_INFO());
			Assert::AreEqual(2, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("A"), L"tree.Remove left child failed", LINE_INFO());
			Assert::AreEqual(1, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("E"), L"tree.Remove root failed", LINE_INFO());
			Assert::AreEqual(0, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
		}

		TEST_METHOD(RemoveRightChildWithInnerChild)
		{
			BinaryTree<string> tree;
			tree.Insert("A");
			tree.Insert("C");
			tree.Insert("B");
			tree.Insert("E");
			tree.Insert("D");

			{
				ostringstream stream;
				tree.PreOrderPrint(stream);
				actual = stream.str();
				expected = "A C B E D ";
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
				expected = "B D E C A ";
				Assert::AreEqual(expected, actual, L"Postorder failed", LINE_INFO());
			}

			Assert::AreEqual(5, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Insert failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("C"), L"tree.Remove right child with inner child failed", LINE_INFO());
			Assert::AreEqual(4, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("D"), L"tree.Remove right child with two children failed", LINE_INFO());
			Assert::AreEqual(3, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("E"), L"tree.Remove right child with right child failed", LINE_INFO());
			Assert::AreEqual(2, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("B"), L"tree.Remove right child failed", LINE_INFO());
			Assert::AreEqual(1, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("A"), L"tree.Remove root failed", LINE_INFO());
			Assert::AreEqual(0, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
		}

		TEST_METHOD(RemoveLeftChildWithOuterChild)
		{
			BinaryTree<string> tree;
			tree.Insert("E");
			tree.Insert("B");
			tree.Insert("A");
			tree.Insert("C");
			tree.Insert("D");

			{
				ostringstream stream;
				tree.PreOrderPrint(stream);
				actual = stream.str();
				expected = "E B A C D ";
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
				expected = "A D C B E ";
				Assert::AreEqual(expected, actual, L"Postorder failed", LINE_INFO());
			}

			Assert::AreEqual(5, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Insert failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("B"), L"tree.Remove right child with outer child failed", LINE_INFO());
			Assert::AreEqual(4, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("C"), L"tree.Remove right child with two children failed", LINE_INFO());
			Assert::AreEqual(3, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("D"), L"tree.Remove right child with left child failed", LINE_INFO());
			Assert::AreEqual(2, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("A"), L"tree.Remove right child failed", LINE_INFO());
			Assert::AreEqual(1, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("E"), L"tree.Remove root failed", LINE_INFO());
			Assert::AreEqual(0, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
		}

		TEST_METHOD(RemoveRightChildWithOuterChild)
		{
			BinaryTree<string> tree;
			tree.Insert("A");
			tree.Insert("C");
			tree.Insert("B");
			tree.Insert("D");
			tree.Insert("E");
			Assert::AreEqual(5, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Insert failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("C"), L"tree.Remove right child with outer child failed", LINE_INFO());
			Assert::AreEqual(4, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("D"), L"tree.Remove right child with two children failed", LINE_INFO());
			Assert::AreEqual(3, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("E"), L"tree.Remove right child with left child failed", LINE_INFO());
			Assert::AreEqual(2, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("B"), L"tree.Remove right child failed", LINE_INFO());
			Assert::AreEqual(1, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("A"), L"tree.Remove root failed", LINE_INFO());
			Assert::AreEqual(0, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
		}

		////////////////////////////////////////////////////////////////////////////////////////////////////////
		// Root Great Grand Child Tests
		////////////////////////////////////////////////////////////////////////////////////////////////////////
		TEST_METHOD(RemoveRootWithRightLeftLeftChild)
		{
			BinaryTree<string> tree;
			tree.Insert("B");
			tree.Insert("A");
			tree.Insert("E");
			tree.Insert("D");
			tree.Insert("C");
			Assert::AreEqual(5, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Insert failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("B"), L"tree.Remove root with right left left child failed", LINE_INFO());
			Assert::AreEqual(4, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("C"), L"tree.Remove root with right left child failed", LINE_INFO());
			Assert::AreEqual(3, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("D"), L"tree.Remove root with right child failed", LINE_INFO());
			Assert::AreEqual(2, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("E"), L"tree.Remove root with left child failed", LINE_INFO());
			Assert::AreEqual(1, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("A"), L"tree.Remove root failed", LINE_INFO());
			Assert::AreEqual(0, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
		}

		TEST_METHOD(RemoveRootWithRightLeftRightChild)
		{
			BinaryTree<string> tree;
			tree.Insert("B");
			tree.Insert("A");
			tree.Insert("E");
			tree.Insert("C");
			tree.Insert("D");
			Assert::AreEqual(5, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Insert failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("B"), L"tree.Remove root with right left right child failed", LINE_INFO());
			Assert::AreEqual(4, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("C"), L"tree.Remove root with right left child failed", LINE_INFO());
			Assert::AreEqual(3, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("D"), L"tree.Remove root with right child failed", LINE_INFO());
			Assert::AreEqual(2, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("E"), L"tree.Remove root with left child failed", LINE_INFO());
			Assert::AreEqual(1, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("A"), L"tree.Remove root failed", LINE_INFO());
			Assert::AreEqual(0, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
		}

		////////////////////////////////////////////////////////////////////////////////////////////////////////
		// Nonroot Great Grand Child Tests
		////////////////////////////////////////////////////////////////////////////////////////////////////////
		TEST_METHOD(RemoveRootLeftWithRightLeftLeftChild)
		{
			BinaryTree<string> tree;
			tree.Insert("F");
			tree.Insert("B");
			tree.Insert("A");
			tree.Insert("E");
			tree.Insert("D");
			tree.Insert("C");
			Assert::AreEqual(6, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Insert failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("B"), L"tree.Remove nonroot with right left left child failed", LINE_INFO());
			Assert::AreEqual(5, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("C"), L"tree.Remove nonroot with right left child failed", LINE_INFO());
			Assert::AreEqual(4, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("D"), L"tree.Remove nonroot with two children failed", LINE_INFO());
			Assert::AreEqual(3, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("E"), L"tree.Remove nonroot with left child failed", LINE_INFO());
			Assert::AreEqual(2, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("A"), L"tree.Remove root's left child failed", LINE_INFO());
			Assert::AreEqual(1, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("F"), L"tree.Remove root failed", LINE_INFO());
			Assert::AreEqual(0, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
		}

		TEST_METHOD(RemoveRootRightWithRightLeftLeftChild)
		{
			BinaryTree<string> tree;
			tree.Insert("A");
			tree.Insert("C");
			tree.Insert("B");
			tree.Insert("F");
			tree.Insert("E");
			tree.Insert("D");
			Assert::AreEqual(6, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Insert failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("C"), L"tree.Remove nonroot with right left left child failed", LINE_INFO());
			Assert::AreEqual(5, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("D"), L"tree.Remove nonroot with right left child failed", LINE_INFO());
			Assert::AreEqual(4, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("E"), L"tree.Remove nonroot with two children failed", LINE_INFO());
			Assert::AreEqual(3, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("F"), L"tree.Remove nonroot with left child failed", LINE_INFO());
			Assert::AreEqual(2, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("B"), L"tree.Remove root's left child failed", LINE_INFO());
			Assert::AreEqual(1, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("A"), L"tree.Remove root failed", LINE_INFO());
			Assert::AreEqual(0, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
		}

		TEST_METHOD(RemoveRootLeftWithRightLeftRightChild)
		{
			BinaryTree<string> tree;
			tree.Insert("F");
			tree.Insert("B");
			tree.Insert("A");
			tree.Insert("E");
			tree.Insert("C");
			tree.Insert("D");
			Assert::AreEqual(6, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Insert failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("B"), L"tree.Remove nonroot with right left right child failed", LINE_INFO());
			Assert::AreEqual(5, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("C"), L"tree.Remove nonroot with right left child failed", LINE_INFO());
			Assert::AreEqual(4, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("D"), L"tree.Remove nonroot with two children failed", LINE_INFO());
			Assert::AreEqual(3, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("E"), L"tree.Remove nonroot with left child failed", LINE_INFO());
			Assert::AreEqual(2, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("A"), L"tree.Remove root's left child failed", LINE_INFO());
			Assert::AreEqual(1, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("F"), L"tree.Remove root failed", LINE_INFO());
			Assert::AreEqual(0, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
		}

		TEST_METHOD(RemoveRootRightWithRightLeftRightChild)
		{
			BinaryTree<string> tree;
			tree.Insert("A");
			tree.Insert("C");
			tree.Insert("B");
			tree.Insert("F");
			tree.Insert("D");
			tree.Insert("E");
			Assert::AreEqual(6, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Insert failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("C"), L"tree.Remove nonroot with right left right child failed", LINE_INFO());
			Assert::AreEqual(5, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("D"), L"tree.Remove nonroot with right left child failed", LINE_INFO());
			Assert::AreEqual(4, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("E"), L"tree.Remove nonroot with two children failed", LINE_INFO());
			Assert::AreEqual(3, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("F"), L"tree.Remove nonroot with left child failed", LINE_INFO());
			Assert::AreEqual(2, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("B"), L"tree.Remove root's left child failed", LINE_INFO());
			Assert::AreEqual(1, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("A"), L"tree.Remove root failed", LINE_INFO());
			Assert::AreEqual(0, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
		}

		////////////////////////////////////////////////////////////////////////////////////////////////////////
		// Remove Min Chain
		////////////////////////////////////////////////////////////////////////////////////////////////////////
		TEST_METHOD(RemoveRootMinChain)
		{
			BinaryTree<string> tree;
			tree.Insert("A");
			tree.Insert("H");
			tree.Insert("G");
			tree.Insert("F");
			tree.Insert("E");
			tree.Insert("D");
			tree.Insert("C");
			tree.Insert("B");
			Assert::AreEqual(8, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Insert failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("A"), L"tree.Remove root with min chain", LINE_INFO());
			Assert::AreEqual(7, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("B"), L"tree.Remove root with min chain failed", LINE_INFO());
			Assert::AreEqual(6, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("C"), L"tree.Remove root with min chain failed", LINE_INFO());
			Assert::AreEqual(5, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("D"), L"tree.Remove root with min chain failed", LINE_INFO());
			Assert::AreEqual(4, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("E"), L"tree.Remove root with min chain failed", LINE_INFO());
			Assert::AreEqual(3, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("F"), L"tree.Remove root with min chain failed", LINE_INFO());
			Assert::AreEqual(2, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("G"), L"tree.Remove root with min chain failed", LINE_INFO());
			Assert::AreEqual(1, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("H"), L"tree.Remove root failed", LINE_INFO());
			Assert::AreEqual(0, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
		}

		////////////////////////////////////////////////////////////////////////////////////////////////////////
		// Remove Big Tree
		////////////////////////////////////////////////////////////////////////////////////////////////////////
		TEST_METHOD(RemoveBigTree)
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
			Assert::AreEqual(26, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Insert failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("A"), L"tree.Remove Big Tree", LINE_INFO());
			Assert::AreEqual(25, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("B"), L"tree.Remove Big Tree", LINE_INFO());
			Assert::AreEqual(24, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("C"), L"tree.Remove Big Tree", LINE_INFO());
			Assert::AreEqual(23, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("D"), L"tree.Remove Big Tree", LINE_INFO());
			Assert::AreEqual(22, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("E"), L"tree.Remove Big Tree", LINE_INFO());
			Assert::AreEqual(21, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("F"), L"tree.Remove Big Tree", LINE_INFO());
			Assert::AreEqual(20, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("G"), L"tree.Remove Big Tree", LINE_INFO());
			Assert::AreEqual(19, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("H"), L"tree.Remove Big Tree", LINE_INFO());
			Assert::AreEqual(18, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("I"), L"tree.Remove Big Tree", LINE_INFO());
			Assert::AreEqual(17, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("J"), L"tree.Remove Big Tree", LINE_INFO());
			Assert::AreEqual(16, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("K"), L"tree.Remove Big Tree", LINE_INFO());
			Assert::AreEqual(15, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("L"), L"tree.Remove Big Tree", LINE_INFO());
			Assert::AreEqual(14, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("M"), L"tree.Remove Big Tree", LINE_INFO());
			Assert::AreEqual(13, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("N"), L"tree.Remove Big Tree", LINE_INFO());
			Assert::AreEqual(12, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("O"), L"tree.Remove Big Tree", LINE_INFO());
			Assert::AreEqual(11, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("P"), L"tree.Remove Big Tree", LINE_INFO());
			Assert::AreEqual(10, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("Q"), L"tree.Remove Big Tree", LINE_INFO());
			Assert::AreEqual(9, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("R"), L"tree.Remove Big Tree", LINE_INFO());
			Assert::AreEqual(8, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("S"), L"tree.Remove Big Tree", LINE_INFO());
			Assert::AreEqual(7, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("T"), L"tree.Remove Big Tree", LINE_INFO());
			Assert::AreEqual(6, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("U"), L"tree.Remove Big Tree", LINE_INFO());
			Assert::AreEqual(5, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("V"), L"tree.Remove Big Tree", LINE_INFO());
			Assert::AreEqual(4, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("W"), L"tree.Remove Big Tree", LINE_INFO());
			Assert::AreEqual(3, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("X"), L"tree.Remove Big Tree", LINE_INFO());
			Assert::AreEqual(2, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("Y"), L"tree.Remove Big Tree", LINE_INFO());
			Assert::AreEqual(1, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("Z"), L"tree.Remove Big Tree", LINE_INFO());
			Assert::AreEqual(0, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
		}
	};
}