#include "pch.h"
#include "CppUnitTest.h"
#include "../C1XX/5304.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestC1xx
{
    TEST_CLASS(UnitTest5304)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            check("[1,3,4,8]",
                "[[0,1],[1,2],[0,3],[3,3]]",
                "[2,7,14,8]");
        }

        TEST_METHOD(TestMethod2)
        {
            check("[4,8,2,10]",
                "[[2,3],[1,3],[0,0],[0,3]]",
                "[8,0,4,4]");
        }

        void check(string arrSrc, string queriesSrc, string expectedSrc)
        {
            auto arr = toIntArray(arrSrc);
            auto queries = toInt2DArray(queriesSrc);
            auto expected = toIntArray(expectedSrc);
            Solution sln;
            auto actual = sln.xorQueries(arr, queries);
            Assert::AreEqual(expected, actual);
        }
    };
}