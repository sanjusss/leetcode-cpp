#include "pch.h"
#include "CppUnitTest.h"
#include "../C1XX/5320.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestC1xx
{
    TEST_CLASS(UnitTest5320)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            check("[[1,4,1,40,10],[2,8,0,50,5],[3,8,1,30,4],[4,10,0,10,3],[5,1,1,15,1]]", 
                1,
                50,
                10,
                "[3,1,5]");
        }

        TEST_METHOD(TestMethod2)
        {
            check("[[1,4,1,40,10],[2,8,0,50,5],[3,8,1,30,4],[4,10,0,10,3],[5,1,1,15,1]]",
                0,
                50,
                10,
                "[4,3,2,1,5]");
        }

        TEST_METHOD(TestMethod3)
        {
            check("[[1,4,1,40,10],[2,8,0,50,5],[3,8,1,30,4],[4,10,0,10,3],[5,1,1,15,1]]",
                0,
                30,
                3,
                "[4,5]");
        }

        TEST_METHOD(TestMethod4)
        {
            check("[[77484,13400,1,4010,2926],[3336,85138,0,49966,89979],[28391,55328,0,69158,29058],[57395,64988,0,45312,30261]]",
                0,
                99739,
                60242,
                "[57395,28391,77484]");
        }

        void check(string restaurantsSrc, int veganFriendly, int maxPrice, int maxDistance, string expectedSrc)
        {
            auto restaurants = toInt2DArray(restaurantsSrc);
            auto expected = toIntArray(expectedSrc);
            Solution sln;
            auto actual = sln.filterRestaurants(restaurants, veganFriendly, maxPrice, maxDistance);
            Assert::AreEqual(expected, actual);
        }
    };
}