#include "pch.h"
#include "CppUnitTest.h"
#include "../C1XX/5211.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestC197 {
    TEST_CLASS(UnitTest5211) {
public:

    TEST_METHOD(TestMethod1) {
        check(3,
            "[[0, 1], [1, 2], [0, 2]]",
        "[0.5, 0.5, 0.2]",
        0,
            2,
            0.25);
    }

    void check(int n, string edgesSrc, string succProbSrc, int start, int end, double expected) {
        auto edges = toInt2DArray(edgesSrc);
        auto succProb = toArray<double>(succProbSrc);

        Solution sln;
        auto actual = sln.maxProbability(n, edges, succProb, start, end);
        Assert::IsTrue(abs(expected - actual) < 1e-5);
    }
    };
}