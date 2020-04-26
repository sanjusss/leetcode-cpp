#include "pch.h"
#include "CppUnitTest.h"
#include "../C1XX/5393.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestC186
{
    TEST_CLASS(UnitTest5393)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            check("[1,2,3,4,5,6,1]",
                3,
                12);
        }

        TEST_METHOD(TestMethod2)
        {
            check("[2,2,2]",
                2,
                4);
        }

        TEST_METHOD(TestMethod3)
        {
            check("[9,7,7,9,7,7,9]",
                7,
                55);
        }

        TEST_METHOD(TestMethod4)
        {
            check("[1,1000,1]",
                1,
                1);
        }

        TEST_METHOD(TestMethod5)
        {
            check("[1,79,80,1,1,1,200,1]",
                3,
                202);
        }

        void check(string cardPointsSrc, int k, int expected)
        {
            auto cardPoints = toIntArray(cardPointsSrc);
            Solution sln;
            auto actual = sln.maxScore(cardPoints, k);
            Assert::AreEqual(expected, actual);
        }
    };
}