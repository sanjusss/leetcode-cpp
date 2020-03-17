#include "pch.h"
#include "CppUnitTest.h"
#include "../201-300/0215.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest201300
{
    TEST_CLASS(UnitTest215)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            check("[3,2,1,5,6,4]",
                2, 5);
        }

        TEST_METHOD(TestMethod2)
        {
            check("[3,2,3,1,2,4,5,5,6]",
                4, 4);
        }

        TEST_METHOD(TestMethod3)
        {
            check("[-1,2,0]",
                1, 2);
        }

        TEST_METHOD(TestMethod4)
        {
            check("[-1,2,0,2]",
                2, 2);
        }

        TEST_METHOD(TestMethod5)
        {
            check("[3,3,3,3,4,3,3,3,3]",
                5, 3);
        }

        TEST_METHOD(TestMethod6)
        {
            check("[2,1]",
                1, 2);
        }

    private:
        void check(string numsSrc, int k, int expected)
        {
            auto nums = toIntArray(numsSrc);
            Solution sln;
            auto actual = sln.findKthLargest(nums, k);
            Assert::AreEqual(expected, actual);
        }
    };
}
