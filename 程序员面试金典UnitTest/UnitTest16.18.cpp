#include "pch.h"
#include "CppUnitTest.h"
#include "unittest.h"
#include "../程序员面试金典/16.18.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace 程序员面试金典UnitTest16
{
    TEST_CLASS(程序员面试金典UnitTest16_18)
    {
    public:
        TEST_METHOD(TestMethod1)
        {
            check("abba",
                "dogcatcatdog",
                true);
        }

        TEST_METHOD(TestMethod2)
        {
            check("abba",
                "dogcatcatfish",
                false);
        }
        TEST_METHOD(TestMethod3)
        {
            check("aaaa",
                "dogcatcatdog",
                false);
        }
        TEST_METHOD(TestMethod4)
        {
            check("abba",
                "dogdogdogdog",
                true);
        }

        TEST_METHOD(TestMethod5)
        {
            check("a",
                "",
                true);
        }

        void check(string pattern, string value, bool expected)
        {
            Solution sln;
            auto actual = sln.patternMatching(pattern, value);
            Assert::AreEqual(expected, actual);
        }
    };
}
