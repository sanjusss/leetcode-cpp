#include "pch.h"
#include "CppUnitTest.h"
#include "../201-300/0230.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest201300
{
    TEST_CLASS(UnitTest230)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            check("[3,1,4,null,2]",
                1,
                1);
        }

        TEST_METHOD(TestMethod2)
        {
            check("[5,3,6,2,4,null,null,1]",
                3,
                3);
        }

    private:
        void check(string rootSrc, int k, int expected)
        {
            auto root = toTreeNode(rootSrc);
            Solution sln;
            auto actual = sln.kthSmallest(root, k);
            Assert::AreEqual(expected, actual);
            freeTreeNode(root);
        }
    };
}
