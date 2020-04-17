#include "pch.h"
#include "CppUnitTest.h"
#include "../1-100/0055.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1100
{
    TEST_CLASS(UnitTest55)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            check("[2,3,1,1,4]",
                true);
        }

        TEST_METHOD(TestMethod2)
        {
            check("[3,2,1,0,4]",
                false);
        }

    private:
        void check(string numsSrc, bool expected)
        {
            auto nums = toIntArray(numsSrc);
            Solution s;
            auto actual = s.canJump(nums);
            Assert::AreEqual(expected, actual);
        }
    };
}
