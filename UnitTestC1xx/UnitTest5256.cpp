#include "pch.h"
#include "CppUnitTest.h"
#include "../C1XX/5256.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestC1xx
{
    TEST_CLASS(UnitTest5256)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            check(5, 5, "[2,1,2,0,1,0,1,2,0,1]", "[[1,1,1,0,1,0,0,1,0,0],[1,0,1,0,0,0,1,1,0,1]]");
        }

        void check(int upper, int lower, string colsumSrc, string expectedSrc)
        {
            auto colsum = toIntArray(colsumSrc);
            auto expected = toInt2DArray(expectedSrc);

            Solution sln;
            auto actual = sln.reconstructMatrix(upper, lower, colsum);
            Assert::AreEqual(expected, actual);
        }
    };
}
