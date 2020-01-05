#include "pch.h"
#include "CppUnitTest.h"
#include "../1-100/0085.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1100
{
    TEST_CLASS(UnitTest85)
    {
    public:
        TEST_METHOD(TestMethod1)
        {
            check("[[\"1\",\"0\",\"1\",\"0\",\"0\"],[\"1\",\"0\",\"1\",\"1\",\"1\"],[\"1\",\"1\",\"1\",\"1\",\"1\"],[\"1\",\"0\",\"0\",\"1\",\"0\"]]",
                6);
        }

    private:
        void check(string matrixSrc, int expected)
        {
            auto matrix = toChar2DArray(matrixSrc);
            Solution sln;
            auto actual = sln.maximalRectangle(matrix);
            Assert::AreEqual(expected, actual);
        }
    };
}
