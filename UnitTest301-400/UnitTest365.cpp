#include "pch.h"
#include "CppUnitTest.h"
#include "../301-400/0365.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest301400
{
    TEST_CLASS(UnitTest0365)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            check(3, 5, 4,
                true);
        }

        TEST_METHOD(TestMethod2)
        {
            check(2, 6, 5,
                false);
        }

        TEST_METHOD(TestMethod3)
        {
            check(1, 2, 3,
                true);
        }

        void check(int x, int y, int z, bool expected)
        {
            Solution sln;
            auto actual = sln.canMeasureWater(x, y, z);
            Assert::AreEqual(expected, actual);
        }
    };
}