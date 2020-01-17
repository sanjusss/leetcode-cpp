#include "pch.h"
#include "CppUnitTest.h"
#include "../1-100/0047.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1100
{
    TEST_CLASS(UnitTest0047)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            check("[1,1,2]", "[[1,1,2],[1,2,1],[2,1,1]]");
        }

        void check(string numsSrc, string expectedSrc)
        {
            auto nums = toIntArray(numsSrc);
            auto expected = toInt2DArray(expectedSrc);
            Solution sln;
            auto actual = sln.permuteUnique(nums);
            Assert::AreEqual(expected, actual);
        }
    };
}