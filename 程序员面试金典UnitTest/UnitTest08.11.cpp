#include "pch.h"
#include "CppUnitTest.h"
#include "unittest.h"
#include "../程序员面试金典/08.11.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace 程序员面试金典UnitTest08
{
    TEST_CLASS(程序员面试金典UnitTest08_11)
    {
    public:
        TEST_METHOD(TestMethod1)
        {
            check(5,
                2);
        }

        TEST_METHOD(TestMethod2)
        {
            check(10,
                4);
        }

        void check(int n, int expected)
        {
            Solution sln;
            auto actual = sln.waysToChange(n);
            Assert::AreEqual(expected, actual);
        }
    };
}
