#include "pch.h"
#include "CppUnitTest.h"
#include "../1-100/0034.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1100
{
    TEST_CLASS(UnitTest34)
    {
    public:
        TEST_METHOD(TestMethod1)
        {
            check("[5,7,7,8,8,10]",
                8,
                "[3,4]");
        }

        TEST_METHOD(TestMethod2)
        {
            check("[5,7,7,8,8,10]",
                6,
                "[-1,-1]");
        }

        TEST_METHOD(TestMethod3)
        {
            check("[]",
                6,
                "[-1,-1]");
        }

        TEST_METHOD(TestMethod4)
        {
            check("[3,3,3]",
                3,
                "[0,2]");
        }

        TEST_METHOD(TestMethod5)
        {
            check("[1,2,3]",
                1,
                "[0,0]");
        }

    private:
        void check(string numsSrc, int target, string expectedSrc)
        {
            auto nums = toIntArray(numsSrc);
            auto expected = toIntArray(expectedSrc);

            Solution sln;
            auto actual = sln.searchRange(nums, target);
            Assert::AreEqual(expected, actual);
        }
    };
}