#include "pch.h"
#include "CppUnitTest.h"
#include "../C1XX/5355.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestC1xx
{
    TEST_CLASS(UnitTest5355)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            check(7,
                "[[1,2],[1,3],[1,7],[2,4],[2,6],[3,5]]",
                2,
                4,
                0.16666666666666666);
        }

        TEST_METHOD(TestMethod2)
        {
            check(7,
                "[[1,2],[1,3],[1,7],[2,4],[2,6],[3,5]]",
                1,
                7,
                0.3333333333333333);
        }

        TEST_METHOD(TestMethod3)
        {
            check(7,
                "[[1,2],[1,3],[1,7],[2,4],[2,6],[3,5]]",
                20,
                6,
                0.16666666666666666);
        }

        TEST_METHOD(TestMethod4)
        {
            check(10,
                "[[2,1],[3,2],[4,2],[5,2],[6,5],[7,1],[8,3],[9,1],[10,1]]",
                1,
                9,
                0.25);
        }

        void check(int n, string edgesSrc, int t, int target, double expected)
        {
            auto edges = toInt2DArray(edgesSrc);
            Solution sln;
            auto actual = sln.frogPosition(n, edges, t, target);
            Assert::IsTrue(fabs(expected - actual) < 1e-5);
        }
    };
}