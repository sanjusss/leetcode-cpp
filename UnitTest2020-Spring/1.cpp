#include "pch.h"
#include "CppUnitTest.h"
#include "../2020-spring/1.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest2020Spring
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            check("[4,2,1]",
                4);
        }

        TEST_METHOD(TestMethod2)
        {
            check("[2,3,10]",
                8);
        }

        void check(string coinsSrc, int expected)
        {
            auto coins = toIntArray(coinsSrc);
            Solution sln;
            auto actual = sln.minCount(coins);
            Assert::AreEqual(expected, actual);
        }
    };
}