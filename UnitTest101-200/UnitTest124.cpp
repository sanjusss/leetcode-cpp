#include "pch.h"
#include "CppUnitTest.h"
#include "../101-200/0124.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestC1xx
{
    TEST_CLASS(UnitTest0124)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            check("[1,2,3]",
                6);
        }

        TEST_METHOD(TestMethod2)
        {
            check("[-10,9,20,null,null,15,7]",
                42);
        }

        TEST_METHOD(TestMethod3)
        {
            check("[1,-2,-3,1,3,-2,null,-1]",
                3);
        }

        TEST_METHOD(TestMethod4)
        {
            check("[5,4,8,11,null,13,4,7,2,null,null,null,1]",
                48);
        }

        void check(string rootSrc, int expected)
        {
            TreeNode* root = toTreeNode(rootSrc);
            Solution sln;
            auto actual = sln.maxPathSum(root);
            Assert::AreEqual(expected, actual);
            freeTreeNode(root);
        }
    };
}