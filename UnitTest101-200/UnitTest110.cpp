#include "pch.h"
#include "CppUnitTest.h"
#include "../101-200/0110.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest101200
{
    TEST_CLASS(UnitTest110)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            check("[3,9,20,null,null,15,7]",
                true);
        }

        TEST_METHOD(TestMethod2)
        {
            check("[1,2,2,3,3,null,null,4,4]",
                false);
        }

        TEST_METHOD(TestMethod3)
        {
            check("[1,2,2,3,null,null,3,4,null,null,4]",
                false);
        }

        void check(string rootSrc, bool expected)
        {
            auto root = toTreeNode(rootSrc);
            Solution sln;
            auto actual = sln.isBalanced(root);
            Assert::AreEqual(expected, actual);
        }
    };
}
