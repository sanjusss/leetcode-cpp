#include "pch.h"
#include "CppUnitTest.h"
#include "../C1XX/5307.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestC1xx
{
    TEST_CLASS(UnitTest5307)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            check(2, "[1,1]");
        }

        TEST_METHOD(TestMethod2)
        {
            check(11, "[2,9]");
        }

        TEST_METHOD(TestMethod3)
        {
            check(10000, "[1,9999]");
        }

        TEST_METHOD(TestMethod4)
        {
            check(69, "[1,68]");
        }

        TEST_METHOD(TestMethod5)
        {
            check(1010, "[11,999]");
        }

        void check(int n, string expectedSrc)
        {
            auto expected = toIntArray(expectedSrc);
            Solution sln;
            auto actual = sln.getNoZeroIntegers(n);
            Assert::AreEqual(expected, actual);
        }
    };
}