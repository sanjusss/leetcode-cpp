#include "pch.h"
#include "CppUnitTest.h"
#include "../C1XX/5402.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestC187
{
    TEST_CLASS(UnitTest5402)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            check("[8,2,4,7]",
                4,
                2);
        }

        TEST_METHOD(TestMethod2)
        {
            check("[4,2,2,2,4,4,2,2]",
                0,
                3);
        }

        TEST_METHOD(TestMethod3)
        {
            check("[10,1,2,4,7,2]",
                5,
                4);
        }

        void check(string numsSrc, int limit, int expected)
        {
            auto nums = toIntArray(numsSrc);
            Solution sln;
            auto actual = sln.longestSubarray(nums, limit);
            Assert::AreEqual(expected, actual);
        }
    };
}