#include "pch.h"
#include "CppUnitTest.h"
#include "../301-400/0315.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest301400
{
    TEST_CLASS(UnitTest0315)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            check("[5,2,6,1]",
                "[2,1,1,0]");
        }

        TEST_METHOD(TestMethod2)
        {
            check("[2,0,1]",
                "[2,0,0]");
        }

        TEST_METHOD(TestMethod3)
        {
            check("[-1,-1]",
                "[0,0]");
        }

        TEST_METHOD(TestMethod4)
        {
            check("[26,78,27,100,33,67,90,23,66,5,38,7,35,23,52,22,83,51,98,69,81,32,78,28,94,13,2,97,3,76,99,51,9,21,84,66,65,36,100,41]",
                "[10,27,10,35,12,22,28,8,19,2,12,2,9,6,12,5,17,9,19,12,14,6,12,5,12,3,0,10,0,7,8,4,0,0,4,3,2,0,1,0]");
        }

        void check(string numsSrc, string expectedSrc)
        {
            auto nums = toIntArray(numsSrc);
            auto expected = toIntArray(expectedSrc);
            Solution sln;
            auto actual = sln.countSmaller(nums);
            Assert::AreEqual(expected, actual);
        }
    };
}