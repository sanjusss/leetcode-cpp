#include "pch.h"
#include "CppUnitTest.h"
#include "../201-300/0300.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest201300
{
    TEST_CLASS(UnitTest300)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            check("[10,9,2,5,3,7,101,18]",
                4);
        }

        TEST_METHOD(TestMethod2)
        {
            check("[0]",
                1);
        }

        TEST_METHOD(TestMethod3)
        {
            check("[10,9,2,5,3,7,101,18]",
                4);
        }

    private:
        void check(string numsSrc, int expected)
        {
            auto nums = toIntArray(numsSrc);
            Solution sln;
            auto actual = sln.lengthOfLIS(nums);
            Assert::AreEqual(expected, actual);
        }
    };
}
