#include "pch.h"
#include "CppUnitTest.h"
#include "../C1XX/5309.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestC1xx
{
    TEST_CLASS(UnitTest5309)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            check(4,
                "[[0,1],[0,2],[1,2]]",
                1);
        }

        TEST_METHOD(TestMethod2)
        {
            check(6,
                "[[0,1],[0,2],[0,3],[1,2],[1,3]]",
                2);
        }

        TEST_METHOD(TestMethod3)
        {
            check(6,
                "[[0,1],[0,2],[0,3],[1,2]]",
                -1);
        }

        TEST_METHOD(TestMethod4)
        {
            check(5,
                "[[0,1],[0,2],[3,4],[2,3]]",
                0);
        }

        void check(int n, string connectionsSrc, int expected)
        {
            auto connections = toInt2DArray(connectionsSrc);
            Solution sln;
            auto actual = sln.makeConnected(n, connections);
            Assert::AreEqual(expected, actual);
        }
    };
}