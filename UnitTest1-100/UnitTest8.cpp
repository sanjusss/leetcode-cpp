#include "pch.h"
#include "CppUnitTest.h"
#include "../1-100/0008.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1100
{
    TEST_CLASS(UnitTest0008)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            check("42", 
                42);
        }

        TEST_METHOD(TestMethod2)
        {
            check("   -42",
                -42);
        }

        TEST_METHOD(TestMethod3)
        {
            check("4193 with words",
                4193);
        }

        TEST_METHOD(TestMethod4)
        {
            check("words and 987",
                0);
        }

        TEST_METHOD(TestMethod5)
        {
            check("-91283472332",
                INT_MIN);
        }

        TEST_METHOD(TestMethod6)
        {
            check("20000000000000000000",
                INT_MAX);
        }


        void check(string str, int expected)
        {
            Solution sln;
            auto actual = sln.myAtoi(str);
            Assert::AreEqual(expected, actual);
        }
    };
}