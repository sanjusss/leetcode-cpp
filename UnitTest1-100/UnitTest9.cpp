#include "pch.h"
#include "CppUnitTest.h"
#include "../1-100/0009.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1100
{
    TEST_CLASS(UnitTest0009)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            check(121,
                true);
        }

        TEST_METHOD(TestMethod2)
        {
            check(-121,
                false);
        }

        TEST_METHOD(TestMethod3)
        {
            check(10,
                false);
        }

        TEST_METHOD(TestMethod4)
        {
            check(0,
                true);
        }


        void check(int x, bool expected)
        {
            Solution sln;
            auto actual = sln.isPalindrome(x);
            Assert::AreEqual(expected, actual);
        }
    };
}