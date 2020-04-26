#include "pch.h"
#include "CppUnitTest.h"
#include "../C1XX/5394.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestC186
{
    TEST_CLASS(UnitTest5394)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            check("[[1,2,3],[4,5,6],[7,8,9]]",
                "[1,4,2,7,5,3,8,6,9]");
        }

        TEST_METHOD(TestMethod2)
        {
            check("[[1,2,3,4,5],[6,7],[8],[9,10,11],[12,13,14,15,16]]",
                "[1,6,2,8,7,3,9,4,12,10,5,13,11,14,15,16]");
        }

        TEST_METHOD(TestMethod3)
        {
            check("[[1,2,3],[4],[5,6,7],[8],[9,10,11]]",
                "[1,4,2,5,3,8,6,9,7,10,11]");
        }

        TEST_METHOD(TestMethod4)
        {
            check("[[1,2,3,4,5,6]]",
                "[1,2,3,4,5,6]");
        }

        void check(string numsSrc,  string expectedSrc)
        {
            auto nums = toInt2DArray(numsSrc);
            auto expected = toIntArray(expectedSrc);
            Solution sln;
            auto actual = sln.findDiagonalOrder(nums);
            Assert::AreEqual(expected, actual);
        }
    };
}