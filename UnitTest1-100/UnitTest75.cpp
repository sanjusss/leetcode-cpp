#include "pch.h"
#include "CppUnitTest.h"
#include "../1-100/0075.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1100
{
    TEST_CLASS(UnitTest75)
    {
    public:
        TEST_METHOD(TestMethod1)
        {
            check("[2,0,2,1,1,0]",
                "[0,0,1,1,2,2]");
        }

    private:
        void check(string numsSrc, string expectedSrc)
        {
            auto nums = toIntArray(numsSrc);
            auto expected = toIntArray(expectedSrc);
            Solution sln;
            sln.sortColors(nums);
            Assert::AreEqual(expected, nums);
        }
    };
}
