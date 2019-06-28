#include "pch.h"
#include "CppUnitTest.h"
#include "../1-100/0003.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1100
{
    TEST_CLASS(UnitTest3)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            check("hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789",
            55);
        }

        TEST_METHOD(TestMethod2)
        {
            check("abcabcbb", 3);
        }

        TEST_METHOD(TestMethod3)
        {
            check("bbbbb", 1);
        }

        TEST_METHOD(TestMethod4)
        {
            check("pwwkew", 3);
        }

    private:
        void check(string s, int expected)
        {
            Solution sln;
            auto actual = sln.lengthOfLongestSubstring(s);
            Assert::AreEqual(expected, actual);
        }
    };
}
