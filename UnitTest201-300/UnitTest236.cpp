#include "pch.h"
#include "CppUnitTest.h"
#include "../201-300/0236.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest201300
{
    TEST_CLASS(UnitTest236)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            check("[6,2,8,0,4,7,9,null,null,3,5]",
                2,
                8,
                6);
        }

        TEST_METHOD(TestMethod2)
        {
            check("[6,2,8,0,4,7,9,null,null,3,5]",
                2,
                4,
                2);
        }

        TEST_METHOD(TestMethod3)
        {
            check("[3,5,1,6,2,0,8,null,null,7,4]",
                5,
                1,
                3);
        }

        TEST_METHOD(TestMethod4)
        {
            check("[3,5,1,6,2,0,8,null,null,7,4]",
                5,
                4,
                5);
        }

    private:
        void check(string rootSrc, int p, int q, int expected)
        {
            auto root = toTreeNode(rootSrc);
            _0236::Solution sln;
            auto actual = sln.lowestCommonAncestor(root, new TreeNode(p), new TreeNode(q));
            Assert::AreEqual(expected, actual->val);
        }
    };
}
