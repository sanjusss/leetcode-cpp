#include "pch.h"
#include "CppUnitTest.h"
#include "../LCP/LCP4.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLCP
{
    TEST_CLASS(UnitTestLCP4)
    {
    public:
        
        TEST_METHOD(TestMethod1)
        {
            check(2, 3,
                "[[1, 0], [1, 1]]",
                2);
        }

        TEST_METHOD(TestMethod2)
        {
            check(2, 3,
                "[]",
                3);
        }

        TEST_METHOD(TestMethod3)
        {
            check(3, 3,
                "[]",
                4);
        }

        TEST_METHOD(TestMethod4)
        {
            check(4, 4,
                "[[1, 1], [2, 2]]",
                6);
        }

        TEST_METHOD(TestMethod5)
        {
            check(4, 4,
                "[]",
                8);
        }

    private:
        void check(int n, int m, string brokenSrc, int expected)
        {
            auto broken = toInt2DArray(brokenSrc);
            Solution sln;
            auto actual = sln.domino(n, m, broken);
            Assert::AreEqual(expected, actual);
        }
    };
}
