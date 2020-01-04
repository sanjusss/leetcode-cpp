#include "pch.h"
#include "CppUnitTest.h"
#include "../301-400/0322.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest301400
{
    TEST_CLASS(UnitTest0322)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            check("[1, 2, 5]",
                11,
                3);
        }

        TEST_METHOD(TestMethod2)
        {
            check("[2]",
                3,
                -1);
        }

        void check(string coinsSrc, int amount, int expected)
        {
            vector<int> coins = toIntArray(coinsSrc);
            Solution sln;
            auto actual = sln.coinChange(coins, amount);
            Assert::AreEqual(expected, actual);
        }
    };
}