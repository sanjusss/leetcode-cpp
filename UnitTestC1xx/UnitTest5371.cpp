#include "pch.h"
#include "CppUnitTest.h"
#include "../C1XX/5371.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestC182
{
    TEST_CLASS(UnitTest5371)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            check(2,
                "aa",
                "da",
                "b",
                51);
        }

        TEST_METHOD(TestMethod2)
        {
            check(8,
                "leetcode",
                "leetgoes",
                "leet",
                0);
        }

        TEST_METHOD(TestMethod3)
        {
            check(2,
                "gx",
                "gz",
                "x",
                2);
        }

        void check(int n, string s1, string s2, string evil, int expected)
        {
            Solution sln;
            auto actual = sln.findGoodStrings(n, s1, s2, evil);
            Assert::AreEqual(expected, actual);
        }
    };
}