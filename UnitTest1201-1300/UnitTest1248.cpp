#include "pch.h"
#include "CppUnitTest.h"
#include "../1201-1300/1248.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest12011300
{
    TEST_CLASS(UnitTest1248)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            check("[1,1,2,1,1]",
                3,
                2);
        }

        TEST_METHOD(TestMethod2)
        {
            check("[2,4,6]",
                1,
                0);
        }

        TEST_METHOD(TestMethod3)
        {
            check("[2,2,2,1,2,2,1,2,2,2]",
                2,
                16);
        }

    private:
        void check(string numsSrc, int k, int expected)
        {
            auto nums = toIntArray(numsSrc);
            Solution sln;
            auto actual = sln.numberOfSubarrays(nums, k);
            Assert::AreEqual(expected, actual);
        }
    };
}
