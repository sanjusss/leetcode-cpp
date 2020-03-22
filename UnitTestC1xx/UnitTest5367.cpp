#include "pch.h"
#include "CppUnitTest.h"
#include "../C1XX/5367.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestC181
{
    TEST_CLASS(UnitTest5367)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            check("level",
                "l");
        }

        TEST_METHOD(TestMethod2)
        {
            check("ababab",
                "abab");
        }

        TEST_METHOD(TestMethod3)
        {
            check("leetcodeleet",
                "leet");
        }

        TEST_METHOD(TestMethod4)
        {
            check("a",
                "");
        }

        void check(string s, string expected)
        {
            Solution sln;
            auto actual = sln.longestPrefix(s);
            Assert::AreEqual(expected, actual);
        }
    };
}