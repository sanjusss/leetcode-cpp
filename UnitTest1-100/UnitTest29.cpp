#include "pch.h"
#include "CppUnitTest.h"
#include "../1-100/0029.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1100
{
    TEST_CLASS(UnitTest0029)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            check(10, 3, 3);
        }

        TEST_METHOD(TestMethod2)
        {
            check(7, -3, -2);
        }

        TEST_METHOD(TestMethod3)
        {
            check(INT_MIN, 2, -1073741824);
        }

        void check(int dividend, int divisor, int expected)
        {
            Solution sln;
            auto actual = sln.divide(dividend, divisor);
            Assert::AreEqual(expected, actual);
        }
    };
}