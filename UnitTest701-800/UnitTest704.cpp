#include "pch.h"
#include "CppUnitTest.h"
#include "../701-800/0704.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest701800
{
    TEST_CLASS(UnitTest704)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            doTest("[-1,0,3,5,9,12]",
                9,
                4);
        }

    private:
        void doTest(string numsSrc, int target, int expected)
        {
            vector<int> nums = toIntArray(numsSrc);
            Solution sln;
            auto actual = sln.search(nums, target);
            Assert::AreEqual(expected, actual);
        }
    };
}
