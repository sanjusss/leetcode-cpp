#include "pch.h"
#include "CppUnitTest.h"
#include "../801-900/0892.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest801900
{
    TEST_CLASS(UnitTest892)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            check("[[2]]",
                10);
        }

        TEST_METHOD(TestMethod2)
        {
            check("[[1,2],[3,4]]",
                34);
        }

        TEST_METHOD(TestMethod3)
        {
            check("[[1,0],[0,2]]",
                16);
        }

        TEST_METHOD(TestMethod4)
        {
            check("[[1,1,1],[1,0,1],[1,1,1]]",
                32);
        }

        TEST_METHOD(TestMethod5)
        {
            check("[[2,2,2],[2,1,2],[2,2,2]]",
                46);
        }

        void check(string gridSrc, int expected)
        {
            auto grid = toInt2DArray(gridSrc);
            Solution sln;
            auto actual = sln.surfaceArea(grid);
            Assert::AreEqual(expected, actual);
        }
    };
}
