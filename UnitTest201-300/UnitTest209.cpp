#include "pch.h"
#include "CppUnitTest.h"
#include "../201-300/0209.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest201300
{
    TEST_CLASS(UnitTest209)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            doTest(7, "[2,3,1,2,4,3]", 2);
        }

        TEST_METHOD(TestMethod2)
        {
            doTest(15, "[5,1,3,5,10,7,4,9,2,8]", 2);
        }

        void doTest(int s, string srcNums, int expected)
        {
            vector<int> nums = toIntArray(srcNums);
            Solution sln;
            auto actual = sln.minSubArrayLen(s, nums);
            Assert::AreEqual(expected, actual);
        }
    };
}