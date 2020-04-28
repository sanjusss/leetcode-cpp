#include "pch.h"
#include "CppUnitTest.h"
#include "unittest.h"
#include "../½£Ö¸Offer/56-1.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest½£Ö¸Offer
{
    TEST_CLASS(UnitTest½£Ö¸Offer56_1)
    {
    public:
        TEST_METHOD(TestMethod1)
        {
            check("[4,1,4,6]",
                "[1,6]");
        }

        TEST_METHOD(TestMethod2)
        {
            check("[1,2,10,4,1,4,3,3]",
                "[2,10]");
        }

        void check(string numsSrc, string expectedSrc)
        {
            auto nums = toIntArray(numsSrc);
            auto expected = toIntArray(expectedSrc);
            Solution sln;
            auto actual = sln.singleNumbers(nums);
            sort(expected.begin(), expected.end());
            sort(actual.begin(), actual.end());
            Assert::AreEqual(expected, actual);
        }
    };
}
