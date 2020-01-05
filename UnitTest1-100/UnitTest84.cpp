#include "pch.h"
#include "CppUnitTest.h"
#include "../1-100/0084.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1100
{
    TEST_CLASS(UnitTest84)
    {
    public:
        TEST_METHOD(TestMethod1)
        {
            check("[2,1,5,6,2,3]",
                10);
        }

    private:
        void check(string heightsSrc, int expected)
        {
            auto heights = toIntArray(heightsSrc);
            Solution sln;
            auto actual = sln.largestRectangleArea(heights);
            Assert::AreEqual(expected, actual);
        }
    };
}
