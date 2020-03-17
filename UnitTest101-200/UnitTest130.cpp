#include "pch.h"
#include "CppUnitTest.h"
#include "../101-200/0130.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestC1xx
{
    TEST_CLASS(UnitTest0130)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            check("[[\"X\",\"X\",\"X\",\"X\"],[\"X\",\"O\",\"O\",\"X\"],[\"X\",\"X\",\"O\",\"X\"],[\"X\",\"O\",\"X\",\"X\"]]",
                "[[\"X\",\"X\",\"X\",\"X\"],[\"X\",\"X\",\"X\",\"X\"],[\"X\",\"X\",\"X\",\"X\"],[\"X\",\"O\",\"X\",\"X\"]]");
        }

        TEST_METHOD(TestMethod2)
        {
            check("[[\"O\",\"O\",\"O\"],[\"O\",\"O\",\"O\"],[\"O\",\"O\",\"O\"]]",
                "[[\"O\",\"O\",\"O\"],[\"O\",\"O\",\"O\"],[\"O\",\"O\",\"O\"]]");
        }

        void check(string boardSrc, string expectedSrc)
        {
            auto board = toChar2DArray(boardSrc);
            auto expected = toChar2DArray(expectedSrc);
            Solution sln;
            sln.solve(board);
            Assert::AreEqual(expected, board);
        }
    };
}