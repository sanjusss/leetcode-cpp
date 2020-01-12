#include "pch.h"
#include "CppUnitTest.h"
#include "../C1XX/5308.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestC1xx
{
    TEST_CLASS(UnitTest5308)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            check(2, 6, 5, 3);
        }

        TEST_METHOD(TestMethod2)
        {
            check(4, 2, 7, 1);
        }

        TEST_METHOD(TestMethod3)
        {
            check(1, 2, 3, 0);
        }

        void check(int a, int b, int c, int expected)
        {
            Solution sln;
            auto actual = sln.minFlips(a, b, c);
            Assert::AreEqual(expected, actual);
        }
    };
}