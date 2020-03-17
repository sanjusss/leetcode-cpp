#include "pch.h"
#include "CppUnitTest.h"
#include "../1-100/0076.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1100
{
    TEST_CLASS(UnitTest76)
    {
    public:
        TEST_METHOD(TestMethod1)
        {
            check("ADOBECODEBANC",
                "ABC",
                "BANC");
        }

        TEST_METHOD(TestMethod2)
        {
            check("a",
                "a",
                "a");
        }

        TEST_METHOD(TestMethod3)
        {
            check("a",
                "aa",
                "");
        }

        TEST_METHOD(TestMethod4)
        {
            check("bdab",
                "ab",
                "ab");
        }

    private:
        void check(string s, string t, string expected)
        {
            Solution sln;
            auto actual = sln.minWindow(s, t);
            Assert::AreEqual(expected, actual);
        }
    };
}
