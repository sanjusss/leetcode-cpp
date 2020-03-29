#include "pch.h"
#include "CppUnitTest.h"
#include "../1101-1200/1162.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest11011200
{
    TEST_CLASS(UnitTest1162)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            check("[[1,0,1],[0,0,0],[1,0,1]]", 
                2);
        }

        TEST_METHOD(TestMethod2)
        {
            check("[[1,0,0],[0,0,0],[0,0,0]]",
                4);
        }

        TEST_METHOD(TestMethod3)
        {
            check("[[0,0,0],[0,0,0],[0,0,0]]",
                -1);
        }

        TEST_METHOD(TestMethod4)
        {
            check("[[1,1,1],[1,1,1],[1,1,1]]",
                -1);
        }

        void check(string gridSrc, int expected)
        {
            auto grid = toInt2DArray(gridSrc);
            Solution sln;
            auto actual = sln.maxDistance(grid);
            Assert::AreEqual(expected, actual);
        }
    };
}