#include "pch.h"
#include "CppUnitTest.h"
#include "../201-300/0216.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest201300 {
    TEST_CLASS(UnitTest216) {
public:

    TEST_METHOD(TestMethod1) {
        check(3, 7, "[[1,2,4]]");
    }

    TEST_METHOD(TestMethod2) {
        check(3, 9, "[[1,2,6], [1,3,5], [2,3,4]]");
    }

    void check(int k, int n, string expectedSrc) {
        auto expected = toInt2DArray(expectedSrc);
        Solution sln;
        auto actual = sln.combinationSum3(k, n);
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