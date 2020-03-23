#include "pch.h"
#include "CppUnitTest.h"
#include "../501-600/0518.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest501600
{
    TEST_CLASS(UnitTest518)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            check(5,
                "[5, 2, 1]",
                4);
        }

        TEST_METHOD(TestMethod2)
        {
            check(2, "[3]", 0);
        }

        TEST_METHOD(TestMethod3)
        {
            check(10, "[10]", 1);
        }

        void check(int amount, string coinsSrc, int expected)
        {
            auto coins = toIntArray(coinsSrc);
            Solution sln;
            auto actual = sln.change(amount, coins);
            Assert::AreEqual(expected, actual);
        }
    };
}
