#include "pch.h"
#include "CppUnitTest.h"
#include "../701-800/0774.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest701800
{
    TEST_CLASS(UnitTest774)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            doTest("[1, 2, 3, 4, 5, 6, 7, 8, 9, 10]",
                9,
                0.5);
        }

        TEST_METHOD(TestMethod2)
        {
            doTest("[23,24,36,39,46,56,57,65,84,98]",
                1,
                14);
        }

    private:
        void doTest(string stationsSrc, int K, double expected)
        {
            vector<int> stations = toIntArray(stationsSrc);
            Solution sln;
            auto actual = sln.minmaxGasDist(stations, K);
            Assert::IsTrue(fabs(expected - actual) < 1.0e-6);
        }
    };
}
