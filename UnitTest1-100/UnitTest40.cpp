#include "pch.h"
#include "CppUnitTest.h"
#include "../1-100/0040.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1100 {
    TEST_CLASS(UnitTest40) {
public:
    TEST_METHOD(TestMethod1) {
        check("[10,1,2,7,6,1,5]",
            8,
            "[[1,1,6],[1,2,5],[1,7],[2,6]]");
    }

    TEST_METHOD(TestMethod2) {
        check("[2,5,2,1,2]",
            5,
            "[[1,2,2],[5]]");
    }

private:
    void check(string candidatesSrc, int target, string expectedSrc) {
        auto candidates = toIntArray(candidatesSrc);
        auto expected = toInt2DArray(expectedSrc);
        Solution sln;
        auto actual = sln.combinationSum2(candidates, target);
        auto cmp = [](const vector<int>& a, vector<int>& b) {
            int end = min(a.size(), b.size());
            for (int i = 0; i < end; ++i) {
                if (a[i] != b[i]) {
                    return a[i] < b[i];
                }
            }

            return a.size() < b.size();
        };

        for (auto& i : expected) {
            sort(i.begin(), i.end());
        }

        for (auto& i : actual) {
            sort(i.begin(), i.end());
        }

        sort(expected.begin(), expected.end(), cmp);
        sort(actual.begin(), actual.end(), cmp);
        Assert::AreEqual(expected, actual);
    }
    };
}
