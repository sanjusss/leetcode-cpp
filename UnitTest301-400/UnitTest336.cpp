#include "pch.h"
#include "CppUnitTest.h"
#include "../301-400/0336.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest301400 {
    TEST_CLASS(UnitTest0336) {
    public:

        TEST_METHOD(TestMethod1) {
            check("[\"abcd\",\"dcba\",\"lls\",\"s\",\"sssll\"]",
                "[[0,1],[1,0],[3,2],[2,4]]");
        }

        TEST_METHOD(TestMethod2) {
            check("[\"bat\",\"tab\",\"cat\"]",
                "[[0,1],[1,0]] ");
        }

        TEST_METHOD(TestMethod3) {
            check("[\"a\",\"\"]",
                "[[0,1],[1,0]] ");
        }

        TEST_METHOD(TestMethod4) {
            check("[\"a\",\"b\",\"c\",\"ab\",\"ac\",\"aa\"]",
                "[[3,0],[1,3],[4,0],[2,4],[5,0],[0,5]]");
        }

        void check(string wordsSrc, string expectedSrc) {
            auto cmp = [](const vector<int>& a, const vector<int>& b) {
                if (a[0] == b[0]) {
                    return a[1] < b[1];
                }
                else {
                    return a[0] < b[0];
                }
            };
            auto words = toStringArray(wordsSrc);
            auto expected = toInt2DArray(expectedSrc);
            Solution sln;
            auto actual = sln.palindromePairs(words);
            sort(expected.begin(), expected.end(), cmp);
            sort(actual.begin(), actual.end(), cmp);
            Assert::AreEqual(expected, actual);
        }
    };
}