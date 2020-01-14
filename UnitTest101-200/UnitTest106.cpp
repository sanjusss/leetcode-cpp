#include "pch.h"
#include "CppUnitTest.h"
#include "../101-200/0106.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest101200
{
    TEST_CLASS(UnitTest106)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            check("[9,3,15,20,7]", "[9,15,7,20,3]", "[3,9,20,null,null,15,7]");
        }

        void check(string inorderSrc, string postorderSrc, string expectedSrc)
        {
            auto inorder = toIntArray(inorderSrc);
            auto postorder = toIntArray(postorderSrc);
            auto expected = toTreeNode(expectedSrc);
            Code0106::Solution sln;
            auto actual = sln.buildTree(inorder, postorder);
            Assert::AreEqual(*expected, *actual);
            freeTreeNode(expected);
            freeTreeNode(actual);
        }
    };
}
