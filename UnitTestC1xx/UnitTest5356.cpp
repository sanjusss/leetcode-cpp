#include "pch.h"
#include "CppUnitTest.h"
#include "../C1XX/5356.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestC180
{
    TEST_CLASS(UnitTest5356)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            check("[[3,7,8],[9,11,13],[15,16,17]]",
                "[15]");
        }

        TEST_METHOD(TestMethod2)
        {
            check("[[1,10,4,2],[9,3,8,7],[15,16,17,12]]",
                "[12]");
        }

        TEST_METHOD(TestMethod3)
        {
            check("[[7,8],[1,2]]",
                "[7]");
        }

        void check(string matrixSrc, string expectedSrc)
        {
            auto matrix = toInt2DArray(matrixSrc);
            auto expected = toIntArray(expectedSrc);
            Solution sln;
            auto actual = sln.luckyNumbers(matrix);
            sort(expected.begin(), expected.end());
            sort(actual.begin(), actual.end());
            Assert::AreEqual(expected, actual);
        }
    };
}