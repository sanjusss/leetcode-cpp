#include "pch.h"
#include "CppUnitTest.h"
#include "../701-800/0702.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest701800
{
    TEST_CLASS(UnitTest702)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            doTest("[-1,0,3,5,9,12]",
                9,
                4);
        }

        TEST_METHOD(TestMethod2)
        {
            doTest("[-1,0,3,5,9,12]",
                2,
                -1);
        }

    private:
        void doTest(string numsSrc, int target, int expected)
        {
            vector<int> nums = toIntArray(numsSrc);
            ArrayReader reader(nums);
            Solution sln;
            auto actual = sln.search(reader, target);
            Assert::AreEqual(expected, actual);
        }
    };
}
