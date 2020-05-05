#include "pch.h"
#include "CppUnitTest.h"
#include "../1-100/0098.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1100
{
    TEST_CLASS(UnitTest98)
    {
    public:
        TEST_METHOD(TestMethod1)
        {
            check("[2,1,3]",
                true);
        }

        TEST_METHOD(TestMethod2)
        {
            check("[10,5,15,null,null,6,20]",
                false);
        }

        TEST_METHOD(TestMethod3)
        {
            check("[5,1,4,null,null,3,6]",
                false);
        }

    private:
        void check(string rootSrc, bool expected)
        {
            auto root = toTreeNode(rootSrc);
            Solution sln;
            auto actual = sln.isValidBST(root);
            Assert::AreEqual(expected, actual);
        }
    };
}
