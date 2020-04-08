#include "pch.h"
#include "CppUnitTest.h"
#include "unittest.h"
#include "../½£Ö¸Offer/13.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest½£Ö¸Offer
{
    TEST_CLASS(UnitTest½£Ö¸Offer13)
    {
    public:
        TEST_METHOD(TestMethod1)
        {
            check(2, 3, 1, 3);
        }

        TEST_METHOD(TestMethod2)
        {
            check(3, 1, 0, 1);
        }

        TEST_METHOD(TestMethod3)
        {
            check(11, 8, 16, 88);
        }

        void check(int m, int n, int k, int expected)
        {
            Solution sln;
            auto actual = sln.movingCount(m, n, k);
            Assert::AreEqual(expected, actual);
        }
    };
}
