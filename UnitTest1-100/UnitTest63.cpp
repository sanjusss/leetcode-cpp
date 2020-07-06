#include "pch.h"
#include "CppUnitTest.h"
#include "../1-100/0063.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1100 {
    TEST_CLASS(UnitTest0063) {
    public:

        TEST_METHOD(TestMethod1) {
            check("[[0,0,0],[0,1,0],[0,0,0]]",
                2);
        }

        TEST_METHOD(TestMethod2) {
            check("[[1]]",
                0);
        }

        TEST_METHOD(TestMethod3) {
            check("[[0,0,0,0],[0,1,0,0],[0,0,0,0],[0,0,1,0],[0,0,0,0]]",
                7);
        }

        void check(string gridSrc, int expected) {
            auto grid = toInt2DArray(gridSrc);
            Solution sln;
            auto actual = sln.uniquePathsWithObstacles(grid);
            Assert::AreEqual(expected, actual);
        }
    };
}