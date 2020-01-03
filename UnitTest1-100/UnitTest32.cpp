#include "pch.h"
#include "CppUnitTest.h"
#include "../1-100/0032.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1100
{
    TEST_CLASS(UnitTest0032)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            check("(()", 2);
        }

        TEST_METHOD(TestMethod2)
        {
            check(")()())", 4);
        }

        TEST_METHOD(TestMethod3)
        {
            check("()(()", 2);
        }

        void check(string s, int expected)
        {
            Solution sln;
            auto actual = sln.longestValidParentheses(s);
            Assert::AreEqual(expected, actual);
        }
    };
}