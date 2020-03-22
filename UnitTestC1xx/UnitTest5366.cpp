#include "pch.h"
#include "CppUnitTest.h"
#include "../C1XX/5366.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestC181
{
    TEST_CLASS(UnitTest5366)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            check("[[2,4,3],[6,5,2]]",
                true);
        }

        TEST_METHOD(TestMethod2)
        {
            check("[[1,2,1],[1,2,1]]",
                false);
        }

        TEST_METHOD(TestMethod3)
        {
            check("[[1,1,2]]",
                false);
        }

        TEST_METHOD(TestMethod4)
        {
            check("[[1,1,1,1,1,1,3]]",
                true);
        }

        TEST_METHOD(TestMethod5)
        {
            check("[[2],[2],[2],[2],[2],[2],[6]]",
                true);
        }

        void check(string gridSrc, bool expected)
        {
            auto grid = toInt2DArray(gridSrc);
            Solution sln;
            auto actual = sln.hasValidPath(grid);
            Assert::AreEqual(expected, actual);
        }
    };
}