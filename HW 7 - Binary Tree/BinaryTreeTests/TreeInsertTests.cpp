#include "stdafx.h"
#include "CppUnitTest.h"
#include "BinaryTree.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace BinaryTreeTests
{
	TEST_CLASS(TreeInsertTests)
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
		// Test the Insert methods on a binary tree
		////////////////////////////////////////////////////////////////////////////////////////////////////////
		TEST_METHOD(EmptyTree)
		{
			BinaryTree<string> tree;
			Assert::AreEqual(0, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after instantiating tree failed", LINE_INFO());
		}

		TEST_METHOD(InsertRoot)
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
		}

		TEST_METHOD(InsertSingleChildLeft)
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
		}

		TEST_METHOD(InsertSingleChildRight)
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
		}

		TEST_METHOD(InsertGrandchildLeftLeft)
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
		}

		TEST_METHOD(InsertGranchildLeftRight)
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
		}

		TEST_METHOD(InsertGrandchildRightLeft)
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
		}

		TEST_METHOD(InsertGrandchildRightRight)
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
		}

		TEST_METHOD(InsertTwoChildren)
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
		}

		TEST_METHOD(InsertTwoGrandchildrenLeft)
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
		}

		TEST_METHOD(InsertTwoGrandchildrenRight)
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
		}

		////////////////////////////////////////////////////////////////////////////////////////////////////////
		// Root Grand Child Tests
		////////////////////////////////////////////////////////////////////////////////////////////////////////
		TEST_METHOD(InsertTwoChildrenOneGrandchildRightLeft)
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
		}

		TEST_METHOD(InsertTwoChildrenOneGrandchildLeftRight)
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
		}

		TEST_METHOD(InsertTwoChildrenOneGrandchildRightRight)
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
		}

		TEST_METHOD(InsertTwoChildrenOneGrandchildLeftLeft)
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
		}

		// RRR
		TEST_METHOD(InsertFiveRightRightRight)
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
		}

		// LRL
		TEST_METHOD(InsertFiveLeftRightLeft)
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
		}



		// RRL
		TEST_METHOD(InsertFiveRightRightLeft)
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
		}

		// LRR
		TEST_METHOD(InsertFiveLeftRightRight)
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
		}
		// RLR
		// A
		//    D
		//  B   E
		//   C
		TEST_METHOD(InsertFiveRightLeftRight)
		{
			BinaryTree<string> tree;
			tree.Insert("A");
			tree.Insert("D");
			tree.Insert("B");
			tree.Insert("C");
			tree.Insert("E");

			{
				ostringstream stream;
				tree.PreOrderPrint(stream);
				actual = stream.str();
				expected = "A D B C E ";
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
				expected = "C B E D A ";
				Assert::AreEqual(expected, actual, L"Postorder failed", LINE_INFO());
			}

			Assert::AreEqual(5, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Insert failed", LINE_INFO());
		}		
		
		// RLL
		// A
		//     D
		//   C   E
		// B
		TEST_METHOD(InsertFiveRightLeftLeft)
		{
			BinaryTree<string> tree;
			tree.Insert("A");
			tree.Insert("D");
			tree.Insert("C");
			tree.Insert("B");
			tree.Insert("E");

			{
				ostringstream stream;
				tree.PreOrderPrint(stream);
				actual = stream.str();
				expected = "A D C B E ";
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
				expected = "B C E D A ";
				Assert::AreEqual(expected, actual, L"Postorder failed", LINE_INFO());
			}

			Assert::AreEqual(5, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Insert failed", LINE_INFO());
		}	
		
		// LLR
		//       E
		//    C
		//  A   D
		//   B
		TEST_METHOD(InsertFiveLeftLeftRight)
		{
			BinaryTree<string> tree;
			tree.Insert("E");
			tree.Insert("C");
			tree.Insert("A");
			tree.Insert("B");
			tree.Insert("D");

			{
				ostringstream stream;
				tree.PreOrderPrint(stream);
				actual = stream.str();
				expected = "E C A B D ";
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
				expected = "B A D C E ";
				Assert::AreEqual(expected, actual, L"Postorder failed", LINE_INFO());
			}

			Assert::AreEqual(5, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Insert failed", LINE_INFO());
		}
		// LLL
		//       E
		//    C
		//  B   D
		// A  	
		TEST_METHOD(InsertFiveLeftLeftLeft)
		{
			BinaryTree<string> tree;
			tree.Insert("E");
			tree.Insert("C");
			tree.Insert("B");
			tree.Insert("A");
			tree.Insert("D");

			{
				ostringstream stream;
				tree.PreOrderPrint(stream);
				actual = stream.str();
				expected = "E C B A D ";
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
				expected = "A B D C E ";
				Assert::AreEqual(expected, actual, L"Postorder failed", LINE_INFO());
			}

			Assert::AreEqual(5, BinaryTreeNode<string>::GetNbrNodes(), L"GetNbrNodes after Insert failed", LINE_INFO());
		}
	};
}