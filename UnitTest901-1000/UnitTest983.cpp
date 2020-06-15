#include "pch.h"
#include "CppUnitTest.h"
#include "../901-1000/0983.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest9011000
{
    TEST_CLASS(UnitTest983)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            check("[1,4,6,7,8,20]", 
                "[2,7,15]",
                11);
        }

        TEST_METHOD(TestMethod2)
        {
            check("[1,2,3,4,5,6,7,8,9,10,30,31]",
                "[2,7,15]",
                17);
        }

        void check(string daysSrc, string costsSrc, int expected)
        {
            auto days = toIntArray(daysSrc);
            auto costs = toIntArray(costsSrc);
            Solution sln;
            auto actual = sln.mincostTickets(days, costs);
            Assert::AreEqual(expected, actual);
        }
    };
}
