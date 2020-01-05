#include "pch.h"
#include "CppUnitTest.h"
#include "../1101-1200/1143.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest11011200
{
    TEST_CLASS(UnitTest1143)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            check("abcde", "ace", 3);
        }

        TEST_METHOD(TestMethod2)
        {
            check("abc", "abc", 3);
        }

        TEST_METHOD(TestMethod3)
        {
            check("abc", "def", 0);
        }

        void check(string text1, string text2, int expected)
        {
            Solution sln;
            auto actual = sln.longestCommonSubsequence(text1, text2);
            Assert::AreEqual(expected, actual);
        }
    };
}