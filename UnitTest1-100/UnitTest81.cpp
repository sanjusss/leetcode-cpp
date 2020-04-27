#include "pch.h"
#include "CppUnitTest.h"
#include "../1-100/0081.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1100
{
    TEST_CLASS(UnitTest81)
    {
    public:
        TEST_METHOD(TestMethod1)
        {
            check("[2,5,6,0,0,1,2]",
                0,
                true);
        }

        TEST_METHOD(TestMethod2)
        {
            check("[2,5,6,0,0,1,2]",
                3,
                false);
        }

        TEST_METHOD(TestMethod3)
        {
            check("[3,1,1]",
                3,
                true);
        }

        TEST_METHOD(TestMethod4)
        {
            check("[1,1,3,1]",
                3,
                true);
        }

    private:
        void check(string numsSrc, int target, bool expected)
        {
            auto nums = toIntArray(numsSrc);
            Solution sln;
            auto actual = sln.search(nums, target);
            Assert::AreEqual(expected, actual);
        }
    };
}
