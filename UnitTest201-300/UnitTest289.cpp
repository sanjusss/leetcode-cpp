#include "pch.h"
#include "CppUnitTest.h"
#include "../201-300/0289.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest201300
{
    TEST_CLASS(UnitTest289)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            doTest("[[0,1,0],[0,0,1],[1,1,1],[0,0,0]]",
                "[[0,0,0],[1,0,1],[0,1,1],[0,1,0]]");
        }

    private:
        void doTest(string boardSrc, string expectedSrc)
        {
            auto borad = toInt2DArray(boardSrc);
            auto expected = toInt2DArray(expectedSrc);
            Solution sln;
            sln.gameOfLife(borad);
            Assert::AreEqual(expected, borad);
        }
    };
}
