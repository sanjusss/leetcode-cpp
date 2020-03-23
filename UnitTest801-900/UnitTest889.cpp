#include "pch.h"
#include "CppUnitTest.h"
#include "../801-900/0889.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest801900
{
    TEST_CLASS(UnitTest889)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            check("[1,2,4,5,3,6,7]", "[4,5,2,6,7,3,1]", "[1,2,3,4,5,6,7]");
        }

        void check(string preorderSrc, string postorderSrc, string expectedSrc)
        {
            auto preorder = toIntArray(preorderSrc);
            auto postorder = toIntArray(postorderSrc);
            auto expected = toTreeNode(expectedSrc);
            Solution sln;
            auto actual = sln.constructFromPrePost(preorder, postorder);
            Assert::AreEqual(*expected, *actual);
            freeTreeNode(expected);
            freeTreeNode(actual);
        }
    };
}
