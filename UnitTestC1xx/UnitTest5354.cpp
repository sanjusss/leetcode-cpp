#include "pch.h"
#include "CppUnitTest.h"
#include "../C1XX/5354.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestC1xx
{
    TEST_CLASS(UnitTest5354)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            check(1,
                0,
                "[-1]",
                "[0]",
                0);
        }

        TEST_METHOD(TestMethod2)
        {
            check(6,
                2,
                "[2,2,-1,2,2,2]",
                "[0,0,1,0,0,0]",
                1);
        }

        TEST_METHOD(TestMethod3)
        {
            check(7,
                6,
                "[1,2,3,4,5,6,-1]",
                "[0,6,5,4,3,2,1]",
                21);
        }

        TEST_METHOD(TestMethod4)
        {
            check(15,
                0,
                "[-1,0,0,1,1,2,2,3,3,4,4,5,5,6,6]",
                "[1,1,1,1,1,1,1,0,0,0,0,0,0,0,0]",
                3);
        }

        TEST_METHOD(TestMethod5)
        {
            check(4,
                2,
                "[3,3,-1,2]",
                "[0,0,162,914]",
                1076);
        }

        void check(int n, int headID, string managerSrc, string informTimeSrc, int expected)
        {
            auto manager = toIntArray(managerSrc);
            auto informTime = toIntArray(informTimeSrc);
            Solution sln;
            auto actual = sln.numOfMinutes(n, headID, manager, informTime);
            Assert::AreEqual(expected, actual);
        }
    };
}