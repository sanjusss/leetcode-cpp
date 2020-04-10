#include "pch.h"
#include "CppUnitTest.h"
#include "../101-200/0151.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest101200
{
    TEST_CLASS(UnitTest151)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            check("the sky is blue", "blue is sky the");
        }

        TEST_METHOD(TestMethod2)
        {
            check("  hello world!  ", "world! hello");
        }

        TEST_METHOD(TestMethod3)
        {
            check("a good   example", "example good a");
        }

        TEST_METHOD(TestMethod4)
        {
            check(" ", "");
        }

        TEST_METHOD(TestMethod5)
        {
            check("1 ", "1");
        }

        void check(string s, string expected)
        {
            Solution sln;
            auto actual = sln.reverseWords(s);
            Assert::AreEqual(expected, actual);
        }
    };
}
