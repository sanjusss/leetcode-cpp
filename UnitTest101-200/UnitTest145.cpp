#include "pch.h"
#include "CppUnitTest.h"
#include "../101-200/0145.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest101200
{
    TEST_CLASS(UnitTest145)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            check("[1,null,2,3] ", "[3,2,1]");
        }

        void check(string rootSrc, string expectedSrc)
        {
            auto root = toTreeNode(rootSrc);
            auto expected = toIntArray(expectedSrc);
            Solution sln;
            auto actual = sln.postorderTraversal(root);
            Assert::AreEqual(expected, actual);
            freeTreeNode(root);
        }
    };
}
