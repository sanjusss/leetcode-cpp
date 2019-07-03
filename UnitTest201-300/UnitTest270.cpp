#include "pch.h"
#include "CppUnitTest.h"
#include "../201-300/0270.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest201300
{
    TEST_CLASS(UnitTest270)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            check("[1]",
                4.428571,
                1);
        }

        TEST_METHOD(TestMethod2)
        {
            check("[4,2,5,1,3]",
                3.714286,
                4);
        }

        TEST_METHOD(TestMethod3)
        {
            check("[4,2,5,1,3]",
                2.51,
                3);
        }

        TEST_METHOD(TestMethod4)
        {
            check("[0]",
                2147483648.0,
                0);
        }

    private:
        void check(string rootSrc, double target, int expected)
        {
            auto root = toTreeNode(rootSrc);

            Solution sln;
            auto actual = sln.closestValue(root, target);
            Assert::AreEqual(expected, actual);
        }
    };
}
