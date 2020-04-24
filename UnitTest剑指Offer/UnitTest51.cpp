#include "pch.h"
#include "CppUnitTest.h"
#include "unittest.h"
#include "../½£Ö¸Offer/51.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest½£Ö¸Offer
{
    TEST_CLASS(UnitTest½£Ö¸Offer51)
    {
    public:
        TEST_METHOD(TestMethod1)
        {
            check("[7,5,6,4]",
                5);
        }

        void check(string numsSrc, int expected)
        {
            auto nums = toIntArray(numsSrc);
            Solution sln;
            auto actual = sln.reversePairs(nums);
            Assert::AreEqual(expected, actual);
        }
    };
}
