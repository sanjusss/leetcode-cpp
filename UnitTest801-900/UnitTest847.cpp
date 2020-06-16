#include "pch.h"
#include "CppUnitTest.h"
#include "../801-900/0847.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest801900
{
    TEST_CLASS(UnitTest847)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            check("[[1,2,3],[0],[0],[0]]",
                4);
        }

        TEST_METHOD(TestMethod2)
        {
            check("[[1],[0,2,4],[1,3,4],[2],[1,2]]",
                4);
        }

    private:
        void check(string graphSrc, int expected)
        {
            auto graph = toInt2DArray(graphSrc);
            Solution sln;
            auto actual = sln.shortestPathLength(graph);
            Assert::AreEqual(expected, actual);
        }
    };
}
