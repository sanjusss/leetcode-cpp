#include "pch.h"
#include "CppUnitTest.h"
#include "unittest.h"
#include "../程序员面试金典/01.07.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace 程序员面试金典UnitTest01
{
    TEST_CLASS(程序员面试金典UnitTest01_07)
    {
    public:
        TEST_METHOD(TestMethod1)
        {
            check("[[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]",
                "[[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]");
        }

        TEST_METHOD(TestMethod2)
        {
            check("[[1,2,3],[4,5,6],[7,8,9]]",
                "[[7,4,1],[8,5,2],[9,6,3]]");
        }

        void check(string matrixSrc, string expectedSrc)
        {
            auto matrix = toInt2DArray(matrixSrc);
            auto expected = toInt2DArray(expectedSrc);
            Solution sln;
            sln.rotate(matrix);
            Assert::AreEqual(expected, matrix);
        }
    };
}
