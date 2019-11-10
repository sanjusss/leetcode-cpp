#include "pch.h"
#include "CppUnitTest.h"
#include "../C1XX/5255.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestC1xx
{
    TEST_CLASS(UnitTest5255)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            check(2, 3, "[[0,1],[1,1]]", 6);
        }

        TEST_METHOD(TestMethod2)
        {
            check(2, 2, "[[1,1],[0,0]]", 0);
        }

        TEST_METHOD(TestMethod3)
        {
            check(48, 37, "[[40,5]]", 83);
        }

        void check(int n, int m, string indicesSrc, int expected)
        {
            auto indices = toInt2DArray(indicesSrc);

            Solution sln;
            auto actual = sln.oddCells(n, m, indices);
            Assert::AreEqual(expected, actual);
        }
    };
}
