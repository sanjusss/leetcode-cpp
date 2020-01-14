#include "pch.h"
#include "CppUnitTest.h"
#include "../101-200/0105.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest101200
{
    TEST_CLASS(UnitTest105)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            check("[3,9,20,15,7]", "[9,3,15,20,7]", "[3, 9, 20, null, null, 15, 7]");
        }

        void check(string preorderSrc, string inorderSrc, string expectedSrc)
        {
            auto preorder = toIntArray(preorderSrc);
            auto inorder = toIntArray(inorderSrc);
            auto expected = toTreeNode(expectedSrc);
            Solution sln;
            auto actual = sln.buildTree(preorder, inorder);
            Assert::AreEqual(*expected, *actual);
            freeTreeNode(expected);
            freeTreeNode(actual);
        }
    };
}
