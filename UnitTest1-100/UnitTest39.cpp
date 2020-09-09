#include "pch.h"
#include "CppUnitTest.h"
#include "../1-100/0039.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1100 {
    TEST_CLASS(UnitTest39) {
    public:
        TEST_METHOD(TestMethod1) {
            check("[2,3,6,7]",
                7,
                "[[2,2,3],[7]]");
        }

        TEST_METHOD(TestMethod2) {
            check("[2,3,8,4]",
                6,
                "[[2,2,2],[2,4],[3,3]]");
        }

        TEST_METHOD(TestMethod3) {
            check("[2,3,5]",
                8,
                "[[2,2,2,2],[2,3,3],[3,5]]");
        }

    private:
        void check(string candidatesSrc, int target, string expectedSrc) {
            auto candidates = toIntArray(candidatesSrc);
            auto expected = toInt2DArray(expectedSrc);
            Solution sln;
            auto actual = sln.combinationSum(candidates, target);
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
