#include "pch.h"
#include "CppUnitTest.h"
#include "../201-300/0213.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest201300
{
    TEST_CLASS(UnitTest213)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            check("[2,3,2]",
                3);
        }

        TEST_METHOD(TestMethod2)
        {
            check("[1,2,3,1]",
                4);
        }

    private:
        void check(string numsSrc, int expected)
        {
            auto nums = toIntArray(numsSrc);
            Solution sln;
            auto actual = sln.rob(nums);
            Assert::AreEqual(expected, actual);
        }
    };
}
