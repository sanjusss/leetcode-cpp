#include "pch.h"
#include "CppUnitTest.h"
#include "../C1XX/5353.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestC1xx
{
    TEST_CLASS(UnitTest5353)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            check("[2,1,3,5,4]",
                3);
        }

        TEST_METHOD(TestMethod2)
        {
            check("[3,2,4,1,5]",
                2);
        }

        TEST_METHOD(TestMethod3)
        {
            check("[4,1,2,3]",
                1);
        }

        TEST_METHOD(TestMethod4)
        {
            check("[2,1,4,3,6,5]",
                3);
        }

        TEST_METHOD(TestMethod5)
        {
            check("[1,2,3,4,5,6]",
                6);
        }

        void check(string lightSrc, int expected)
        {
            auto light = toIntArray(lightSrc);
            Solution sln;
            auto actual = sln.numTimesAllBlue(light);
            Assert::AreEqual(expected, actual);
        }
    };
}