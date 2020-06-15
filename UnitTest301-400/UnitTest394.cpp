#include "pch.h"
#include "CppUnitTest.h"
#include "../301-400/0394.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest301400
{
    TEST_CLASS(UnitTest394)
    {
    public:
        
        TEST_METHOD(TestMethod1)
        {
            string s = "3[a]2[bc]";
            string expected = "aaabcbc";

            Solution sln;
            auto actual = sln.decodeString(s);
            Assert::AreEqual(expected, actual);
        }

        TEST_METHOD(TestMethod2)
        {
            string s = "aaa";
            string expected = "aaa";

            Solution sln;
            auto actual = sln.decodeString(s);
            Assert::AreEqual(expected, actual);
        }

        TEST_METHOD(TestMethod3)
        {
            string s = "3[a2[c]]";
            string expected = "accaccacc";

            Solution sln;
            auto actual = sln.decodeString(s);
            Assert::AreEqual(expected, actual);
        }
    };
}
