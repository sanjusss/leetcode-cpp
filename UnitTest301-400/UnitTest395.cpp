#include "pch.h"
#include "CppUnitTest.h"
#include "../301-400/0395.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestC1xx
{
    TEST_CLASS(UnitTest0395)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            check("aaabb",
                3,
                3);
        }

        TEST_METHOD(TestMethod2)
        {
            check("ababbc",
                2,
                5);
        }

        TEST_METHOD(TestMethod3)
        {
            check("bbaaacbd",
                3,
                3);
        }

        void check(string s, int k, int expected)
        {
            Solution sln;
            auto actual = sln.longestSubstring(s, k);
            Assert::AreEqual(expected, actual);
        }
    };
}