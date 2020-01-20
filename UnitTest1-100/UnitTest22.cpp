#include "pch.h"
#include "CppUnitTest.h"
#include "../1-100/0022.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1100
{
    TEST_CLASS(UnitTest0022)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            check(3, "[\"((()))\",\"(()())\",\"(())()\",\"()(())\",\"()()()\"]");
        }

        TEST_METHOD(TestMethod2)
        {
            check(4, "[\"(((())))\",\"((()()))\",\"((())())\",\"((()))()\",\"(()(()))\",\"(()()())\",\"(()())()\",\"(())(())\",\"(())()()\",\"()((()))\",\"()(()())\",\"()(())()\",\"()()(())\",\"()()()()\"]");
        }

        TEST_METHOD(TestMethod3)
        {
            check(0, "[\"\"]");
        }

        void check(int n, string expectedSrc)
        {
            auto expected = toStringArray(expectedSrc);
            sort(expected.begin(), expected.end());
            Solution sln;
            auto actual = sln.generateParenthesis(n);
            sort(actual.begin(), actual.end());
            Assert::AreEqual(expected, actual);
        }
    };
}