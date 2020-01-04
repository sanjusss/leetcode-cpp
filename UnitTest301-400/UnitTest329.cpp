#include "pch.h"
#include "CppUnitTest.h"
#include "../301-400/0329.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest301400
{
    TEST_CLASS(UnitTest0329)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            check("[[9, 9, 4],[6, 6, 8],[2, 1, 1]] ",
                4);
        }

        TEST_METHOD(TestMethod2)
        {
            check("[[3, 4, 5],[3, 2, 6],[2, 2, 1]] ",
                4);
        }

        TEST_METHOD(TestMethod3)
        {
            check("[[]] ",
                0);
        }

        TEST_METHOD(TestMethod4)
        {
            check("[[0],[1],[5],[5]]",
                3);
        }

        void check(string matrixSrc, int expected)
        {
            auto matrix = toInt2DArray(matrixSrc);
            Solution sln;
            auto actual = sln.longestIncreasingPath(matrix);
            Assert::AreEqual(expected, actual);
        }
    };
}