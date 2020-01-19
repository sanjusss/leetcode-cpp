#include "pch.h"
#include "CppUnitTest.h"
#include "../C1XX/5318.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestC1xx
{
    TEST_CLASS(UnitTest5318)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            check(5, "[3,4,1,1,0,0]", 1);
        }

        TEST_METHOD(TestMethod2)
        {
            check(3, "[0,0,0,0]", -1);
        }

        TEST_METHOD(TestMethod3)
        {
            check(7, "[1,2,1,0,2,1,0,1]", 3);
        }

        TEST_METHOD(TestMethod4)
        {
            check(8, "[4,0,0,0,0,0,0,0,4]", 2);
        }

        TEST_METHOD(TestMethod5)
        {
            check(8, "[4,0,0,0,4,0,0,0,4]", 1);
        }

        TEST_METHOD(TestMethod6)
        {
            check(35, "[1,0,4,0,4,1,4,3,1,1,1,2,1,4,0,3,0,3,0,3,0,5,3,0,0,1,2,1,2,4,3,0,1,0,5,2]", 6);
        }

        TEST_METHOD(TestMethod7)
        {
            check(8, "[0,5,0,3,3,3,1,4,0,4]", 2);
        }


        void check(int n, string rangesSrc, int expected)
        {
            auto ranges = toIntArray(rangesSrc);
            Solution sln;
            auto actual = sln.minTaps(n, ranges);
            Assert::AreEqual(expected, actual);
        }
    };
}