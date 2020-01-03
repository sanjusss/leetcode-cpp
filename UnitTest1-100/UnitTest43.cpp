#include "pch.h"
#include "CppUnitTest.h"
#include "../1-100/0043.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1100
{
    TEST_CLASS(UnitTest0043)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            check("2", "3", "6");
        }

        TEST_METHOD(TestMethod2)
        {
            check("9936", "0", "0");
        }

        TEST_METHOD(TestMethod3)
        {
            check("123", "456", "56088");
        }

        TEST_METHOD(TestMethod4)
        {
            check("9", "9", "81");
        }

        TEST_METHOD(TestMethod5)
        {
            check("9", "99", "891");
        }

        void check(string num1, string num2, string expected)
        {
            Solution sln;
            auto actual = sln.multiply(num1, num2);
            Assert::AreEqual(expected, actual);
        }
    };
}