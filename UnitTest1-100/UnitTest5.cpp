#include "pch.h"
#include "CppUnitTest.h"
#include "../1-100/0005.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1100
{
    TEST_CLASS(UnitTest0003)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            check("ccc", "ccc");
        }

        TEST_METHOD(TestMethod2)
        {
            check("dddd", "dddd");
        }


        void check(string s, string expected)
        {
            Solution sln;
            auto actual = sln.longestPalindrome(s);
            Assert::AreEqual(expected, actual);
        }
    };
}