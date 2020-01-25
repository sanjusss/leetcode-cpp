#include "pch.h"
#include "CppUnitTest.h"
#include "../1-100/0011.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1100
{
    TEST_CLASS(UnitTest0011)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            check("[1,8,6,2,5,4,8,3,7]", 49);
        }

        TEST_METHOD(TestMethod2)
        {
            check("[1,2]", 1);
        }

        void check(string heightSrc, int expected)
        {
            auto height = toIntArray(heightSrc);
            Solution sln;
            auto actual = sln.maxArea(height);
            Assert::AreEqual(expected, actual);
        }
    };
}