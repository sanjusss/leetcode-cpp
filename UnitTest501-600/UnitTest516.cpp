#include "pch.h"
#include "CppUnitTest.h"
#include "../501-600/0516.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest101200
{
    TEST_CLASS(UnitTest516)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            check("bbbab", 4);
        }

        TEST_METHOD(TestMethod2)
        {
            check("cbbd", 2);
        }

        void check(string s, int expected)
        {
            Solution sln;
            auto actual = sln.longestPalindromeSubseq(s);
            Assert::AreEqual(expected, actual);
        }
    };
}
