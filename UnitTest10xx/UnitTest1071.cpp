#include "pch.h"
#include "CppUnitTest.h"
#include "unittest.h"
#include "../10xx/1071.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest10xx
{
    TEST_CLASS(UnitTest1071)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            check("ABCABC", "ABC", "ABC");
        }

        TEST_METHOD(TestMethod2)
        {
            check("ABABAB", "ABAB", "AB");
        }

        TEST_METHOD(TestMethod3)
        {
            check("LEET", "CODE", "");
        }

        void check(string str1, string str2, string expected)
        {
            Solution sln;
            auto actual = sln.gcdOfStrings(str1, str2);
            Assert::AreEqual(expected, actual);
        }
    };
}
