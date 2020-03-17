#include "pch.h"
#include "CppUnitTest.h"
#include "../1-100/0041.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1100
{
    TEST_CLASS(UnitTest41)
    {
    public:
        TEST_METHOD(TestMethod1)
        {
            check("[1,2,0]",
                3);
        }

        TEST_METHOD(TestMethod2)
        {
            check("[3,4,-1,1]",
                2);
        }

        TEST_METHOD(TestMethod3)
        {
            check("[7,8,9,11,12]",
                1);
        }

        TEST_METHOD(TestMethod4)
        {
            check("[]",
                1);
        }

        TEST_METHOD(TestMethod5)
        {
            check("[1]",
                2);
        }

        TEST_METHOD(TestMethod6)
        {
            check("[1,1]",
                2);
        }

    private:
        void check(string numsSrc, int expected)
        {
            auto nums = toIntArray(numsSrc);
            Solution sln;
            auto actual = sln.firstMissingPositive(nums);
            Assert::AreEqual(expected, actual);
        }
    };
}
