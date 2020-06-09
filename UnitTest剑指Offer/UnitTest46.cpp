#include "pch.h"
#include "CppUnitTest.h"
#include "unittest.h"
#include "../½£Ö¸Offer/46.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest½£Ö¸Offer
{
    TEST_CLASS(UnitTest½£Ö¸Offer46)
    {
    public:
        TEST_METHOD(TestMethod1)
        {
            check(12258, 5);
        }

        TEST_METHOD(TestMethod2)
        {
            check(506, 1);
        }

        void check(int num, int expected)
        {
            Solution sln;
            auto actual = sln.translateNum(num);
            Assert::AreEqual(expected, actual);
        }
    };
}
