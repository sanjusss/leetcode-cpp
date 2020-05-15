#include "pch.h"
#include "CppUnitTest.h"
#include "../501-600/0560.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest501600
{
    TEST_CLASS(UnitTest560)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            doTest("[1,1,1]", 2, 2);
        }

        TEST_METHOD(TestMethod2)
        {
            doTest("[1,2,1,2,1]", 3, 4);
        }

        void doTest(string numsSrc, int k, int expected)
        {
            auto nums = toIntArray(numsSrc);
            Solution sln;
            auto actual = sln.subarraySum(nums, k);
            Assert::AreEqual(expected, actual);
        }
    };
}
