#include "pch.h"
#include "CppUnitTest.h"
#include "../C1XX/5319.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestC1xx
{
    TEST_CLASS(UnitTest5319)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            check("ababa", 1);
        }

        TEST_METHOD(TestMethod2)
        {
            check("abb", 2);
        }

        TEST_METHOD(TestMethod3)
        {
            check("baabb", 2);
        }


        TEST_METHOD(TestMethod4)
        {
            check("", 0);
        }


        TEST_METHOD(TestMethod5)
        {
            check("ababb", 2);
        }

        void check(string s, int expected)
        {
            Solution sln;
            auto actual = sln.removePalindromeSub(s);
            Assert::AreEqual(expected, actual);
        }
    };
}