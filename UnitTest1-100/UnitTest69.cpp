#include "pch.h"
#include "CppUnitTest.h"
#include "../1-100/0069.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1100
{
    TEST_CLASS(UnitTest69)
    {
    public:
        TEST_METHOD(TestMethod1)
        {
            check(4, 2);
        }

        TEST_METHOD(TestMethod2)
        {
            check(8, 2);
        }

        TEST_METHOD(TestMethod3)
        {
            check(0, 0);
        }

        TEST_METHOD(TestMethod4)
        {
            check(1, 1);
        }

        TEST_METHOD(TestMethod5)
        {
            check(6, 2);
        }

    private:
        void check(int x, int expected)
        {
            Solution sln;
            auto actual = sln.mySqrt(x);
            Assert::AreEqual(expected, actual);
        }
    };
}
