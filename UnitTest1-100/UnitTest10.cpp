#include "pch.h"
#include "CppUnitTest.h"
#include "../1-100/0010.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1100
{
    TEST_CLASS(UnitTest0010)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            check("aa", "a", false);
        }

        TEST_METHOD(TestMethod2)
        {
            check("aa", "a*", true);
        }

        TEST_METHOD(TestMethod3)
        {
            check("ab", ".*", true);
        }

        TEST_METHOD(TestMethod4)
        {
            check("aab", "c*a*b", true);
        }

        TEST_METHOD(TestMethod5)
        {
            check("mississippi", "mis*is*p*.", false);
        }

        void check(string s, string p, bool expected)
        {
            Solution sln;
            auto actual = sln.isMatch(s, p);
            Assert::AreEqual(expected, actual);
        }
    };
}