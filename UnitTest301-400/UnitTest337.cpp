#include "pch.h"
#include "CppUnitTest.h"
#include "../301-400/0337.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest301400
{
    TEST_CLASS(UnitTest0337)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            check("[3,2,3,null,3,null,1]",
                7);
        }

        TEST_METHOD(TestMethod2)
        {
            check("[3,4,5,1,3,null,1]",
                9);
        }

        TEST_METHOD(TestMethod3)
        {
            check("[2,1,3,null,4]",
                7);
        }

        void check(string rootSrc, int expected)
        {
            auto root = toTreeNode(rootSrc);
            Solution sln;
            auto actual = sln.rob(root);
            Assert::AreEqual(expected, actual);
            freeTreeNode(root);
        }
    };
}