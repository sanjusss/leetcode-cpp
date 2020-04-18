#include "pch.h"
#include "CppUnitTest.h"
#include "../2020-spring/2.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest2020Spring
{
    TEST_CLASS(UnitTest2)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            check(5, 
                "[[0,2],[2,1],[3,4],[2,3],[1,4],[2,0],[0,4]]",
                3,
                3);
        }

        TEST_METHOD(TestMethod2)
        {
            check(3, " [[0,2],[2,1]]",
                2,
                0);
        }

        void check(int n, string relationSrc, int k, int expected)
        {
            auto relation = toInt2DArray(relationSrc);
            Solution sln;
            auto actual = sln.numWays(n, relation, k);
            Assert::AreEqual(expected, actual);
        }
    };
}