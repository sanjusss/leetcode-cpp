#include "pch.h"
#include "CppUnitTest.h"
#include "../101-200/0103.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest101200
{
    TEST_CLASS(UnitTest103)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            check("[3,9,20,null,null,15,7]", "[[3],[20, 9],[15, 7]]");
        }

        TEST_METHOD(TestMethod2)
        {
            check("[1,2,3,4,null,null,5]", "[[1],[3,2],[4,5]]");
        }

        void check(string rootSrc, string expectedSrc)
        {
            auto root = toTreeNode(rootSrc);
            auto expected = toInt2DArray(expectedSrc);
            Solution sln;
            auto actual = sln.zigzagLevelOrder(root);
            Assert::AreEqual(expected, actual);
            freeTreeNode(root);
        }
    };
}
