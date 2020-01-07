#include "pch.h"
#include "CppUnitTest.h"
#include "../401-500/0416.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest401500
{
    TEST_CLASS(UnitTest416)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            check("[1, 5, 11, 5]",
                true);
        }

        TEST_METHOD(TestMethod2)
        {
            check("[1, 2, 3, 5]",
                false);
        }

        void check(string numsSrc, bool expected)
        {
            auto nums = toIntArray(numsSrc);
            Solution sln;
            auto actual = sln.canPartition(nums);
            Assert::AreEqual(expected, actual);
        }
    };
}
