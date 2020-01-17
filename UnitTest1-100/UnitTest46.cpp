#include "pch.h"
#include "CppUnitTest.h"
#include "../1-100/0046.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1100
{
    TEST_CLASS(UnitTest0046)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            check("[1,2,3]", "[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]");
        }

        void check(string numsSrc, string expectedSrc)
        {
            auto nums = toIntArray(numsSrc);
            auto expected = toInt2DArray(expectedSrc);
            Solution sln;
            auto actual = sln.permute(nums);
            Assert::AreEqual(expected, actual);
        }
    };
}