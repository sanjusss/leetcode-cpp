#include "pch.h"
#include "CppUnitTest.h"
#include "../2020-spring/7.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest2020Spring
{
    TEST_CLASS(UnitTest7)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            check("[1,2,3,3]",
                2,
                3);
        }

        TEST_METHOD(TestMethod2)
        {
            check("[999,999,999]",
                4,
                0);
        }

        void check(string timeSrc, int m, int expected)
        {
            auto time = toIntArray(timeSrc);
            Solution sln;
            auto actual = sln.minTime(time, m);
            Assert::AreEqual(expected, actual);
        }
    };
}