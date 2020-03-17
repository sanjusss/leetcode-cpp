#include "pch.h"
#include "CppUnitTest.h"
#include "../C1XX/5322.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestC1xx
{
    TEST_CLASS(UnitTest5322)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            check("[6,5,4,3,2,1]",
                2,
                7);
        }

        TEST_METHOD(TestMethod2)
        {
            check("[9,9,9]",
                4,
                -1);
        }

        TEST_METHOD(TestMethod3)
        {
            check("[1,1,1]",
                3,
                3);
        }

        TEST_METHOD(TestMethod4)
        {
            check("[7,1,7,1,7,1]",
                3,
                15);
        }

        TEST_METHOD(TestMethod5)
        {
            check("[11,111,22,222,33,333,44,444]",
                6,
                843);
        }

        void check(string jobDifficultySrc, int d, int expected)
        {
            auto jobDifficulty = toIntArray(jobDifficultySrc);
            Solution sln;
            auto actual = sln.minDifficulty(jobDifficulty, d);
            Assert::AreEqual(expected, actual);
        }
    };
}