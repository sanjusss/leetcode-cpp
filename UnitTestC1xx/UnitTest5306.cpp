#include "pch.h"
#include "CppUnitTest.h"
#include "../C1XX/5306.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestC1xx
{
    TEST_CLASS(UnitTest5306)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            check("zzazz", 0);
        }

        TEST_METHOD(TestMethod2)
        {
            check("mbadm", 2);
        }

        TEST_METHOD(TestMethod3)
        {
            check("leetcode", 5);
        }

        TEST_METHOD(TestMethod4)
        {
            check("g", 0);
        }

        TEST_METHOD(TestMethod5)
        {
            check("no", 1);
        }

        void check(string s, int expected)
        {
            Solution sln;
            auto actual = sln.minInsertions(s);
            Assert::AreEqual(expected, actual);
        }
    };
}