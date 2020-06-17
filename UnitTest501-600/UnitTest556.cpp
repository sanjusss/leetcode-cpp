#include "pch.h"
#include "CppUnitTest.h"
#include "../501-600/0556.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest501600
{
    TEST_CLASS(UnitTest556)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            check(12,
                21);
        }

        TEST_METHOD(TestMethod2)
        {
            check(21,
                -1);
        }

        TEST_METHOD(TestMethod3)
        {
            check(230241,
                230412);
        }

        TEST_METHOD(TestMethod4)
        {
            check(12222333,
                12223233);
        }

        void check(int n, int expected)
        {
            Solution sln;
            auto actual = sln.nextGreaterElement(n);
            Assert::AreEqual(expected, actual);
        }
    };
}
