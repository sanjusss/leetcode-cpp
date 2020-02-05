#include "pch.h"
#include "CppUnitTest.h"
#include "../201-300/0235.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest201300
{
    TEST_CLASS(UnitTest235)
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

    private:
        void check(string rootSrc, int p, int q, int expected)
        {
            auto root = toTreeNode(rootSrc);
            Solution sln;
            auto actual = sln.lowestCommonAncestor(root, new TreeNode(p), new TreeNode(q));
            Assert::AreEqual(expected, actual->val);
        }
    };
}
