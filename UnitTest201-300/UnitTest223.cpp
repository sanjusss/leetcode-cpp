#include "pch.h"
#include "CppUnitTest.h"
#include "../201-300/0223.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest201300
{
    TEST_CLASS(UnitTest223)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            check(-3, 0, 3, 4, 0, -1, 9, 2, 45);
        }

        TEST_METHOD(TestMethod2)
        {
            check(-1500000001,
                0,
                - 1500000000,
                1,
                1500000000,
                0,
                1500000001,
                1,
                2);
        }

        TEST_METHOD(TestMethod3)
        {
            check(0,
                0,
                50000,
                40000,
                0,
                0,
                50000,
                40000,
                2000000000);
        }

    private:
        void check(int A, int B, int C, int D, int E, int F, int G, int H, int expected)
        {
            Solution sln;
            auto actual = sln.computeArea(A, B, C, D, E, F, G, H);
            Assert::AreEqual(expected, actual);
        }
    };
}
