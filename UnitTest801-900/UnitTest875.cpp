#include "pch.h"
#include "CppUnitTest.h"
#include "../801-900/0875.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest801900
{
    TEST_CLASS(UnitTest875)
    {
    public:
        
        TEST_METHOD(TestMethod1)
        {
            check("[3,6,7,11]",
                8,
                4);
        }

        TEST_METHOD(TestMethod2)
        {
            check("[30,11,23,4,20]",
                5,
                30);
        }

        TEST_METHOD(TestMethod3)
        {
            check("[30,11,23,4,20]",
                6,
                23);
        }

        TEST_METHOD(TestMethod4)
        {
            check("[312884470]",
                968709470,
                1);
        }

    private:
        void check(string pilesSrc, int H, int expected)
        {
            auto piles = toIntArray(pilesSrc);
            Solution sln;
            auto actual = sln.minEatingSpeed(piles, H);
            Assert::AreEqual(expected, actual);
        }
    };
}
